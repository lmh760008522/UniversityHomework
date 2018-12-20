#include <pcap.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>

#define SNAP_LEN 1518
#define SIZE_ETHERNET 14
#define ETHER_ADDR_LEN  6

 struct sniff_ethernet
 {
  u_char ether_dhost[ETHER_ADDR_LEN];
  u_char ether_shost[ETHER_ADDR_LEN];
  u_short ether_type;
 };

 struct sniff_ip
 {
  u_char ip_vhl;			
  u_char ip_tos;			
  u_short ip_len;		   
  u_short ip_id;		   
  u_short ip_off;		     
  u_char ip_ttl;			
  u_char ip_p;			    
  u_short ip_sum;			
  struct in_addr ip_src, ip_dst;   
 };

// TCP
 typedef u_int tcp_seq;

// UDP
 struct sniff_udp
 {
  uint16_t sport;       
  uint16_t dport;      
  uint16_t udp_length;
  uint16_t udp_sum;    
};

struct sniff_tcp
{
  u_short th_sport;     
  u_short th_dport;     
  tcp_seq th_seq;       
  tcp_seq th_ack;      
  u_char th_offx2;      
  u_char th_flags;
  u_short th_win;       
  u_short th_sum;       
  u_short th_urp;       
};

FILE *Packet,*Report;
pthread_t thread[2];
pthread_mutex_t mut;
static int num = 1;
static int totalT = 0;
static int totalU = 0;
static int writeT = 0;
static int writeU = 0;
static int count = 1;     
pcap_t *handle;				

void signalHandler(int signalNum){
	pcap_breakloop(handle);
}

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet){
  const struct sniff_ethernet *ethernet;
  const struct sniff_ip *ip;
  const struct sniff_tcp *tcp;
  const struct sniff_udp *udp;

  int size_ip;
  int size_tcp;
  int size_payload;

  count++;

  ethernet = (struct sniff_ethernet *) (packet);

  ip = (struct sniff_ip *) (packet + SIZE_ETHERNET);
  size_ip = IP_HL (ip) * 4;
  if (size_ip < 20)
  {
      return 0;
  }

  if(ip->ip_p == IPPROTO_TCP){//若为TCP包
    totalT++;
   	printf ("%d[TCP]",num);
	fprintf(Packet,"%d[TCP]",num++);
	writeT++;

	tcp = (struct sniff_tcp *) (packet + SIZE_ETHERNET + size_ip);
    size_tcp = TH_OFF (tcp) * 4;
    if (size_tcp < 20)
    {
       printf ("Invalid TCP header length:%u bytes\n",size_tcp);
       return;
    }

    printf ("tcp->th_sport:%d tcp->th_dport:%d\n", ntohs(tcp->th_sport), ntohs(tcp->th_dport));
    fprintf(Packet,"tcp->th_sport:%d tcp->th_dport:%d\n",ntohs(tcp->th_sport), ntohs(tcp->th_dport));
  }else if(ip->ip_p == IPPROTO_UDP){//若为UDP包
    totalU++;
    printf ("%d[UDP]",num);
	fprintf(Packet,"%d[UDP]",num++);
	writeU++;

	udp = (struct sniff_udp *)(packet + SIZE_ETHERNET + size_ip);
    printf ("udp->sport:%d udp->dport:%d udp->udp_length:%d udp->udp_sum:%d\n", ntohs(udp->sport), ntohs(udp->dport), ntohs(udp->udp_length), ntohs(udp->udp_sum));
    sprintf(Packet,"udp->sport:%d udp->dport:%d udp->udp_length:%d udp->udp_sum:%d\n", ntohs(udp->sport), ntohs(udp->dport), ntohs(udp->udp_length), ntohs(udp->udp_sum));
  }
  return 0;
}

void *thread1(){
	printf("N_rev_P2:%d\nN_wrt_P2:%d\nN_rev_P2/N_wrt_P2=%lf\n", writeU, totalU, (double)totalU/count);
	fprintf(Report,"N_rev_P2:%d\nN_wrt_P2:%d\nN_rev_P2/N_wrt_P2=%lf\n", writeU, totalU, (double)totalU/count);
}
void *thread2(){
	printf("N_rev_P1:%d\nN_wrt_P1:%d\nN_rev_P1/N_wrt_P1=%lf\n", writeT, totalT ,(double)totalT/count);
	fprintf(Report,"N_rev_P1:%d\nN_wrt_P1:%d\nN_rev_P1/N_wrt_P1=%lf\n", writeT, totalT,(double)totalT/count);
}

void thread_create(void){
    int temp;
    memset(&thread, 0, sizeof(thread));
    if((temp = pthread_create(&thread[0], NULL, thread1, NULL)) != 0){
        printf("Thread1 created failed\n");
    }else{
        printf("Thread1 created\n");
    }
    if((temp = pthread_create(&thread[1], NULL, thread2, NULL)) != 0){
        printf("Thread2 created failed");
    }else{
        printf("Thread2 created\n");
    }
}
void thread_wait(void){
    pthread_join(thread[0],NULL);
    pthread_join(thread[1],NULL);
}

int main (int argc, char **argv){
    int j = 0;
    char *dev = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    char filter_exp[] = "ip";
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;
    int num_packets = 0;

    //开启信号量
    signal(SIGINT,signalHandler);

    Packet = fopen("Packet.txt","w+");
    Report = fopen("Report.txt","w+");
    if (!Packet || !Report)
    {
      printf("Cannot open the file!\n");
      return 0;
    }

	//线程互斥
    pthread_mutex_init(&mut,NULL);

    if (argc == 2){
      dev = argv[1];
    }
    else if (argc > 2){
      fprintf (stderr, "Error: unrecognized command-line options\n\n");
      exit (EXIT_FAILURE);
    }
    else{
      dev = pcap_lookupdev (errbuf);
      if (dev == NULL){
       fprintf (stderr, "Couldn't find default device: %s\n", errbuf);
       exit (EXIT_FAILURE);
      }
    } 

   //绑定本机
   if (pcap_lookupnet (dev, &net, &mask, errbuf) == -1){
       fprintf (stderr, "Couldn't get netmask for device %s: %s\n",dev, errbuf);
       net = 0;
       mask = 0;
   }

    //设置网卡过滤规则，只接受IP包
    handle = pcap_open_live (dev, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL){
      fprintf (stderr, "Couldn't open device %s: %s\n", dev, errbuf);
      exit (EXIT_FAILURE);
    }
    if (pcap_datalink (handle) != DLT_EN10MB){
      fprintf (stderr, "%s is not an Ethernet\n", dev);
      exit (EXIT_FAILURE);
    }
    if (pcap_compile (handle, &fp, filter_exp, 0, net) == -1){
      fprintf (stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
      exit (EXIT_FAILURE);
    }
    if (pcap_setfilter (handle, &fp) == -1){
      fprintf (stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
      exit (EXIT_FAILURE);
    }

    pcap_loop (handle, num_packets, got_packet, NULL);
    thread_create();
    thread_wait();

    pcap_freecode (&fp);
    pcap_close (handle);
    printf ("Capture complete.\n");
    fclose(Packet);
    fclose(Report);
    return 0;
}



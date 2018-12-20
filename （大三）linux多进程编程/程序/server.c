#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include<gtk/gtk.h>
#include <fcntl.h>//文件

#define SRVPORT 8000
#define LISTEN_QUEUE 20
#define BUF_SIZE 1024
void deal_pressed1(GtkButton *button, gpointer user_data) //start
{
int serverSock = -1 ,clientSock = -1;
    int opt = 1;
    int length = 0;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t len_clientAddr = sizeof(clientAddr);
    char buffer[BUF_SIZE];
    FILE *server_data;

	// 初始化服务器端的socket地址结构
	bzero(&serverAddr, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = htons(INADDR_ANY);
	serverAddr.sin_port = htons(SRVPORT);

	// 创建socket
	serverSock = socket(AF_INET, SOCK_STREAM, 0);
	if(serverSock < 0)
	{
		perror("Socket Creation Failed：");
		exit(1);
	}
	printf("Socket Create Successfully.\n");
	setsockopt(serverSock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	// 绑定socket
	if((bind(serverSock, (struct sockaddr*)&serverAddr, sizeof(serverAddr))) == -1  )
	{
		perror("Server Bind Failed:");
		exit(1);
	}
	printf("Bind successful.\n");

	// socket监听
	if((listen(serverSock, LISTEN_QUEUE)) == -1)
	{
		perror("Server Listen Failed:");
		exit(1);
	}
	printf("Start to Listen.\n");

		//打开文件
	    server_data = fopen("server_data.txt","w+");
	    if(server_data == -1){
		perror("File Open Failed:");
		exit(1);
	    }
	    printf("File has opened.\n");


	while(1)
	{
		// 接受连接请求，返回一个新的socket(描述符)，这个新socket用于同连接的客户端通信
		clientSock = accept(serverSock, (struct sockaddr*)&clientAddr, &len_clientAddr);
		if(clientSock < 0)
		{
			perror("Server Accept Failed:");
			exit(1);
		}
		printf("Server Accept Success.\n");

		while(1)
		{
			// 从服务器接收数据到buffer中
			// 每接收一段数据，便将其写入文件中，循环直到文件接收完并写完为止
			bzero(buffer, BUF_SIZE);
			length = recv(clientSock, buffer, sizeof(buffer), 0);
			if(length <=0){
				perror("Receive error:");
				exit(1);
			}
			printf("length:%d buffer:%s",length, buffer);
			//if(fwrite(buffer, sizeof(char), sizeof(buffer), server_data) < length)
			if(fputs(buffer, server_data) < 0)
			{
				printf("File Write Failed\n");
				exit(1);
			}else{
				printf("Write success. buffer:%s", buffer);
			}
			bzero(buffer, BUF_SIZE);
		}
		close(clientSock);
	}

	close(serverSock);
	fclose(server_data);
	return 0;
}
void deal_pressed2(GtkButton *button, gpointer user_data) //start
{
return 0;
}
int main(int argc,char *argv[])
{
      //1.gtk环境的初始化
    gtk_init(&argc, &argv);
    //2.创建一个窗口
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *table = gtk_table_new(3,5,TRUE);
     //将table加入到window中
     gtk_container_add(GTK_CONTAINER(window), table);



         //3.创建一个按钮button
        GtkWidget *button1 = gtk_button_new_with_label("Start");
  GtkWidget *button2 = gtk_button_new_with_label("End");

     gtk_table_attach_defaults(GTK_TABLE(table), button1, 1, 2, 1, 2);
     gtk_table_attach_defaults(GTK_TABLE(table), button2, 3, 4, 1, 2);
   

        //4.创建一个按钮信号
        g_signal_connect(button1, "pressed", G_CALLBACK(deal_pressed1), " Start");  //start
        g_signal_connect(button1, "pressed", G_CALLBACK(deal_pressed2), " End"); //end

        //5.显示所控件
        gtk_widget_show_all(window);

        //6.主事件循环
        gtk_main();

        return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include<gtk/gtk.h>

#define SERVER_PORT 8000
#define BUF_SIZE 1024
void deal_pressed1(GtkButton *button, gpointer user_data) //start
{
	int clientSock = -1;
	struct sockaddr_in client_addr ,server_addr;
	socklen_t server_addr_length;
   	char buffer[BUF_SIZE];
	int length = 0;
	FILE *fp;

	//初始化一个客户端的socket地址结构
	bzero(&client_addr, sizeof(client_addr));
	client_addr.sin_family = AF_INET;
	client_addr.sin_addr.s_addr = htons(INADDR_ANY);
	client_addr.sin_port = htons(0);

	//初始化一个服务器端的socket地址结构
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(SERVER_PORT);
	server_addr_length = sizeof(server_addr);

	//创建socket，若成功，返回socket描述符
	clientSock = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSock < 0)
	{
		perror("Create Socket Failed:");
		exit(1);
	}
	printf("Creat Socket Success.\n");

	//绑定客户端的socket和客户端的socket地址结构
	if((bind(clientSock, (struct sockaddr*)&client_addr, sizeof(client_addr))) == -1)
	{
		perror("Client Bind Error:");
		exit(1);
	}
	printf("Client Bind Success.\n");


	// 向服务器发起连接
	if(connect(clientSock, (struct sockaddr*)&server_addr, server_addr_length) < 0)
	{
		perror("Connect error:");
		exit(1);
	}
	printf("Connect Success.\n");

		// 打开文件并读取文件数据
		fp = fopen("Packet.txt", "r");
		if(NULL == fp)
		{
			printf("File Not Found\n");
		}
		else
		{
			printf("File has opened successfully.\n");
			bzero(buffer, BUF_SIZE);

			// 每读取一段数据，便将其发送给客户端，循环直到文件读完为止
			while(fgets(buffer, BUF_SIZE, fp) != NULL)
			{
				printf("buffer:%s ", buffer);
				length = send(clientSock, buffer, sizeof(buffer), 0);
				printf("length:%d\n",length);
				if(length <0)
				{
					perror("Send Failed:");
					break;
				}else{

					printf("Send success.");
				}
				bzero(buffer, BUF_SIZE);
			}
			// 关闭文件
			fclose(fp);
			//printf("File Transfer Successful!\n");
		}

	close(clientSock);
	return 0;
}
void deal_pressed2(GtkButton *button, gpointer user_data) //end 
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

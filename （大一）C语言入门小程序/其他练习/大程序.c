/* Note:Your choice is C IDE */
#include "stdio.h"
#include"string.h"
typedef struct student
{
	int  num;
	char name[20];
	int score;
	int rank;
}student;
int readin(student *stu)
{
	int i=0;
    int n;
    printf("学号：");
	scanf("%d\n",&stu[i].num);
	printf("姓名：");
    scanf("%c\n",&stu[i].name);
    printf("成绩：");
    scanf("%d",&stu[i].score);
    printf("        1.继续        ");
    printf("        0.返回        ");
    scanf("%d",&n);
    switch(n)
    {
    	case 0:printf("返回！");break;
    	case 1:
    	{
    	if(i<19)
    	{
    		i++;
    		readin(stu);
    	}
    	else printf("返回！");
    	}
    }
	
}
void print(student *stu)
{
	int i;
	FILE *fp;
	char ch;
	fp=fopen("d:\\学生档案.txt","r");
	if(fp==0)
	{
		printf("文件打开失败！");
	}
	ch=fgetc(fp);
	printhead();
	while(ch!=EOF)
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	putchar('\n');
    fclose(fp);
    
}
int sort(student *stu,int n)
{
	
}
int cul(student *stu,int n)
{
	
}
int insert(student *stu,int n)
{
	
}
int del(student *stu,int n)
{
	
}
void printhead()
{
	printf("学号    姓名    成绩    名次\n");
}
void menu()
{
	printf("********1.显示基本信息********\n");
	printf("********2.基本信息管理********\n");
	printf("********3.学生成绩管理********\n");
	printf("********4.考试成绩统计********\n");
	printf("********5.根据条件查询********\n");
	printf("********0.退出        ********\n");
}
void manubase()
{
	printf("%%%%%%%%1.插入学生记录%%%%%%%%\n");
	printf("%%%%%%%%2.删除学生记录%%%%%%%%\n");
	printf("%%%%%%%%3.修改学生记录%%%%%%%%\n");
	printf("%%%%%%%%0.退出        %%%%%%%%\n");
}
void menuscore()
{
	printf("@@@@@@@@1.计算学生总分@@@@@@@@");
	printf("@@@@@@@@2.根据总分排名@@@@@@@@");
	printf("@@@@@@@@0.返回上层菜单@@@@@@@@");
}
void menucount()
{
	printf("&&&&&&&&1.求课程最高分&&&&&&&&");
	printf("&&&&&&&&2.求课程最低分&&&&&&&&");
	printf("&&&&&&&&3.求课程平均分&&&&&&&&");
	printf("&&&&&&&&0.返回上层菜单&&&&&&&&");
}
void menuscarch()
{
	printf("########1.按学号查询  ########");
	printf("########2.按姓名查询  ########");
	printf("########3.按名次查询  ########");
	printf("########0.返回上层菜单########");
}
int menu2(student *stu,int n)
{
	int choice,t,find[20];
	student s;
	do
	{
		menubase();
		printf("选择：\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
		}
	};
}

int main()
{
    stedunt stu[20];
    int choice,n;
    FILE *fp;
    fp=fopen("d:\\学生档案.txt","w+");
    if(fp==0)
    {
    	printf("文件打开失败！");
    }
    menu();
    printf("选择：");
    scanf("%d",&n);
    switch(n)
    {
    	case 1:
    	case 2:
    	case 3:
    	case 4:
    	case 5:
    	case 0:printf("再见！");
    }
}
#include "SysMan.h"
#include<stdio.h>
#include<stdlib.h>
char * s_gets(char *st,int n)
{
	char *ret_val;
	char *find;


	ret_val=fgets(st, n, stdin);
	if(ret_val)
	{
		find=strchr(st,'\n');
		if(find)
			*find = '\0';
		else
		while(getchar()!='\n')
			continue;
	}
	return ret_val;
}
void ShowNChar(char ch,int num)
{
	int cnt;
	for(cnt=1;cnt<=num;cnt++)
		putchar(ch);
}
void delay(unsigned long msec)//一个超级浪费的延时函数，单位毫秒
{
	clock_t now,start;

	start=clock();
	do
	{
		now=clock();
	}
	while(now-start<msec);
	return;
}
void delayexit(void)
{
	/********为了好玩*********/
	putchar('\n');
	ShowNChar(' ',25);
	printf("*** ***\n");
	putchar('\n');
	ShowNChar(' ',25);
	printf("操作成功，正在退出.");
	delay(250);
	putchar('.');
	delay(250);
	putchar('.');
	delay(250);
	putchar('.');
	delay(250);
	putchar('.');
	delay(250);
	putchar('.');
	/********JUST FOR FUN*********/
}
int GetOrder(void)
{
	int temp=-1;
	while(scanf("%d",&temp)!=1||(temp<0||temp>5)){//输入不合法
		ShowNChar(' ',10);
		printf("Wrong choice!");
//		getchar();
//		getchar();
		fflush(stdin);
		ShowNChar(' ',10);
		system("pause");
		system("cls");
		ShowMenu();
	}
	return temp;
}
void ShowMenu(void)
{
	system("cls");
	int spaces;//记录跳过空格的数量
	putchar('\n');
	spaces=(WIDTH-strlen(TOPIC))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",TOPIC);
	putchar('\n');
	spaces=(WIDTH-strlen(DIVIDE))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",DIVIDE);
	putchar('\n');
	spaces=(WIDTH-strlen(SYS1))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",SYS1);
	putchar('\n');
	spaces=(WIDTH-strlen(SYS2))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",SYS2);
	putchar('\n');
	spaces=(WIDTH-strlen(SYS3))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",SYS3);
	putchar('\n');
	spaces=(WIDTH-strlen(SYS4))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",SYS4);
	putchar('\n');
	spaces=(WIDTH-strlen(SYS5))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",SYS5);
	putchar('\n');
	spaces=(WIDTH-strlen(SYS0))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",SYS0);
	spaces=(WIDTH-strlen(DIVIDE))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",DIVIDE);
	putchar('\n');

	ShowNChar(' ',10);
	printf("Enter your choice<0-5> :");
//	fflush(stdin);
}
void StuManage(void)//子菜单-学生信息
{
	int StuOrder;
	ShowStuMenu();
    while((StuOrder=StuGetOrder())!=0){
		printf("StuOrder:%d\n",StuOrder);
		switch (StuOrder)
		{
			case 1:
				system("cls");
				AddStu();
				break;
			case 2:
				system("cls");
				FixStu();
				break;
			case 3:
				system("cls");
				DeletStu();
				break;
			case 4:
				system("cls");
				ShowStu();
				break;
			case 5:
				system("cls");
				SortStu();
				break;
			case 0:
				break;
			default:
				printf("Wrong.");
		}
		ShowStuMenu();
    }

    return;
}
void ClaManage(void)//子菜单-课程
{
	int ClaOrder;
	ShowClaMenu();
    while((ClaOrder=ClaGetOrder())!=0){
		printf("ClaOrder:%d\n",ClaOrder);
		switch (ClaOrder)
		{
			case 1:
				system("cls");
				AddCla();
				break;
			case 2:
				system("cls");
				FixCla();
				break;
			case 3:
				system("cls");
				DeletCla();
				break;
			case 4:
				system("cls");
				ShowCla();
				break;
			case 5:
				system("cls");
				SortCla();
				break;
			case 0:
				break;
			default:
				printf("Wrong.");
		}
		ShowClaMenu();
    }
    return;
}
void ChoManage(void)//子菜单-选课
{
	int ChoOrder;
	ShowChoMenu();
    while((ChoOrder=ChoGetOrder())!=0){
		printf("ChoOrder:%d\n",ChoOrder);
		switch (ChoOrder)
		{
			case 1:
				system("cls");
				ChooseCourse();
				break;
			case 2:
				system("cls");
				DelBySno();
				break;
			case 3:
				system("cls");
				DelByCno();
				break;
			case 4:
				system("cls");
				ShowBySno();
				break;
			case 5:
				system("cls");
				ShowByCno();
				break;
			case 6:
				system("cls");
				ShowAll();
				break;
			case 0:
				break;
			default:
				printf("Wrong.");
		}
		ShowChoMenu();
    }
    return;
}
void GraManage(void)//子菜单-成绩
{
	int GraOrder;
	ShowGradeMenu();
    while((GraOrder=GradeGetOrder())!=0){
		printf("GraOrder:%d\n",GraOrder);
		switch (GraOrder)
		{
			case 1:
				system("cls");
				EnterGrade();
				break;
			case 2:
				system("cls");
				FixGrade();
				break;
			default:
				printf("Wrong.");
		}
		ShowGradeMenu();
    }
    return;
}
void InqManage(void)//子菜单-查询
{
	int InqOrder;
	ShowInqMenu();
    while((InqOrder=InqGetOrder())!=0){
		printf("InqOrder:%d\n",InqOrder);
		switch (InqOrder)
		{
			case 11:
				system("cls");
				InqSBySno();
				break;
			case 12:
				system("cls");
				InqSBySname();
				break;
			case 13:
				system("cls");
				InqSByAddress();
				break;
			case 21:
				system("cls");
				InqCByCno();
				break;
			case 22:
				system("cls");
				InqCByCname();
				break;
			case 31:
				system("cls");
				ShowBySno();
				break;
			case 32:
				system("cls");
				ShowByCno();
				break;
			case 33:
				system("cls");
				ShowAll();
				break;
			case 41:
				system("cls");
				InqGraBySno();
				break;
			case 42:
				system("cls");
				InqGraByCno();
				break;
			case 43:
				system("cls");
				InqGraByList();
				break;
			default:
				printf("Wrong.");
		}
		ShowInqMenu();
    }
    return;
}

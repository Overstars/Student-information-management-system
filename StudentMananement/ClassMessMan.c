
#include "ClassMessMan.h"
#include<stdio.h>
#include<stdlib.h>

void ShowClaMenu(void)
{
	system("cls");
	int spaces;//记录跳过空格的数量
	putchar('\n');
	spaces=(WIDTHCLA-strlen(TOPICCLA))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",TOPICCLA);
	putchar('\n');
	spaces=(WIDTHCLA-strlen(DIVIDE))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",DIVIDE);
	putchar('\n');
	spaces=(WIDTHCLA-strlen(CLA1))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",CLA1);
	putchar('\n');
	spaces=(WIDTHCLA-strlen(CLA2))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",CLA2);
	putchar('\n');
	spaces=(WIDTHCLA-strlen(CLA3))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",CLA3);
	putchar('\n');
	spaces=(WIDTHCLA-strlen(CLA4))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",CLA4);
	putchar('\n');
	spaces=(WIDTHCLA-strlen(CLA5))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",CLA5);
	putchar('\n');
	spaces=(WIDTHCLA-strlen(CLA0))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",CLA0);
	spaces=(WIDTHCLA-strlen(DIVIDE))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",DIVIDE);
	putchar('\n');
	ShowNChar(' ',10);
	printf("Enter your choice<0-5> :");

//	getchar();
	fflush(stdin);

	return;
}
int ClaGetOrder(void)
{
	int temp=-1;
	while(scanf("%d",&temp)!=1||(temp<0||temp>5)){//输入不合法
		ShowNChar(' ',10);
		printf("Wrong choice!");
//		getchar();
//		getchar();
		fflush(stdin);
		system("cls");
		ShowClaMenu();
	}
	return temp;
}

//void AddItem(cla item,cla *plist);//将item添加至链表尾
void EmptyList(cla *plist)
{
	cla *psave;
	while(plist!=NULL){
		psave=plist->next;
		free(plist);
		plist=psave;
	}
}
void AddCla(void)//创建链表,写入文件后清空链表
{
	cla *head=NULL,*pre,*current;//创建头节点
	int cnum=0;
	printf("\n\n\n");
	ShowNChar(' ',25);
	puts("添加新课程信息( 输入课程号为0结束)");
	printf("\n");
	ShowNChar(' ',25);
	fflush(stdin);
	printf("课序号: ");
	while(scanf("%d",&cnum)==1&&cnum>0){
		current=(cla*)malloc(sizeof(cla));//申请到新节点
		if(head==NULL)
			head=current;
		else
			pre->next=current;
		current->next=NULL;
		/************输入信息部分************/
		current->cno=cnum;

		printf("\n");
		ShowNChar(' ',25);
		fflush(stdin);
		printf("课程名: ");
		s_gets(current->name,30);

		printf("\n");
		ShowNChar(' ',25);
		fflush(stdin);
		printf("学  分: ");
		scanf("%d",&current->score);

		printf("\n");
		ShowNChar(' ',25);
		fflush(stdin);
		printf("学  时: ");
		scanf("%d",&current->hour);

		/************输入信息结束************/
		pre=current;

		system("cls");
		printf("\n\n\n");
		ShowNChar(' ',25);
		puts("添加新课程信息( 输入课程号为0结束)");
		printf("\n");
		ShowNChar(' ',25);
		fflush(stdin);
		printf("课序号: ");
	}
	if(head==NULL){
		printf("\n\n\n");
		ShowNChar(' ',25);
		puts("没有数据.");
	}
	else{
		FILE *fp;
		if((fp=fopen("course.dat","ab+"))==NULL){
			puts("Cant't open course.dat.");
			exit(1);
		}
		current=head;
		while(current!=NULL){
			fwrite(current,sizeof(cla),1,fp);
			current=current->next;
		}
		if(fclose(fp)!=0)
		{
			printf("关闭文件错误\n");
			exit(1);
		}
		current=head;
		EmptyList(current);
	}
	delayexit();
	return;
}
void ShowClaMess(cla *p)//FixCla()的附加函数
{
	putchar('\n');
	ShowNChar(' ',25);
	printf("原课程信息:\n");
	ShowNChar(' ',25);
	printf("课程号:%d\n",p->cno);
	ShowNChar(' ',25);
	printf("课程名:%s\n",p->name);
	ShowNChar(' ',25);
	printf("学  分:%d\n",p->score);
	ShowNChar(' ',25);
	printf("学  时:%d\n\n",p->hour);
}
void FixCla(void)
{
	int cnum,flag=0;//是否存在目标课程
//	int spaces;//记录跳过空格的数量
	FILE *fp;
	if((fp=fopen("course.dat","rb+"))==NULL){
		puts("Cant't open course.dat.");
		exit(1);
	}
	putchar('\n');
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("输入要修改信息的课程号：");
	while(scanf("%d",&cnum)!=1){
		fflush(stdin);
		ShowNChar(' ',25);
		printf("请正确输入!");
	}
	cla temp;
	fread(&temp,sizeof(cla),1,fp);
	while(!feof(fp)){
		if(temp.cno==cnum){
			flag=1;
			break;
		}
		fread(&temp,sizeof(cla),1,fp);
	}
	if(flag){
		char jud[10];
		ShowClaMess(&temp);
		/************************************/
			ShowNChar(' ',25);
			fflush(stdin);
			printf("输入要修改的信息:\n");
			ShowNChar(' ',25);
			printf("课程号：%d",temp.cno);

			printf("\n");
			ShowNChar(' ',25);
			fflush(stdin);
			printf("课程名: ");
			s_gets(temp.name,30);

			ShowNChar(' ',25);
			fflush(stdin);
			printf("学  分: ");
			scanf("%d",&temp.score);
			fflush(stdin);

			ShowNChar(' ',25);
			fflush(stdin);
			printf("学  时: ");
			scanf("%d",&temp.hour);

		/************************************/
		putchar('\n');
		putchar('\n');
		ShowNChar(' ',25);
		fflush(stdin);
		printf("保存修改吗？(Y-确认 N-放弃)：");
		s_gets(jud,10);
		if(jud[0]=='y'||jud[0]=='Y'){
			fseek(fp,-sizeof(cla),SEEK_CUR);
			fwrite(&temp,sizeof(cla),1,fp);
		}
	}
	else{
		putchar('\n');
		ShowNChar(' ',25);
		printf("ERROR!该课程不存在!\n\n");
	}
	if(fclose(fp)!=0)
	{
		printf("关闭course.dat错误\n");
		exit(1);
	}
	ShowNChar(' ',25);
	system("pause");
	system("cls");
	return;
}
void DeletCla(void)

{
	int cnum=0,flag=0;//是否存在目标课程
	FILE *fp,*ft;
	if((fp=fopen("course.dat","rb+"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	putchar('\n');
	ShowNChar(' ',25);
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("输入要删除信息的课程号：");
	while(scanf("%d",&cnum)!=1){
		fflush(stdin);
		putchar('\n');
		ShowNChar(' ',25);
		printf("请正确输入!");
	}
	cla temp;
	fread(&temp,sizeof(cla),1,fp);
	while(!feof(fp)){
		if(temp.cno==cnum){
			flag=1;
			ShowClaMess(&temp);
			break;
		}
		fread(&temp,sizeof(cla),1,fp);
	}
	if(flag){
		char jud[10];
		putchar('\n');
		putchar('\n');
		ShowNChar(' ',25);
		fflush(stdin);
		printf("保存修改吗？(Y-确认 N-放弃)：");
		s_gets(jud,10);
		if(jud[0]=='y'||jud[0]=='Y'){
			if((ft=fopen("tempc.dat","wb+"))==NULL)
			{
				ShowNChar(' ',25);
				puts("Cant't open.");
				exit(1);
			}
			rewind(fp);//fp移到开头
			fread(&temp,sizeof(cla),1,fp);
			while(!feof(fp)){
				if(temp.cno!=cnum){
				   fwrite(&temp,sizeof(cla),1,ft);
				}
				fread(&temp,sizeof(cla),1,fp);
			}
			if(fclose(ft)!=0)
			{
				putchar('\n');
				ShowNChar(' ',25);
				puts("Can't close!");
				exit(1);
			}
			if(fclose(fp)!=0)
			{
				putchar('\n');
				ShowNChar(' ',25);
				printf("关闭文件错误\n");
				exit(1);
			}
			if(remove("course.dat")==0)
				printf("Removed course.dat\n");
			else{
				printf("error:%d",errno);//快做完了这里也要处理
				printf("移除失败\n");
			}
			if(rename("tempc.dat","course.dat")==0)
				printf("Rename tempc.dat to course.dat\n");
			else
				printf("重命名失败\n");
			/********很无奈的写法结束*********/
			delayexit();
		}
		else{//取消删除
			if(fclose(fp)!=0)
			{
				putchar('\n');
				ShowNChar(' ',25);
				printf("关闭文件错误\n");
				exit(1);
			}
		}
	}
	else{//找不到要删除的
		putchar('\n');
		ShowNChar(' ',25);
		printf("ERROR!该课程不存在!\n\n");
		if(fclose(fp)!=0)
		{
			putchar('\n');
			ShowNChar(' ',25);
			printf("关闭文件错误\n");
			exit(1);
		}

	}
	putchar('\n');
	ShowNChar(' ',25);
	system("cls");
	return;
}
void ShowCla(void)
{
	cla temp;
	FILE *fp;
	if((fp=fopen("course.dat","rb"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	putchar('\n');
//	int spaces=(WIDTHCLA-strlen("课程信息"))/2;
	ShowNChar(' ',37);
	puts("课程信息");
	printf("\n\n");
	ShowNChar(' ',25);
	printf("课程号\t课程名       学分    学时\n");
	ShowNChar(' ',25);
	ShowNChar('-',30);
	putchar('\n');
	fread(&temp,sizeof(cla),1,fp);
	while(!feof(fp)){
		ShowNChar(' ',25);
		printf("%-8d%-12s%-8d%-8d\n",temp.cno,temp.name,temp.score,temp.hour);
		fread(&temp,sizeof(cla),1,fp);
	}
	printf("\n");
	ShowNChar(' ',25);
	if(fclose(fp)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("关闭文件错误\n");
		exit(1);
	}
	system("pause");
	system("cls");
	return;
}
int cmpcla(const void *a,const void *b)//SortCla()附加函数
{
	cla c=*(cla*)a;
	cla d=*(cla*)b;//按升序排序
	return c.cno-d.cno;
//    return ((*(stu*)b).sno) - ((*(stu*)a).sno);
}
void SortCla(void)
{
	cla arr[100],temp;
	int cnt=0;
	FILE *fp;
	if((fp=fopen("course.dat","rb+"))==NULL){
		puts("Cant't open course.dat.");
		exit(1);
	}
	fread(&temp,sizeof(cla),1,fp);
	while(!feof(fp)&&cnt<80)
	{
		arr[cnt++]=temp;
		fread(&temp,sizeof(cla),1,fp);
	}
	if(fclose(fp)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("关闭文件错误\n");
		exit(1);
	}
	qsort(arr,cnt,sizeof(cla),cmpcla);
	if((fp=fopen("course.dat","wb+"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	int i;
	for(i=0;i<cnt;i++){
		fwrite(&arr[i],sizeof(cla),1,fp);
	}
//	for(i=0;i<cnt;i++)//调试函数
//	{
//		printf("排序后%d:",i+1);
//		printf("%-8d%-10s%d     %-8s\n",temp.cno,temp.name,temp.score,temp.hour);
//	}
	if(fclose(fp)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("关闭文件错误\n");
		exit(1);
	}
	delayexit();
	return;
}

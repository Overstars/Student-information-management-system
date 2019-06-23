
#include "ClassMessMan.h"
#include<stdio.h>
#include<stdlib.h>

void ShowClaMenu(void)
{
	system("cls");
	int spaces;//��¼�����ո������
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
	while(scanf("%d",&temp)!=1||(temp<0||temp>5)){//���벻�Ϸ�
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

//void AddItem(cla item,cla *plist);//��item���������β
void EmptyList(cla *plist)
{
	cla *psave;
	while(plist!=NULL){
		psave=plist->next;
		free(plist);
		plist=psave;
	}
}
void AddCla(void)//��������,д���ļ����������
{
	cla *head=NULL,*pre,*current;//����ͷ�ڵ�
	int cnum=0;
	printf("\n\n\n");
	ShowNChar(' ',25);
	puts("����¿γ���Ϣ( ����γ̺�Ϊ0����)");
	printf("\n");
	ShowNChar(' ',25);
	fflush(stdin);
	printf("�����: ");
	while(scanf("%d",&cnum)==1&&cnum>0){
		current=(cla*)malloc(sizeof(cla));//���뵽�½ڵ�
		if(head==NULL)
			head=current;
		else
			pre->next=current;
		current->next=NULL;
		/************������Ϣ����************/
		current->cno=cnum;

		printf("\n");
		ShowNChar(' ',25);
		fflush(stdin);
		printf("�γ���: ");
		s_gets(current->name,30);

		printf("\n");
		ShowNChar(' ',25);
		fflush(stdin);
		printf("ѧ  ��: ");
		scanf("%d",&current->score);

		printf("\n");
		ShowNChar(' ',25);
		fflush(stdin);
		printf("ѧ  ʱ: ");
		scanf("%d",&current->hour);

		/************������Ϣ����************/
		pre=current;

		system("cls");
		printf("\n\n\n");
		ShowNChar(' ',25);
		puts("����¿γ���Ϣ( ����γ̺�Ϊ0����)");
		printf("\n");
		ShowNChar(' ',25);
		fflush(stdin);
		printf("�����: ");
	}
	if(head==NULL){
		printf("\n\n\n");
		ShowNChar(' ',25);
		puts("û������.");
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
			printf("�ر��ļ�����\n");
			exit(1);
		}
		current=head;
		EmptyList(current);
	}
	delayexit();
	return;
}
void ShowClaMess(cla *p)//FixCla()�ĸ��Ӻ���
{
	putchar('\n');
	ShowNChar(' ',25);
	printf("ԭ�γ���Ϣ:\n");
	ShowNChar(' ',25);
	printf("�γ̺�:%d\n",p->cno);
	ShowNChar(' ',25);
	printf("�γ���:%s\n",p->name);
	ShowNChar(' ',25);
	printf("ѧ  ��:%d\n",p->score);
	ShowNChar(' ',25);
	printf("ѧ  ʱ:%d\n\n",p->hour);
}
void FixCla(void)
{
	int cnum,flag=0;//�Ƿ����Ŀ��γ�
//	int spaces;//��¼�����ո������
	FILE *fp;
	if((fp=fopen("course.dat","rb+"))==NULL){
		puts("Cant't open course.dat.");
		exit(1);
	}
	putchar('\n');
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("����Ҫ�޸���Ϣ�Ŀγ̺ţ�");
	while(scanf("%d",&cnum)!=1){
		fflush(stdin);
		ShowNChar(' ',25);
		printf("����ȷ����!");
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
			printf("����Ҫ�޸ĵ���Ϣ:\n");
			ShowNChar(' ',25);
			printf("�γ̺ţ�%d",temp.cno);

			printf("\n");
			ShowNChar(' ',25);
			fflush(stdin);
			printf("�γ���: ");
			s_gets(temp.name,30);

			ShowNChar(' ',25);
			fflush(stdin);
			printf("ѧ  ��: ");
			scanf("%d",&temp.score);
			fflush(stdin);

			ShowNChar(' ',25);
			fflush(stdin);
			printf("ѧ  ʱ: ");
			scanf("%d",&temp.hour);

		/************************************/
		putchar('\n');
		putchar('\n');
		ShowNChar(' ',25);
		fflush(stdin);
		printf("�����޸���(Y-ȷ�� N-����)��");
		s_gets(jud,10);
		if(jud[0]=='y'||jud[0]=='Y'){
			fseek(fp,-sizeof(cla),SEEK_CUR);
			fwrite(&temp,sizeof(cla),1,fp);
		}
	}
	else{
		putchar('\n');
		ShowNChar(' ',25);
		printf("ERROR!�ÿγ̲�����!\n\n");
	}
	if(fclose(fp)!=0)
	{
		printf("�ر�course.dat����\n");
		exit(1);
	}
	ShowNChar(' ',25);
	system("pause");
	system("cls");
	return;
}
void DeletCla(void)

{
	int cnum=0,flag=0;//�Ƿ����Ŀ��γ�
	FILE *fp,*ft;
	if((fp=fopen("course.dat","rb+"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	putchar('\n');
	ShowNChar(' ',25);
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("����Ҫɾ����Ϣ�Ŀγ̺ţ�");
	while(scanf("%d",&cnum)!=1){
		fflush(stdin);
		putchar('\n');
		ShowNChar(' ',25);
		printf("����ȷ����!");
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
		printf("�����޸���(Y-ȷ�� N-����)��");
		s_gets(jud,10);
		if(jud[0]=='y'||jud[0]=='Y'){
			if((ft=fopen("tempc.dat","wb+"))==NULL)
			{
				ShowNChar(' ',25);
				puts("Cant't open.");
				exit(1);
			}
			rewind(fp);//fp�Ƶ���ͷ
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
				printf("�ر��ļ�����\n");
				exit(1);
			}
			if(remove("course.dat")==0)
				printf("Removed course.dat\n");
			else{
				printf("error:%d",errno);//������������ҲҪ����
				printf("�Ƴ�ʧ��\n");
			}
			if(rename("tempc.dat","course.dat")==0)
				printf("Rename tempc.dat to course.dat\n");
			else
				printf("������ʧ��\n");
			/********�����ε�д������*********/
			delayexit();
		}
		else{//ȡ��ɾ��
			if(fclose(fp)!=0)
			{
				putchar('\n');
				ShowNChar(' ',25);
				printf("�ر��ļ�����\n");
				exit(1);
			}
		}
	}
	else{//�Ҳ���Ҫɾ����
		putchar('\n');
		ShowNChar(' ',25);
		printf("ERROR!�ÿγ̲�����!\n\n");
		if(fclose(fp)!=0)
		{
			putchar('\n');
			ShowNChar(' ',25);
			printf("�ر��ļ�����\n");
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
//	int spaces=(WIDTHCLA-strlen("�γ���Ϣ"))/2;
	ShowNChar(' ',37);
	puts("�γ���Ϣ");
	printf("\n\n");
	ShowNChar(' ',25);
	printf("�γ̺�\t�γ���       ѧ��    ѧʱ\n");
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
		printf("�ر��ļ�����\n");
		exit(1);
	}
	system("pause");
	system("cls");
	return;
}
int cmpcla(const void *a,const void *b)//SortCla()���Ӻ���
{
	cla c=*(cla*)a;
	cla d=*(cla*)b;//����������
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
		printf("�ر��ļ�����\n");
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
//	for(i=0;i<cnt;i++)//���Ժ���
//	{
//		printf("�����%d:",i+1);
//		printf("%-8d%-10s%d     %-8s\n",temp.cno,temp.name,temp.score,temp.hour);
//	}
	if(fclose(fp)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("�ر��ļ�����\n");
		exit(1);
	}
	delayexit();
	return;
}

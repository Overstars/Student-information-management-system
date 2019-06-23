
#include "StudentManage.h"
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>


void ShowStuMenu(void)
{
	system("cls");
	int spaces;//��¼�����ո������
	putchar('\n');
	spaces=(WIDTHST-strlen(TOPICST))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",TOPICST);
	putchar('\n');
	spaces=(WIDTHST-strlen(DIVIDE))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",DIVIDE);
	putchar('\n');
	spaces=(WIDTHST-strlen(STM1))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",STM1);
	putchar('\n');
	spaces=(WIDTHST-strlen(STM2))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",STM2);
	putchar('\n');
	spaces=(WIDTHST-strlen(STM3))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",STM3);
	putchar('\n');
	spaces=(WIDTHST-strlen(STM4))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",STM4);
	putchar('\n');
	spaces=(WIDTHST-strlen(STM5))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",STM5);
	putchar('\n');
	spaces=(WIDTHST-strlen(STM0))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",STM0);
	spaces=(WIDTHST-strlen(DIVIDE))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",DIVIDE);
	putchar('\n');
	ShowNChar(' ',10);
	printf("Enter your choice<0-5> :");

//	getchar();
	fflush(stdin);

	return;
}
int StuGetOrder(void)
{
	int temp=-1;
	while(scanf("%d",&temp)!=1||(temp<0||temp>5)){//���벻�Ϸ�
		ShowNChar(' ',10);
		printf("Wrong choice!");
		fflush(stdin);
		putchar('\n');
		system("pause");
		system("cls");
		ShowStuMenu();
	}
	return temp;
}

void AddStu(void)
{
	FILE *fp;
	if((fp=fopen("student.dat","ab+"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	stu temp;
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("�����ѧ����Ϣ<����ѧ��ѧ��Ϊ0ʱ����>\n\n");
	ShowNChar(' ',25);
	printf("ѧ�ţ�");
	while(scanf("%d",&temp.sno)==1&&temp.sno!=0){
		printf("\n");
		ShowNChar(' ',25);
		fflush(stdin);
		printf("����: ");
		s_gets(temp.name,30);

		printf("\n");
		ShowNChar(' ',25);
		fflush(stdin);
		printf("�Ա�: ");
		scanf(" %c",&temp.sex);


		printf("\n");
		ShowNChar(' ',25);
		fflush(stdin);
		printf("��ַ: ");
		s_gets(temp.address,30);

		fwrite(&temp,sizeof(stu),1,fp);
		system("cls");

		printf("\n\n\n");
		ShowNChar(' ',25);
		printf("�����ѧ����Ϣ<����ѧ��ѧ��Ϊ0ʱ����>\n\n");
		ShowNChar(' ',25);
		printf("ѧ�ţ�");
		fflush(stdin);
	}
	if(fclose(fp)!=0)
	{
		printf("�ر��ļ�����\n");
		exit(1);
	}
	delayexit();
	return;
}

void FixStu(void)
{
	int snum,flag=0;//�Ƿ����Ŀ��ѧ��
//	int spaces;//��¼�����ո������
	FILE *fp;
	if((fp=fopen("student.dat","rb+"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	putchar('\n');
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("����Ҫ�޸���Ϣ��ѧ��ѧ�ţ�");
	while(scanf("%d",&snum)!=1){
		fflush(stdin);
		ShowNChar(' ',25);
		printf("����ȷ����!");
	}
	stu temp;
	fread(&temp,sizeof(stu),1,fp);
	while(!feof(fp)){
		if(temp.sno==snum){
			flag=1;
			break;
		}
		fread(&temp,sizeof(stu),1,fp);
	}
	if(flag){
		char jud[10];
		ShowStuMess(&temp);
		/************************************/
			ShowNChar(' ',25);
			fflush(stdin);
			printf("����Ҫ�޸ĵ���Ϣ:\n");
			ShowNChar(' ',25);
			printf("ѧ�ţ�%d",temp.sno);

			printf("\n");
			ShowNChar(' ',25);
			fflush(stdin);
			printf("����: ");
			s_gets(temp.name,30);

			ShowNChar(' ',25);
			fflush(stdin);
			printf("�Ա�: ");
			scanf(" %c",&temp.sex);
			fflush(stdin);

			ShowNChar(' ',25);
			fflush(stdin);
			printf("��ַ: ");
			s_gets(temp.address,30);

		/************************************/
		putchar('\n');
		putchar('\n');
		ShowNChar(' ',25);
		fflush(stdin);
		printf("�����޸���(Y-ȷ�� N-����)��");
		s_gets(jud,10);
		if(jud[0]=='y'||jud[0]=='Y'){
			fseek(fp,-sizeof(stu),SEEK_CUR);
			fwrite(&temp,sizeof(stu),1,fp);
		}
	}
	else{
		putchar('\n');
		ShowNChar(' ',25);
		printf("ERROR!��ѧ��������!\n\n");
	}
	if(fclose(fp)!=0)
	{
		printf("�ر��ļ�����\n");
		exit(1);
	}
	ShowNChar(' ',25);
	system("pause");
	system("cls");
	return;
}
void ShowStuMess(stu *p)//FixStu()�ĸ��Ӻ���
{
	putchar('\n');
	ShowNChar(' ',25);
	printf("ԭѧ����Ϣ:\n");
	ShowNChar(' ',25);
	printf("ѧ��:%d\n",p->sno);
	ShowNChar(' ',25);
	printf("����:%s\n",p->name);
	ShowNChar(' ',25);
	printf("�Ա�:%c\n",p->sex);
	ShowNChar(' ',25);
	printf("��ַ:%s\n\n",p->address);
}
void DeletStu(void)
{
	int snum=0,flag=0;//�Ƿ����Ŀ��ѧ��
//	int spaces;//��¼�����ո������
	FILE *fp,*ft;
	if((fp=fopen("student.dat","rb+"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	putchar('\n');
	ShowNChar(' ',25);
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("����Ҫɾ����Ϣ��ѧ��ѧ�ţ�");
	while(scanf("%d",&snum)!=1){
		fflush(stdin);
		putchar('\n');
		ShowNChar(' ',25);
		printf("����ȷ����!");
	}
	stu temp;
	fread(&temp,sizeof(stu),1,fp);
	while(!feof(fp)){
		if(temp.sno==snum){
			flag=1;
			ShowStuMess(&temp);
			break;
		}
		fread(&temp,sizeof(stu),1,fp);
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
			/********�����ε�д��1����Դ�ļ����в���*********/
//			while(!feof(fp)){
//				fseek(fp,0L,SEEK_SET);
//				fread(&temp,sizeof(stu),1,fp);//��ȡ����һ����
//				if(feof(fp)==0)
//					break;
//				fseek(fp,-2*sizeof(stu),SEEK_CUR);//д����һ������
//				fwrite(&temp,sizeof(stu),1,fp);
//				fseek(fp,2*sizeof(stu),SEEK_CUR);
//			}
			/********�����ε�д��2�������ļ�*********/
			if((ft=fopen("temp.dat","wb+"))==NULL)
			{
				ShowNChar(' ',25);
				puts("Cant't open.");
				exit(1);
			}
			rewind(fp);//fp�Ƶ���ͷ
//			int index=0;
			fread(&temp,sizeof(stu),1,fp);
			while(!feof(fp)){
				if(temp.sno!=snum){
				   fwrite(&temp,sizeof(stu),1,ft);
//				   index++;//ͳ����ɾ��ѧ�Ų�ͬ�ĸ���
				}
//				else{
//					fseek(fp,0,SEEK_CUR);//�Թ��������Ϣ
//				}
//				if(feof(fp)!=0){
//					fseek(fp,sizeof(stu),SEEK_CUR);
//					if(feof(fp)==0)
//						break;
//					fseek(fp,-sizeof(stu),SEEK_CUR);
//				}
				fread(&temp,sizeof(stu),1,fp);
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
			if(remove("student.dat")==0)//�������˾Ͱ���鴦��һ��
				printf("Removed student.dat\n");
			else{
				printf("error:%d",errno);
				printf("�Ƴ�ʧ��\n");
			}
			if(rename("temp.dat","student.dat")==0)
				printf("Rename temp.dat to student.dat\n");
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
	else{//�Ҳ���Ҫɾ����ѧ��
		putchar('\n');
		ShowNChar(' ',25);
		printf("ERROR!��ѧ��������!\n\n");
		if(fclose(fp)!=0)
		{
			putchar('\n');
			ShowNChar(' ',25);
			printf("�ر��ļ�����\n");
			exit(1);
		}

//		system("pause");
	}

	putchar('\n');
	ShowNChar(' ',25);
	system("cls");
	return;
}
void ShowStu(void)
{
	stu temp;
	FILE *fp;
	if((fp=fopen("student.dat","rb"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	putchar('\n');
	int spaces=(WIDTHST-strlen("ѧ����Ϣ"))/2;
	ShowNChar(' ',spaces);
	printf("\n\n");
	ShowNChar(' ',25);
	printf("ѧ��\t����      �Ա�  ��ַ\n");
	ShowNChar(' ',25);
	ShowNChar('-',30);
	putchar('\n');
	fread(&temp,sizeof(stu),1,fp);
	while(!feof(fp)){
		ShowNChar(' ',25);
		printf("%-8d%-10s%c     %-8s\n",temp.sno,temp.name,temp.sex,temp.address);
		fread(&temp,sizeof(stu),1,fp);
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
void SortStu(void)
{
	stu arr[80],temp;
	int cnt=0;
	FILE *fp;
	if((fp=fopen("student.dat","rb+"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	fread(&temp,sizeof(stu),1,fp);
	while(!feof(fp)&&cnt<80)
	{
		arr[cnt++]=temp;
		fread(&temp,sizeof(stu),1,fp);
	}
	if(fclose(fp)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("�ر��ļ�����\n");
		exit(1);
	}
	qsort(arr,cnt,sizeof(stu),cmpst);
	if((fp=fopen("student.dat","wb+"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	int i;
	for(i=0;i<cnt;i++){
		fwrite(&arr[i],sizeof(stu),1,fp);
	}
//	for(i=0;i<cnt;i++)//���Ժ���
//	{
//		printf("�����%d:",i+1);
//		printf("%-8d%-10s%c     %-8s\n",arr[i].sno,arr[i].name,arr[i].sex,arr[i].address);
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
int cmpst(const void *a,const void *b)//SortStu()���Ӻ���
{
	stu c=*(stu*)a;
	stu d=*(stu*)b;//����������
	return c.sno-d.sno;
//    return ((*(stu*)b).sno) - ((*(stu*)a).sno);
}


#include "SysMan.h"
#include "ChooseCor.h"//�ṩ�ṹ��ԭ��
void ShowChoMenu(void)
{
	system("cls");
	int spaces;//��¼�����ո������
	putchar('\n');
	spaces=(WIDTHCHO-strlen(TOPICCHO))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",TOPICCHO);
	putchar('\n');
	spaces=(WIDTHCHO-strlen(DIVIDE))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",DIVIDE);
	putchar('\n');
	spaces=(WIDTHCHO-strlen(CHO1))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",CHO1);
	putchar('\n');
	spaces=(WIDTHCHO-strlen(CHO2))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",CHO2);
	putchar('\n');
	spaces=(WIDTHCHO-strlen(CHO3))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",CHO3);
	putchar('\n');
	spaces=(WIDTHCHO-strlen(CHO4))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",CHO4);
	putchar('\n');
	spaces=(WIDTHCHO-strlen(CHO5))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",CHO5);
	putchar('\n');
	spaces=(WIDTHCHO-strlen(CHO6))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",CHO6);
	putchar('\n');
	spaces=(WIDTHCHO-strlen(CHO0))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",CHO0);
	spaces=(WIDTHCHO-strlen(DIVIDE))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",DIVIDE);
	putchar('\n');
	ShowNChar(' ',10);
	printf("Enter your choice<0-6> :");

//	getchar();
	fflush(stdin);

	return;
}
int ChoGetOrder(void)
{
	int temp=-1;
	while(scanf("%d",&temp)!=1||(temp<0||temp>6)){//���벻�Ϸ�
		ShowNChar(' ',10);
		printf("Wrong choice!");
		fflush(stdin);
		putchar('\n');
		system("pause");
		system("cls");
		ShowChoMenu();
	}
	return temp;
}

void ChooseCourse(void)
{
	system("cls");
	FILE *fpCho,*fpStu,*fpCor;
	if((fpCho=fopen("result.dat","ab+"))==NULL||(fpStu=fopen("student.dat","rb"))==NULL||(fpCor=fopen("course.dat","rb"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	cho tempcho;
	stu tempstu;
	cla tempcla;
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("ѡ�Σ�\n");
	ShowNChar(' ',25);
	ShowNChar('-',30);
	printf("\n");
	ShowNChar(' ',25);
	fflush(stdin);
	printf("����ѧ�ţ�");
	int stuno,sflag=0;//��¼�����ѧ��

	while(scanf("%d",&stuno)!=1||stuno<1){
		ShowNChar(' ',25);
		printf("����ȷ���룡\n");
		ShowNChar(' ',25);
		fflush(stdin);
	}
	fread(&tempstu,sizeof(stu),1,fpStu);
	while(!feof(fpStu)){
		if(tempstu.sno==stuno){//ȷ��ѧ���Ƿ����
			sflag=1;
			break;
		}
		fread(&tempstu,sizeof(stu),1,fpStu);
	}
	if(sflag){
		fflush(stdin);
		ShowNChar(' ',25);
		printf("����ѡ��ѧ�ڣ�");
		int term=0,cournum=0;
		while(scanf("%d",&term)!=1||term<1){
			ShowNChar(' ',25);
			printf("����ȷ���룡\n");
			ShowNChar(' ',25);
			fflush(stdin);
		}
		tempcho.sno=stuno;//��ѧ�Ŵ���
		tempcho.term=term;//��ѧ�ڴ���
		strncpy(tempcho.sname,tempstu.name,30);//��ѧ����������
		tempcho.grade=0;//�ɼ���ʱ��ʼ��Ϊ0
		system("cls");
		/**********ChooseCourse����ҳ��**********/
		printf("\n\n\n");
		ShowNChar(' ',25);
		printf("ѡ��\t\t\tѧ�ڣ�%d\n",term);
		ShowNChar(' ',25);
		ShowNChar('-',30);
		printf("\n\n");
		ShowNChar(' ',25);
		fflush(stdin);
		printf("ѧ�ţ�%d\t\t������%s\n\n",stuno,tempstu.name);

		ShowNChar(' ',25);
		printf("����ѡ�κ�(����0����)��");
		while(1){
			while(scanf("%d",&cournum)!=1||cournum<0){
				printf("����ȷ���룡\n");
				fflush(stdin);
			}
			if(cournum==0)
				break;
			int cflag=0;
			rewind(fpCor);
			fread(&tempcla,sizeof(cla),1,fpCor);
			while(!feof(fpCor)){
				if(tempcla.cno==cournum){//ȷ���γ��Ƿ����
					cflag=1;
					break;
				}
				fread(&tempcla,sizeof(cla),1,fpCor);
			}
			if(cflag){
				tempcho.course=cournum;
				strncpy(tempcho.cname,tempcla.name,30);//���γ�������
				fwrite(&tempcho,sizeof(cho),1,fpCho);
			}
			else{
				ShowNChar(' ',25);
				printf("ERROR:�ÿγ̲�����!\n");
			}
			ShowNChar(' ',25);
			fflush(stdin);
			printf("����ѡ�κ�(����0����)��");
		}
		/*********��ҳ�����***********/
		printf("\n\n");
		ShowNChar(' ',25);
		delayexit();
	}
	else{
		ShowNChar(' ',25);
		printf("ERROR:��ѧ��������!\n\n");
		ShowNChar(' ',25);
		system("pause");
	}
	if(fclose(fpStu)!=0||fclose(fpCho)!=0||fclose(fpCor)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("�ر��ļ�����\n");
		exit(1);
	}
	return;
}

void ShowChoCourMess1(stu *ps)//DelBySno()�ĸ��Ӻ���1������ָ��stu�ṹ��ָ�룬����չʾѧ����ѡ����Ϣ
{
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("ѡ����Ϣ\n");
	ShowNChar(' ',25);
	ShowNChar('-',30);
	printf("\n");
	ShowNChar(' ',25);
	printf("ѧ�ţ�%-8d\t������%-8s\n\n",ps->sno,ps->name);
	ShowNChar(' ',25);
	printf("�γ̺�\t\t�γ���\t\tѧ��\n");
}
void ShowChoCourMess2(cho *pcho)//DelBySno()�ĸ��Ӻ���2
{
	ShowNChar(' ',25);
	printf("%-15d%-16s%d\n",pcho->course,pcho->cname,pcho->term);
}
void DelBySno(void)
{
	system("cls");

	FILE *fpCho,*fpStu,*fpCor;
	if((fpCho=fopen("result.dat","rb+"))==NULL||(fpStu=fopen("student.dat","rb"))==NULL||(fpCor=fopen("course.dat","rb"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	cho tempcho;
	stu tempstu;
//	cla tempcla;

	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("ɾ��ѡ�Σ�\n");

	ShowNChar(' ',25);
	ShowNChar('-',30);
	printf("\n");
	ShowNChar(' ',25);
	fflush(stdin);
	printf("����ѧ�ţ�");

	int sno=0,sflag=0;//��¼�����ѧ�ţ��͸�ѧ���Ƿ����
	while(scanf("%d",&sno)!=1){
		ShowNChar(' ',25);
		printf("����ȷ���룡\n");
		ShowNChar(' ',25);
		fflush(stdin);
	}
	fread(&tempstu,sizeof(stu),1,fpStu);
	while(!feof(fpStu)){
		if(tempstu.sno==sno){//ȷ��ѧ���Ƿ����
			sflag=1;
			break;
		}
		fread(&tempstu,sizeof(stu),1,fpStu);
	}
    if(sflag){//ѧ�����ڣ��л���ҳ��չʾѧ����Ϣ
		ShowChoCourMess1(&tempstu);
		fread(&tempcho,sizeof(cho),1,fpCho);
		while(!feof(fpCho)){
			if(tempcho.sno==sno){//����ѡ��ʲô��
				ShowChoCourMess2(&tempcho);
			}
			fread(&tempcho,sizeof(cho),1,fpCho);
		}
		printf("\n");
		ShowNChar(' ',25);
		ShowNChar('-',30);
		printf("\n");
		ShowNChar(' ',25);
		//չʾ���ֽ�����
		int delcno=0;
		char jud[10];
		fflush(stdin);
		printf("����Ҫɾ���Ŀγ̺ţ�");
		while(scanf("%d",&delcno)!=1||delcno<0){
			printf("����ȷ���룡\n");
			fflush(stdin);
		}
		printf("\n");
		ShowNChar(' ',25);
		fflush(stdin);
		printf("�����޸���(Y-ȷ�� N-����)��");
		s_gets(jud,10);
		//���޸ġ�������������������������������������������������������������������������������������������������������������������
		if(jud[0]=='y'||jud[0]=='Y'){
			FILE *ft;
			if((ft=fopen("temp.dat","wb+"))==NULL)
			{
				ShowNChar(' ',25);
				puts("Cant't open.");
				exit(1);
			}
			rewind(fpCho);
			fread(&tempcho,sizeof(cho),1,fpCho);
			while(!feof(fpCho)){
				if(tempcho.sno!=sno||tempcho.course!=delcno){
				   fwrite(&tempcho,sizeof(cho),1,ft);
				}
				fread(&tempcho,sizeof(cho),1,fpCho);
			}
			if(fclose(ft)!=0)
			{
				putchar('\n');
				ShowNChar(' ',25);
				puts("Can't close!");
				exit(1);
			}
			if(fclose(fpCho)!=0)
			{
				putchar('\n');
				ShowNChar(' ',25);
				printf("�ر��ļ�����\n");
				exit(1);
			}
			if(remove("result.dat")==0)//�������˾Ͱ���鴦��һ��
				printf("Removed result.dat\n");
			else{
				printf("error:%d",errno);
				printf("�Ƴ�ʧ��\n");
			}
			if(rename("temp.dat","result.dat")==0)
				printf("Rename temp.dat to result.dat\n");
			else
				printf("������ʧ��\n");
			/********������д�������Լ���ש*********/
			delayexit();
		}
		//���޸ġ�������������������������������������������������������������������������������������������������������������������
		else{//���ȡ��ɾ��
			if(fclose(fpCho)!=0)
			{
				putchar('\n');
				ShowNChar(' ',25);
				printf("�ر��ļ�����\n");
				exit(1);
			}

		}
    }
    else{//��ѧ��������
		if(fclose(fpCho)!=0)
		{
			putchar('\n');
			ShowNChar(' ',25);
			printf("�ر��ļ�����\n");
			exit(1);
		}
		ShowNChar(' ',25);
		printf("ERROR:��ѧ��������!\n\n");
		ShowNChar(' ',25);
		system("pause");
	}
	if(fclose(fpStu)!=0||fclose(fpCor)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("�ر��ļ�����\n");
		exit(1);
	}
	return;
}
void DelByCno_ShowMess1(cho *pcho,int term)//DelByCno()�ĸ��Ӻ���1������ָ��cho�ṹ��ָ�룬����չʾ�γ�ѧ����Ϣ
{
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("ѡ����Ϣ\n");
	ShowNChar(' ',25);
	ShowNChar('-',30);
	printf("\n");
	ShowNChar(' ',25);
	printf("�γ̺ţ�%-7d�γ�����%-9sѧ�ڣ�%d\n\n",pcho->course,pcho->cname,term);
	ShowNChar(' ',25);
	printf("���\t\tѧ��\t\t����\n");
}
void DelByCno_ShowMess2(cho *pcho,int cnt)//DelByCno()�ĸ��Ӻ���2
{
	ShowNChar(' ',25);
	printf("%-15d%-16d%-16s\n",cnt,pcho->sno,pcho->sname);
}
void DelByCno(void)
{
	system("cls");

	FILE *fpCho,*fpStu,*fpCor;
	if((fpCho=fopen("result.dat","rb+"))==NULL||(fpStu=fopen("student.dat","rb"))==NULL||(fpCor=fopen("course.dat","rb"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	cho tempcho;
//	stu tempstu;
	cla tempcla;

	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("ɾ��ѡ�Σ�\n");

	ShowNChar(' ',25);
	ShowNChar('-',30);
	printf("\n");
	ShowNChar(' ',25);
	fflush(stdin);
	printf("����γ̺ţ�");

	int cno=0,choterm=0,cflag=0;
	while(scanf("%d",&cno)!=1||cno<1){
		ShowNChar(' ',25);
		printf("����ȷ���룡\n");
		ShowNChar(' ',25);
		fflush(stdin);
	}
	ShowNChar(' ',25);
	fflush(stdin);
	printf("����ѡ��ѧ�ڣ�");
	while(scanf("%d",&choterm)!=1||choterm<1){
		ShowNChar(' ',25);
		printf("����ȷ���룡\n");
		ShowNChar(' ',25);
		fflush(stdin);
	}
	fread(&tempcla,sizeof(cla),1,fpCor);
	while(!feof(fpCor)){
		if(tempcla.cno==cno){//ȷ���γ��Ƿ����
			cflag=1;//���ڸÿγ�
			break;
		}
		fread(&tempcla,sizeof(cla),1,fpCor);
	}
	if(fclose(fpCor)!=0){//�ò��Ͼ���ǰ���˰�
		printf("\n");
		ShowNChar(' ',25);
		printf("2019��6��19��20��51��д����~~~~");
		exit(1);
	}
    if(cflag){//�γ̴���
		DelByCno_ShowMess1(&tempcho,choterm);
		int cnt=0;
		fread(&tempcho,sizeof(cho),1,fpCho);
		while(!feof(fpCho)){
			if(tempcho.course==cno&&tempcho.term==choterm){//���Ҹÿθ�ѧ����˭ѡ
				cnt++;
				DelByCno_ShowMess2(&tempcho,cnt);
			}
			fread(&tempcho,sizeof(cho),1,fpCho);
		}
		printf("\n");
		ShowNChar(' ',25);
		ShowNChar('-',30);
		printf("\n");
		ShowNChar(' ',25);
		//չʾ���ֽ���
		if(cnt==0){//��ѧ��ѡ��
			if(fclose(fpCho)!=0)
			{
				putchar('\n');
				ShowNChar(' ',25);
				printf("�ر��ļ�����\n");
				exit(1);
			}
			printf("\n");
			ShowNChar(' ',25);
			printf("û��ѧ��ѡ�Σ�\n\n");
			ShowNChar(' ',25);
			system("pause");
		}
		else{//��ѧ��ѡ��
			char jud[10];
			printf("\n");
			ShowNChar(' ',25);
			fflush(stdin);
			printf("ȷ��ɾ����(Y-ȷ�� N-����)��");
			s_gets(jud,10);
			if(jud[0]=='y'||jud[0]=='Y'){
				FILE *ft;
				if((ft=fopen("temp.dat","wb+"))==NULL)
				{
					ShowNChar(' ',25);
					puts("Cant't open.");
					exit(1);
				}
				rewind(fpCho);
				fread(&tempcho,sizeof(cho),1,fpCho);
				while(!feof(fpCho)){
					if(tempcho.course!=cno||tempcho.term!=choterm){
					   fwrite(&tempcho,sizeof(cho),1,ft);
					}
					fread(&tempcho,sizeof(cho),1,fpCho);
				}
				if(fclose(ft)!=0)
				{
					putchar('\n');
					ShowNChar(' ',25);
					puts("Can't close!");
					exit(1);
				}
				if(fclose(fpCho)!=0)
				{
					putchar('\n');
					ShowNChar(' ',25);
					printf("�ر��ļ�����\n");
					exit(1);
				}
				if(remove("result.dat")==0)//�������˾Ͱ���鴦��һ��
					printf("Removed result.dat\n");
				else{
					printf("error:%d",errno);
					printf("�Ƴ�ʧ��\n");
				}
				if(rename("temp.dat","result.dat")==0)
					printf("Rename temp.dat to result.dat\n");
				else
					printf("������ʧ��\n");
				/********������д�������Լ���ש*********/
				delayexit();
			}
			//���޸ġ�������������������������������������������������������������������������������������������������������������������
			else{//���ȡ��ɾ��
				if(fclose(fpCho)!=0)
				{
					putchar('\n');
					ShowNChar(' ',25);
					printf("�ر��ļ�����\n");
					exit(1);
				}

			}
		}
    }//�γ̴���
    else{//�γ̲�����
		if(fclose(fpCho)!=0)
		{
			putchar('\n');
			ShowNChar(' ',25);
			printf("�ر��ļ�����\n");
			exit(1);
		}
		ShowNChar(' ',25);
		printf("ERROR:�ÿγ̲�����!\n\n");
		ShowNChar(' ',25);
		system("pause");
    }
	if(fclose(fpStu)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("�ر��ļ�����\n");
		exit(1);
	}
    return;
}
void ShowBySno(void)
{
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("ѡ����Ϣ��ѯ��\n");

	ShowNChar(' ',25);
	ShowNChar('-',30);
	printf("\n");
	ShowNChar(' ',25);
	fflush(stdin);
	printf("����ѧ�ţ�");

	FILE *fpCho,*fpStu;
	if((fpCho=fopen("result.dat","rb"))==NULL||(fpStu=fopen("student.dat","rb"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	cho tempcho;
	stu tempstu;

	int sno=0,sflag=0;//��¼�����ѧ�ţ��͸�ѧ���Ƿ����
	while(scanf("%d",&sno)!=1){
		ShowNChar(' ',25);
		printf("����ȷ���룡\n");
		ShowNChar(' ',25);
		fflush(stdin);
	}
	fread(&tempstu,sizeof(stu),1,fpStu);
	while(!feof(fpStu)){
		if(tempstu.sno==sno){//ȷ��ѧ���Ƿ����
			sflag=1;
			break;
		}
		fread(&tempstu,sizeof(stu),1,fpStu);
	}
	if(sflag){
		ShowChoCourMess1(&tempstu);
		fread(&tempcho,sizeof(cho),1,fpCho);
		while(!feof(fpCho)){
			if(tempcho.sno==sno){
				ShowChoCourMess2(&tempcho);
			}
			fread(&tempcho,sizeof(cho),1,fpCho);
		}
	}
	else{
		ShowNChar(' ',25);
		printf("ERROR:��ѧ��������!\n\n");
		ShowNChar(' ',25);
	}
	if(fclose(fpStu)!=0||fclose(fpCho)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("�ر��ļ�����\n");
		exit(1);
	}
	printf("\n");
	ShowNChar(' ',25);
	system("pause");
	return;
}
void ShowByCno_ShowMess1(cho *pcho)//ShowByCno()�ĸ��Ӻ���1������ָ��cho�ṹ��ָ�룬����չʾ�γ���Ϣ
{
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("�γ���Ϣ��\n");
	ShowNChar(' ',25);
	ShowNChar('-',30);
	printf("\n");
	ShowNChar(' ',25);
	printf("�γ̺ţ�%-7d�γ�����%-9s\n\n",pcho->course,pcho->cname);
	ShowNChar(' ',25);
	printf("ѧ��\t\t����\t\tѧ��\n");
}
void ShowByCno_ShowMess2(cho *pcho)//ShowByCno()�ĸ��Ӻ���2
{
	ShowNChar(' ',25);
	printf("%-15d%-16s%-16d\n",pcho->sno,pcho->sname,pcho->term);
}
void ShowByCno(void)
{
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("ѡ����Ϣ��ѯ��\n");

	ShowNChar(' ',25);
	ShowNChar('-',30);
	printf("\n");
	ShowNChar(' ',25);
	fflush(stdin);
	printf("����γ̺ţ�");

	FILE *fpCho,*fpCor;
	if((fpCho=fopen("result.dat","rb"))==NULL||(fpCor=fopen("course.dat","rb"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	cho tempcho;
	cla tempcla;

	int cno=0,cflag=0;//��¼
	while(scanf("%d",&cno)!=1||cno<0){
		ShowNChar(' ',25);
		printf("����ȷ���룡\n");
		ShowNChar(' ',25);
		fflush(stdin);
	}
	fread(&tempcla,sizeof(cla),1,fpCor);
	while(!feof(fpCor)){
		if(tempcla.cno==cno){//ȷ���γ��Ƿ����
			cflag=1;
			break;
		}
		fread(&tempcla,sizeof(cla),1,fpCor);
	}
	if(cflag){
		ShowByCno_ShowMess1(&tempcho);
		fread(&tempcho,sizeof(cho),1,fpCho);
		while(!feof(fpCho)){
			if(tempcho.course==cno){
				ShowByCno_ShowMess2(&tempcho);

			}
			fread(&tempcho,sizeof(cho),1,fpCho);
		}
	}
	else{
		ShowNChar(' ',25);
		printf("ERROR:�ÿγ̲�����!\n\n");
		ShowNChar(' ',25);
	}
	if(fclose(fpCor)!=0||fclose(fpCho)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("�ر��ļ�����\n");
		exit(1);
	}
	printf("\n");
	ShowNChar(' ',25);
	system("pause");
	return;
}
void ShowAll(void)
{
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("ȫ��ѡ����Ϣ");
	ShowNChar(' ',25);
	printf("Page:1\n");

	ShowNChar(' ',25);
	ShowNChar('-',55);
	printf("\n\n");
	ShowNChar(' ',25);
	printf("���  ѧ��  ����        �κ�  ����        ѧ��  �ɼ�\n");

	FILE *fpCho;
	if((fpCho=fopen("result.dat","rb"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	cho tempcho;
	fflush(stdin);
	int cnt=1;
	fread(&tempcho,sizeof(cho),1,fpCho);
	while(!feof(fpCho)){
		ShowNChar(' ',25);
		printf("%-6d%-6d%-12s%-6d%-12s%-6d%-6d\n",cnt++,tempcho.sno,tempcho.sname,tempcho.course,tempcho.cname,tempcho.term,tempcho.grade);
		fread(&tempcho,sizeof(cho),1,fpCho);
	}
	if(fclose(fpCho)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("�ر��ļ�����\n");
		exit(1);
	}
	printf("\n");
	ShowNChar(' ',25);
	system("pause");
	return;
}

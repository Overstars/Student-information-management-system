
#include "MessInquire.h"


void ShowInqMenu(void)
{
	system("cls");
	int spaces;//��¼�����ո������
	putchar('\n');
	spaces=(WIDTH-strlen("��Ϣ��ѯ"))/2;
	ShowNChar(' ',spaces);
	printf("%s\n","��Ϣ��ѯ");

	putchar('\n');
	spaces=(WIDTH-strlen(DIVIDE))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",DIVIDE);

	int i=0;
	for(i=0;i<16;i++){
		putchar('\n');
		spaces=(WIDTH-strlen(InqInfor[i]))/2;
		ShowNChar(' ',spaces);
		printf("%s",InqInfor[i]);
	}
	putchar('\n');
	spaces=(WIDTH-strlen(DIVIDE))/2;
	ShowNChar(' ',spaces);
	printf("%s\n\n",DIVIDE);
	ShowNChar(' ',10);
	printf("Enter your choice<11-43> :");

}
int InqGetOrder(void)
{
	int temp=-1;
	while(scanf("%d",&temp)!=1||(temp!=0&&temp<11)||(temp>13&&temp<21)||(temp>22&&temp<31)||(temp>33&&temp<41)||temp>43){//���벻�Ϸ�
		ShowNChar(' ',10);
		printf("Wrong choice!");
		fflush(stdin);
		ShowNChar(' ',10);
		system("pause");
		system("cls");
		ShowInqMenu();
	}
	return temp;
}
void ShowStuMess2(stu *p)//չʾѧ����Ϣ���Ӻ���
{
	printf("\n");
	ShowNChar(' ',25);
	printf("ѧ��:%d\n",p->sno);
	ShowNChar(' ',25);
	printf("����:%s\n",p->name);
	ShowNChar(' ',25);
	printf("�Ա�:%c\n",p->sex);
	ShowNChar(' ',25);
	printf("��ַ:%s\n\n",p->address);
}
void InqSBySno(void)//��ѧ�Ų�ѯѧ����Ϣ
{
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("ѧ����Ϣ��ѯ\n");
	ShowNChar(' ',25);
	ShowNChar('-',50);
	printf("\n");
	ShowNChar(' ',25);
	int sno=0,flag=0;
	printf("����Ҫ���ҵ�ѧ��ѧ�ţ�");
	while(scanf("%d",&sno)!=1||sno<0){
		fflush(stdin);
		putchar('\n');
		ShowNChar(' ',25);
		printf("����ȷ����!");
	}
	FILE *fp;
	stu temp;
	if((fp=fopen("student.dat","rb"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	fread(&temp,sizeof(stu),1,fp);
	while(!feof(fp)){
		if(temp.sno==sno){
			flag=1;
			printf("\n");
			ShowNChar(' ',25);
			printf("ѧ����Ϣ:");
			ShowStuMess2(&temp);
			break;
		}
		fread(&temp,sizeof(stu),1,fp);
	}
	if(!flag){
		ShowNChar(' ',25);
		printf("ERROR:��ѧ��������\n");
	}
	if(fclose(fp)!=0)
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
void InqSBySname(void)
{
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("ѧ����Ϣ��ѯ\n");
	ShowNChar(' ',25);
	ShowNChar('-',50);
	printf("\n");
	ShowNChar(' ',25);
	int cnt=0;
	printf("����Ҫ���ҵ�ѧ��������");
	fflush(stdin);
	char name[30];
	s_gets(name,30);

	FILE *fp;
	stu temp;
	if((fp=fopen("student.dat","rb"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	printf("\n");
	ShowNChar(' ',25);
	printf("ѧ����Ϣ:");
	fread(&temp,sizeof(stu),1,fp);
	while(!feof(fp)){
		if(strncmp(temp.name,name,30)==0){
			cnt++;
			ShowStuMess2(&temp);
			putchar('\n');
		}
		fread(&temp,sizeof(stu),1,fp);
	}
	ShowNChar(' ',25);
	printf("һ����%d��ѧ��\n",cnt);
	if(fclose(fp)!=0)
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
void InqSByAddress(void)
{
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("ѧ����Ϣ��ѯ\n");
	ShowNChar(' ',25);
	ShowNChar('-',50);
	printf("\n");
	ShowNChar(' ',25);
	int cnt=0;
	printf("����Ҫ���ҵ�ѧ����ַ��");
	fflush(stdin);
	char address[30];
	s_gets(address,30);

	FILE *fp;
	stu temp;
	if((fp=fopen("student.dat","rb"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	printf("\n");
	ShowNChar(' ',25);
	printf("ѧ����Ϣ:");
	fread(&temp,sizeof(stu),1,fp);
	while(!feof(fp)){
		if(strncmp(temp.address,address,30)==0){
			cnt++;
			ShowStuMess2(&temp);
			putchar('\n');
		}
		fread(&temp,sizeof(stu),1,fp);
	}
	ShowNChar(' ',25);
	printf("һ����%d��ѧ��\n",cnt);
	if(fclose(fp)!=0)
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
void ShowClaMess2(cla *p)//չʾ�γ���Ϣ���Ӻ���
{
	ShowNChar(' ',25);
	printf("�γ̺ţ�%-8d\n",p->cno);
	ShowNChar(' ',25);
	printf("�γ�����%-12s\n",p->name);
	ShowNChar(' ',25);
	printf("ѧ�֣�%-8d\n",p->score);
	ShowNChar(' ',25);
	printf("ѧʱ��%-8d\n",p->hour);
}
void InqCByCno(void)
{
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("�γ���Ϣ��ѯ\n");
	ShowNChar(' ',25);
	ShowNChar('-',50);
	printf("\n");
	ShowNChar(' ',25);
	int cno=0,flag=0;
	printf("����Ҫ���ҵĿγ̺ţ�");
	while(scanf("%d",&cno)!=1||cno<0){
		fflush(stdin);
		putchar('\n');
		ShowNChar(' ',25);
		printf("����ȷ����!");
	}
	FILE *fp;
	cla temp;
	if((fp=fopen("course.dat","rb"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	fread(&temp,sizeof(cla),1,fp);
	while(!feof(fp)){
		if(temp.cno==cno){
			flag=1;
			printf("\n");
			ShowNChar(' ',25);
			printf("�γ���Ϣ:\n");
			ShowClaMess2(&temp);
			break;
		}
		fread(&temp,sizeof(cla),1,fp);
	}
	if(!flag){
		ShowNChar(' ',25);
		printf("ERROR:�ÿγ̲�����\n");
	}
	if(fclose(fp)!=0)
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
void InqCByCname(void)
{
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("�γ���Ϣ��ѯ\n");
	ShowNChar(' ',25);
	ShowNChar('-',50);
	printf("\n");
	ShowNChar(' ',25);
	int cnt=0;
	printf("����Ҫ���ҵĿγ�����");
	fflush(stdin);
	char name[30];
	s_gets(name,30);

	FILE *fp;
	cla temp;
	if((fp=fopen("course.dat","rb"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	printf("\n");
	ShowNChar(' ',25);
	printf("�γ̺�\t�γ���       ѧ��    ѧʱ\n");
	ShowNChar(' ',25);
	ShowNChar('-',50);
	printf("\n");
	fread(&temp,sizeof(cla),1,fp);
	while(!feof(fp)){
		if(strncmp(temp.name,name,30)==0){
			cnt++;
			ShowNChar(' ',25);
			printf("%-8d%-12s%-8d%-8d\n",temp.cno,temp.name,temp.score,temp.hour);
		}
		fread(&temp,sizeof(cla),1,fp);
	}
	ShowNChar(' ',25);
	printf("һ����%d�ſ�",cnt);
	if(fclose(fp)!=0)
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
//void InqChoBySno(void);//�൱��ShowBySno
//void InqChoByCno(void);//�൱��ShowByCno
//void ShowAllCho(void);//�൱��ShowAll();
void ScoreBoard(cho *p)
{
	ShowNChar(' ',25);
	printf("%-9d%-10d%-12s%-8d\n",p->term,p->course,p->cname,p->grade);
}
void InqGraBySno(void)
{
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("�ɼ���Ϣ��ѯ\n\n");
	ShowNChar(' ',25);
	ShowNChar('-',50);
	printf("\n");
	ShowNChar(' ',25);
	printf("����Ҫ���ҵ�ѧ��ѧ�ţ�");
	int sno=0,flag=0;
	while(scanf("%d",&sno)!=1||sno<0){
		fflush(stdin);
		putchar('\n');
		ShowNChar(' ',25);
		printf("����ȷ����!");
	}
	FILE *fp;
	stu temp;
	if((fp=fopen("student.dat","rb"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	fread(&temp,sizeof(stu),1,fp);
	while(!feof(fp)){
		if(temp.sno==sno){
			flag=1;
			break;
		}
		fread(&temp,sizeof(stu),1,fp);
	}
	if(fclose(fp)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("�ر��ļ�����\n");
		exit(1);
	}
	if(!flag){
		ShowNChar(' ',25);
		printf("ERROR:��ѧ��������\n\n");
		ShowNChar(' ',25);
		system("pause");
		return;
	}
	else{
		FILE *fpCho;
		if((fpCho=fopen("result.dat","rb"))==NULL){
			puts("Cant't open.");
			exit(1);
		}
		cho tempcho;
		system("cls");
		printf("\n\n\n");
		ShowNChar(' ',25);
		printf("�ɼ���\n\n");
		ShowNChar(' ',25);
		printf("ѧ��%-8d����%-12s\n",temp.sno,temp.name);
		ShowNChar(' ',25);
		ShowNChar('-',50);
		printf("\n");
		int cnt=0;
		double sum=0;
		ShowNChar(' ',25);
		printf("ѧ��     �γ̺�    �γ���      �ɼ�\n");
		fread(&tempcho,sizeof(cho),1,fpCho);
		while(!feof(fpCho)){
			if(tempcho.sno==sno){
				cnt++;
				sum+=tempcho.grade;
				ScoreBoard(&tempcho);
			}
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
		printf("һ����%d�ſ�\n",cnt);
		ShowNChar(' ',25);
		printf("ƽ���ɼ���%.2lf\n",sum/cnt);
	}
	putchar('\n');
	ShowNChar(' ',25);
	system("pause");
	return;
}
void InqGraByCno(void)//2019��6��20��15��06��
{
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("�ɼ���Ϣ��ѯ��\n");

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

	int cno=0,cflag=0,term=0;//��¼
	while(scanf("%d",&cno)!=1||cno<0){
		ShowNChar(' ',25);
		printf("����ȷ���룡\n");
		ShowNChar(' ',25);
		fflush(stdin);
	}
	ShowNChar(' ',25);
	fflush(stdin);
	printf("����ѡ��ѧ�ڣ�");
	while(scanf("%d",&term)!=1||term<0){
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
		system("cls");
		printf("\n\n\n");
		ShowNChar(' ',25);
		printf("�ɼ���\n\n");
		ShowNChar(' ',25);
		printf("�γ̺�%-8d�γ���%-12sѧ��%d\n",tempcla.cno,tempcla.name,term);
		ShowNChar(' ',25);
		ShowNChar('-',50);
		printf("\n");
		int cnt=0;
		double sum=0;
		ShowNChar(' ',25);
		printf("���     ѧ��      ����        �ɼ�\n");

		fread(&tempcho,sizeof(cho),1,fpCho);
		while(!feof(fpCho)){
			if(tempcho.course==cno&&tempcho.term==term){
				cnt++;
				sum+=tempcho.grade;
				ShowNChar(' ',25);
				printf("%-9d%-10d%-12s%-8d\n",cnt,tempcho.sno,tempcho.sname,tempcho.grade);
			}
			fread(&tempcho,sizeof(cho),1,fpCho);
		}
		printf("\n");
		ShowNChar(' ',25);
		printf("һ����%d��ѧ��\n",cnt);
		ShowNChar(' ',25);
		printf("ƽ���ɼ���%.2lf\n",sum/cnt);
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
void InqGraByList(void)
{
    SSB arr[200];
    int cnt=0,i;//��¼����ѧ��
    FILE *fp,*fpCho;
    if((fp=fopen("student.dat","rb+"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	stu temp;
	cho tempcho;
	fread(&temp,sizeof(stu),1,fp);
	while(!feof(fp)){
		arr[cnt++].st=temp;
		arr[cnt-1].cnt=0;
		arr[cnt-1].sum=0;//δ¼��ɼ�,��ʼ��Ϊ0
		fread(&temp,sizeof(stu),1,fp);
	}
	if((fpCho=fopen("result.dat","rb"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	fread(&tempcho,sizeof(cho),1,fpCho);
	while(!feof(fpCho)){
		for(i=0;i<cnt;i++){
			if(arr[i].st.sno==tempcho.sno){
				arr[i].cnt++;
				arr[i].sum+=tempcho.grade;
				break;
			}
		}
		fread(&tempcho,sizeof(cho),1,fpCho);
	}
	if(fclose(fp)!=0||fclose(fpCho)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("�ر��ļ�����\n");
		exit(1);
	}
	qsort(arr,cnt,sizeof(SSB),cmpSSB);
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("����     ѧ��      ����        ƽ���ɼ�\n");
	ShowNChar(' ',25);
	ShowNChar('-',50);
	printf("\n\n");
	for(i=0;i<cnt;i++){
		ShowNChar(' ',25);
		printf("%-9d%-10d%-12s%.2lf\n",i+1,arr[i].st.sno,arr[i].st.name,(arr[i].cnt==0)?-1:arr[i].sum/arr[i].cnt);//������Ϊ0
	}
	printf("\n");
	ShowNChar(' ',25);
	printf("һ����%d��ѧ��\n",cnt);
	printf("\n");
	ShowNChar(' ',25);
	system("pause");
}
int cmpSSB(const void *a,const void *b)//SortStu()���Ӻ���,�Ӵ�С
{
	SSB c=*(SSB*)a;
	SSB d=*(SSB*)b;//�ָ�����
	if(c.cnt ==0&& d.cnt >0)
		return 1;
	if(c.cnt > 0&& d.cnt == 0)
		return -1;

	if(c.sum/c.cnt > d.sum/d.cnt)
		return -1;
	else
		return 1;
//    return ((*(stu*)b).sno) - ((*(stu*)a).sno);
}

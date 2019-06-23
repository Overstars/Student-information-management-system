
#include "GradeMessMan.h"
void ShowGradeMenu(void)
{
	system("cls");
	int spaces;//��¼�����ո������
	putchar('\n');
	spaces=(WIDTHCLA-strlen(TOPICGRA))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",TOPICGRA);

	putchar('\n');
	spaces=(WIDTHCLA-strlen(DIVIDE))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",DIVIDE);

	putchar('\n');
	spaces=(WIDTHCLA-strlen(GRA1))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",GRA1);

	putchar('\n');
	spaces=(WIDTHCLA-strlen(GRA2))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",GRA2);

	putchar('\n');
	spaces=(WIDTHCLA-strlen(GRA0))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",GRA0);
	spaces=(WIDTHCLA-strlen(DIVIDE))/2;
	ShowNChar(' ',spaces);
	printf("%s\n",DIVIDE);
	putchar('\n');
	ShowNChar(' ',10);
	printf("Enter your choice<0-2> :");
	fflush(stdin);
	return;
}
int GradeGetOrder(void)
{
	int temp=-1;
	while(scanf("%d",&temp)!=1||(temp<0||temp>2)){//���벻�Ϸ�
		ShowNChar(' ',10);
		printf("Wrong choice!");
		fflush(stdin);
		system("cls");
		ShowGradeMenu();
	}
	return temp;
}
void EnterGrade_Show1(cho *pc,int term)
{
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("�γ̺ţ�%-6d�γ���%-12sѧ�ڣ�%d\n",pc->course,pc->cname,term);
	ShowNChar(' ',25);
	ShowNChar('-',50);
	printf("\n\n");
	ShowNChar(' ',25);
	printf("���      ѧ��      ����      �ɼ�\n");
}
void EnterGrade_Show2(cho *pc,int num)
{
	ShowNChar(' ',25);
	printf("%-10d%-10d%-10s",num,pc->sno,pc->sname);
	while(scanf("%d",&pc->grade)!=1){
		fflush(stdin);
		ShowNChar(' ',25);
		printf("����ȷ����!");
	}
}
void EnterGrade(void)
{
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	int cno=0,term=0;
	puts("����Ҫ¼��ɼ��Ŀγ̺ź�ѧ��");
	ShowNChar(' ',25);
	printf("�γ̺ţ�");
	while(scanf("%d",&cno)!=1){
		fflush(stdin);
		ShowNChar(' ',25);
		printf("����ȷ����!");
	}
	fflush(stdin);
	ShowNChar(' ',25);
	printf("ѧ�ڣ�");
	while(scanf("%d",&term)!=1){
		fflush(stdin);
		ShowNChar(' ',25);
		printf("����ȷ����!");
	}
	fflush(stdin);//����γ̺ź�ѧ�����
	FILE *fp;
	int cnt=0,flag=0;
	cho temp;
	if((fp=fopen("result.dat","rb+"))==NULL){
		puts("Cant't open result.dat.");
		exit(1);
	}
	fread(&temp,sizeof(cho),1,fp);
	while(!feof(fp))
	{
		if(temp.course==cno){
			flag=1;
			break;
		}
		fread(&temp,sizeof(cho),1,fp);
	}
	if(flag){
		rewind(fp);
		EnterGrade_Show1(&temp,term);
		fread(&temp,sizeof(cho),1,fp);
		while(!feof(fp))
		{
			if(temp.course==cno&&temp.term==term){
				cnt++;
				EnterGrade_Show2(&temp,cnt);
				fseek(fp,-sizeof(cho),SEEK_CUR);
				fwrite(&temp,sizeof(cho),1,fp);
			}
			fseek(fp,0,SEEK_CUR);
			fread(&temp,sizeof(cho),1,fp);
		}
		printf("\n");
		ShowNChar(' ',25);
		printf("ѡ��������%d\n",cnt);
	}
	else{
		ShowNChar(' ',25);
		printf("�ÿγ̲�����ѡ����Ϣ\n");
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
void FixGrade(void)
{
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	int sno=0,cno=0,term=0;
	puts("����Ҫ�޸ĵ�ѧ�š��γ̺ź�ѧ��");
	ShowNChar(' ',25);
	fflush(stdin);
	printf("ѧ�ţ�");
	while(scanf("%d",&sno)!=1){
		fflush(stdin);
		ShowNChar(' ',25);
		printf("����ȷ����!");
	}
	ShowNChar(' ',25);
	fflush(stdin);
	printf("�γ̺ţ�");
	while(scanf("%d",&cno)!=1){
		fflush(stdin);
		ShowNChar(' ',25);
		printf("����ȷ����!");
	}
	ShowNChar(' ',25);
	fflush(stdin);
	printf("ѧ�ڣ�");
	while(scanf("%d",&term)!=1){
		fflush(stdin);
		ShowNChar(' ',25);
		printf("����ȷ����!");
	}
	int flag=0;
	FILE *fp;
	cho temp;
	if((fp=fopen("course.dat","rb+"))==NULL){
		puts("Cant't open course.dat.");
		exit(1);
	}
	fread(&temp,sizeof(cho),1,fp);
	while(!feof(fp))
	{
		if(temp.course==cno&&temp.sno==sno&&temp.term==term){
			flag=1;
			break;
		}
		fread(&temp,sizeof(cho),1,fp);
	}
	if(flag){
		printf("\n\n\n");
		ShowNChar(' ',25);
		printf("ԭ�ɼ���Ϣ��");
		ShowNChar(' ',25);
		ShowNChar('-',50);
		printf("\n");
		ShowNChar(' ',25);
		printf("ѧ�ţ�%d\n",temp.sno);
		ShowNChar(' ',25);
		printf("������%s\n",temp.sname);
		ShowNChar(' ',25);
		printf("�κţ�%d\n",temp.course);
		ShowNChar(' ',25);
		printf("������%s\n",temp.cname);
		ShowNChar(' ',25);
		printf("ѧ�ڣ�%d\n",temp.term);
		ShowNChar(' ',25);
		printf("�ɼ���%d\n",temp.grade);
		ShowNChar('-',50);
		printf("\n\n");
		fflush(stdin);
		printf("�����³ɼ���");
		while(scanf("%d",&temp.grade)!=1){
			fflush(stdin);
			ShowNChar(' ',25);
			printf("����ȷ����!");
		}
		char jud[10];
		ShowNChar(' ',25);
		fflush(stdin);
		printf("\n�����޸���(Y-ȷ�� N-����)��");
		s_gets(jud,10);
		if(jud[0]=='y'||jud[0]=='Y'){
			fseek(fp,-sizeof(cho),SEEK_CUR);
			fwrite(&temp,1,sizeof(cho),fp);
			printf("\n");
			ShowNChar(' ',25);
			delayexit();
		}
		else{//ȡ��
			;
		}
	}
	else{
		ShowNChar(' ',25);
		printf("ERROR:����Ϣ�����ڣ�\n");
		printf("\n");
		ShowNChar(' ',25);
		system("pause");
	}
	if(fclose(fp)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("�ر��ļ�����\n");
		exit(1);
	}
	return;
}

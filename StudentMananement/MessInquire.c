
#include "MessInquire.h"


void ShowInqMenu(void)
{
	system("cls");
	int spaces;//记录跳过空格的数量
	putchar('\n');
	spaces=(WIDTH-strlen("信息查询"))/2;
	ShowNChar(' ',spaces);
	printf("%s\n","信息查询");

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
	while(scanf("%d",&temp)!=1||(temp!=0&&temp<11)||(temp>13&&temp<21)||(temp>22&&temp<31)||(temp>33&&temp<41)||temp>43){//输入不合法
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
void ShowStuMess2(stu *p)//展示学生信息附加函数
{
	printf("\n");
	ShowNChar(' ',25);
	printf("学号:%d\n",p->sno);
	ShowNChar(' ',25);
	printf("姓名:%s\n",p->name);
	ShowNChar(' ',25);
	printf("性别:%c\n",p->sex);
	ShowNChar(' ',25);
	printf("地址:%s\n\n",p->address);
}
void InqSBySno(void)//按学号查询学生信息
{
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("学生信息查询\n");
	ShowNChar(' ',25);
	ShowNChar('-',50);
	printf("\n");
	ShowNChar(' ',25);
	int sno=0,flag=0;
	printf("输入要查找的学生学号：");
	while(scanf("%d",&sno)!=1||sno<0){
		fflush(stdin);
		putchar('\n');
		ShowNChar(' ',25);
		printf("请正确输入!");
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
			printf("学生信息:");
			ShowStuMess2(&temp);
			break;
		}
		fread(&temp,sizeof(stu),1,fp);
	}
	if(!flag){
		ShowNChar(' ',25);
		printf("ERROR:该学生不存在\n");
	}
	if(fclose(fp)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("关闭文件错误\n");
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
	printf("学生信息查询\n");
	ShowNChar(' ',25);
	ShowNChar('-',50);
	printf("\n");
	ShowNChar(' ',25);
	int cnt=0;
	printf("输入要查找的学生姓名：");
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
	printf("学生信息:");
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
	printf("一共有%d个学生\n",cnt);
	if(fclose(fp)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("关闭文件错误\n");
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
	printf("学生信息查询\n");
	ShowNChar(' ',25);
	ShowNChar('-',50);
	printf("\n");
	ShowNChar(' ',25);
	int cnt=0;
	printf("输入要查找的学生地址：");
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
	printf("学生信息:");
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
	printf("一共有%d个学生\n",cnt);
	if(fclose(fp)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("关闭文件错误\n");
		exit(1);
	}
	printf("\n");
	ShowNChar(' ',25);
	system("pause");
	return;
}
void ShowClaMess2(cla *p)//展示课程信息附加函数
{
	ShowNChar(' ',25);
	printf("课程号：%-8d\n",p->cno);
	ShowNChar(' ',25);
	printf("课程名：%-12s\n",p->name);
	ShowNChar(' ',25);
	printf("学分：%-8d\n",p->score);
	ShowNChar(' ',25);
	printf("学时：%-8d\n",p->hour);
}
void InqCByCno(void)
{
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("课程信息查询\n");
	ShowNChar(' ',25);
	ShowNChar('-',50);
	printf("\n");
	ShowNChar(' ',25);
	int cno=0,flag=0;
	printf("输入要查找的课程号：");
	while(scanf("%d",&cno)!=1||cno<0){
		fflush(stdin);
		putchar('\n');
		ShowNChar(' ',25);
		printf("请正确输入!");
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
			printf("课程信息:\n");
			ShowClaMess2(&temp);
			break;
		}
		fread(&temp,sizeof(cla),1,fp);
	}
	if(!flag){
		ShowNChar(' ',25);
		printf("ERROR:该课程不存在\n");
	}
	if(fclose(fp)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("关闭文件错误\n");
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
	printf("课程信息查询\n");
	ShowNChar(' ',25);
	ShowNChar('-',50);
	printf("\n");
	ShowNChar(' ',25);
	int cnt=0;
	printf("输入要查找的课程名：");
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
	printf("课程号\t课程名       学分    学时\n");
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
	printf("一共有%d门课",cnt);
	if(fclose(fp)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("关闭文件错误\n");
		exit(1);
	}
	printf("\n");
	ShowNChar(' ',25);
	system("pause");
	return;
}
//void InqChoBySno(void);//相当于ShowBySno
//void InqChoByCno(void);//相当于ShowByCno
//void ShowAllCho(void);//相当于ShowAll();
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
	printf("成绩信息查询\n\n");
	ShowNChar(' ',25);
	ShowNChar('-',50);
	printf("\n");
	ShowNChar(' ',25);
	printf("输入要查找的学生学号；");
	int sno=0,flag=0;
	while(scanf("%d",&sno)!=1||sno<0){
		fflush(stdin);
		putchar('\n');
		ShowNChar(' ',25);
		printf("请正确输入!");
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
		printf("关闭文件错误\n");
		exit(1);
	}
	if(!flag){
		ShowNChar(' ',25);
		printf("ERROR:该学生不存在\n\n");
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
		printf("成绩单\n\n");
		ShowNChar(' ',25);
		printf("学号%-8d姓名%-12s\n",temp.sno,temp.name);
		ShowNChar(' ',25);
		ShowNChar('-',50);
		printf("\n");
		int cnt=0;
		double sum=0;
		ShowNChar(' ',25);
		printf("学期     课程号    课程名      成绩\n");
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
			printf("关闭文件错误\n");
			exit(1);
		}
		printf("\n");
		ShowNChar(' ',25);
		printf("一共有%d门课\n",cnt);
		ShowNChar(' ',25);
		printf("平均成绩：%.2lf\n",sum/cnt);
	}
	putchar('\n');
	ShowNChar(' ',25);
	system("pause");
	return;
}
void InqGraByCno(void)//2019年6月20日15点06分
{
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("成绩信息查询：\n");

	ShowNChar(' ',25);
	ShowNChar('-',30);
	printf("\n");
	ShowNChar(' ',25);
	fflush(stdin);
	printf("输入课程号：");


	FILE *fpCho,*fpCor;
	if((fpCho=fopen("result.dat","rb"))==NULL||(fpCor=fopen("course.dat","rb"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	cho tempcho;
	cla tempcla;

	int cno=0,cflag=0,term=0;//记录
	while(scanf("%d",&cno)!=1||cno<0){
		ShowNChar(' ',25);
		printf("请正确输入！\n");
		ShowNChar(' ',25);
		fflush(stdin);
	}
	ShowNChar(' ',25);
	fflush(stdin);
	printf("输入选课学期：");
	while(scanf("%d",&term)!=1||term<0){
		ShowNChar(' ',25);
		printf("请正确输入！\n");
		ShowNChar(' ',25);
		fflush(stdin);
	}
	fread(&tempcla,sizeof(cla),1,fpCor);
	while(!feof(fpCor)){
		if(tempcla.cno==cno){//确定课程是否存在
			cflag=1;
			break;
		}
		fread(&tempcla,sizeof(cla),1,fpCor);
	}
	if(cflag){
		system("cls");
		printf("\n\n\n");
		ShowNChar(' ',25);
		printf("成绩单\n\n");
		ShowNChar(' ',25);
		printf("课程号%-8d课程名%-12s学期%d\n",tempcla.cno,tempcla.name,term);
		ShowNChar(' ',25);
		ShowNChar('-',50);
		printf("\n");
		int cnt=0;
		double sum=0;
		ShowNChar(' ',25);
		printf("序号     学号      姓名        成绩\n");

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
		printf("一共有%d名学生\n",cnt);
		ShowNChar(' ',25);
		printf("平均成绩：%.2lf\n",sum/cnt);
	}
	else{
		ShowNChar(' ',25);
		printf("ERROR:该课程不存在!\n\n");
		ShowNChar(' ',25);
	}
	if(fclose(fpCor)!=0||fclose(fpCho)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("关闭文件错误\n");
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
    int cnt=0,i;//记录多少学生
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
		arr[cnt-1].sum=0;//未录入成绩,初始化为0
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
		printf("关闭文件错误\n");
		exit(1);
	}
	qsort(arr,cnt,sizeof(SSB),cmpSSB);
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("名次     学号      姓名        平均成绩\n");
	ShowNChar(' ',25);
	ShowNChar('-',50);
	printf("\n\n");
	for(i=0;i<cnt;i++){
		ShowNChar(' ',25);
		printf("%-9d%-10d%-12s%.2lf\n",i+1,arr[i].st.sno,arr[i].st.name,(arr[i].cnt==0)?-1:arr[i].sum/arr[i].cnt);//除数不为0
	}
	printf("\n");
	ShowNChar(' ',25);
	printf("一共有%d名学生\n",cnt);
	printf("\n");
	ShowNChar(' ',25);
	system("pause");
}
int cmpSSB(const void *a,const void *b)//SortStu()附加函数,从大到小
{
	SSB c=*(SSB*)a;
	SSB d=*(SSB*)b;//分高在上
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

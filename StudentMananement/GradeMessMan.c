
#include "GradeMessMan.h"
void ShowGradeMenu(void)
{
	system("cls");
	int spaces;//记录跳过空格的数量
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
	while(scanf("%d",&temp)!=1||(temp<0||temp>2)){//输入不合法
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
	printf("课程号：%-6d课程名%-12s学期：%d\n",pc->course,pc->cname,term);
	ShowNChar(' ',25);
	ShowNChar('-',50);
	printf("\n\n");
	ShowNChar(' ',25);
	printf("序号      学号      姓名      成绩\n");
}
void EnterGrade_Show2(cho *pc,int num)
{
	ShowNChar(' ',25);
	printf("%-10d%-10d%-10s",num,pc->sno,pc->sname);
	while(scanf("%d",&pc->grade)!=1){
		fflush(stdin);
		ShowNChar(' ',25);
		printf("请正确输入!");
	}
}
void EnterGrade(void)
{
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	int cno=0,term=0;
	puts("输入要录入成绩的课程号和学期");
	ShowNChar(' ',25);
	printf("课程号：");
	while(scanf("%d",&cno)!=1){
		fflush(stdin);
		ShowNChar(' ',25);
		printf("请正确输入!");
	}
	fflush(stdin);
	ShowNChar(' ',25);
	printf("学期：");
	while(scanf("%d",&term)!=1){
		fflush(stdin);
		ShowNChar(' ',25);
		printf("请正确输入!");
	}
	fflush(stdin);//输入课程号和学期完成
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
		printf("选课人数：%d\n",cnt);
	}
	else{
		ShowNChar(' ',25);
		printf("该课程不存在选课信息\n");
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
void FixGrade(void)
{
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	int sno=0,cno=0,term=0;
	puts("输入要修改的学号、课程号和学期");
	ShowNChar(' ',25);
	fflush(stdin);
	printf("学号：");
	while(scanf("%d",&sno)!=1){
		fflush(stdin);
		ShowNChar(' ',25);
		printf("请正确输入!");
	}
	ShowNChar(' ',25);
	fflush(stdin);
	printf("课程号：");
	while(scanf("%d",&cno)!=1){
		fflush(stdin);
		ShowNChar(' ',25);
		printf("请正确输入!");
	}
	ShowNChar(' ',25);
	fflush(stdin);
	printf("学期：");
	while(scanf("%d",&term)!=1){
		fflush(stdin);
		ShowNChar(' ',25);
		printf("请正确输入!");
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
		printf("原成绩信息：");
		ShowNChar(' ',25);
		ShowNChar('-',50);
		printf("\n");
		ShowNChar(' ',25);
		printf("学号：%d\n",temp.sno);
		ShowNChar(' ',25);
		printf("姓名：%s\n",temp.sname);
		ShowNChar(' ',25);
		printf("课号：%d\n",temp.course);
		ShowNChar(' ',25);
		printf("课名：%s\n",temp.cname);
		ShowNChar(' ',25);
		printf("学期：%d\n",temp.term);
		ShowNChar(' ',25);
		printf("成绩：%d\n",temp.grade);
		ShowNChar('-',50);
		printf("\n\n");
		fflush(stdin);
		printf("输入新成绩：");
		while(scanf("%d",&temp.grade)!=1){
			fflush(stdin);
			ShowNChar(' ',25);
			printf("请正确输入!");
		}
		char jud[10];
		ShowNChar(' ',25);
		fflush(stdin);
		printf("\n保存修改吗？(Y-确认 N-放弃)：");
		s_gets(jud,10);
		if(jud[0]=='y'||jud[0]=='Y'){
			fseek(fp,-sizeof(cho),SEEK_CUR);
			fwrite(&temp,1,sizeof(cho),fp);
			printf("\n");
			ShowNChar(' ',25);
			delayexit();
		}
		else{//取消
			;
		}
	}
	else{
		ShowNChar(' ',25);
		printf("ERROR:该信息不存在！\n");
		printf("\n");
		ShowNChar(' ',25);
		system("pause");
	}
	if(fclose(fp)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("关闭文件错误\n");
		exit(1);
	}
	return;
}

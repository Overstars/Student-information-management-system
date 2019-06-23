
#include "SysMan.h"
#include "ChooseCor.h"//提供结构体原型
void ShowChoMenu(void)
{
	system("cls");
	int spaces;//记录跳过空格的数量
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
	while(scanf("%d",&temp)!=1||(temp<0||temp>6)){//输入不合法
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
	printf("选课：\n");
	ShowNChar(' ',25);
	ShowNChar('-',30);
	printf("\n");
	ShowNChar(' ',25);
	fflush(stdin);
	printf("输入学号：");
	int stuno,sflag=0;//记录输入的学号

	while(scanf("%d",&stuno)!=1||stuno<1){
		ShowNChar(' ',25);
		printf("请正确输入！\n");
		ShowNChar(' ',25);
		fflush(stdin);
	}
	fread(&tempstu,sizeof(stu),1,fpStu);
	while(!feof(fpStu)){
		if(tempstu.sno==stuno){//确定学生是否存在
			sflag=1;
			break;
		}
		fread(&tempstu,sizeof(stu),1,fpStu);
	}
	if(sflag){
		fflush(stdin);
		ShowNChar(' ',25);
		printf("输入选课学期：");
		int term=0,cournum=0;
		while(scanf("%d",&term)!=1||term<1){
			ShowNChar(' ',25);
			printf("请正确输入！\n");
			ShowNChar(' ',25);
			fflush(stdin);
		}
		tempcho.sno=stuno;//将学号存入
		tempcho.term=term;//将学期存入
		strncpy(tempcho.sname,tempstu.name,30);//将学生姓名存入
		tempcho.grade=0;//成绩暂时初始化为0
		system("cls");
		/**********ChooseCourse的子页面**********/
		printf("\n\n\n");
		ShowNChar(' ',25);
		printf("选课\t\t\t学期：%d\n",term);
		ShowNChar(' ',25);
		ShowNChar('-',30);
		printf("\n\n");
		ShowNChar(' ',25);
		fflush(stdin);
		printf("学号：%d\t\t姓名：%s\n\n",stuno,tempstu.name);

		ShowNChar(' ',25);
		printf("输入选课号(输入0结束)：");
		while(1){
			while(scanf("%d",&cournum)!=1||cournum<0){
				printf("请正确输入！\n");
				fflush(stdin);
			}
			if(cournum==0)
				break;
			int cflag=0;
			rewind(fpCor);
			fread(&tempcla,sizeof(cla),1,fpCor);
			while(!feof(fpCor)){
				if(tempcla.cno==cournum){//确定课程是否存在
					cflag=1;
					break;
				}
				fread(&tempcla,sizeof(cla),1,fpCor);
			}
			if(cflag){
				tempcho.course=cournum;
				strncpy(tempcho.cname,tempcla.name,30);//将课程名存入
				fwrite(&tempcho,sizeof(cho),1,fpCho);
			}
			else{
				ShowNChar(' ',25);
				printf("ERROR:该课程不存在!\n");
			}
			ShowNChar(' ',25);
			fflush(stdin);
			printf("输入选课号(输入0结束)：");
		}
		/*********子页面结束***********/
		printf("\n\n");
		ShowNChar(' ',25);
		delayexit();
	}
	else{
		ShowNChar(' ',25);
		printf("ERROR:该学生不存在!\n\n");
		ShowNChar(' ',25);
		system("pause");
	}
	if(fclose(fpStu)!=0||fclose(fpCho)!=0||fclose(fpCor)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("关闭文件错误\n");
		exit(1);
	}
	return;
}

void ShowChoCourMess1(stu *ps)//DelBySno()的附加函数1，传入指向stu结构的指针，用于展示学生的选课信息
{
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("选课信息\n");
	ShowNChar(' ',25);
	ShowNChar('-',30);
	printf("\n");
	ShowNChar(' ',25);
	printf("学号：%-8d\t姓名：%-8s\n\n",ps->sno,ps->name);
	ShowNChar(' ',25);
	printf("课程号\t\t课程名\t\t学期\n");
}
void ShowChoCourMess2(cho *pcho)//DelBySno()的附加函数2
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
	printf("删除选课：\n");

	ShowNChar(' ',25);
	ShowNChar('-',30);
	printf("\n");
	ShowNChar(' ',25);
	fflush(stdin);
	printf("输入学号：");

	int sno=0,sflag=0;//记录输入的学号，和该学号是否存在
	while(scanf("%d",&sno)!=1){
		ShowNChar(' ',25);
		printf("请正确输入！\n");
		ShowNChar(' ',25);
		fflush(stdin);
	}
	fread(&tempstu,sizeof(stu),1,fpStu);
	while(!feof(fpStu)){
		if(tempstu.sno==sno){//确定学生是否存在
			sflag=1;
			break;
		}
		fread(&tempstu,sizeof(stu),1,fpStu);
	}
    if(sflag){//学生存在，切换子页面展示学生信息
		ShowChoCourMess1(&tempstu);
		fread(&tempcho,sizeof(cho),1,fpCho);
		while(!feof(fpCho)){
			if(tempcho.sno==sno){//查找选了什么课
				ShowChoCourMess2(&tempcho);
			}
			fread(&tempcho,sizeof(cho),1,fpCho);
		}
		printf("\n");
		ShowNChar(' ',25);
		ShowNChar('-',30);
		printf("\n");
		ShowNChar(' ',25);
		//展示部分结束，
		int delcno=0;
		char jud[10];
		fflush(stdin);
		printf("输入要删除的课程号：");
		while(scanf("%d",&delcno)!=1||delcno<0){
			printf("请正确输入！\n");
			fflush(stdin);
		}
		printf("\n");
		ShowNChar(' ',25);
		fflush(stdin);
		printf("保存修改吗？(Y-确认 N-放弃)：");
		s_gets(jud,10);
		//待修改…………………………………………………………………………………………………………………………………………………………
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
				printf("关闭文件错误\n");
				exit(1);
			}
			if(remove("result.dat")==0)//快做完了就把这块处理一下
				printf("Removed result.dat\n");
			else{
				printf("error:%d",errno);
				printf("移除失败\n");
			}
			if(rename("temp.dat","result.dat")==0)
				printf("Rename temp.dat to result.dat\n");
			else
				printf("重命名失败\n");
			/********又是老写法，搬自己的砖*********/
			delayexit();
		}
		//待修改…………………………………………………………………………………………………………………………………………………………
		else{//如果取消删除
			if(fclose(fpCho)!=0)
			{
				putchar('\n');
				ShowNChar(' ',25);
				printf("关闭文件错误\n");
				exit(1);
			}

		}
    }
    else{//该学生不存在
		if(fclose(fpCho)!=0)
		{
			putchar('\n');
			ShowNChar(' ',25);
			printf("关闭文件错误\n");
			exit(1);
		}
		ShowNChar(' ',25);
		printf("ERROR:该学生不存在!\n\n");
		ShowNChar(' ',25);
		system("pause");
	}
	if(fclose(fpStu)!=0||fclose(fpCor)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("关闭文件错误\n");
		exit(1);
	}
	return;
}
void DelByCno_ShowMess1(cho *pcho,int term)//DelByCno()的附加函数1，传入指向cho结构的指针，用于展示课程学生信息
{
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("选课信息\n");
	ShowNChar(' ',25);
	ShowNChar('-',30);
	printf("\n");
	ShowNChar(' ',25);
	printf("课程号：%-7d课程名：%-9s学期：%d\n\n",pcho->course,pcho->cname,term);
	ShowNChar(' ',25);
	printf("序号\t\t学号\t\t姓名\n");
}
void DelByCno_ShowMess2(cho *pcho,int cnt)//DelByCno()的附加函数2
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
	printf("删除选课：\n");

	ShowNChar(' ',25);
	ShowNChar('-',30);
	printf("\n");
	ShowNChar(' ',25);
	fflush(stdin);
	printf("输入课程号：");

	int cno=0,choterm=0,cflag=0;
	while(scanf("%d",&cno)!=1||cno<1){
		ShowNChar(' ',25);
		printf("请正确输入！\n");
		ShowNChar(' ',25);
		fflush(stdin);
	}
	ShowNChar(' ',25);
	fflush(stdin);
	printf("输入选课学期：");
	while(scanf("%d",&choterm)!=1||choterm<1){
		ShowNChar(' ',25);
		printf("请正确输入！\n");
		ShowNChar(' ',25);
		fflush(stdin);
	}
	fread(&tempcla,sizeof(cla),1,fpCor);
	while(!feof(fpCor)){
		if(tempcla.cno==cno){//确定课程是否存在
			cflag=1;//存在该课程
			break;
		}
		fread(&tempcla,sizeof(cla),1,fpCor);
	}
	if(fclose(fpCor)!=0){//用不上就提前关了吧
		printf("\n");
		ShowNChar(' ',25);
		printf("2019年6月19日20点51分写到这~~~~");
		exit(1);
	}
    if(cflag){//课程存在
		DelByCno_ShowMess1(&tempcho,choterm);
		int cnt=0;
		fread(&tempcho,sizeof(cho),1,fpCho);
		while(!feof(fpCho)){
			if(tempcho.course==cno&&tempcho.term==choterm){//查找该课该学期有谁选
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
		//展示部分结束
		if(cnt==0){//无学生选课
			if(fclose(fpCho)!=0)
			{
				putchar('\n');
				ShowNChar(' ',25);
				printf("关闭文件错误\n");
				exit(1);
			}
			printf("\n");
			ShowNChar(' ',25);
			printf("没有学生选课！\n\n");
			ShowNChar(' ',25);
			system("pause");
		}
		else{//有学生选课
			char jud[10];
			printf("\n");
			ShowNChar(' ',25);
			fflush(stdin);
			printf("确认删除吗？(Y-确认 N-放弃)：");
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
					printf("关闭文件错误\n");
					exit(1);
				}
				if(remove("result.dat")==0)//快做完了就把这块处理一下
					printf("Removed result.dat\n");
				else{
					printf("error:%d",errno);
					printf("移除失败\n");
				}
				if(rename("temp.dat","result.dat")==0)
					printf("Rename temp.dat to result.dat\n");
				else
					printf("重命名失败\n");
				/********又是老写法，搬自己的砖*********/
				delayexit();
			}
			//待修改…………………………………………………………………………………………………………………………………………………………
			else{//如果取消删除
				if(fclose(fpCho)!=0)
				{
					putchar('\n');
					ShowNChar(' ',25);
					printf("关闭文件错误\n");
					exit(1);
				}

			}
		}
    }//课程存在
    else{//课程不存在
		if(fclose(fpCho)!=0)
		{
			putchar('\n');
			ShowNChar(' ',25);
			printf("关闭文件错误\n");
			exit(1);
		}
		ShowNChar(' ',25);
		printf("ERROR:该课程不存在!\n\n");
		ShowNChar(' ',25);
		system("pause");
    }
	if(fclose(fpStu)!=0)
	{
		putchar('\n');
		ShowNChar(' ',25);
		printf("关闭文件错误\n");
		exit(1);
	}
    return;
}
void ShowBySno(void)
{
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("选课信息查询：\n");

	ShowNChar(' ',25);
	ShowNChar('-',30);
	printf("\n");
	ShowNChar(' ',25);
	fflush(stdin);
	printf("输入学号：");

	FILE *fpCho,*fpStu;
	if((fpCho=fopen("result.dat","rb"))==NULL||(fpStu=fopen("student.dat","rb"))==NULL){
		puts("Cant't open.");
		exit(1);
	}
	cho tempcho;
	stu tempstu;

	int sno=0,sflag=0;//记录输入的学号，和该学号是否存在
	while(scanf("%d",&sno)!=1){
		ShowNChar(' ',25);
		printf("请正确输入！\n");
		ShowNChar(' ',25);
		fflush(stdin);
	}
	fread(&tempstu,sizeof(stu),1,fpStu);
	while(!feof(fpStu)){
		if(tempstu.sno==sno){//确定学生是否存在
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
		printf("ERROR:该学生不存在!\n\n");
		ShowNChar(' ',25);
	}
	if(fclose(fpStu)!=0||fclose(fpCho)!=0)
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
void ShowByCno_ShowMess1(cho *pcho)//ShowByCno()的附加函数1，传入指向cho结构的指针，用于展示课程信息
{
	system("cls");
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("课程信息：\n");
	ShowNChar(' ',25);
	ShowNChar('-',30);
	printf("\n");
	ShowNChar(' ',25);
	printf("课程号：%-7d课程名：%-9s\n\n",pcho->course,pcho->cname);
	ShowNChar(' ',25);
	printf("学号\t\t姓名\t\t学期\n");
}
void ShowByCno_ShowMess2(cho *pcho)//ShowByCno()的附加函数2
{
	ShowNChar(' ',25);
	printf("%-15d%-16s%-16d\n",pcho->sno,pcho->sname,pcho->term);
}
void ShowByCno(void)
{
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("选课信息查询：\n");

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

	int cno=0,cflag=0;//记录
	while(scanf("%d",&cno)!=1||cno<0){
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
void ShowAll(void)
{
	printf("\n\n\n");
	ShowNChar(' ',25);
	printf("全部选课信息");
	ShowNChar(' ',25);
	printf("Page:1\n");

	ShowNChar(' ',25);
	ShowNChar('-',55);
	printf("\n\n");
	ShowNChar(' ',25);
	printf("序号  学号  姓名        课号  课名        学期  成绩\n");

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
		printf("关闭文件错误\n");
		exit(1);
	}
	printf("\n");
	ShowNChar(' ',25);
	system("pause");
	return;
}

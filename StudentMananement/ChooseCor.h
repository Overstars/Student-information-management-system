#ifndef CHOOSECOR_H_
#define CHOOSECOR_H_

#include "SysMan.h"
#include "StudentManage.h"
#include "ClassMessMan.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define WIDTHCHO 60
#define TOPICCHO "选课管理"
#define DIVIDE "------------------------------"
#define CHO1 "1.选          课"
#define CHO2 "2.按学号删除选课"
#define CHO3 "3.按课号删除选课"
#define CHO4 "4.按学号查看选课"
#define CHO5 "5.按课号查看选课"
#define CHO6 "6.查看全部选课信息"
#define CHO0 "0.返 回 主 菜 单"

typedef struct Choose_Course
{
	int sno;
	char sname[30];
	int course;
	char cname[30];
	int term;
	int grade;
} cho;


void ShowChoMenu(void);//展示菜单，已完成
int ChoGetOrder(void);//已完成
void ShowChoCourMess1(stu *ps);//DelBySno()的附加函数1，传入指向stu结构的指针，用于展示学生的选课信息
void ShowChoCourMess2(cho *pcho);//DelBySno()的附加函数2，展示课号，课程名，学期
void DelByCno_ShowMess1(cho *pcho,int term);//DelByCno()的附加函数1，传入指向cho结构的指针，用于展示课程学生信息
void DelByCno_ShowMess2(cho *pcho,int cnt);//DelByCno()的附加函数2


void ChooseCourse(void);//选课，已完成
void DelBySno(void);//按学号删除，已完成
void DelByCno(void);//按课号删除,应该完成了2019年6月19日21点23分
void ShowBySno(void);
void ShowByCno(void);
void ShowAll(void);

#endif // CHOOSECOR_H_

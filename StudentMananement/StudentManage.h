#ifndef STUMAN_H_
#define STUMAN_H_

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<errno.h>
#include<string.h>
#include "SysMan.h"//包含一些工具函数

#define WIDTHST 60
#define TOPICST "学生信息管理"
#define DIVIDE "------------------------------"
#define STM1 "1.增          加"
#define STM2 "2.修          改"
#define STM3 "3.删          除"
#define STM4 "4.查          看"
#define STM5 "5.按学号升序排列"
#define STM0 "0.返 回 主 菜 单"
struct student_massage
{
	int sno;
	char name[30];
	char sex;
	char address[30];
//	struct student_massage *next;
};
typedef struct student_massage stu;

void ShowStuMess(stu *p);//一些附加函数
int StuGetOrder(void);
int cmpst(const void *a,const void *b);
void ShowNChar(char ch,int num);

void ShowStuMenu(void);
void AddStu(void);
void FixStu(void);
void DeletStu(void);
void ShowStu(void);
void SortStu(void);

#endif // STUMAN_H_

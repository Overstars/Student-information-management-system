#ifndef STUMAN_H_
#define STUMAN_H_

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<errno.h>
#include<string.h>
#include "SysMan.h"//����һЩ���ߺ���

#define WIDTHST 60
#define TOPICST "ѧ����Ϣ����"
#define DIVIDE "------------------------------"
#define STM1 "1.��          ��"
#define STM2 "2.��          ��"
#define STM3 "3.ɾ          ��"
#define STM4 "4.��          ��"
#define STM5 "5.��ѧ����������"
#define STM0 "0.�� �� �� �� ��"
struct student_massage
{
	int sno;
	char name[30];
	char sex;
	char address[30];
//	struct student_massage *next;
};
typedef struct student_massage stu;

void ShowStuMess(stu *p);//һЩ���Ӻ���
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

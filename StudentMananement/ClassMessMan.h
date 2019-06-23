#ifndef CLASSMESSMAN_H_
#define CLASSMESSMAN_H_

#include<string.h>
#include<stdio.h>
#include "SysMan.h"//包含一些工具函数

#define WIDTHCLA 60
#define TOPICCLA "课程信息管理"
#define DIVIDE "------------------------------"
#define CLA1 "1.增          加"
#define CLA2 "2.修          改"
#define CLA3 "3.删          除"
#define CLA4 "4.查          看"
#define CLA5 "5.按课号升序排列"
#define CLA0 "0.返 回 主 菜 单"

typedef struct Class_Massage
{
	int cno;
	char name[30];
	int score;
	int hour;
	struct Class_Massage *next;
} cla;

void ShowClaMenu(void);
int ClaGetOrder(void);
void ShowClaMess(cla *p);//FixCla()的附加函数
void EmptyList(cla *plist);//清空cla链表

//void AddItem(cla item,cla *plist);//将item添加至链表尾

void AddCla(void);//完成
void FixCla(void);//完成
void DeletCla(void);//完成
void ShowCla(void);//完成
void SortCla(void);


#endif // CLASSMESSMAN_H_

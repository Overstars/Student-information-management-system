#ifndef CLASSMESSMAN_H_
#define CLASSMESSMAN_H_

#include<string.h>
#include<stdio.h>
#include "SysMan.h"//����һЩ���ߺ���

#define WIDTHCLA 60
#define TOPICCLA "�γ���Ϣ����"
#define DIVIDE "------------------------------"
#define CLA1 "1.��          ��"
#define CLA2 "2.��          ��"
#define CLA3 "3.ɾ          ��"
#define CLA4 "4.��          ��"
#define CLA5 "5.���κ���������"
#define CLA0 "0.�� �� �� �� ��"

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
void ShowClaMess(cla *p);//FixCla()�ĸ��Ӻ���
void EmptyList(cla *plist);//���cla����

//void AddItem(cla item,cla *plist);//��item���������β

void AddCla(void);//���
void FixCla(void);//���
void DeletCla(void);//���
void ShowCla(void);//���
void SortCla(void);


#endif // CLASSMESSMAN_H_

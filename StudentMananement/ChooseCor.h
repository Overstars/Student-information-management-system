#ifndef CHOOSECOR_H_
#define CHOOSECOR_H_

#include "SysMan.h"
#include "StudentManage.h"
#include "ClassMessMan.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define WIDTHCHO 60
#define TOPICCHO "ѡ�ι���"
#define DIVIDE "------------------------------"
#define CHO1 "1.ѡ          ��"
#define CHO2 "2.��ѧ��ɾ��ѡ��"
#define CHO3 "3.���κ�ɾ��ѡ��"
#define CHO4 "4.��ѧ�Ų鿴ѡ��"
#define CHO5 "5.���κŲ鿴ѡ��"
#define CHO6 "6.�鿴ȫ��ѡ����Ϣ"
#define CHO0 "0.�� �� �� �� ��"

typedef struct Choose_Course
{
	int sno;
	char sname[30];
	int course;
	char cname[30];
	int term;
	int grade;
} cho;


void ShowChoMenu(void);//չʾ�˵��������
int ChoGetOrder(void);//�����
void ShowChoCourMess1(stu *ps);//DelBySno()�ĸ��Ӻ���1������ָ��stu�ṹ��ָ�룬����չʾѧ����ѡ����Ϣ
void ShowChoCourMess2(cho *pcho);//DelBySno()�ĸ��Ӻ���2��չʾ�κţ��γ�����ѧ��
void DelByCno_ShowMess1(cho *pcho,int term);//DelByCno()�ĸ��Ӻ���1������ָ��cho�ṹ��ָ�룬����չʾ�γ�ѧ����Ϣ
void DelByCno_ShowMess2(cho *pcho,int cnt);//DelByCno()�ĸ��Ӻ���2


void ChooseCourse(void);//ѡ�Σ������
void DelBySno(void);//��ѧ��ɾ���������
void DelByCno(void);//���κ�ɾ��,Ӧ�������2019��6��19��21��23��
void ShowBySno(void);
void ShowByCno(void);
void ShowAll(void);

#endif // CHOOSECOR_H_

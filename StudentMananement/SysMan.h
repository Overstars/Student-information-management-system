#ifndef SYSMAN_H_
#define SYSMAN_H_

#include<string.h>
#include<stdio.h>
#include<time.h>

#define WIDTH 60
#define TOPIC "ѧ���ɼ�����ϵͳ"
#define DIVIDE "------------------------------"
#define SYS1 "1.ѧ����Ϣ����"
#define SYS2 "2.�γ���Ϣ����"
#define SYS3 "3.ѡ        ��"
#define SYS4 "4.�ɼ���Ϣ����"
#define SYS5 "5.��        ѯ"
#define SYS0 "0.�� ��  ϵ ͳ"

void ShowNChar(char ch,int num);//һЩ�Զ��幤�ߺ���
char * s_gets(char *st,int n);
void delay(unsigned long msec);
void delayexit(void);

void ShowMenu(void);//�˵��ຯ��
int GetOrder(void);
void StuManage(void);//�Ӳ˵�-ѧ����Ϣ
void ClaManage(void);//�Ӳ˵�-�γ�
void ChoManage(void);//�Ӳ˵�-ѡ��
void GraManage(void);//�Ӳ˵�-�ɼ�
void InqManage(void);//�Ӳ˵�-��ѯ
#endif // SYSMAN_H_

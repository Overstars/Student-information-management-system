#ifndef GRADEMESSMAN_H_
#define GRADEMESSMAN_H_

#include<stdio.h>
#include<stdlib.h>
#include "ChooseCor.h"
#include "SysMan.h"

//#define WIDTH 60
#define TOPICGRA "�ɼ�����"
#define DIVIDE "------------------------------"
#define GRA1 "1.¼ �� �� ��"
#define GRA2 "2.�� �� �� ��"
#define GRA0 "0.���� ���˵�"
void ShowGradeMenu(void);
int GradeGetOrder(void);

void EnterGrade(void);
void FixGrade(void);

#endif // GRADEMESSMAN_H_

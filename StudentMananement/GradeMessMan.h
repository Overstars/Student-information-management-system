#ifndef GRADEMESSMAN_H_
#define GRADEMESSMAN_H_

#include<stdio.h>
#include<stdlib.h>
#include "ChooseCor.h"
#include "SysMan.h"

//#define WIDTH 60
#define TOPICGRA "成绩管理"
#define DIVIDE "------------------------------"
#define GRA1 "1.录 入 成 绩"
#define GRA2 "2.修 改 成 绩"
#define GRA0 "0.返回 主菜单"
void ShowGradeMenu(void);
int GradeGetOrder(void);

void EnterGrade(void);
void FixGrade(void);

#endif // GRADEMESSMAN_H_

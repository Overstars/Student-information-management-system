#ifndef SYSMAN_H_
#define SYSMAN_H_

#include<string.h>
#include<stdio.h>
#include<time.h>

#define WIDTH 60
#define TOPIC "学生成绩管理系统"
#define DIVIDE "------------------------------"
#define SYS1 "1.学生信息管理"
#define SYS2 "2.课程信息管理"
#define SYS3 "3.选        课"
#define SYS4 "4.成绩信息管理"
#define SYS5 "5.查        询"
#define SYS0 "0.退 出  系 统"

void ShowNChar(char ch,int num);//一些自定义工具函数
char * s_gets(char *st,int n);
void delay(unsigned long msec);
void delayexit(void);

void ShowMenu(void);//菜单类函数
int GetOrder(void);
void StuManage(void);//子菜单-学生信息
void ClaManage(void);//子菜单-课程
void ChoManage(void);//子菜单-选课
void GraManage(void);//子菜单-成绩
void InqManage(void);//子菜单-查询
#endif // SYSMAN_H_

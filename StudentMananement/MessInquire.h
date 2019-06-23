#ifndef MESSINQUIRE_H_
#define MESSINQUIRE_H_

#include "SysMan.h"
#include "ChooseCor.h"

char InqInfor[][20]={
	"查询学生信息","11.按学号","12.按姓名","13.按地址",
	"查询课程信息","21.按课号","22.按课名",
	"查询选课信息","31.按学号","32.按课号","33.全  部",
	"查询成绩信息","41.按学号","42.按课号","43.排  名",
	"0.返回主菜单"
};
typedef struct StuScoreBoard
{
	stu st;
	int cnt;
	double sum;
} SSB;



void ShowInqMenu(void);
int InqGetOrder(void);

void ShowStuMess2(stu *p);
int cmpSSB(const void *a,const void *b);

void InqSBySno(void);
void InqSBySname(void);
void InqSByAddress(void);
void InqCByCno(void);
void InqCByCname(void);
//void InqChoBySno(void);//相当于ShowBySno
//void InqChoByCno(void);//相当于ShowByCno
//void ShowAllCho(void);//相当于ShowAll();
void InqGraBySno(void);
void InqGraByCno(void);
void InqGraByList(void);


#endif // MESSINQUIRE_H_

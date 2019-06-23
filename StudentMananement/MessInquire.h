#ifndef MESSINQUIRE_H_
#define MESSINQUIRE_H_

#include "SysMan.h"
#include "ChooseCor.h"

char InqInfor[][20]={
	"��ѯѧ����Ϣ","11.��ѧ��","12.������","13.����ַ",
	"��ѯ�γ���Ϣ","21.���κ�","22.������",
	"��ѯѡ����Ϣ","31.��ѧ��","32.���κ�","33.ȫ  ��",
	"��ѯ�ɼ���Ϣ","41.��ѧ��","42.���κ�","43.��  ��",
	"0.�������˵�"
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
//void InqChoBySno(void);//�൱��ShowBySno
//void InqChoByCno(void);//�൱��ShowByCno
//void ShowAllCho(void);//�൱��ShowAll();
void InqGraBySno(void);
void InqGraByCno(void);
void InqGraByList(void);


#endif // MESSINQUIRE_H_

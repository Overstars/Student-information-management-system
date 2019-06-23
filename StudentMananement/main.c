#include <stdio.h>
#include <stdlib.h>//Ã·π©exit
#include "SysMan.h"
#include "StudentManage.h"
#include "ClassMessMan.h"
#include "ChooseCor.h"
int main(void)
{
	int MainOrder;
	ShowMenu();
    while((MainOrder=GetOrder())!=0){
		printf("Order:%d\n",MainOrder);
		switch (MainOrder)
		{
			case 1:
				StuManage();
				break;
			case 2:
				ClaManage();
				break;
			case 3:
				ChoManage();
				break;
			case 4:
				GraManage();
				break;
			case 5:
				InqManage();
				break;
			default:
				printf("Wrong.");
		}
		ShowMenu();
    }
	return 0;
}

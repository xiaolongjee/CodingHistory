#include "../include/func.h"
#include "memery.h"

T_Que_Elem gFriends;
T_Que_Elem gColegues;
T_Que_Elem gFamilies;

T_Contact tContact[MAX_PERSON_NUM];

int main()
{
	UCHAR location = 0;
	person maomao;
	
	
	InitContactData();
	InitQue();
	
	maomao.name = "maomao";
	maomao.age  = 18;
	maomao.gender = MALE;
	maomao.telephonev = ""+86-88888888888;
	maomao.email = "maomao@mm.com";
	
	memcpy(&tContact[location], &maomao, sizeof(T_Contact));
	Que_Put_Head(&gFriends, tContact[location].linker);

	return 1;
}

VOID InitData()
{
	InitQue();
	InitContactData();
}

VOID InitQue()
{
	Que_Create(&gFriends);
	Que_Create(&gColegues);
	Que_Create(&gFamilies);
}

VOID InitContactData()
{
	memset(tContact, 0, sizeof(T_Person) * MAX_PERSON_NUM);
}



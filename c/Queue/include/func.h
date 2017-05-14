#ifndef __FUNC_H_201705140613
#define __FUNC_H_201705141813

#include "queue.h"

typedef char data;
typedef struct T_Contact
{
	T_Que_Elem* linker;

	data* name;
	data  group;
	data  gender;
	data  age;
	data* telephone;
	data* email;
}T_Contact, person;

#define MALE   0
#define FEMALE 1

#define MAX_PERSON_NUM	100

extern VOID InitData();
extern VOID InitQue();
extern VOID InitContactData();

#endif

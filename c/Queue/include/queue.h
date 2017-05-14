#ifndef __QUEUE_H_201705140613
#define __QUEUE_H_201705141813

#include "basetype.h"

typedef struct T_Que_Elem
{
	struct T_Que_Elem *next;
	struct T_Que_Elem *pre;
}T_Que_Elem, *Que_Handle;

typedef struct person
{
	T_Que_Elem* linker;

	UCHAR* name;
	UCHAR  gender; /* 0-male, 1-female */
	UCHAR  age;
	UCHAR* telnum;
	UCHAR* email;
	
	
}person;

extern size_t Que_Create(Que_Handle queue);
extern BOOL Que_Empty(Que_Handle queue);
extern VOID Que_Put_Head(Que_Handle queue, T_Que_Elem* elem);
extern VOID Que_Put_Tail(Que_Handle queue, T_Que_Elem* elem);
extern VOID Que_Remove(T_Que_Elem* elem);
extern VOID Que_Clear(Que_Handle queue);
extern VOID Que_Delete(Que_Handle queue);
extern T_Que_Elem* Que_Head(Que_Handle queue);
extern T_Que_Elem* Que_Next(T_Que_Elem* elem);
extern T_Que_Elem* Que_Pre(T_Que_Elem* elem);
extern T_Que_Elem* Que_Get(Que_Handle queue);

#endif

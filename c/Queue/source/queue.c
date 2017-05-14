#include "../include/queue.h"

size_t Que_Create(Que_Handle queue)
{
	queue->next = queue;
	queue->pre = queue;
	return (size_t)queue;
}

VOID Que_Put_Head(Que_Handle queue, T_Que_Elem* elem)
{
	T_Que_Elem* pre = queue->pre;
	elem->next = queue;
	elem->pre  = pre;
	queue->pre = elem;
	pre->next  = elem;
	return;
}

VOID Que_Put_Tail(Que_Handle queue, T_Que_Elem* elem)
{
	queue->next = elem;
	elem->pre = queue;
	return;
}


VOID Que_Remove(T_Que_Elem* elem)
{
	elem->pre->next = elem->next;
	elem->next->pre = elem->pre;
	return;
}

BOOL Que_Empty(Que_Handle queue)
{
	if((queue->pre == queue) && (queue->next == queue))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

T_Que_Elem* Que_Head(Que_Handle queue)
{
	return (queue->next);
}

T_Que_Elem* Que_Next(T_Que_Elem* elem)
{
	return (elem->next);
}

T_Que_Elem* Que_Pre(T_Que_Elem* elem)
{
	return (elem->pre);
}


/* 取出队列的头部并摘除 */
T_Que_Elem* Que_Get(Que_Handle queue)
{
	T_Que_Elem* elem = NULL;
	T_Que_Elem* next = NULL;

	next = elem->next;
	elem = queue->next;

	queue->next = next;
	next->pre   = queue;

	return elem;
}

VOID Que_Clear(Que_Handle queue)
{
	queue->next = queue;
	queue->pre  = queue;
	return;
}

VOID Que_Delete(Que_Handle queue)
{
	queue->next = NULL;
	queue->pre  = NULL;
	return;
}


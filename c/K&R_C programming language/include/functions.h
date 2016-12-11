#ifndef _FUNCTIONS_H_201611172232
#define _FUNCTIONS_H_201611172232

#include "basetype.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*************************宏定义***********************/
#define MAX_WORD_LENGTH 15
/************************类型声明**********************/
typedef int (*FuncPtr)(void);

/***********************结构体定义*********************/

/************************全局变量**********************/

/************************函数声明**********************/
extern int funcptrCall(void);
extern int* binarySearch(int* arry, int n, const int value);
extern WORD32 memcopy(int* des, int desSize, int* src, int srcSize);
extern WORD32 sort(int* arry, int size);
extern WORD32 wordLengthRecord(char* text, int* wordCounter);

#ifdef __cplusplus
}
#endif

#endif


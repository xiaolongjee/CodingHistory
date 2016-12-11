#ifndef __TESTCASE_H_201611131802
#define __TESTCASE_H_201611131802

#include "basetype.h"
#include "common.h"
#include <assert.h>

#ifdef __cplusplus
extern "C"
{
#endif

/*************************宏定义***********************/

/************************类型声明**********************/
typedef void (*test)(void);
typedef int (*FuncPtr)(void);
/***********************结构体定义*********************/

/************************全局变量**********************/

/************************函数声明**********************/
extern void test_getPutchar(void);
extern void test_tempreturePrint(void);
extern void test_funcptr(void);
extern void test_binarySearch(void);
extern void test_memcopy(void);
extern void test_wordPrint(void);
extern void test_sort(void);
extern void test_wordLengthPrint(void);

#ifdef __cplusplus
}
#endif

#endif

#ifndef __TESTCASE_H_201611131802
#define __TESTCASE_H_201611131802

#include "basetype.h"
#include "common.h"
#include <assert.h>

#ifdef __cplusplus
extern "C"
{
#endif

/*************************�궨��***********************/

/************************��������**********************/
typedef void (*test)(void);
typedef int (*FuncPtr)(void);
/***********************�ṹ�嶨��*********************/

/************************ȫ�ֱ���**********************/

/************************��������**********************/
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

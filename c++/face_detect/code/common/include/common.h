#ifndef __COMMON_H_201611131803
#define __COMMON_H_201611131803

#include "basetype.h"

/*************************宏定义***********************/
#define SUCCESS (WORD32)0x00000000
#define FAILURE (WORD32)0xFFFFFFFF

#define MAX_MEM_SIZE   (BYTE)5000000  /* 开辟最大共享内存5M */
#define CACHE_MEM_SIZE (BYTE)1000000  /* 缓存数据区大小1M */

//////////////////////////////////////////////////////
#define CSTD_BEGIN \
#ifdef _cplusplus \
{ \
extern "C" \
#endif

#define CSTD_END
#ifdef _cplusplus \
}\
#endif

/************************类型声明**********************/


/***********************结构体定义*********************/


/************************函数声明********************/
extern void powerInit();
extern void powerDown();

#endif

#ifndef __COMMON_H_201611131803
#define __COMMON_H_201611131803

#include "basetype.h"

/*************************�궨��***********************/
#define SUCCESS (WORD32)0x00000000
#define FAILURE (WORD32)0xFFFFFFFF

#define MAX_MEM_SIZE   (BYTE)5000000  /* ����������ڴ�5M */
#define CACHE_MEM_SIZE (BYTE)1000000  /* ������������С1M */

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

/************************��������**********************/


/***********************�ṹ�嶨��*********************/


/************************��������********************/
extern void powerInit();
extern void powerDown();

#endif

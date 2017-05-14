#include "common.h"
#include <memory.h>

BYTE memry[MAX_MEM_SIZE];
BYTE cache[CACHE_MEM_SIZE];

/************************º¯Êý¶¨Òå**********************/
void powerInit()
{
	memset(memry, 0, MAX_MEM_SIZE * sizeof(BYTE));
	memset(cache, 0, CACHE_MEM_SIZE * sizeof(BYTE));
	
}
void powerDown()
{
	powerInit();
}


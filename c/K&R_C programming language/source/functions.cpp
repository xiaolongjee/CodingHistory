#include "functions.h"
#include "common.h"
#include <stdlib.h>

//////////////////////////////////////////////////////////
int funcptr(void)
{
  return 1;
}
int funcptrCall(void)
{
	FuncPtr ptr;
	ptr = funcptr;
  	return ptr();
}
//////////////////////////////////////////////////////////
int* binarySearch(int* arry, int n, const int value)
{
    int half = n / 2;
    if(1 == n)
    {
        if(value == *arry) 
			return arry;
        else 
			return NULL;
	}
	else
	{
        if(value == arry[half]) 
			return &arry[half];
        else if(value > arry[half])
        	return binarySearch(&arry[half + 1], (n - half), value);
        else
        	return binarySearch(arry, half, value);
	}
}
int other_Binary_Search(int* a, int len, int goal)
{
    int low = 0;
    int high = len - 1;
    while (low <= high)
    {
        int middle = (high - low) / 2 + low; // in case of overflow by using ((high + low) / 2); 
        if (a[middle] == goal)
            return middle;
        //left side;
        else if (a[middle] > goal)
            high = middle - 1;
        //right side;
        else
            low = middle + 1;
    }
    // not found;
    return -1;
}
//////////////////////////////////////////////////////////
#define CHECK_POINTER(ptr) \
	if(NULL == ptr)  \
	{ \
		return FAILURE; \
	}
	
WORD32 memcopy(int* des, int desSize, int* src, int srcSize)
{
	int* ptr = NULL;
	int counter = 0;

	CHECK_POINTER(des);
	CHECK_POINTER(src);
	
	if(desSize >= srcSize)
	{
		ptr = des;
		counter = srcSize;
		while((ptr != (des + desSize - 1)) && (counter != 0))
		{
			*ptr = *src;
			ptr++;
			src++;
			counter--;
		}

		return SUCCESS;
	}
	else
		return FAILURE;
}
//////////////////////////////////////////////////////////
WORD32 sort(int* arry, int size)
{
	int elem = 0;
	int rightSide = 0;
	int leftSide = 0;

	for(rightSide = size - 1; rightSide > 0; rightSide--)
	{
		for(leftSide = 0; leftSide < rightSide; leftSide++)
		{
    		elem = arry[leftSide + 1];
    		if(elem < arry[leftSide])
    		{
    			elem = arry[leftSide];
    			arry[leftSide] = arry[leftSide + 1];
    			arry[leftSide + 1] = elem;
    		}
		}		
	}
	
	return SUCCESS;
}
////////////////////////////////////////////////////////////////////
#define isALetter(input) \
(((input) >= 65) && ((input) <= 90)) || \
(((input) >= 97) && ((input) <= 122))	    
WORD32 wordLengthRecord(char* text, int* wordCounter)
{
	char* preLetter = NULL;
	char* curLetter = NULL;
	 int  length = 0;
	
	preLetter = text;
	curLetter = preLetter + 1;
	if(true == isALetter(*preLetter)) /* 对第一个字符进行单独处理 */
	{
		length++;
	}
	while('\0' != *curLetter)
	{	
		if(*curLetter == ' ')
		{
			wordCounter[MAX_WORD_LENGTH]++; /* 记录单词总数目，要求每个单词后空出一格无论是否带标点 */
		}
		if(true == isALetter(*curLetter))
		{
			length++;
		}
		else
		{
			if(MAX_WORD_LENGTH < length) /* 防止超出统计的最大长度 */
				continue;
			wordCounter[length]++;
			preLetter = curLetter;
			length = 0;
		}

		curLetter++;
	}
	return SUCCESS;
}




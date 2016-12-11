#include "testcase.h"
#include "functions.h"
#include <stdio.h>

////////////////////////////////////////////////////////////
void test_getPutchar(void)
{
	int str;
	while(EOF != (str = getchar()))
	{
		putchar(str);
	}
}
////////////////////////////////////////////////////////////
void test_tempreturePrint(void)
{
	int highTempreture = 300;
	int lowTempreture = 0;
	int fahr = 0;
	int celsius = 0;

	for(fahr = highTempreture; fahr >= lowTempreture; fahr -= 2)
	{
		celsius = 5 * (fahr - 32) / 9;
		printf("fahr = %3d,  celsius = %3d\n", fahr, celsius);
	}
}
////////////////////////////////////////////////////////////
void test_funcptr(void)
{
	printf("%d\n", funcptrCall());

}
////////////////////////////////////////////////////////////
void test_binarySearch(void)
{
	int arry[8] = {0, 2, 3, 4, 5,7,12,90};
	for(int loop = 0; loop < 8; loop++)
	{
		int* result = binarySearch(arry, 8, arry[loop]+1);
		if(NULL != result)
			printf("%d\n", *result);
	}
}
////////////////////////////////////////////////////////////
void test_memcopy(void)
{
	int des[10] = {0};
	int src[5] = {90,213,29,0,29};
	char loop = 0;
	
	if(SUCCESS == memcopy(des, 10, src, 5))
	{
		for(loop = 0; loop < 10; loop++)
		{
			printf("des[%d] = %d\n", loop, des[loop]);
		}
	}
}
////////////////////////////////////////////////////////////
#define IsAnotherWord(input) \
	 ( \
		( (input) == '\n') ||  \
		( (input) == '\t') ||  \
		( (input) == ' ')  \
	)
#define CHECK_LOCATION(location) \
	if(location > 1023)  \
		break;  \
		
void test_wordPrint(void)
{
	char input = 0;
	char printer[1024] = {'\0'};
	int location = 0;

	while(EOF != (input = getchar()))
	{
		if (IsAnotherWord(input))
		{
			printer[location] = '\0';
			printf("%s\n", printer);
			location = 0;
		}
		else
		{
			printer[location] = input;
			location++;
			CHECK_LOCATION(location);
		}
	}
}

////////////////////////////////////////////////////////////
void test_sort(void)
{
	int loop = 0;
	int data[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	
	sort(data, 10);
	for(loop = 0; loop < 10; loop++)
	{
		printf("%d ", data[loop]);
	}
	printf("\n");

}

void test_wordLengthPrint(void)
{
	int dotNum = 0;
	char* text =  "Apologize "

				  "I am holding on your rope "
				  "Got me ten feet off the ground " 
				  "I am hearin what you say but I just cannot make a sound " 
                  "You tell me that you need me "
                  "Then you go and cut me down, but wait " 
                  "You tell me that you are sorry "
                  "Didnot think I would turn around, and say... "
                  
                  "Its too late to apologize, its too late "
		          "said its too late to apologize, its too late "
		          
                  "I would take another chance, take a fall "
                  "Take a shot fore you "
                  "And I need you like a heart needs a beat "
                  "But its nothin newed "
                  "I loved you with a fire red- "
                  "Now its turning blue, and you say... "
                  "Sorry like the angel heaven let me think was you "
                  "But I am afraid... "
				 
	              "I said its too late to apologize, its too late "
                  "Its too late to apologize, its too late ";
	
	/* 数组索引即单词长度，存储值为对应长度的单词数目,扩充长度存储总单词数目 */
	int wordCounter[MAX_WORD_LENGTH + 1] = {0}; 

	wordLengthRecord(text, wordCounter);

	for(int idx = 1; idx < MAX_WORD_LENGTH; idx++)
	{
		printf("%5d |", idx);
		for(dotNum = 0; dotNum < wordCounter[idx]; dotNum++)
			printf("%c", 0x2605);
		printf("\n"); /* 隔一行再进行打印 */
	}
	printf("Words num in this text are %d.\n", wordCounter[MAX_WORD_LENGTH]);
}


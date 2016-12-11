#include "testcase.h"
#include <stdlib.h>

int main()
{
	int caseNumberSlect = 0;
	test testCase[100] = 
		{
/**CASE NUMBER**/ /*****************************TEST CASE*******************************/
/*  0/ 1/ 2/ 3 */ test_getPutchar, test_tempreturePrint, test_funcptr, test_binarySearch, 
/*  4/ 5/ 6/ 7 */ test_memcopy,    test_wordPrint,       test_sort,    test_wordLengthPrint,
/*  8/ 9/10/11 */
		};

	caseNumberSlect = 7; /* */
	testCase[caseNumberSlect]();

	system("pause");
	return SUCCESS;
}
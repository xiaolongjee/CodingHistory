
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	FILE *srcFile = NULL;
	FILE *desFile = NULL;
	char data = 0;

	if(3 != argc)
	{
		cout<<"Argument number is wrong!"<<endl;
		cout<<"Example:copytest.exe a.txt b.txt"<<endl;
		exit(-1);
	}

	srcFile = fopen(argv[1], "r");
	if(!srcFile)
	{
		cout<<"Open source file failed!"<<endl;
		exit(-1);
	}

	desFile = fopen(argv[2], "w");
	if(!desFile)
	{
		cout<<"Create des file failed!"<<endl;
		exit(-1);
	}

	while(EOF != fscanf(srcFile, "%c", &data))
	{
		fprintf(desFile, "%c", data);
	}
	fclose(srcFile);
	fclose(desFile);
	
	return 1;
}
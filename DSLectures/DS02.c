#include "stdio.h"
typedef struct Letter
{
	int : 5;
	int sign : 1;
	int : 2;
}Letter;

void DS02()
{
	int var1 = 7;
	int var2 = 8;

	int* const ptr = &var1;
	*ptr = 6;
	//ptr = &var2;

	int const* pint1 = &var1;
	const int* pint2 = &var2;
	pint1 = pint2;
	//*pint1 = 6;

	const int* const ppint = &var1;
	//*ppint = 4;
	//ppint = &var2;

	char buffer1[] = "Popescu";
	char* buffer2 = "Popescu";
	//buffer2[0] = 'R';

	for (int i = 0; i < strlen(buffer1); i++)
	{
		printf("%c",buffer1[i]);
		Letter* pletter = &buffer1[i];
		pletter->sign = ~pletter->sign;
		printf("%c\n", buffer1[i]);
	}


	
}
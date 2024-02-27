#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
void insertNumber(int**, int, int*);
void main()
{
	int* array = NULL;
	int number = 0; int size = 0;
	printf("Input number: ");
	//scanf("%d", &number);
	//printf("Valoare pointer: %d\n", masiv);
	printf("Give a number: ");
	scanf("%d", &number);

	while (number != 0)
	{
		insertNumber(&array, number, &size);
		for (int i = 0; i < size; i++)
			printf("%d; ", array[i]);
		printf("\n");
		printf("Give a number: ");
		scanf("%d", &number);
	}
}

void insertNumber(int** masiv, int number, int* size)
{

}
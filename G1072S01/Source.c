#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void insertNumber(int**, int, int*);

void main()
{
	printf("Hello G1072!\n");
	int* array = NULL;
	int size = 0; int number = 0;
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
void insertNumber(int** array, int number, int* size)
{
	int* tmp = (int*)malloc(sizeof(int) * (*size + 1));
	int k = 0, i = 0;
	while (i < *size && number > (*array)[i])
	{
		tmp[k++] = (*array)[i++];
	}
	tmp[k++] = number;
	while (i < *size)
	{
		tmp[k++] = (*array)[i++];
	}
	free(*array);
	*array = tmp;
	(*size)++;
}
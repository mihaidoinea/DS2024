#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main()
{
	printf("Hello G1072!");
	int* array = NULL;
	int size = 0; int number = 0;
	printf("Give a number: ");
	scanf("%d", &number);

	while (number != 0)
	{
		for (int i = 0; i < size; i++)
			printf("%d; ", array[i]);
		insertNumber(&array, number, &size);
		printf("Give a number: ");
		scanf("%d", &number);
	}
}
void insertNumber(int** array, int number, int* size)
{
	int* tmp = (int*)malloc(sizeof(int) * (*size + 1));
	int k = 0, i = 0;
	while (i < *size && number > *array[i])
	{
		tmp[k++] = *array[i++];
	}
	tmp[k++] = number;
}
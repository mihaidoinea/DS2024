#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void insertNumber(int**, int, int*);
void main()
{
	printf("Hello G1070!\n");
	int* array = NULL;
	int size = 0;
	int value = 0;
	printf("Give a number: ");
	scanf("%d", &value);
	while (value != 0)
	{
		insertNumber(&array, value, &size);
		for (int i = 0; i < size; i++)
			printf("%d; ", array[i]);
		printf("\n");
		printf("Give a number: ");
		scanf("%d", &value);
	}
}
void insertNumber(int** vector, int value, int* size)
{
	int* tmp = (int*)malloc(sizeof(int) * (*size + 1));
	int k = 0, i = 0;
	while (i < *size && value>(*vector)[i])
	{
		tmp[k++] = (*vector)[i++];
	}
	tmp[k++] = value;
	while (i < *size)
	{
		tmp[k++] = (*vector)[i++];
	}
	free(*vector);
	*vector = tmp;
	(*size)++;
}
#include <stdio.h>
#include <malloc.h>
void insertNumber(int**, int, int*);
void main()
{
	printf("Hello G1051!\n");
	int* array = NULL;
	int number = 0, size = 0;
	printf("Give a number: ");
	scanf_s("%d", &number);
	while (number != 0)
	{
		insertNumber(&array, number, &size);
		for (int i = 0; i < size; i++)
			printf("%d; ", array[i]);
		printf("\n");

		printf("Give a number: ");
		scanf_s("%d", &number);
	}
}
void insertNumber(int** vector, int value, int* dim)
{
	int* tmp = (int*)malloc(sizeof(int) * (*dim + 1));
	int i = 0, k = 0;
	//if((*vector)[i] != NULL)
	while (i < *dim && value > (*vector)[i])
	{
		tmp[k++] = (*vector)[i++];
	}
	tmp[k++] = value;
	while (i < *dim)
	{
		tmp[k++] = (*vector)[i++];
	}
	(*dim)++;
	free(*vector);
	*vector = tmp;
}

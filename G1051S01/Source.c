#include <stdio.h>
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
		printf("Give a number: ");
		scanf_s("%d", &number);
	}
}
void insertNumber(int** vector, int value, int* dim)
{
	int* tmp = (int*)malloc(sizeof(int) * (*dim + 1));

}

#include <stdio.h>
#include <stdlib.h>

// Брижак Андрей. ДЗ к занятию 8 по курсу Алгоритмы и структры данных. Задача 1.
//2. Реализовать быструю сортировку.
/*
input.txt
90 27 30 23 62 84 76 31 57 26 94 34 29 40 25 95 41 41 13 26 47 45 15 62 65 45 2 53 99 55 97 95 3
22 48 74 86 39 76 16 90 72 20 11 49 44 18 2 97 10 33 65 92 83 16 3 35 70 18 61 1 63 20 98 85 24
12 97 23 25 95 11 66 74 85 38 44 33 47 20 18 78 54 60 28 7 67 70 63 52 38 9 47 31 10 30 47 92 64 30
*/
const int MAX = 100;


void quickSort(int *numbers, int left, int right)
{
	int pivot; 
	int l_hold = left; 
	int r_hold = right; 
	pivot = numbers[left];
	while (left < right) 
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--; 
		if (left != right) 
		{
			numbers[left] = numbers[right];
			left++; 
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++; 
		if (left != right) 
		{
			numbers[right] = numbers[left]; 
			right--; 
		}
	}
	numbers[left] = pivot; 
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) 
		quickSort(numbers, left, pivot - 1);
	if (right > pivot)
		quickSort(numbers, pivot + 1, right);
}
int main()
{
	int i, *a, b, s, k, n, o;
	FILE *fin/*, *fout*/;
	fin = fopen("input.txt", "r");
	/*fout = fopen("output.txt", "w");*/
	if (fin == NULL)
	{
		puts("Can't open file!");
		getch();
		exit(1);
	}
	int count;
	fscanf(fin, "%d", &count);
	a = (int *)malloc(MAX * sizeof(int));
	i = 0;
	for (i = 0; i < count; i++)
	{
		fscanf(fin, "%d", &a[i]);
		printf("%d ", a[i]);
	}
	printf("\n ");
	getch();
	/*int a[10];
	
	for (int i = 0; i<10; i++)
		a[i] = rand() % 20 - 10;
	
	for (int i = 0; i<10; i++)
		printf("%d ", a[i]);
	printf("\n");*/
	quickSort(a, 1, 100); 
						
	for (int i = 0; i<MAX; i++)
		printf("%d ", a[i]);
	printf("\n");
	getchar();
	return 0;
}
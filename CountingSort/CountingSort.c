#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Брижак Андрей. ДЗ к занятию 8 по курсу Алгоритмы и структры данных. Задача 1.
// 1. Реализовать сортировку подсчетом.
/*
input.txt
90 27 30 23 62 84 76 31 57 26 94 34 29 40 25 95 41 41 13 26 47 45 15 62 65 45 2 53 99 55 97 95 3
22 48 74 86 39 76 16 90 72 20 11 49 44 18 2 97 10 33 65 92 83 16 3 35 70 18 61 1 63 20 98 85 24
12 97 23 25 95 11 66 74 85 38 44 33 47 20 18 78 54 60 28 7 67 70 63 52 38 9 47 31 10 30 47 92 64 30
*/

const int MAX = 100;

simpleCountingSort(int * a, int k) // где k – длина массива А,
								   
{
	int i, *c, b, j;
	c = (int *)malloc(MAX * sizeof(int));
	for (i = 0; i < k; i++)
	{
		c[i] = 0;// Вначале мы обнуляем массив
	}
	/*c[a[i]] = 1;*/
	for (i = 0; i < MAX; i++)
	{
		c[a[i]]++;
	}
	printf("\n ");
	for (i = 0; i < MAX; i++)
	{
		printf("\n ");
		printf("%d ", i);
		printf("%d ", c[i]);
	}
	printf("\n ");
	getch();
	b = 0;
	for (j = 0; j< MAX; j++)
	{
		if (c[j]>0)
		{
			for (i = 0; i< c[j]; i++)
			{
				a[b] = j;
				b++;
			}
		}
	}

	
}

int main(void)
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
	simpleCountingSort(a, count);
	printf("Sorted Array:\n");
	for (i = 0; i <count; i++)
	{
		printf("%d ", a[i]);
	}
	getch();

	free(a);
	fclose(fin);
	//fclose(fout);
	
	return 0;
}
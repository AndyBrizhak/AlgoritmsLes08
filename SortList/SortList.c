
#include <stdio.h>
#include <stdlib.h>
// ������ ������. �� � ������� 8 �� ����� ��������� � �������� ������. ������ 4.
// 4. **����������� �������� ���������� �� �������.
/*
input.txt
90 27 30 23 62 84 76 31 57 26 94 34 29 40 25 95 41 41 13 26 47 45 15 62 65 45 2 53 99 55 97 95 3
22 48 74 86 39 76 16 90 72 20 11 49 44 18 2 97 10 33 65 92 83 16 3 35 70 18 61 1 63 20 98 85 24
12 97 23 25 95 11 66 74 85 38 44 33 47 20 18 78 54 60 28 7 67 70 63 52 38 9 47 31 10 30 47 92 64 30
*/
typedef struct key 
{
	/*int val;*/
	int key;
} Key;

const unsigned int MAX = 100;
ListCountingSort(int * a, int k) // ��� k � ����� ������� �,

{
	int i, /**c,*/ b, j;
	Key *c;
	c = (Key *)malloc(MAX * sizeof(Key));
	for (i = 0; i < k; i++)
	{
		c[i].key = 0;
		
	}
	
	for (i = 0; i < MAX; i++)
	{
		c[a[i]].key++;
	}
	printf("\n ");
	for (i = 0; i < MAX; i++)
	{
		printf("\n ");
		printf("%d ", i);
		printf("%d ", c[i].key);
	}
	printf("\n ");
	getch();
	b = 0;
	for (j = 0; j< MAX; j++)
	{
		if (c[j].key>0)
		{
			for (i = 0; i< c[j].key; i++)
			{
				a[b] = j;
				b++;
			}
		}
	}


}


int main()
{
	int i, *a, *c;
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
	ListCountingSort(a, count);
	printf("Sorted Array:\n");
	for (i = 0; i <count; i++)
	{
		printf("%d ", a[i]);
	}
	getch();

	free(a);
	fclose(fin);
	return 0;
}

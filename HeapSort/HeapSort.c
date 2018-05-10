#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
input.txt
90 27 30 23 62 84 76 31 57 26 94 34 29 40 25 95 41 41 13 26 47 45 15 62 65 45 2  53 99 55 97 95 3
22 48 74 86 39 76 16 90 72 20 11 49 44 18 2  97 10 33 65 92 83 16 3  35 70 18 61 1  63 20 98 85 24
12 97 23 25 95 11 66 74 85 38 44 33 47 20 18 78 54 60 28 7  67 70 63 52 38 9  47 31 10 30 47 92 64 30
*/
void Swap(int *, int *);
int HeapSort(int *, int);
const int MAX = 1024;
int main(void)
{
	int i, *a, b, s, k, n, o;
	FILE *fin, *fout;
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	a = (int *)malloc(MAX * sizeof(int));// выделяем память
	i = 0;
	/*fscanf(fin, "%d", &a[i]) == 1*/
	while (fscanf(fin, "%d", &a[i]) == 1)
	{
		i++;
	}

	n = i;
	k = HeapSort(a, n); // количество сравнений 
	printf("Number of  elements: %d\nNumber of compares: %d\n", n, k);
	printf("n^2 = %d\nn*log(n) = %d\n",
		n * n, (int)(n*log(n) / log(exp(1))));
	printf("Sorted Array:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}

	free(a);
	fclose(fin);
	fclose(fout);
	getch();
	return 0;
}

void Swap(int *p, int *q)
{
	int buf;
	buf = *p;
	*p = *q;
	*q = buf;
}

// Пирамидальная сортировка
int HeapSort(int *a, int n)
{
	int i, j, mid, t = n - 1, k;
	mid = n / 2;// середина массива
	for (i = mid; i >= 1; i--)
	{
		if (a[i - 1] < a[2 * i - 1])  // условие сравнения, которое соответствует пирам. сортировке
			Swap(&a[i - 1], &a[2 * i - 1]);
		if (2 * i < n && a[i - 1] < a[2 * i]) // если n-нечетное
			Swap(&a[i - 1], &a[2 * i]);
	}
	k = 2 * mid;
	Swap(&a[0], &a[t]);
	t--;
	while (t > 0)
	{
		mid = t / 2; // теперь на последнем месте стоит максимальный элемент, его больше не трогаем
		for (i = mid; i >= 1; i--)
		{// и проходимся по коротким ветвям
			if (a[i - 1] < a[2 * i - 1])
				Swap(&a[i - 1], &a[2 * i - 1]);
			if (2 * i < n && a[i - 1] < a[2 * i])
				Swap(&a[i - 1], &a[2 * i]);
		}
		k += 2 * mid;
		Swap(&a[0], &a[t]);
		t--;
	}
	if (n > 0 && a[0] > a[1]) // самое последнее сравнение: нулевого с первым элементом
		Swap(&a[0], &a[1]);
	k++;
	return k;

}
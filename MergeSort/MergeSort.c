#include <stdio.h>
#include <stdlib.h>

// ������ ������. �� � ������� 8 �� ����� ��������� � �������� ������. ������ 3.
// 3. *����������� ���������� ��������.
/*
input.txt
90 27 30 23 62 84 76 31 57 26 94 34 29 40 25 95 41 41 13 26 47 45 15 62 65 45 2 53 99 55 97 95 3
22 48 74 86 39 76 16 90 72 20 11 49 44 18 2 97 10 33 65 92 83 16 3 35 70 18 61 1 63 20 98 85 24
12 97 23 25 95 11 66 74 85 38 44 33 47 20 18 78 54 60 28 7 67 70 63 52 38 9 47 31 10 30 47 92 64 30
*/
const unsigned int MAX = 100;

/**
* ��������� ������, ��������� ����������� ���������� ��������
* up - ��������� �� ������, ������� ����� �����������
* down - ��������� �� ������ �, ��� �������, ����� �� �������� ��� � 'up', ������������ ��� �����
* left - ����� ������� �������, ��������� 0, ����� ����������� ������ � ������
* right - ������ ������� �������, ��������� ����� ������� - 1, ����� ����������� ������ �� ���������� ��������
* ����������: ��������� �� ��������������� ������. ��-�� ������������ ������ ������ ����������
* ��������������� ������ ������� ����� ��������� ���� � 'up', ���� � 'down'
**/
int* merge_sort(int *up, int *down, unsigned int left, unsigned int right)
{
	if (left == right)
	{
		down[left] = up[left];
		return down;
	}

	unsigned int middle = (left + right) / 2;

	// �������� � ��������
	int *l_buff = merge_sort(up, down, left, middle);
	int *r_buff = merge_sort(up, down, middle + 1, right);

	// ������� ���� ��������������� �������
	int *target = l_buff == up ? down : up;

	unsigned int l_cur = left, r_cur = middle + 1;
	for (unsigned int i = left; i <= right; i++)
	{
		if (l_cur <= middle && r_cur <= right)
		{
			if (l_buff[l_cur] < r_buff[r_cur])
			{
				target[i] = l_buff[l_cur];
				l_cur++;
			}
			else
			{
				target[i] = r_buff[r_cur];
				r_cur++;
			}
		}
		else if (l_cur <= middle)
		{
			target[i] = l_buff[l_cur];
			l_cur++;
		}
		else
		{
			target[i] = r_buff[r_cur];
			r_cur++;
		}
	}
	return target;
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
	c = (int *)malloc(MAX * sizeof(int));
	unsigned int left = 0;
	/*MergeSort(a, 0, MAX - 1);*/
	int res;
	res =* merge_sort(a, c, left, MAX);
	printf("\n");
	for (int i = 1; i<MAX+1; i++)
		printf("%d ", a[i]);
	printf("\n");
	getchar();
	/*free(a);
	fclose(fin);*/
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
// Функция быстрой сортировки
void quickSort(int *numbers, int left, int right)
{
	int pivot; // разрешающий элемент
	int l_hold = left; //левая граница
	int r_hold = right; // правая граница
	pivot = numbers[left];
	while (left < right) // пока границы не сомкнутся
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
			left++; // сдвигаем левую границу вправо 
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
			right--; // сдвигаем правую границу вправо 
		}
	}
	numbers[left] = pivot; // ставим разрешающий элемент на место
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // � екурсивно вызываем сортировку для левой и правой части массива
		quickSort(numbers, left, pivot - 1);
	if (right > pivot)
		quickSort(numbers, pivot + 1, right);
}
int main()
{
	int a[10];
	// Заполнение массива случайными числами
	for (int i = 0; i<10; i++)
		a[i] = rand() % 20 - 10;
	// Вывод элементов массива до сортировки
	for (int i = 0; i<10; i++)
		printf("%d ", a[i]);
	printf("\n");
	quickSort(a, 0, 9); // вызов функции сортировки
						// Вывод элементов массива после сортировки
	for (int i = 0; i<10; i++)
		printf("%d ", a[i]);
	printf("\n");
	getchar();
	return 0;
}
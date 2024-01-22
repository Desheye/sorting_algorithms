#include "sort.h"

void recursive_quick_sort(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_quick_sort(array, 0, size - 1, size);
}

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int i = low - 1, j = low;
	int pivot = array[high], temp = 0;

	for (; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}


void recursive_quick_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		recursive_quick_sort(array, low, pivot - 1, size);
		recursive_quick_sort(array, pivot + 1, high, size);
	}
}

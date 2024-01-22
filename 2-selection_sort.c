#include "sort.h"

void selection_sort(int *array, size_t size)
{
    int temp = 0;
    size_t i = 0, j = 0, min_index = 0;

    if (array == NULL || size == 0)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }
        if (min_index != i)
        {
            temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
            print_array(array, size);
        }
    }
}


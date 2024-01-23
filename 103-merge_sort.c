#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - Sorts an array using the merge sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
    size_t i = 0;
    int *temp_array = NULL;

    if (array == NULL || size < 2)
        return;

    temp_array = malloc(sizeof(int) * size);
    if (temp_array == NULL)
        return;

    for (; i < size; i++)
        temp_array[i] = array[i];

    merge_partition(0, size, array, temp_array);

    free(temp_array);
}

/**
 * merge - Merges two sorted subarrays into a single sorted array.
 * @lo: Lower index.
 * @mi: Middle index.
 * @hi: Higher index.
 * @dest: Destination array.
 * @src: Source array.
 */
void merge(size_t low, size_t mi, size_t high, int *dest, int *src)
{
    size_t i = 0, j = 0, k = 0;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(src + low, mi - low);
    printf("[right]: ");
    print_array(src + mi, high - mi);

    i = low;
    j = mi;
    k = low;

    while (k < high)
    {
        if (i < mi && (j >= high || src[i] <= src[j]))
        {
            dest[k] = src[i];
            i++;
        }
        else
        {
            dest[k] = src[j];
            j++;
        }
        k++;
    }

    printf("[Done]: ");
    print_array(dest + low, high - low);
}

/**
 * merge_partition - Recursively divides and merges the array.
 * @low: Lower index.
 * @high: Higher index.
 * @array: The array to sort.
 * @temp_array: Temporary copy of the array.
 */
void merge_partition(size_t low, size_t high, int *array, int *temp_array)
{
    size_t mi = 0;

    if (high - low < 2)
        return;

    mi = (low + high) / 2;
    merge_partition(low, mi, array, temp_array);
    merge_partition(mi, high, array, temp_array);
    merge(low, mi, high, array, temp_array);

    for (mi = low; mi < high; mi++)
        temp_array[mi] = array[mi];
}

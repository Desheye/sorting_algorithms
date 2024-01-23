#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - Sorts an array using the counting sort algorithm.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void counting_sort(int *array, size_t size)
{
    unsigned int i = 1;
    int *count = NULL, max_value = 0, temp_value = 0, index = 0;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    max_value = array[0];
    for (; i < size; i++)
    {
        if (array[i] > max_value)
            max_value = array[i];
    }

    /* Allocate memory for the count array */
    count = malloc(sizeof(int) * (max_value + 1));
    if (count == NULL)
        return;

    /* Initialize count array with zeros */
    for (i = 0; i <= (size_t)max_value; i++)
        count[i] = 0;

    /* Count occurrences of each element */
    for (i = 0; i < size; i++)
        count[array[i]]++;

    /* Update count array to store cumulative count */
    for (i = 1; i <= (size_t)max_value; i++)
        count[i] += count[i - 1];

    /* Print intermediate count array */
    for (i = 0; i < (size_t)max_value; i++)
    {
        printf("%d, ", count[i]);
    }
    printf("%d\n", count[max_value]);

    /* Rearrange the elements in the original array */
    for (i = 0; i < size; i++)
    {
        index = count[array[i]] - 1;
        if (array[i] != array[index])
        {
            temp_value = array[i];
            array[i] = array[index];
            array[index] = temp_value;
        }
    }

    /* Free dynamically allocated memory */
    free(count);
}

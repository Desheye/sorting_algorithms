#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using Selection Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size) {
    if (array == NULL || size < 2)
        return;

    for (size_t i = 0; i < size - 1; i++) {
        size_t min_index = i;

        for (size_t j = i + 1; j < size; j++) {
            if (array[j] < array[min_index])
                min_index = j;
        }

        if (min_index != i) {
            /*Swap array[i] and array[min_index]*/
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;

            /* Print the array after each swap*/
            for (size_t k = 0; k < size; k++) {
                printf("%d ", array[k]);
            }
            printf("\n");
        }
    }
}

#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size) {
    if (array == NULL || size < 2)
        return;

    recursive_quick_sort(array, 0, size - 1, size);
}

/**
 * recursive_quick_sort - Recursively sorts a partition of the array using Quick Sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 */
void recursive_quick_sort(int *array, int low, int high, size_t size) {
    if (low < high) {
        int pivot_index = lomuto_partition(array, low, high, size);
        recursive_quick_sort(array, low, pivot_index - 1, size);
        recursive_quick_sort(array, pivot_index + 1, high, size);
    }
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 *
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 *
 * Return: The index of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap_elements(array, i, j);

            /* Print the array after each swap*/
            print_array(array, size);
        }
    }

    /* Place the pivot in its correct position*/
    swap_elements(array, i + 1, high);

    /* Print the array after each swap */
    print_array(array, size);

    return (i + 1);
}

/**
 * swap_elements - Swaps two elements in an array
 *
 * @array: The array containing the elements to be swapped
 * @a: Index of the first element
 * @b: Index of the second element
 */
void swap_elements(int *array, int a, int b) {
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

/**
 * print_array - Prints the elements of an array
 *
 * @array: The array to be printed
 * @size: Number of elements in the array
 */
void print_array(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("\n");
}

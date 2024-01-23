#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using Quick sort
 *                    with Hoare partition scheme.
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort_hoare(int *array, size_t size) {
    if (array == NULL || size < 2)
        return;

    quicksort_hoare(array, 0, size - 1, size);
}

/**
 * quicksort_hoare - Recursive function to perform Quick sort with Hoare partition
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 */
void quicksort_hoare(int *array, int low, int high, size_t size) {
    if (low < high) {
        int pivot_index = hoare_partition(array, low, high, size);
        quicksort_hoare(array, low, pivot_index, size);
        quicksort_hoare(array, pivot_index + 1, high, size);
    }
}

/**
 * hoare_partition - Hoare partition scheme for Quick Sort
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 *
 * Return: The index of the pivot after partitioning
 */
int hoare_partition(int *array, int low, int high, size_t size) {
    int pivot = array[high];
    int i = low - 1, j = high + 1;

    while (1) {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        /* Swap array[i] and array[j] */
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;

        /* Print the array after each swap */
        print_array(array, size);
    }
}

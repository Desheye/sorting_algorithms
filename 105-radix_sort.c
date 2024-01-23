#include "sort.h"
#include <stdlib.h>

/**
 * getMax - Gets the maximum element from an array
 * @array: The array to find the maximum element
 * @size: Number of elements in the array
 * Return: The maximum element
 */
int getMax(int *array, size_t size) {
    int max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

/**
 * countingSort - Performs counting sort based on digit (exp)
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @exp: The current digit (1, 10, 100, ...)
 */
void countingSort(int *array, size_t size, int exp) {
    int output[size];
    int count[10] = {0};

    for (size_t i = 0; i < size; i++) {
        count[(array[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (size_t i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size) {
    if (array == NULL || size < 2) {
        return;
    }

    int max = getMax(array, size);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(array, size, exp);
        print_array(array, size);
    }
}

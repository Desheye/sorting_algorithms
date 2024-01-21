#include "sort.h"

void print_array(const int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubble_sort(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                /* Swap array[j] and array[j + 1]*/
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                /* Print the array after each swap*/
                print_array(array, size);
            }
        }
    }
}


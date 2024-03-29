#include "sort.h"

void shell_sort(int *array, size_t size) {
    size_t i, j, gap = 1;
    if (array == NULL || size < 2)
        return;

    while (gap < size / 3)
        gap = gap * 3 + 1;

    while (gap > 0) {
        for (i = gap; i < size; i++) {
            int temp = array[i];
            j = i;

            while (j >= gap && array[j - gap] > temp) {
                array[j] = array[j - gap];
                j -= gap;
            }

            array[j] = temp;
        }

        gap /= 3;

        print_array(array, size);
    }
}

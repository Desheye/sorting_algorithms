#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in the heap.
 * @array: The heap to sort.
 * @node1: Index of the first node.
 * @node2: Index of the second node.
 * @size: The size of the array.
 */
void swap_nodes(int *array, size_t node1, size_t node2, size_t size)
{
    int temp = array[node1];
    array[node1] = array[node2];
    array[node2] = temp;
    print_array(array, size);
}

/**
 * heapify - Heapifies the subtree rooted at given index.
 * @array: The heap to sort.
 * @root: Index of the root node.
 * @hi: Highest index of the heap.
 * @size: The size of the array.
 */
void heapify(int *array, size_t root, size_t hi, size_t size)
{
    size_t left, right, largest;

    while (1)
    {
        largest = root;
        left = 2 * root + 1;
        right = 2 * root + 2;

        if (left <= hi && array[left] > array[largest])
            largest = left;

        if (right <= hi && array[right] > array[largest])
            largest = right;

        if (largest == root)
            return;

        swap_nodes(array, root, largest, size);
        root = largest;
    }
}

/**
 * heap_sort - Sorts an array using the heap sort algorithm.
 * @array: An array to sort.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
    size_t gap, hi;

    if (array == NULL || size < 2)
        return;

    for (gap = (size - 2) / 2; gap > 0; gap--)
        heapify(array, gap, size - 1, size);

    for (hi = size - 1; hi > 0; hi--)
    {
        swap_nodes(array, 0, hi, size);
        heapify(array, 0, hi - 1, size);
    }
}

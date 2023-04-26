#include "sort.h"

#define INSERTION_THRESHOLD 32

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);
void insertion_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * hoare_partition - Order a subset of an array of integers
 *                   according to the Hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Handles cases where the pivot element appears multiple times in the array.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
    int pivot, above, below;

    pivot = array[right];
    for (above = left - 1, below = right + 1; above < below;)
    {
        do {
            above++;
        } while (array[above] < pivot);
        while (array[below] > pivot) {
            below--;
            if (below <= above)
                return above;
        }
        if (array[below] == pivot && below != right)
        {
            swap_ints(array + above, array + below);
            above++;
        }
        if (above < below)
        {
            swap_ints(array + above, array + below);
            above++;
            below--;
        }
    }

    return above;
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 * Switches to insertion sort for small arrays.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
    int part;

    if (right - left >= INSERTION_THRESHOLD)
    {
        part = hoare_partition(array, size, left, right);
        hoare_sort(array, size, left, part);
        hoare_sort(array, size, part + 1, right);
    }
    else
    {
        insertion_sort(array + left, right - left + 1);
    }
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme.
 * Prints the array after each swap of two elements.
 * Switches to insertion sort for small arrays.
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    hoare_sort(array, size, 0, size - 1);
}

/**
 * insertion_sort - Sort an

#include "sort.h"
#include <stddef.h>

/**
 * quick_sort - function that sorts an array
 * of integers in ascending order using the
 * quick sort algorithm
 *
 * @array: input arrray
 * @size: size of the array
 * Return: no return
 */
void quick_sort(int *array, size_t size)
{
	_qsort(array, 0, size - 1, size);
}

/**
 * _qsort - auxiliar function for the
 * quick_sort function
 * @a: input arrray
 * @low: index for the first element
 * @high: index for the last element
 * @size: size of the array
 * Return: no return
 */
void _qsort(int *a, int low, int high, size_t size)
{
	int pivot, pivot_index, i;
	int tmp;

	if (low < high)
	{
		/* Select pivot element */
		pivot = a[high];
		pivot_index = low;

		/* Partition the array around the pivot */
		for (i = low; i < high; i++)
		{
			if (a[i] < pivot)
			{
				if (i != pivot_index)
				{
					/* Swap elements */
					tmp = a[i];
					a[i] = a[pivot_index];
					a[pivot_index] = tmp;

					/* Print the array after each swap */
					print_array(a, size);
				}
				pivot_index++;
			}
		}

		/* Swap pivot with element at pivot index */
		if (pivot_index != high && a[pivot_index] != a[high])
		{
			tmp = a[pivot_index];
			a[pivot_index] = a[high];
			a[high] = tmp;

			/* Print the array after each swap */
			print_array(a, size);
		}

		/* Recursively sort sub-arrays */
		_qsort(a, low, pivot_index - 1, size);
		_qsort(a, pivot_index + 1, high, size);
	}
}

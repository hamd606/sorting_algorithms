#include "sort.h"

/**
  * quick_sort - the sloppiest implementation of quick sort alg
  * @array: array
  * @size: array size
  */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursion(array, 0, size - 1, size);
}

/**
  * quick_sort_recursion - the recursion part of the quick sort alg
  * @array: array
  * @lower: lower limit of the sub array
  * @upper: upper limit of the sub array
  * @size: array size
  */
void quick_sort_recursion(int *array, int lower, int upper, size_t size)
{
	int low_part = 0;

	if (lower < upper)
	{
		low_part = lomuto_partition(array, lower, upper, size);
		quick_sort_recursion(array, lower, low_part - 1, size);
		quick_sort_recursion(array, low_part + 1, upper, size);
	}
}

/**
  * lomuto_partition - Lomuto partition scheme
  * @array: array
  * @lower: lower part of the sub array
  * @upper: upper part of the sub array
  * @size: array size
  * Return: the index of the new sub arr start
  */
int lomuto_partition(int *array, int lower, int upper, size_t size)
{
	int i = 0, j = 0, pivot = 0, k = 0;

	pivot = array[upper];
	i = lower;

	for (j = lower; j < upper; ++j)
	{
		if (array[j] < pivot)
		{
			k = array[i];
			array[i] = array[j];
			array[j] = k;

			if (k != array[i])
				print_array(array, size);

			++i;
		}
	}

	k = array[i];
	array[i] = array[upper];
	array[upper] = k;

	if (k != array[i])
		print_array(array, size);

	return (i);
}

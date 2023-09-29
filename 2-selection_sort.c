#include "sort.h"

/**
 * min - returns the min of an array starting from
 * a position and moving to the right
 * @array: the array
 * @size: array size
 * @start_pos: search starting position
 * Return: the index of the minimun value of the array
 * from position starting_pos onward
*/
size_t min(int *array, size_t size, size_t start_pos)
{
	size_t i = 0;
	size_t current_min = start_pos;

	for (i = start_pos; i < size; i++)
	{
		if (array[current_min] > array[i])
		{
			current_min = i;
		}
		;
	}

	return (current_min);
}

/**
 * selection_sort - the sloppiest implementation of selection sort alg
 * @array: array to e sorted
 * @size: size of array
*/
void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	int tmp;
	size_t minimum;
	size_t min_idx;

	for (i = 0; i < size; i++)
	{


		if (array[i] > array[min(array, size, i)])
		{
			minimum = array[min(array, size, i)];
			min_idx = min(array, size, i);



			tmp = array[i];

			array[i] = minimum;
			array[min_idx] = tmp;
			print_array(array, size);
		}

		;
	}
}

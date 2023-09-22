#include "sort.h"
/**
 * bubble_sort - bubble sort alg
 * @array: array to be sorted
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	int tmp;
	size_t passes = size;


	while (passes)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;

				print_array(array, size);
			}
		}

		passes = passes - 1;
	}
}

#include "sort.h"

/**
 * adjust_list_head - Resets the lists head to the correct node
 * @list: a pointer to list head
*/
void adjust_list_head(listint_t **list)
{
	while ((*list)->prev != NULL)
	{
		(*list) = (*list)->prev;
	}
}

/**
 * _swap_a_b - swaps two nodes in thier places
 * @upper: upper limit in a list
 * @lower: lower limit in a list
 * @a: the greater value of the two being swaped
 * @b: the smaller value of the two being swaped
*/
void _swap_a_b(listint_t *upper, listint_t *lower, listint_t *a, listint_t *b)
{
	if (upper != NULL)
	{
		upper->prev = a;
	}
	if (lower != NULL)
	{
		lower->next = b;
	}

	a->next = upper;
	a->prev = b;

	b->next = a;
	b->prev = lower;

}


/**
 * insertion_sort_list - the sloppiest implimentation of insertion sort
 * @list: list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;

	if (!list || !(*list) || !(*list)->next)
		return;

	while (current)
	{
		while (current->prev != NULL && current->prev->n > current->n)
		{
			_swap_a_b(current->next, current->prev->prev, current->prev, current);
			adjust_list_head(list);
			print_list(*list);
		}

		current = current->next;
	}

}

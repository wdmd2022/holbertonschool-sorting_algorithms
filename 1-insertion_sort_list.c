#include "sort.h"

/**
 * nodeflip - changes around 2 adjacent nodes in a linked list
 * @nodepointer: pointer to the node
 * Return: nothing at all
 */
void nodeflip(listint_t **nodepointer)
{
	listint_t *a = (*nodepointer);
	listint_t *b = (*nodepointer)->next;

	if (a->prev == NULL)
	{
		a->next = b->next;
		b->prev = a->prev;
		b->next = a;
		a->prev = b;
		a->next->prev = a;
	}
	else
	{
		a->next = b->next;
		b->prev = a->prev;
		b->prev->next = b;
		a->prev = b;
		b->next = a;
		a->next->prev = a;
	}
}

/**
 * insertion_sort_list - sorts a doubly-linked list using insertion sort
 * @list: double pointer to listint_t type list
 */

void insertion_sort_list(listint_t **list)
{
        listint_t *element = *list;
	listint_t *backnode;

	if (element == NULL)
		return;
	for (; element->next != NULL; element = element->next)
	{
		if (element->n > element->next->n)
		{
			nodeflip(&element);
			print_list(*list);
			backnode = element->prev;

			for (; backnode != NULL; backnode = backnode->prev)
			{
				if (backnode->n > backnode->next->n)
				{
					nodeflip(&backnode);
					print_list(*list);
				}
				else
					break;
			}
		}
	}
}

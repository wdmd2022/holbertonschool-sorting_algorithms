#include "sort.h"
/**
 * switcheroo - switch two  elements of a doublylinked  listint_t type list
 * @head: pointer to head
 * @first: pointer to first adjacent node
 * @second: pointer to second adjacent node
 * Return: nothing
 */

void switcheroo(listint_t **head, listint_t **first, listint_t **second)
{
	listint_t *previous = NULL, *next = NULL;
	listint_t *a = *first, *b = *second;

	if (a->prev)
	{
		previous = a->prev;
		previous->next = b;
	}
	b->prev = previous;
	if (b->next)
	{
		next = b->next;
		next->prev = a;
	}
	a->next = next;
	b->next = a;
	a->prev = b;

	if (*head == a)
		*head = b;
}

/**
 * insertion_sort_list - sort a doubly-linked list using insertion
 * sort algorithm (list is of listint_t type)
 * @list: head of the listint_t list
 * Return: nothing at all
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node;
	listint_t *rev;

	if (!list)
	{
		return;
	}

	node = *list;

	while (node->next)
	{
		if (node->next != NULL && node->n > node->next->n)
		{
			switcheroo(list, &node, &(node->next));
			print_list(*list);
			rev = node->prev;
			while (rev->prev != NULL && rev->n < rev->prev->n)
			{
				switcheroo(list, &(rev->prev), &(rev));
				print_list(*list);
			}

		}
		if (node->next != NULL && node->n <= node->next->n)
		{
			node = node->next;
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

int     ft_list_size(t_list *begin_list)
{
	int counter = 0;
	while (begin_list != NULL)
	{
		counter++;
		begin_list = begin_list->next;
	}
	return counter;
}

int main ()
{
	t_list *node1;
	t_list *node2;
	t_list *node3;
	t_list *node4;

	
	node1 = malloc (sizeof (t_list));
	node2 = malloc (sizeof (t_list));
	node3 = malloc (sizeof (t_list));
	node4 = malloc (sizeof (t_list));

	node1->data = malloc (sizeof (int));
	node2->data = malloc (sizeof (int));
	node3->data = malloc (sizeof (int));
	node4->data = malloc (sizeof (int));

	*(int *)node1->data = 1;
	*(int *)node2->data = 2;
	*(int *)node3->data = 3;
	*(int *)node4->data = 4;
	

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	printf ("size = %d",ft_list_size(node1));

	free(node1);
	free(node2);
	free(node3);
	free(node4);
}

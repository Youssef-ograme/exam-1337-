#include <stdio.h>
#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>

/*void ft_putchar (char c)
{
	write (1,&c,1);
}

void ft_putnbr (int nbr)
{
	long nb = nbr;

	if (nb < 0)
	{
		ft_putchar ('-');
	}

	if (nb >= 10)
	{
		ft_putnbr (nb / 10);
	}

	ft_putchar ((nb % 10) + 48);
}*/

int comp ( void *data, int value)
{
	if ( *(int *)data == value)
	{
		return 1;
	}
	return 0;
}

int check_data (t_list *head , int value)
{
	int count = 0;
	while (head != NULL)
	{
		if (comp((int *)head->data , value) == 1)
		{
			count++;
			free(head);
		}
		head = head->next;
	}
	return count;
}

/*int	ft_list_size(t_list *begin_list)
{
	int count = 0;
	while (begin_list != NULL)
	{
		count++;
		begin_list = begin_list->next;
	}
	return count;
}*/

int main ()
{
	t_list *node1 = NULL;
	t_list *node2 = NULL;
	t_list *node3 = NULL;
	t_list *node4 = NULL;


	node1 = malloc (sizeof (t_list));
	node2 = malloc (sizeof (t_list));
	node3 = malloc (sizeof (t_list));
	node4 = malloc (sizeof (t_list));
	

	node1->data = malloc (sizeof (int));
	node2->data = malloc (sizeof (int));
	node3->data = malloc (sizeof (int));
	node4->data = malloc (sizeof (int));


	*(int *)node1->data = 1;
	*(int *)node2->data = 4;
	*(int *)node3->data = 3;
	*(int *)node4->data = 4;
	

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	int value = 4;
	int res = check_data (node1,value);
	printf ("size : %d",res);
	//printf ("size of nodes : %d \n",ft_list_size(node1));
	

}

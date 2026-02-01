#include <stdio.h>
#include <stdlib.h>
int     *ft_rrange(int start, int end)
{
	int size ;
	if (end >= start)
	{
		size = (end - start) + 1;
	}
	else if (end <= start)
	{
		size = (start - end) + 1;
	}
	int *tab = malloc (size * sizeof (int));
	int i = 0;
	if (end >= start)
	{
		while (end >= start)
		{
			tab[i] = end;
			end--;
			i++;
		}
	}
	else if (end <= start)
	{
		while (end <= start)
		{
			tab[i] = end;
			end++;
			i++;
		}
	}
	return tab;
}

int main()
{
	int i = 0;
	int end = -1;
	int start = 3;
	int size ;
	if (end >= start)
	{
		size = (end - start) + 1;
	}
	else if (end <= start)
	{
		size = (start - end) + 1;
	}
	int *tab = ft_rrange(start,end);
	printf ("end %d \n",end);
	while (i < size)
	{
		printf ("%d",tab[i]);
		i++;
	}
}

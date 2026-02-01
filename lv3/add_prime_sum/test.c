#include <stdio.h>
int main ()
{
	int nbr = 7;
	int i = 2;
	while (i * i <= nbr)
	{
		if (nbr % i == 0)
		{
			printf ("%d",i);
		}
		i++;
	}
}

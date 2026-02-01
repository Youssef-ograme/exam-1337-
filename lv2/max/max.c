#include <stdio.h>
// 437
int             max(int* tab, unsigned int len)
{
	int i = 0 ;
	int max = tab[0];
	while (i < len)
	{
		if (tab[i] > max)
		{
			ax = tab[i];
		}
		i++;
	}
	return max;
}
int main ()
{
	int tab[] = {1,2,3,100,4,5,7};
	int len = 7;
	printf ("%d",max(tab,len));
}

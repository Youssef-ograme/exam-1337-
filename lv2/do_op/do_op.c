#include <stdio.h>
#include "do_op.h"
#include <unistd.h>
void ft_putchar (char c)
{
	write (1,&c,1);
}

int do_op (char *nbr , char *op , char *nbr2)
{
	int val1 = ft_atoi(nbr);
	int val2 = ft_atoi(nbr2);
	int res;
	if (op[0] == '/')
		res = val1 / val2;	
	else if (op[0] == '*')
		res = val1 * val2;
	else if (op[0] == '+')
		res = val1 + val2;
	else if (op[0] == '-')
		res = val1 - val2;
	else if (op[0] == '%')
		res = val1 % val2;
	return res ;
}

int main (int argc , char *argv[])
{
	if (argc == 4)
	{
		printf ("%d\n",do_op(argv[1],argv[2],argv[3]));
	}
	else
	ft_putchar ('\n');
}


#include <unistd.h>
#include <stdlib.h>
void ft_putchar (char c)
{
	write (1,&c,1);
}

int ft_atoi (char *str)
{
	int i = 0;
	int signe = 1;
	int res = 0;
	int val ;
	while(str[i] == ' ' || str[i] == '\t')
	i++;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signe *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = str[i] - 48;
		res = (res * 10) + val;
		i++;
	}
	return signe * res;
}

int ft_putnbr (int nbr)
{
	if (nbr >= 10)
	{
		ft_putnbr (nbr / 10);
	}
	ft_putchar (nbr % 10  + 48);
}
int is_prime (int n)
{
	int i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
		{
			return 0;
		}
		i++;
	}
	return 1;
}
//#include <stdio.h>
int check_prime (char *str)
{
	int val = ft_atoi(str);
	int som = 0;
	if (val < 0)
	{
		ft_putchar ('0');
		ft_putchar ('\n');
		exit(0);
	}
	int i = 2;
	while ( i <= val)
	{
		if (is_prime(i))
		{
			som = som + i;
	//		printf ("%d\n",i);
		}
		i++;
	}
	return som;
}

void print_som (char *str)
{
	int val = check_prime (str);
	ft_putnbr(val);
}

int main (int argc , char *argv[])
{
	if (argc == 2)
	{
		print_som(argv[1]);
	}
	else 
	{
		ft_putchar ('\n');
	}
}


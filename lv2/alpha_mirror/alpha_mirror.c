#include <unistd.h>
void ft_putchar (char c)
{
	write (1,&c,1);
}

int check_index (char c)
{
	char lo[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char up[] = "abcdefghijklmnopqrstuvwxyz";
	int i = 0;
	while (lo[i] || up[i])
	{
		if (lo[i] == c)
		{
			return i;
		}
		else if (up[i] == c)
		{
			return i;
		}
		i++;
	}
	return 0;
}

int ft_strlen (char *str)
{
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return i;
}	

void check_check (char *str)
{
	char lo[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 	char up[] = "abcdefghijklmnopqrstuvwxyz";
	int i = 0;
	int val ;
	int nbr = ft_strlen (up) - 1;
	int res ;
	while (str[i])
	{	
		val = check_index (str[i]);
		res = nbr - val;
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			ft_putchar (up[res]);
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			ft_putchar (lo[res]);
		}
		else 
		{
			ft_putchar (str[i]);
		}
		i++;
	}
	ft_putchar ('\n');
}
// hello

int main (int argc , char *argv[])
{
	if (argc == 2)
	{
		check_check (argv[1]);
	}
	else 
	{
		ft_putchar ('\n');
	}
}

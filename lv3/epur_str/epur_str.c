#include <unistd.h>
void ft_putchar (char c)
{
	write (1,&c,1);
}

int check_str (char c)
{
	if (c == ' ')
	{
		return 1;
	}
	return 0;
}
void check (char *str)
{
	int i = 0;
	int j = 0;
	int first = 1;
	while (str[i])
	{
		i++;
	}

	if (check_str(str[0]) == 1)
	j++;
	if (check_str(str[i - 1]) == 1)
	i--;


	while (j < i)
	{
		if (str[j] == ' ' && first == 1)
		{
				ft_putchar (' ');
				first = 0;
		}
		else if ((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z'))
		{
			first = 1;
			ft_putchar (str[j]);
		}
		j++;
	}
	ft_putchar ('\n');
}

// "hh       hello    brother "
int main (int argc , char *argv[])
{	
	if (argc == 2)
	{
		check (argv[1]);
	}
	else 
	{
		ft_putchar ('\n');
	}
}

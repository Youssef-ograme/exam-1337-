#include <unistd.h>
void ft_putchar (char c)
{
    write (1,&c,1);
}

int ft_atoi (char *str)
{
    int i = 0;
    int res = 0;
    int val ;
    int signe = 1;
    while (str[i] == ' ' || str[i] == '\t')
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
        val = str[i] - '0';
        res = (res * 10) + val;
        i++;
    }
    return res * signe;
}

void check_programe(int nbr , char *base)
{
    if (nbr < 0)
    {
        nbr = -nbr;
    }
    if (nbr >= 16)
    {
        check_programe(nbr / 16 , base);
    }
    ft_putchar(base[nbr % 16]);
}

void programe (char *src , char *base)
{
    int nbr = ft_atoi (src);
    check_programe(nbr , base);
}

int main (int argc , char *argv[])
{
    if (argc == 2)
    {
        char base[] = "0123456789abcdef";
        programe(argv[1],base);
    }
    ft_putchar('\n');
}
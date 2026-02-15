#include <stdlib.h>
#include <stdio.h>
int size_degits (int nbr)
{
    int count = 0;
    if (nbr < 0)
    {
        nbr = -nbr;
        while (nbr > 0)
        {
            count++;
            nbr /= 10;
        }
        count = count + 1;
        return count;
    }

    else if (nbr > 0)
    {
        while (nbr > 0)
        {
            count++;
            nbr /= 10;
        }
        return count;
    }
}

char    *ft_itoa(int nbr)
{
    int size = size_degits(nbr);
    char *str = malloc ((size + 1) * sizeof (char));
    if (str == NULL)
    {
        return NULL;
    }

    if (nbr < 0)
    {
        str[0] = '-';
        nbr = -nbr;
    }

    char val;
    int fine = size;
    size = size -1;
    while (nbr > 0)
    {
        val = (nbr % 10) + 48;
        str[size] = val;
        size--;
        nbr /= 10;
    }
    str[fine] = '\0';
    return str;
}

int main ()
{
    printf ("%s",ft_itoa(-1000000000));
}
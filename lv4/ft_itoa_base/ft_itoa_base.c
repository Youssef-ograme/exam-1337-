#include <stdio.h>
#include <stdlib.h>
int check_negative_value(int value ,int base)
{
    if (base < 2 || base > 16)
    {
        return 0;
    }
    int count =  0;
    if (value < 0)
    {
        value = -value;
        while (value > 0)
        {
            count++;
            value /= base;
        }
        count += 1;
        return count;

    }
    else if (value > 0)
    {
        while (value > 0)
        {
            count++;
            value /= base;
        }
        return count;
    }
}

char    *ft_itoa_base(int value, int base)
{
    int size = check_negative_value(value, base);
    int max ;
    char base_str[16] = "0123456789ABCDEF";
    char *str = malloc ((size + 1) * sizeof (char));
    if (str == NULL)
    {
        return NULL;
    }
    if (value < 0)
    {
        str[0] = '-';
        value = -value;
    }
    max = size;
    size = size - 1;
    while (value > 0)
    {
        str[size] = base_str[value % base];
        size--;
        value /= base;
    }
    str[max] = '\0';
    return str;
}

int main ()
{
    printf ("%s",ft_itoa_base(100,16));
}
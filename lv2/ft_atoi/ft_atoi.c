// "     +-123a912"
#include <stdio.h>
int ft_atoi (char *str)
{
    int i = 0;
    int singe = 1;
    int res = 0;
    int deg;

    while (str[i] == ' ' || str[i] == '\t')
    i++;
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
        {
            singe *= -1;
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        deg = str[i] -= 48;
        res = (res * 10) + deg;
        i++;
    }
    return res * singe;
}
int main ()
{
    char str[] = "     ---1w23s45";
    int res = ft_atoi(str);
    printf ("%d",res);
}
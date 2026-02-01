#include <unistd.h>

void ft_putchar (char c)
{
    write (1,&c,1);
}

int ft_strlen (char *str)
{
    int i = 0;
    while (str[i])
    i++;
    return i;
}

void check_upercess (char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
        i++;
    }
}

int check_space (char c)
{
    if (c == ' ' || c == '\t')
    {
        return 1;
    }
    return 0;
}

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
    ft_putchar('\n');
}

int check_laset (char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return 1;
    }
    return 0;
}

int check_degits (char c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    return 0;
}
void rstr_capitalizer (char *str)
{
    check_upercess(str);
    int i = 0;
    int new_world = 1;
    int size = ft_strlen (str);
    while (check_space(str[i]) != 0)
    {
        i++;
    }
    while (str[i])
    {
            if (check_degits(str[i]))
            i++;
            else if (check_space(str[i]) == 1 && new_world == 1)
            {
                i = i - 1;
                str[i] -= 32;
                i++;
                new_world = 0;
            }
            else if (check_laset(str[i]))
            {
                new_world = 1;
            }
            i++;
    }
    if (check_laset(str[size -1]))
    {
        str[size -1] -=32;
    }
    ft_putstr(str);
}

int main (int argc , char *argv[])
{
        int i = 1;
        while (i <= argc - 1)
        {
            rstr_capitalizer(argv[i]);
            i++;
        }
        if (argc == 1)
        {
            ft_putchar('\n');
        }
}
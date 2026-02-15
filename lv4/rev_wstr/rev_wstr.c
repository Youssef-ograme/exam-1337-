#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int ft_strlen (char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

int check_space (char c)
{
   return (c == ' ' || c == '\t') ? 1 : 0;
}

void ft_putchar (char c)
{
    write (1,&c,1);
}

int len_arges (char *str)
{
    int i = 0;
    int new_world = 1;
    int count = 0;
    while (str[i])
    {
        if (!check_space(str[i]) && new_world)
        {
            count++;   
            new_world = 0;
        }
        else if (check_space (str[i]))
        {
            new_world = 1;
        }
        i++;
    }
    return count;
}

char *ft_strdup (char *str)
{
    int size = ft_strlen(str);
    char *tab = malloc ((size + 1) * sizeof (char));
    int i = 0;
    while (str[i])
    {
        tab[i] = str[i];
        i++;
    }
    tab[i] = '\0';
    return tab;
}

char  **rev_wstr (char *str)
{
    int i = 0;
    int j = 0;
    int count = 0 ;
    int size_str = ft_strlen (str);
    int size_arges = len_arges(str);
    char *tab = malloc ((size_str + 1) * sizeof(char));
    char **wstr = malloc ((size_arges + 1) * sizeof(char *));
    if (wstr == NULL || tab == NULL)
    {
        return NULL;
    }
    while (check_space(str[i]))
    i++;
    while (str[i])
    {
        if (check_space(str[i]) != 1)
        {
            tab[j] = str[i];
            j++;
        }

        else if (j > 0)
        {
            tab[j] = '\0';
            wstr[count] = ft_strdup(tab);
            count++;
            j = 0;
        }
        i++;
    }


    if (j > 0)
    {
        tab[j] = '\0';
        wstr[count] = ft_strdup(tab);
        count++;
    }

    wstr[count] = NULL;
    free(tab);
    return wstr;
}

void print_res (char *src)
{
    char **str = rev_wstr (src);
    int size = len_arges(src);
    int i;
    size = size - 1;
    while (size >= 0)
    {
        i = 0;
        while (str[size][i])
        {
            ft_putchar(str[size][i]);
            i++;
        }
        if (size > 1)
        {
            ft_putchar (' ');
        }
        size--;
    }
}
int main (int argc , char *argv[])
{
    if (argc == 2)
    {
        print_res(argv[1]);
    }
    ft_putchar ('\n');
}
#include <unistd.h>
#include <stdlib.h>
int check_space (char c)
{
    return (c == ' ' || c == '\t');
}

void ft_putchar (char c )
{
    write (1,&c,1);
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

int count_worlds (char *str)
{
    int i = 0;
    int new_world = 1;
    int count = 0;
    while (str[i])
    {
        if(!check_space(str[i]) && new_world)
        {
            count++;
            new_world = 0;
        }
        else if (check_space(str[i]))
        {
            new_world = 1;
        }
        i++;
    }
    return count;
}

char *ft_strdup (char *str)
{
    int size = ft_strlen (str);
    char *dest = malloc ((size + 1) * sizeof(char));
    if (dest == NULL)
    {
        return NULL;
    }
    int i = 0;
    while (str[i])
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char **link_rostring (char *str)
{
    int i = 0;
    int j = 0;
    int count  = 0;
    int len_world = count_worlds(str);
    int len_str = ft_strlen (str);
    char **rostr = malloc ((len_world + 1) * sizeof (char *));
    char *tab = malloc ((len_str + 1) * sizeof (char));
    if (tab == NULL || rostr == NULL)
    {
        return NULL;
    }
    while (check_space(str[i]))
    i++;
    while (str[i])
    {
        if (!check_space(str[i]))
        {
            tab[j] = str[i];
            j++;
        }
        else if (j > 0)
        {
            tab[j] = '\0';
            rostr[count] = ft_strdup(tab);
            count++;
            j = 0;
        }
        i++;
    }
    if (j > 0)
    {
            tab[j] = '\0';
            rostr[count] = ft_strdup(tab);
            count++;
    }
    rostr[count] = NULL;
    free(tab);
    return rostr;
}
//"le temp hello brother NULL"
void rostring (char *str)
{
    char **rostr = link_rostring(str);
    int size = count_worlds(str);
    int i = 1;
    int j ;
    size = size - 1;
    while (i <= size)
    {
        j = 0;
        while (rostr[i][j])
        {
            ft_putchar (rostr[i][j]);
            j++;
        }
        ft_putchar (' ');
        i++;
    }
    j = 0;
    while (rostr[0][j])
    {
        ft_putchar (rostr[0][j]);
        j++;
    }
}

int main (int argc , char *argv[])
{
    if (argc == 2)
    {
        rostring(argv[1]);
    }
    ft_putchar ('\n');
}
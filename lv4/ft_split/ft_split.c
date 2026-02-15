#include <stdio.h>
#include <stdlib.h>
int check_space (char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
    {
        return 1;
    }
    return 0;
}

int count_world (char *str)
{
    int i = 0;
    while (str[i] && check_space(str[i]) != 1)
    {
        i++;
    }
    return i;
}

int count_arges (char *str)
{
    int i = 0;
    int count = 0;
    int new_world = 1;

    while (str[i])
    {
        if (check_space(str[i]) != 1 && new_world == 1)
        {   
            count++;
            new_world = 0;
        }
        else if (check_space(str[i]) == 1)
        {
            new_world = 1;
        }
        i++;
    }
    return count;
}

char *ft_strcpy (char *str)
{
    int size = count_world (str);
    char *dest = malloc ((size + 1) * sizeof (char));
    int i = 0;
    if (dest == NULL)
    {
        return NULL;
    }
    while (i < size)
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char    **ft_split(char *str)
{
    int size = count_arges (str);
    int index = 0;
    char **tab = malloc ((size + 1) * sizeof (char *));
    int i = 0;
    while (str[i])
    {
            while (str[i] && check_space(str[i]))
            i++;
            if (str[i] != '\0')
            {
                tab[index] = ft_strcpy(&str[i]);
                if (tab == NULL)
                {
                    int j = 0;
                    while (j < size)
                    {
                        free(tab[j]);
                        j++;
                    }
                    free(tab);
                    return NULL;
                }
            }
            index++;
            i += count_world(&str[i]);
    }
    printf ("index : %d \n",index);
    tab[index] = NULL;
    return tab;
}
int main ()
{
    char str[] = "\n hell\no   wdskj klsdjxk kjdklxm jdsax sjadxm  world\n";
    char **tab = ft_split(str);
    int i = 0;
    while (tab[i] != NULL)
    {
        printf ("%s \n",tab[i]);
        i++;
    }
}
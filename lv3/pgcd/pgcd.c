#include <stdio.h>
#include <stdlib.h>
int ft_atoi (char *str)
{
    int i = 0;
    int signe = 1;
    int value ;
    int res = 0;
    while (str[i] == ' ' || str[i] == '\t')
    i++;

    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
        {
            signe *=-1;
        }
        i++;
    }
    
    while (str[i] >= '0' && str[i] <= '9')
    {
        value = str[i] - 48;
        res = (res * 10) + value;
        i++;
    }
    return signe * res;

}

int size_pgcd (int nbr)
{
    int i = 1;
    int count = 0;
    while (i <= nbr)
    {
        if (nbr % i == 0)
        {
            count++;
        }
        i++;
    }
    return count;
}

int *arr_pgcd (int nbr , int *size)
{
    int i = 1;
    *size = size_pgcd(nbr);
    int *arr = malloc ((*size) * sizeof (int));
    if (arr == NULL)
    {
        return NULL;
    }

    int j = 0;
    while (i <= nbr)
    {
        if (nbr % i == 0)
        {
            arr[j++] = i;
        }
        i++;
    }
    return arr;
}

int count_pgcd (int val1 , int val2)
{
    int z1 ;
    int z2;
    int *tab1 = arr_pgcd(val1 ,&z1);
    int *tab2 = arr_pgcd(val2 ,&z2);
    int count = 0;
    int i = 0;
    int j ;
    while (i < z1)
    {
        j = 0;
        while (j < z2)
        {
            if (tab1[i] == tab2[j])
            {
                count++;
            }
            j++;
        }
        i++;
    }
    return count;
}

int *check_pgcd (int val1 , int val2)
{
    int i = 0;
    int j ;
    int k = 0;
    int s1;
    int s2;
    int *tab1 = arr_pgcd(val1 ,&s1);
    int *tab2 = arr_pgcd(val2, &s2);
    int size = count_pgcd(val1,val2);
    int *arr = malloc (size * sizeof (int));
    if (arr == NULL)
    {
        return NULL;
    }
    while (i < s1)
    {
        j = 0;
        while (j < s2)
        {
            if (tab1[i] == tab2[j])
            {
                arr[k] = tab1[i];
                k++;
            }
            j++;
        }
        i++;
    }
    free(tab1);
    free(tab2);
    return arr;
}

int check_max (unsigned int val1 , unsigned int val2 )
{
    int size ;
    int *tab = check_pgcd(val1,val2);
    int count = count_pgcd(val1,val2);
    int max = tab[0];
    int i = 0;
    while (i < count)
    {
        if (tab[i] >= max)
        {
            max = tab[i];
        }
        i++;
    }
    free(tab);
    return max;
}

int check_programe (char *str1 , char *str2)
{
    int val1 = ft_atoi(str1);
    int val2 = ft_atoi(str2);
    return check_max(val1,val2);
}

int main (int argc , char *argv[])
{
    int res = check_programe(argv[1],argv[2]);
    if (argc == 3)
    {
        printf ("%d",res);
    }
    printf ("\n");
   
}
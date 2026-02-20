#include <stdio.h>
#include <stdlib.h>

int is_number (char c)
{
    if (c >= '0' && c <= '9' || c == ' ' || c == '-')
    {
        return 1;
    }
    return 0;
}

int check_space (char c)
{
    return (c == ' ' || c == '\t');
}

int check_numbers (const char *str)
{
    int i = 0;
    while (str[i])
    {
        if (!is_number(str[i]))
        {
            return 1;
        }
        i++;
    }
    return 0;
}

// "01 23 24 33 22 44 34"
int size_of_array (const char *str)
{
    int i = 0;
    int new_world = 1;
    int count = 0;
    while (str[i])
    {
        if (check_space(str[i]) != 1 && new_world == 1)
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

int ft_atoi (char *str)
{
    int i = 0;
    int res = 0 ;
    int val ;
    int signe = 1;
    if (str[i] == '-')
    {
        signe = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        val = str[i] - 48;
        res = (res * 10) + val;
        i++;
    }
    return res * signe;
}

int ft_strlen (const char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

int *transform_array (const char *str , int size)
{
    int *arr = malloc (size * sizeof (int));
    char *tab = malloc (ft_strlen(str) + 1);
    int i = 0;
    int j = 0;
    int count = 0;
    while (str[i])
    {
        if (!check_space(str[i]))
        {
            tab[j++] = str[i];
        }

        else if (j > 0)
        {
            tab[j] = '\0';
            arr[count++] = ft_atoi(tab);
            j = 0;
        }
        i++;
    }

    if (j > 0)
    {
        tab[j] = '\0';
        arr[count++] = ft_atoi(tab);
    }
    free(tab);
    return arr;
}

void swap (int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int *ft_sort(const char *str , int size)
{
    
    int i = 0;
    int *arr = transform_array(str , size);
    int k = 0;
    int j ;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] < arr[j])
            {
                swap(&arr[i] , &arr[j]);
            }
            j++;
        }
        i++;
    }
    return arr;
}

int len_numbers (int nbr)
{
    int count = 0;
    if (nbr < 0)
    {
        nbr = -nbr;
    }

    while (nbr > 0)
    {
        count++;
        nbr /= 10;
    }
    return count;
}

void rev_array (int *arr , int size)
{
    int i = 0;
    int temp ;
    while (i < size / 2)
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
        i++;
    }
}

char *orderWeight(const char *str)
{
    if (check_numbers(str))
    {
        return NULL;
    }
    int size = size_of_array(str);
    int *arr = ft_sort(str,size);
    int len_s = ft_strlen (str);
    int i = 0;
    int val ;
    int j;
    int len;
    char *src = malloc (len_s + 1);
    int l = 0;
    int nb;
    int k ;
    while (i < size)
    {
        j = 0;
        val = arr[i];
        if (val < 0)
        {
            src[l++] = '-';
            val = -val;
        }
        len = len_numbers(arr[i]);
        int tab[len];
        if (val == 0)
        {
            tab[j++] = 0;
        }
        while (val > 0)
        {
            tab[j++] = val % 10;
            val /= 10;
        }
        rev_array(tab , len);
        k = 0;
        while (k < len)
        {
            nb = tab[k];
            src[l++] = nb + 48;
            k++;
        }
        src[l++] = ' ';
        i++;
    }
    src[l] = '\0';
    return src;
}
int main () 
{ 
    char str[] = "-60 -700 -90";
    printf ("%s",orderWeight(str));
    // output : -60 -90 -700
}


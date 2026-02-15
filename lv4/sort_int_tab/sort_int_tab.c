#include <stdio.h>
void ft_swap (int *a, int *b)
{
    int temp ;
    temp = *a ;
    *a = *b;
    *b = temp;
}
void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i = 0;
    unsigned int j ;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (tab[i] >= tab[j])
            {
                ft_swap (&tab[i],&tab[j]);
            }
            j++;
        }
        i++;
    }
}

int main ()
{
    int tab[] = {9,0,-1,3,2,4,5,5};
    int size = 8;
    sort_int_tab(tab,size);
    int i = 0;
    while (i < size)
    {
        printf ("%d",tab[i]);
        i++;
    }
}
#include <stdio.h>
// pwwkew
int lengthOfLongestSubstring(char* s) 
{
    int i = 0;
    int k = 0;
    int j;
    int max = 0;
    while (s[i])
    {
        j = k;
        while (j < i)
        {
            if (s[j] == s[i])
            {
                k = j + 1;
            }
            j++;
        }

        int check = i - k + 1;
        if (check > max)
        {
            max = check;
        }
        i++;
    }
    return max;

}

int main ()
{
    char str[] = "aaaaa";
    printf("%d",lengthOfLongestSubstring(str));
}
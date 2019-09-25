/**
 * @date 5-13-2019
 * KVM algrom in pattern recognise
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *nextJ(char *c)
{
    //get the string size
    int size = 0;
    int p = 0;
    while (*(c + p++) != '\0')
        size++;
    //new the array
    int *next = (int *)malloc(size * sizeof(int));
    //the opt
    int k = -1, j = 0;
    next[j] = k;
    while (j < size - 1)
    {
        if (k == -1 || c[j] == c[k])
            next[++j] = ++k;
        else
            k = next[k];
    }
    return next;
}

int *nextJJ(char *p)
{
    //get the string size
    // int size = 0;
    // int p = 0;
    // while (*(c + p++) != '\0')
    //     size++;
    int size = strlen(p);
    //the array next
    int *next = (int *)malloc(size * sizeof(int));
    //the opt
    int k = -1, j = 0;
    next[j] = k;
    while (j < size - 1)
    {
        if (k == -1 || p[j] == p[k])
        {
            if (p[++j] == p[++k]) //改进之处:相等时要跳过
                next[j] = next[k];
            else
                next[j] = k;
        }
        else
            k = next[k];
    }
    return next;
}

int KMP(char *s, char *p)
{
    int s_len = strlen(s);
    int p_len = strlen(p);
    int i = 0; //source string index
    int j = 0; //pattern string index
    int *next = nextJJ(p);
    while (i < s_len && j < p_len)
    {
        if (j == -1 || s[i] == p[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    //return the index;
    if (j == p_len)
        return i - j;
    else
        return 0;
}

int main()
{
    char *s = "acabaabaabcacaabc";
    char *p = "abaabcac";
    int pos = KMP(s, p);
    printf("%d", pos);
    return 0;
}
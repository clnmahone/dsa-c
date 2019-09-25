#include <stdio.h>
#include<stdlib.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *countAndSay(int n)
{
    if (n == 1)
        return "1";

    char *res = (char *)malloc(2);
    char *temp;

    res[0] = '1';
    res[1] = '\0';

    int group = 1;
    int j, len, count;
    for (int ii = 2; ii <= n; ii++)
    {
        len = strlen(res);

        for (int i = 1; i < len; i++)
            if (res[i - 1] != res[i])
                group++;

        temp = (char *)calloc(group * 2 + 1, sizeof(char));

        group = 1;
        count = 1;
        j = 0;

        for (int i = 0; i < len - 1; i++)
        {
            if (res[i] == res[i + 1])
                count++;
            else
            {
                temp[j++] = '0' + count;
                temp[j++] = res[i];
                count = 1;
            }
        }
        temp[j++] = '0' + count;
        temp[j++] = res[len - 1];
        free(res);
        res = temp;
    }

    return res;
}



int main(){

    printf("%s",countAndSay(23));
    return 0;
}
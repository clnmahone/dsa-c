#include <stdio.h>
#include <math.h>

int main()
{
    int f(int n);
    int n = 1000;
    int flag = 0;
    while (n--)
    {
        flag = (n * n - n) % f(n);
        if (flag == 0)
        {
            printf("%d * %d = %d\n", n, n, n * n);
        }
    }

    return 0;
}

int f(int n)
{
    int i = 0;
    while (n)
    {
        n /= 10;
        i++;
    }
    return pow(10, i);
}

#include <stdio.h>

int main()
{

    void hanoi(int n, char one, char two, char three);
    hanoi(3, 'A', 'B', 'C');
    return 0;
}

void hanoi(int n, char one, char two, char three)
{
    void move(char one, char two);

    if (n == 1)
    {
        move(one, three);
    }
    else
    {
        hanoi(n - 1, one, three, two);
        move(one, three);
        hanoi(n - 1, two, one, three);
    }
}

void move(char one, char two)
{
    printf("%c->%c\n", one, two);
}
#include <cstdio>
#include <cstdlib>
#include <ctime>

void foo()
{
    puts("true");
}

void bar()
{
    puts("false");
}

int main()
{
    srand(time(NULL));

    int c = rand() % 10;
    int i = rand() % 10;

    c = c * i;

    if (c > 0)
        foo();
    else
        bar();

    return 0;
}

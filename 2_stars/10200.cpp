#include <cstdio>
#include <cmath>

using namespace std;

bool IsPrime(int i)
{
    if (i == 0) 
        return false;

    if (i == 2 || i == 1)
        return true;

    int ubound = (int)sqrt((double)i);

    for (int j = 2; j <= ubound; j++) {
        if (i % j == 0)
            return false;
    }

    return true;
}

bool prime_table[10001] = {};

int main()
{
    for (int i = 0; i < 40; i++)
        prime_table[i] = true;

    for (int i = 41; i <= 10000; i++) {
        prime_table[i] = IsPrime((i*i) + i + 41);
    }

    int a, b;
    while (scanf("%d %d", &a, &b) == 2) {
        int x = 0;

        for (int i = a; i <= b; i++) {
            if (prime_table[i])
                x++;
        }

        double d = (((double)x * 100) / (b - a + 1));
        double ans = floor((d + 0.005)*100);

        printf("%.2f\n", ans / 100);
    }
	return 0;
}

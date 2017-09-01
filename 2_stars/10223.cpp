#include <cstdio>

using namespace std;

unsigned table[19] = {
    1,
    2,
    5,
    14,
    42,
    132,
    429,
    1430,
    4862,
    16796,
    58786,
    208012,
    742900,
    2674440,
    9694845,
    35357670,
    129644790,
    477638700,
    1767263190,
};

unsigned f(unsigned n)
{
    if (n == 1 || n == 2)
        return n;

    if (n == 3)
        return 5;

    unsigned t = 2 * f(n-1);
    unsigned tmp = 0;
    for (unsigned i = 1; i <= (n-2)/2; i++) {
        tmp += f(i) * f(n-1-i);
    }
    t += 2 * tmp;

    if (n % 2 != 0) {
        tmp = f(n/2);
        t += tmp * tmp;
    }

    return t;
}

int main()
{
    unsigned n = 0;
    while (scanf("%u", &n) == 1) {
        for (int i = 0; i < 19; i++) {
            if (table[i] == n) {
                printf("%d\n", i + 1);
                break;
            }
        }
    }

	return 0;
}

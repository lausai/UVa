#include <cstdio>
#include <climits>

using namespace std;

unsigned gcd(unsigned a, unsigned b)
{
    unsigned max = a;
    unsigned min = b;

    if (a < b) {
        min = a;
        max = b;
    }

    if (max % min == 0)
        return min;
    else
        return gcd(min, (max % min));
}

int main()
{
    int n = 0;

    while (scanf("%d", &n), n != 0) {
        unsigned c1, n1, c2, n2;

        scanf("%u %u", &c1, &n1);
        scanf("%u %u", &c2, &n2);
        
        unsigned gcd_ = gcd(n1, n2);

        if (n % gcd_ != 0) {
            puts("failed");
            continue;
        }

        unsigned m1 = 1;
        unsigned m2 = 0;
        unsigned t1 = 1;
        unsigned price = INT_MAX;

        while (n1 * t1 < n) {
            unsigned i = n - (n1 * t1);

            if (i % n2 == 0) {
                unsigned t2 = i / n2;
                unsigned p = (c1 * t1) + (c2 * t2);

                if (p < price) {
                    price = p;
                    m1 = t1;
                    m2 = t2;
                }
            }

            t1++;
        }

        if (price == INT_MAX)
            puts("failed");
        else
            printf("%u %u\n", m1, m2);
    }

	return 0;
}

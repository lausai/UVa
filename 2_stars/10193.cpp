#include <cstdio>
#include <cstdlib>

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
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        char s1[64] = {};
        char s2[64] = {};

        fgets(s1, sizeof(s1) - 1, stdin);
        fgets(s2, sizeof(s2) - 1, stdin);

        unsigned s1u = strtoul(s1, NULL, 2);
        unsigned s2u = strtoul(s2, NULL, 2);
        if (gcd(s1u, s2u) > 1) {
            printf("Pair #%d: All you need is love!\n", i);
        } else {
            printf("Pair #%d: Love is not all you need!\n", i);
        }
    }
	return 0;
}

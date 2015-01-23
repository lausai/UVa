#include <cstdio>
#include <cmath>

using namespace std;

unsigned long long AddN(unsigned long long n)
{
    return (n * (n+1)) / 2;
}

int main()
{
    unsigned long long n = 0;

    while (scanf("%llu", &n) != EOF) {
        unsigned long long i = sqrt((long double)n * 2);
        
        while (AddN(i) < n)
            i++;

        unsigned long long idx = n - AddN(i-1);
//        printf("%u\n", idx);
        printf("%llu/%llu\n", i-idx+1, idx);
    }

	return 0;
}

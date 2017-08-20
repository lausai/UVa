#include <cstdio>

using namespace std;

int main()
{
    long round = 0;
    scanf("%ld", &round);

    for (int i = 0; i < round; i++) {
        unsigned long long s = 0;
        scanf("%lld", &s);

        unsigned long long n = ((s + 1) * (s + 1)) - 1;
        printf("%lld\n", n);
    }
	return 0;
}

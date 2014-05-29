#include <cstdio>

int main()
{
	long long w1, w2;

	while (EOF != scanf("%lld %lld", &w1, &w2)) {
		long long result = (w1 > w2) ? w1-w2 : w2-w1;
		printf("%lld\n", result);
	}

	return 0;
}
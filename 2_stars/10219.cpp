# define _USE_MATH_DEFINES

#include <cstdio>
#include <cmath>

using namespace std;

const double eular = 2.71828182845904523536;

double log_stirling(double n)
{
    return log10(sqrt(2 * M_PI * n)) + (n * log10(n / eular));
}

int main()
{
    int n = 0, k = 0;
    while (scanf("%d %d", &n, &k) == 2) {
        printf("%d\n", (int)ceil(log_stirling(n) - log_stirling(k) - log_stirling(n - k)));
    }
	return 0;
}

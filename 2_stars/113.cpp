#include <cstdio>
#include <cmath>

int main()
{
	double n, p;

	while (scanf("%lf %lf", &n, &p) == 2)
		printf("%.0f\n", pow(p, (double)1/n));

	return 0;
}
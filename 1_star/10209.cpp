#include <cstdio>
#include <cmath>

#define PI    (2.0*acos(0.0))
#define A1(a) (2 * (a*a/2 - a*a*sqrt(3.0)/8 - a*a*PI/12))
#define A(a)  (A1(a) * 4)
#define B(a)  (4 * (a*a - a*a*PI/4 - 2*A1(a)))
#define C(a)  (a*a - A(a) - B(a))

int main()
{
	double d;

	while (EOF != scanf("%lf", &d))
		printf("%.3lf %.3lf %.3lf\n", C(d), B(d), A(d));

	return 0;
}
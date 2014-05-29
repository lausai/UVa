#include <cstdio>

using namespace std;

int n = 0;
double a0 = 0, an1 = 0;
double c[3002] = {};

double SumC(int num)
{
    double ret = 0;

    for (int i = 1; i <= num; i++)
        ret += c[i] * (num - i + 1);

    return 2 * ret;
}

int main()
{
    int num = 0;

    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        scanf("%d", &n);
        scanf("%lf", &a0);
        scanf("%lf", &an1);
        
        // start from index 1        
        for (int j = 1; j <= n; j++)
            scanf("%lf", &c[j]);
       
        double a1 = (an1 + (n * a0) - SumC(n)) / (n + 1);
        if (i > 0) puts("");
        printf("%.2f\n", a1);

    }

	return 0;
}

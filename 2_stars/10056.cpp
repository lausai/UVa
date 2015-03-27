#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int s = 0;
    scanf("%d", &s);

    for (int i = 0; i < s; i++) {
        int n, l;
        double p;

        scanf("%d %lf %d", &n, &p, &l);
        if (p == 0) {
            printf("0.0000\n");
        } else {
            double d = p * pow(1-p, l-1) * (1 / (1 - pow(1-p, n)));
            printf("%.4f\n", d);
        }
    }

	return 0;
}

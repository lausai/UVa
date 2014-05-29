#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int n = 0;

    while (scanf("%d", &n) != EOF) {
        int tmp = (int)sqrt((double)2 * n);

        while ((tmp * (tmp + 1)) < (2 * n))
            tmp++;
        
        int num = n - (tmp * (tmp - 1) / 2);
        int den = tmp + 1 - num;

        if (tmp % 2 == 0)
            printf("TERM %d IS %d/%d\n", n, num, den);
        else
            printf("TERM %d IS %d/%d\n", n, den, num);
    }

	return 0;
}

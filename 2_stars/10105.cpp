#include <cstdio>

using namespace std;

int C(int a, int b)
{
    if (b == 0) return 0;
    if (b == 1) return a;

    int m = 1;
    for (int i = a; i > b; i--)
        m *= i;

    int n = 1;
    for (int i = 1; i <= a - b; i++)
        n *= i;

    return m/n;
}

int main()
{
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        int num = 0;
        int ans = 1;

        for (int i = 0; i < k; i++) {
            scanf("%d", &num);

            if (num == 0) 
                continue;

            ans *= C(n, num);
            n -= num;
        }
        printf("%d\n", ans);
    }

	return 0;
}

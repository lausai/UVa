#include <cstdio>
#include <algorithm>

using namespace std;

bool Compute(int N, int* a, int* b)
{
    for (int i = 9; i > 0; i--) {
        int c = N % i;

        if (c == 0) {
            *a = i;
            *b = N / i;
            return true;
        }
    }

    return false;
}

int main()
{
    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int N;
        int ans[16] = {};
        scanf("%d", &N);
        int a, b = N;
        int ansLen = 0;

        if (N == 1 || N == 0) {
            printf("%d\n", N);
            continue;
        }

        while (Compute(b, &a, &b) && a != 1) {
            ans[ansLen] = a;
            ansLen++;
        }

        if (b != 1) {
            puts("-1");
            continue;
        }

        sort(ans, ans + ansLen);

        for (int j = 0; j < ansLen; j++)
            printf("%d", ans[j]);

        puts("");
    }

	return 0;
}

#include <cstdio>
#include <cmath>

int arr[500000] = {};

int main()
{
    int x;
    while (scanf("%d", &x) != EOF) {
        char c;
        int a;
        int cnt = 0;
        while (scanf("%d%c", &a, &c)) {
            arr[cnt] = a;
            cnt++;
            if (c == '\n') break;
        }

        long long result = 0;
        for (int i = 0; i < cnt - 1; i++) {
            long long tmp = (long long)arr[i] * (cnt - i - 1);
            result = result * x + tmp;
        }
        printf("%lld\n", result);
    }

    return 0;
}

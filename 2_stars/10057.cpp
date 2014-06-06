#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    int n = 0;

    while (scanf("%d", &n) != EOF) {
        int* buf = (int*)malloc(sizeof(int) * n);

        for (int i = 0; i < n; i++)
            scanf("%d", &buf[i]);

        sort(buf, buf + n);

        int lidx = 0, ridx = 0;
        int sum = 0;

        if (n % 2 == 0) {
           lidx = (n / 2) - 1;
           ridx = n / 2;
        } else {
            lidx = ridx = n / 2;
        }

        for (int i = lidx; i >= 0; i--) {
            if (buf[lidx] == buf[i])
                sum++;

            if (buf[i] < buf[lidx]) break;
        }

        for (int i = ridx; i < n; i++) {
            if (buf[ridx] == buf[i])
                sum++;

            if (buf[i] > buf[ridx]) break;
        }

        if (n % 2 == 1)
            sum--;

        printf("%d %d %d\n", buf[lidx], sum, buf[ridx] - buf[lidx]+ 1);

        free(buf);
    }
	return 0;
}

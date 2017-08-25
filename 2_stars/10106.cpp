#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char x[252] = {};
    char y[252] = {};

    while (scanf("%s\n%s", x, y) == 2) {
        char ans[504] = {};
        int lenx = strlen(x);
        int leny = strlen(y);
        int max = 0;

        if ((lenx == 1 && x[0] == '0') || (leny == 1 && y[0] == '0')) {
            printf("0\n");
            continue;
        }

        for (int i = 0; i < lenx; i++) {
            int tx = x[lenx - i - 1] - '0';

            for (int j = 0; j < leny; j++) {
                int ty = y[leny - j - 1] - '0';
                int t = tx * ty;
                int jpi = j + i;

                max = jpi;
                ans[jpi] += (t % 10);
                if (ans[jpi] > 9) {
                    ans[jpi] -= 10;
                    ans[jpi + 1] += 1;
                    max = jpi + 1;
                }
                
                if (t >= 10) {
                    ans[jpi + 1] += (t / 10);
                    max = jpi + 1;
                    if (ans[jpi + 1] > 9) {
                        ans[jpi + 1] -= 10;
                        ans[jpi + 2] += 1;
                        max = jpi + 2;
                    }
                }
            }
        }

        while (max >= 0) {
            printf("%c", ans[max] + '0');
            max--;
        }
        puts("");
    }
	return 0;
}

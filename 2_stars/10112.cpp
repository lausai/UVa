#include <cstdio>
#include <cmath>

using namespace std;

double power(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return abs(0.5 * (((y3 - y1) * (x2 - x1)) - ((y2 - y1) * (x3 - x1))));
}

bool check(int i, int j, int k, int num, int t[][2], double d)
{
    for (int l = 0; l < num; l++) {
        if (l == i || l == j || l == k)
            continue;

        double t1 = power(t[l][0], t[l][1], 
            t[i][0], t[i][1], t[j][0], t[j][1]);
                
        double t2 = power(t[l][0], t[l][1], 
            t[i][0], t[i][1], t[k][0], t[k][1]);
                
        double t3 = power(t[l][0], t[l][1], 
            t[k][0], t[k][1], t[j][0], t[j][1]);
                
        if (t1 + t2 + t3 <= d)
            return false;
    }
    
    return true;
}

int main()
{
    int num = 0;
    while (scanf("%d", &num), num != 0) {
        char c[15][3] = {};
        int t[15][2] = {};

        for (int i = 0; i < num; i++) {
            scanf("%s %d %d", c[i], &t[i][0], &t[i][1]);
        }

        double max = 0.0;
        char ans[4] = {};

        for (int i = 0; i < num - 2; i++) {
            for (int j = i + 1; j < num - 1; j++) {
                for (int k = j + 1; k < num; k++) {
                    double tmp = power(t[i][0], t[i][1], 
                        t[j][0], t[j][1], t[k][0], t[k][1]);
                    
                    if (tmp > max) {
                        if (check(i, j, k, num, t, tmp)) {
                            max = tmp;
                            ans[0] = c[i][0];
                            ans[1] = c[j][0];
                            ans[2] = c[k][0];
                        }
                    }
                }
            }
        }

        printf("%s\n", ans);
    }
	return 0;
}

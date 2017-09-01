#include <cstdio>
#include <string.h>

using namespace std;

int main()
{
    int n = 0, m = 0;
    int round = 1;
    while (scanf("%d %d\n", &n, &m) && n != 0 && m != 0) {
        const int len = 105;

        char c[len] = {};
        char ans[len][len] = {};
        int x[len * len] = {};
        int y[len * len] = {};
        int num_point = 0;

        for (int i = 1; i <= 100; i++)
            memset(&ans[i][1], '0', 100);

        for (int i = 1; i <= n; i++) {
            fgets(c, len - 1, stdin);

            for (int j = 0; j < m; j++) {
                if (c[j] == '*') {
                    ans[i][j + 1] = '*';
                    x[num_point] = i;
                    y[num_point] = j + 1;
                    num_point += 1;
                }
            }
        }

        for (int i = 0; i < num_point; i++) {
            if (ans[x[i] - 1][y[i]] != '*')
                ans[x[i] - 1][y[i]]++;
            
            if (ans[x[i]][y[i] + 1] != '*')
                ans[x[i]][y[i] + 1]++;

            if (ans[x[i] + 1][y[i]] != '*')
                ans[x[i] + 1][y[i]]++;

            if (ans[x[i]][y[i]-1] != '*')
                ans[x[i]][y[i]-1]++;

            if (ans[x[i] - 1][y[i] - 1] != '*')
                ans[x[i] - 1][y[i] - 1]++;

            if (ans[x[i] - 1][y[i] + 1] != '*')
                ans[x[i] - 1][y[i] + 1]++;

            if (ans[x[i] + 1][y[i] + 1] != '*')
                ans[x[i] + 1][y[i] + 1]++;

            if (ans[x[i] + 1][y[i] - 1] != '*')
                ans[x[i] + 1][y[i] - 1]++;
        }
        
        const char* prefix = round > 1 ? "\n" : "";
        printf("%sField #%d:\n", prefix, round++);
        for (int i = 1; i <= n; i++) {
            ans[i][m+1] = 0;
            printf("%s\n", &ans[i][1]);
        }
    }
	return 0;
}

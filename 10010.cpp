#include <cstdio>
#include <cstring>

using namespace std;

void FindStr(char map[50][50], int m, int n, char* str, int* x, int* y)
{
    int len = strlen(str);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            
        }
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char map[50][50] = {};
        int m, n;

        scanf("%d %d", &m, &n);

        for (int j = 0; j < m; j++)
            scanf("%s", &map[j]);

        int k = 0;
        scanf("%d", &k);

        if (i > 0)
            puts("");

        for (int j = 0; j < k; j++) {
            char str[50] = {};
            int x, y;

            scanf("%s", str);
            FindStr(map, m, n, str, &x, &y);

            printf("%d %d\n", x, y);
        }
    }

	return 0;
}

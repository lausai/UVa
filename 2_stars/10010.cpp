#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

void FindStr(char map[50][50], int m, int n, char* str, int* x, int* y)
{
    int len = strlen(str);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int lr = n - j;
            int ll = j + 1;
            int lu = i + 1;
            int ld = m - i;
            bool find = true;
            
            *x = i;
            *y = j;

            if (lr >= len && lu >= len) {
                for (int k = 0; k < len; k++) {
                    if (toupper(map[i - k][j + k]) != toupper(str[k])) {
                        find = false;
                        break;
                    }
                }

                if (find)
                    return;
            }
            
            find = true;
            if (lr >= len && ld >= len) {
                for (int k = 0; k < len; k++) {
                    if (toupper(map[i + k][j + k]) != toupper(str[k])) {
                        find = false;
                        break;
                    }
                }

                if (find)
                    return;
            }

            find = true;
            if (ll >= len && lu >= len) {
                for (int k = 0; k < len; k++) {
                    if (toupper(map[i - k][j - k]) != toupper(str[k])) {
                        find = false;
                        break;
                    }
                }

                if (find)
                    return;
            }

            find = true;
            if (ll >= len && ld >= len) {
                for (int k = 0; k < len; k++) {
                    if (toupper(map[i + k][j - k]) != toupper(str[k])) {
                        find = false;
                        break;
                    }
                }

                if (find)
                    return;
            }

            find = true;
            if (lr >= len) {
                for (int k = 0; k < len; k++) {
                    if (toupper(map[i][j + k]) != toupper(str[k])) {
                        find = false;
                        break;
                    }
                }

                if (find)
                    return;
            }

            find = true;
            if (ll >= len) {
                for (int k = 0; k < len; k++) {
                    if (toupper(map[i][j - k]) != toupper(str[k])) {
                        find = false;
                        break;
                    }
                }

                if (find)
                    return;
            }

            find = true;
            if (lu >= len) {
                for (int k = 0; k < len; k++) {
                    if (toupper(map[i - k][j]) != toupper(str[k])) {
                        find = false;
                        break;
                    }
                }

                if (find)
                    return;
            }

            find = true;
            if (ld >= len) {
                for (int k = 0; k < len; k++) {
                    if (toupper(map[i + k][j]) != toupper(str[k])) {
                        find = false;
                        break;
                    }
                }

                if (find)
                    return;
            }
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

        for (int j = 0; j < m; j++) {
            scanf("%s", &map[j]);
        }
        
        int k = 0;
        scanf("%d", &k);

        if (i > 0)
            puts("");

        for (int j = 0; j < k; j++) {
            char str[50] = {};
            int x, y;

            scanf("%s", str);
            FindStr(map, m, n, str, &x, &y);

            printf("%d %d\n", x + 1, y + 1);
        }
    }

	return 0;
}

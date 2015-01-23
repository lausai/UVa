#include <cstdio>

using namespace std;

bool (*map)[102] = NULL;

int main()
{
    int round = 0;

    scanf("%d", &round);

    for (int i = 0; i < round; i++) {
        int x, y;
        char c;

        scanf("%d %d", &x, &y);
        bool _map[102][102] = {};
        int _ans[102][102] = {};
        map = _map;

        for (int j = 0; j < x; j++) {
            char buf[1024] = {};
            char* addr = buf;
            int _x = 0, _y = 0, n = 0;
            
            while (buf[0] == '\n' || buf[0] == 0)
                fgets(buf, sizeof(buf), stdin);

            sscanf(addr, "%d%n", &_x, &n);
            addr += n;

            while (sscanf(addr, "%d%n", &_y, &n) > 0) {
                addr += n;
                map[_x][_y] = true;
            }
        }

        for (int j = 1; j <= x; j++) {
            for (int k = 1; k <= y; k++) {
                if (map[j][k]) {
                    _ans[j][k] = 0;
                    continue;
                }

                if (j == 1 && k == 1) {
                    _ans[j][k] = 1;
                    continue;
                }

                if (j == 1 || k == 1) {
                    if (j == 2 || k == 2) {
                        _ans[j][k] = 1;
                        continue;
                    }
                }

                _ans[j][k] = _ans[j-1][k] + _ans[j][k-1];
            }
        }
        
        if (i > 0)
            puts("");
        
        _ans[1][1] = 1;
        printf("%d\n", _ans[x][y]);
    }

	return 0;
}

#include <cstdio>

using namespace std;

bool (*map)[100] = NULL;


int walk(int x, int y)
{
    if (x == 0 || y == 0)
        return 0;

    if (map[x - 1][y - 1])
        return 0;

    if (x == 1 && y == 1)
        return 1;

    if (x == 2 && y == 1)
        return 1;

    if (x == 1 && y == 2)
        return 1;

    if (x == 1)
        return walk(x, y - 1);

    if (y == 1)
        return walk(x - 1, y);

    return walk(x - 1, y) + walk(x, y - 1);
}

int main()
{
    int round = 0;

    scanf("%d", &round);

    for (int i = 0; i < round; i++) {
        int x, y;
        char c;

        scanf("%d %d", &x, &y);
        bool _map[100][100] = {};
        int _ans[100][100] = {};
        map = _map;

        for (int j = 0; j < x; j++) {
            int _x = 0, _y = 0;

            scanf("%d%c", &_x, &c);
            if (c == '\n')
                continue;

            while (c != '\n') {
                scanf("%d%c", &_y, &c);
                
                map[_x][_y] = true;
            }
        }

//        int ans = walk(x, y);

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

        printf("%d\n", _ans[x][y]);
    }

	return 0;
}

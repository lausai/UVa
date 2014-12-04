#include <cstdio>

using namespace std;

bool (*map)[1000] = NULL;


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
        bool _map[1000][1000] = {};
        map = _map;

//        map = new bool*[x]();
//        
//        for (int j = 0; j < x; j++)
//            map[j] = new bool[y]();

        for (int j = 0; j < x; j++) {
            int _x = 0, _y = 0;

            scanf("%d%c", &_x, &c);
            if (c == '\n')
                continue;

            while (c != '\n') {
                scanf("%d%c", &_y, &c);
                
                map[_x - 1][_y - 1] = true;
            }
        }

        int ans = walk(x, y);
        
        if (i > 0)
            puts("");

        printf("%d\n", ans);

//        for (int j = 0; j < x; j++)
//            delete [] map[j];
//
//        delete [] map;
    }

	return 0;
}

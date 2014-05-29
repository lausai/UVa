#include <cstdio>

using namespace std;

int main()
{
        int round = 0;

        while (scanf("%d", &round), round != 0) {
                int x, y;
                
                scanf("%d %d", &x, &y);
                for (int i = 0; i < round; i++) {
                        int x1, y1;

                        scanf("%d %d", &x1, &y1);
                        if (x1 == x || y1 == y)
                                puts("divisa");
                        else if (x1 > x && y1 > y)
                                puts("NE");
                        else if (x1 < x && y1 > y)
                                puts("NO");
                        else if (x1 < x && y1 < y)
                                puts("SO");
                        else
                                puts("SE");
                }
        }

	return 0;
}

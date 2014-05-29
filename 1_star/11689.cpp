#include <cstdio>

using namespace std;

int main()
{
        int round = 0;

        scanf("%d", &round);

        for (int i = 0; i < round; i++) {
                int e, f, c;

                scanf("%d %d %d", &e, &f, &c);
                
                int result = 0;

                for (int sodas = e + f; sodas >= c; sodas = (sodas%c) + (sodas/c))
                        result += sodas / c;

                printf("%d\n", result);
        }

	return 0;
}

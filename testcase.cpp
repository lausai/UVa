#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));

    int num = 20;
    printf("%d\n\n", num);

    for (int i = 0; i < num; i++) {
        int x = rand() % 30;
        int y = rand() % 30;

        printf("%d %d\n", x, y);

        for (int j = 0; j < x; j++) {
            printf("%d", j + 1);

            for (int k = 0; k < y; k++) {
                if (rand() % 10 == 0)
                    printf(" %d", k + 1);
            }

            puts("");
        }

        puts("");
    }
    return 0;
}

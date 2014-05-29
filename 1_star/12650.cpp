#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n = 0, R = 0;

    while (scanf("%d %d", &n, &R) != EOF) {
        int nums[10000] = {};

        for (int i = 0; i < R; i++) {
            int num = 0;

            scanf("%d", &num);
            nums[num] = 1;
        }
        
        bool hit = false;

        for (int i = 1; i <= n; i++) {
            if (nums[i] != 1) {
                printf("%d ", i);
                hit = true;
            }
        }

        if (hit == false)
            printf("*");

        puts("");
    }

	return 0;
}

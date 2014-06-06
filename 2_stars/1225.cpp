#include <cstdio>

using namespace std;

int main()
{
    int round = 0;

    scanf("%d", &round);

    for (int i = 0; i < round; i++) {
        int N = 0;
        int ans[11] = {};

        scanf("%d", &N);

        for (int j = 1; j <= N; j++) {
            int tmp = j;

            while (tmp != 0) {
                int idx = tmp % 10;
                ans[idx]++;
                tmp /= 10;
            }
        }

        printf("%d %d %d %d %d %d %d %d %d %d\n", 
                ans[0], ans[1], ans[2], ans[3], ans[4], ans[5], ans[6], ans[7], ans[8], ans[9]);
    }

	return 0;
}

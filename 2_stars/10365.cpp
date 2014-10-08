#include <cstdio>
#include <cmath>
#include <climits>

using namespace std;

int surface(int x, int y, int z)
{
    int tmp = (4 * x) + 2;

    tmp = (tmp * y) - (2 * x * (y - 1));
    tmp = (tmp * z) - (2 * (x * y) * (z - 1));

    return tmp;
}

int main()
{
    int n = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int N = 0;

        scanf("%d", &N);
        
        int ans = INT_MAX;

        for (int j = 1; j <= (int)sqrt((double)N); j++) {
            if (N % j != 0)
                continue;
            
            int limit = N / j;

            for (int k = j; k <= (int)sqrt((double)limit); k++) {
                if (limit % k != 0)
                    continue;
                
                int tmp = surface(j, k, limit / k);

                if (tmp < ans)
                    ans = tmp;
            }
        }

        printf("%d\n", ans);
    }

	return 0;
}

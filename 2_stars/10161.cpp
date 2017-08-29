#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int N = 0;
    while (scanf("%d", &N) == 1 && N != 0) {
        if (N == 1) {
            puts("1 1");
            continue;
        }

        int root = ceil(sqrt((double)N));
        int x = 0, y = 0;

        if (root % 2 == 0) {
            x = min(N - ((root - 1) * (root - 1)), root);
            y = min((root * root) - N + 1, root);
        } else {
            x = min((root * root) - N + 1, root);
            y = min(N - ((root - 1) * (root - 1)), root);
        }
        printf("%d %d\n", x, y);
    }

	return 0;
}

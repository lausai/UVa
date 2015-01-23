#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int S, A, F;
        int x_arr[50000] = {};
        int y_arr[50000] = {};
        scanf("%d %d %d", &S, &A, &F);

        for (int j = 0; j < F; j++)
            scanf("%d %d", &x_arr[j], &y_arr[j]);

        sort(x_arr, x_arr + F);
        sort(y_arr, y_arr + F);

        int idx = (F % 2 == 0) ? (F / 2) - 1 : (F / 2);
        printf("(Street: %d, Avenue: %d)\n", x_arr[idx], y_arr[idx]);
    }
	return 0;
}

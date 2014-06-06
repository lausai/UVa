#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    int round = 0;
    
    scanf("%d", &round);

    for (int i = 0; i < round; i++) {
        int r = 0;
        int arr[500] = {};

        scanf("%d", &r);

        for (int j = 0; j < r; j++)
            scanf("%d", &arr[j]);

        sort(arr, arr + r);
        
        int center = arr[r / 2];
        int sum = 0;

        for (int k = 0; k < r; k++)
            sum += abs(center - arr[k]);

        printf("%d\n", sum);
    }

	return 0;
}

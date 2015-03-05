#include <cstdio>
#include <cmath>

using namespace std;

int primeList[3501] = {};
int primeLen = 0;

bool IsPrime(int i)
{
    if (i == 2 || i == 1)
        return true;

    int ubound = (int)sqrt((double)i);

    for (int j = 2; j <= ubound; j++) {
        if (i % j == 0)
            return false;
    }

    return true;
}

int main()
{
    int p = 2;

    for (int i = 0; i < 3502; i++) {
        while (!IsPrime(p))
            p++;

        primeList[i] = p;
        p++;
    }

    int n = 0;

    while (scanf("%d", &n), n != 0) {
        int arr[3501] = {};

        for (int i = 0; i < n - 1; i++)
            arr[i] = i + 1;
        
        int idx = 0;

        for (int i = 0; i < n - 1; i++) {
            int s = primeList[i];
            int preidx = 0;
//            printf("%d %d\n", primeList[i], s);

            for (int j = 0; j < s - 1; j++) {
                preidx = idx;
                idx = arr[idx];
            }
            
            int tmp = idx;
//            printf("%d\n", idx);
            arr[preidx] = arr[idx];
            idx = arr[idx];
            arr[tmp] = -1;
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                printf("%d\n", i + 1);
                break;
            }
        }
    }
    
	return 0;
}

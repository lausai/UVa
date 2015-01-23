#include <cstdio>

using namespace std;

unsigned AddN(unsigned n)
{
    return ((n+1) * n) / 2;
}

int main()
{
    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        unsigned x, y;
        scanf("%u %u", &x, &y);
        unsigned j = 0;
        unsigned ans = 0;
        unsigned dis = y - x;
        while ((AddN(j) * 2) < dis)
            j++;
        
        ans = (j-1) * 2;
        
        if ((dis - (AddN(j-1) * 2)) == 0)
            ans = 0;
        else if ((dis - (AddN(j-1) * 2)) > j)
            ans += 2;
        else
            ans += 1;

        printf("%d\n", ans);
    }
	return 0;
}

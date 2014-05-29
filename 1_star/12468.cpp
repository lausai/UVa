#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int a = 0, b = 0;
    
    while (scanf("%d %d", &a, &b), a != -1 && b != -1) {
        if (a > b)
            swap(a, b);

        int ans1 = b - a;
        int ans2 = (99 - b) + (a - 0) + 1;
        
        printf("%d\n", ans1 < ans2 ? ans1 : ans2);
    }

	return 0;
}

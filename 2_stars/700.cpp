#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n = 0;
    int num = 1;
    while (scanf("%d", &n), n != 0) {
        int yi[20] = {};
        int ai[20] = {};
        int bi[20] = {};
        vector<int> v[20] = {};

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &yi[i], &ai[i], &bi[i]);
            
            int y = yi[i];

            while (y < 10000) {
                v[i].push_back(y);
                y += bi[i] - ai[i];
            }
        }
        
        bool findAns = false;
        int ans = 0;

        for (int i = 0; i < v[0].size(); i++) {
            int findCount = 0;

            for (int j = 0; j < n; j++) {
                if (find(v[j].begin(), v[j].end(), v[0][i]) != v[j].end())
                    findCount++;
            }

            if (findCount == n) {
                ans = v[0][i];
                findAns = true;
                break;
            }
        }
        
        printf("Case #%d:\n", num);

        if (findAns)
            printf("The actual year is %d.\n\n", ans);
        else
            puts("Unknown bugs detected.\n");

        num++;
    }
	return 0;
}

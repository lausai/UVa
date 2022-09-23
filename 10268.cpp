#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>

using namespace std;

int num_list[1000000/2] = {};

int main()
{

    int x = 0;
    while (scanf("%d\n", &x) == 1) {
        char line[1000003] = {};
        fgets(line, sizeof(line) - 1, stdin);
        char* start = line;
        int n = 0;
        int tmp = 0, len = 0;
        
        while (sscanf(start, "%d%n", &num_list[n], &len) == 1) {
            n++;
            start += len + 1;
        }

        n--;
        long ans = 0;
        start = line;
        for (int i = 0; i < n; i++) {
            long a = num_list[i];
            ans = (ans * x) + (a * (n - i));
        }
        printf("%ld\n", ans);
    }
	return 0;
}

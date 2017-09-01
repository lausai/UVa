#include <cstdio>
#include <set>

using namespace std;

int main()
{
    int round = 0;
    scanf("%d\n\n", &round);

    for (int i = 0; i < round; i++) {
        char line[16] = {};
        int P = 0, T = 0;

        fgets(line, sizeof(line) - 1, stdin);
        set<int> list[100];
        int ans = 0;
        int num = 0;
        while (fgets(line, sizeof(line) - 1, stdin) != NULL) {
            int i = 0, j = 0;
            if (sscanf(line, "%d %d", &i, &j) != 2)
                break;

            list[i-1].insert(j);
            num++;
        }

        for (int k = 0; i < num; i++) {
        }
    }

	return 0;
}

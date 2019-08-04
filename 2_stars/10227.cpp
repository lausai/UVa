#include <cstdio>
#include <set>

using namespace std;

int main()
{
    int round = 0;
    scanf("%d\n\n", &round);

    for (int i = 0; i < round; i++) {
        char line[16] = {};
        size_t P = 0, T = 0;

        fgets(line, sizeof(line) - 1, stdin);
        sscanf(line, "%u %u", &P, &T);

        set<int> list[100];
        set<int> p_set;
        while (fgets(line, sizeof(line) - 1, stdin) != NULL) {
            int i = 0, j = 0;
            if (sscanf(line, "%d %d", &i, &j) != 2)
                break;

            list[i-1].insert(j);
            p_set.insert(i-1);
        }

        set<int>::iterator itor = p_set.begin();
        set<set<int> > ans;
        for (; itor != p_set.end(); itor++) {
            ans.insert(list[*itor]);
        }


        const char* prefix = i == 0 ? "" : "\n";
        printf("%s%d\n", prefix, p_set.size() == P ? ans.size() : ans.size() + 1);
    }

	return 0;
}

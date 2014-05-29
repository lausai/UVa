#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
        int round = 0;

        scanf("%d", &round);

        for (int i = 0; i < round; i++) {
                int edge1, edge2, edge3;

                scanf("%d %d %d", &edge1, &edge2, &edge3);

                vector<int> edges;
                edges.push_back(edge1);
                edges.push_back(edge2);
                edges.push_back(edge3);

                sort(edges.begin(), edges.end());

                if (edges[1] <= edges[2] - edges[0])
                        puts("Wrong!!");
                else
                        puts("OK");
         }

	return 0;
}

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
        int num = 0;

        scanf("%d", &num);

        for (int i = 0; i < num; i++) {
                int edge1, edge2, edge3;

                scanf("%d %d %d", &edge1, &edge2, &edge3);

                vector<int> edges;
                edges.push_back(edge1);
                edges.push_back(edge2);
                edges.push_back(edge3);

                sort(edges.begin(), edges.end());

                if (edges[1] <= edges[2] - edges[0]) {
                        printf("Case %d: Invalid\n", i + 1);
                } else {
                        if (edges[0] == edges[1] && edges[1] == edges[2])
                                printf("Case %d: Equilateral\n", i + 1);
                        else if (edges[0] == edges[1] || edges[0] == edges[2] || edges[1] == edges[2])
                                printf("Case %d: Isosceles\n", i + 1);
                        else
                                printf("Case %d: Scalene\n", i + 1);
                }
        }

	return 0;
}

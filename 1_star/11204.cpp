#include <cstdio>

using namespace std;

int main()
{
        int round = 0;
        
        scanf("%d", &round);
        while (round-- > 0) {
                int N, M;

                scanf("%d %d", &N, &M);

                int num_of_favorite[32] = {0};

                for (int i = 0; i < M; i++) {
                        for (int j = 0; j < N; j++) {
                                int tmp = 0;

                                scanf("%d", &tmp);
                                if (tmp == 1)
                                        ++num_of_favorite[j];
                        }
                }
                
                int dis = 1;
                for (int i = 0; i < N; i++) {
                        if (num_of_favorite[i] > 1)
                                dis *= num_of_favorite[i];
                }

                printf("%d\n", dis);
        }
	return 0;
}

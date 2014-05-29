#include <cstdio>

using namespace std;

int main()
{
        int round = 0;

        scanf("%d", &round);
        
        for (int i = 0; i < round; i++) {
                double result = 0;
                int C, d;

                scanf("%d %d", &C, &d);
                
                result = (((double)d*5) / 9) + C;
                printf("Case %d: %.2f\n", i+1, result);
        }

	return 0;
}

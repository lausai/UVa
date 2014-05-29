#include <cstdio>

using namespace std;

int main()
{
    int n = 0, m = 0, c = 0;
    int loops = 1;

    while (scanf("%d %d %d", &n, &m, &c), n != 0 && m != 0 && c != 0) {
        int e[20] = {};
        int status[20] = {};
        int powerConsume = 0;
        int maxPower = 0;
        int eNum = 0;
        bool blown = false;

        for (int i = 0; i < n; i++)
            scanf("%d", &e[i]);
        
        for (int i = 0; i < m; i++) {
            scanf("%d", &eNum);
            
            if (blown) continue;
            
            eNum--;

            if (status[eNum] == 0) {
                if (powerConsume + e[eNum] > c)
                    blown = true;
                
                powerConsume += e[eNum];
                status[eNum] = 1;

                if (powerConsume > maxPower)
                    maxPower = powerConsume;
            } else {
                powerConsume -= e[eNum];
                status[eNum] = 0;
            }
        }


        printf("Sequence %d\n", loops);
        
        if (blown) {
            puts("Fuse was blown.");
        } else {
            puts("Fuse was not blown.");
            printf("Maximal power consumption was %d amperes.\n", maxPower);
        }

        puts("");
        loops++;
    }
	return 0;
}

#include <cstdio>

using namespace std;

int main()
{
        int Z, I, M, L;
        int Case = 1;

        while (true) {
                scanf("%d %d %d %d", &Z, &I, &M, &L);
                if (0 == Z && 0 == I && 0 == M && 0 == L) break;

                int L_values[9999] = {L};       // set the first element to L
                int cycle;
                
                for (cycle = 1; cycle < 9999; cycle++) {
                        L               = ((Z*L) + I) % M;
                        bool find_cycle = false;
                        
                        for (int i = 0; i < cycle; i++) {
                                if (L == L_values[i]) {
                                        find_cycle = true;
                                        cycle = cycle - i;
                                        break;
                                }
                        }

                        if (find_cycle) break;

                        L_values[cycle] = L;
                }

                printf("Case %d: %d\n", Case++, cycle);
        }
	return 0;
}

#include <cstdio>

using namespace std;

int main()
{
    int N = 0;

    while (scanf("%d", &N), N != 0) {
        int answer = 1;

        while (true) {
            int next = 1;
            int cities[128] = {1, 1};

            for (int i = 0; i < N - 1; i++) {
                for (int j = 0; j < answer; j++) {
                    next++;
                    
                    while (true) {
                        if (next > N)
                            next = 1;
        
                        if (cities[next] != 1)
                            break;
                        else
                            next++;
                    }
                }
                cities[next] = 1;
            }

            if (next == 13) break;

            answer++;
        }

        printf("%d\n", answer);
    }

	return 0;
}

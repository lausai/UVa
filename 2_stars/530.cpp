#include <cstdio>

using namespace std;

int main()
{
        long long M = 0, N = 0;

        while (scanf("%lld %lld", &N, &M), M != 0 || N != 0) {
                long long result = 1;
                long long divides[100000] = {0};
                long long divide = N - M;
                
                if (M == 0 || N == M) {
                        puts("1");
                        continue;
                } else if (M == 1) {
                        printf("%lld\n", N);
                        continue;
                }

                if (N - M > M) {
                        divide = M;
                        M      = N - M;
                }

                for (long long i = N; i > M; i--) {
                        result *= i;

                        while (divide > 1 && result % divide == 0) {
                                result /= divide;
                                --divide;
                        }
                }

                printf("%lld\n", result);
        }

	return 0;
}

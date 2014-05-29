#include <cstdio>

using namespace std;

int main()
{
    long long A = 0, L = 0;
    int loop = 1;
    while (scanf("%lld %lld", &A, &L), A >= 0 && L >= 0) {
        unsigned int num = 1;
        long long tmp = A;

        while (true) {
            if (tmp == 1) break;

            if (tmp % 2 == 0) {
                tmp /= 2;
                num++;
                continue;
            }

            tmp = (3 * tmp) + 1;

            if (tmp > L) break;

            num++;
        }

        printf("Case %d: A = %lld, limit = %lld, number of terms = %u\n", loop, A, L, num);
        loop++;
    }

	return 0;
}

#include <cstdio>

using namespace std;

int main()
{
        int value = 0;

        while (EOF != scanf("%d", &value)) {
                long long result = 1;
                
                for (int i = 2; i <= value; i++) {
                        result *= i;
                        
                        while (result % 10 == 0)
                                result /= 10;

                        result %= 1000000;
                }

                printf("%5d -> %lld\n", value, result % 10);
        }

	return 0;
}

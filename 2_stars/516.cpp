#include <cstdio>
#include <cmath>

using namespace std;

size_t primes[4096] = {2};

bool IsPrime(int val)
{
        int factor = floor(sqrt((double)val));

        for (int i = 2; i <= factor; i++) {
                if (val % i == 0) return false;
        }

        return true;
}

int GetPrimeGreater(int val)
{
        for (int i = val + 1; ; i++) {
                if (IsPrime(i)) return i;
        }
}

int main()
{
        int X = 1; 
        int degree = 0, poly = 0;

        while (scanf("%d %d", &poly, &degree), poly != 0) {
                char ch = getc(stdin);
                
                X *= (int)pow((double)poly, degree);

                if ('\n' == ch) {
                        X -= 1;

                        int factor_num    = 0;
                        int prime_pos     = 0;
                        int results[1024] = {0};
                        int result_pos    = 0;

                        while (X != 1) {
                                if (X % primes[prime_pos] == 0) {
                                        ++factor_num;
                                        X /= primes[prime_pos];
                                } else {
                                        ++prime_pos;

                                        if (primes[prime_pos] == 0) {
                                                int prime = GetPrimeGreater(primes[prime_pos - 1]);

                                                primes[prime_pos] = prime;
                                        }

                                        if (factor_num != 0) {
                                                results[result_pos++] = factor_num;
                                                results[result_pos++] = primes[prime_pos - 1];
                                                factor_num = 0;
                                        }
                                }
                        }
                        
                        printf("%d %d", primes[prime_pos], factor_num);

                        for (int i = result_pos - 1; i >= 0; i--)
                                printf(" %d", results[i]);
                        
                        puts("");
                }
        }
	return 0;
}

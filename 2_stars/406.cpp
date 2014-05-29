#include <cstdio>

using namespace std;

int primes[1000] = {1};

bool IsPrime(int num)
{
        if (num == 0) return false;

        if (num <= 3) return true;

        for (int i = 2; i <= num / 2; i++) {
                if (num % i == 0) return false;
        }

        return true;
}

void PrintPrimes(int num_primes, int C)
{
        int start = 0;
        int end   = 0;

        if (num_primes % 2 != 0) {
                if ((2*C - 1) > num_primes) {
                        start = 0;
                        end   = num_primes - 1;
                } else {
                        start = (num_primes / 2) - C + 1;
                        end   = (num_primes / 2) + C - 1;
                }
        } else {
                if (2*C > num_primes) {
                        start = 0;
                        end   = num_primes - 1;
                } else {
                        start = (num_primes / 2) - C;
                        end   = (num_primes / 2) + C - 1;
                }
        }

        for (int i = start; i <= end; i++)
                printf(" %d", primes[i]);
}

int main()
{
        int N, C;
        int max_prime_pos = 0;

        while (EOF != scanf("%d %d", &N, &C)) {
                printf("%d %d:", N, C);

                if (N <= primes[max_prime_pos]) {
                        int pos_max_primes_less_N = max_prime_pos;
                        
                        while (primes[pos_max_primes_less_N] > N)
                                --pos_max_primes_less_N;
                        
                        PrintPrimes(pos_max_primes_less_N + 1, C);
                } else {
                        for (int i = primes[max_prime_pos] + 1; i <= N; i++) {
                                if (!IsPrime(i)) continue;
                                
                                ++max_prime_pos;
                                primes[max_prime_pos] = i;
                        }
                        
                        PrintPrimes(max_prime_pos + 1, C);
                }

                puts("\n");
        }

	return 0;
}

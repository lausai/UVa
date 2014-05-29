#include <cstdio>
#include <cmath>

using namespace std;

bool IsPrime(int val)
{
        int max = floor(sqrt((double)val));

        for (int i = 3; i <= max; i += 2) {
                if (val % i == 0) {
                        return false;
                }
        }
        
        return true;
}

int main()
{
        bool prime_table[999999] = {false, false, true, true, false};
        
        for (int i = 5; i < 1000000; i += 2) {
                if (IsPrime(i))
                        prime_table[i] = true;
        }
         
        int value = 0;

        while (scanf("%d", &value), value != 0) {
                bool find_solution = false;

                for (int i = 3; i <= value / 2; i += 2) {
                        if (prime_table[i] && prime_table[value - i]) {
                                printf("%d = %d + %d\n", value, i, value - i);
                                find_solution = true;
                                break;
                        }
                }

                if (!find_solution) puts("Goldbach's conjecture is wrong.");
        }

	return 0;
}

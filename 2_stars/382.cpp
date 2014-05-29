#include <cstdio>

using namespace std;

int main()
{
        int value = 0;
        
        puts("PERFECTION OUTPUT");

        while (scanf("%d", &value), value != 0) {
                if (value == 1) {
                        printf("%5d  DEFICIENT\n", 1);
                        continue;
                }

                int factors[60000] = {0};
                int sum_of_factors = 1;

                int start = value / 2;

                for (int i = 2; i <= start; i++) {
                        if ((value % i) == 0) {
                                sum_of_factors += i;
                        }
                }

                char* result = NULL;

                if (sum_of_factors == value)
                        result = "PERFECT";
                else if (sum_of_factors < value)
                        result = "DEFICIENT";
                else
                        result = "ABUNDANT";

                printf("%5d  %s\n", value, result);
        }
        puts("END OF OUTPUT");

        return 0;
}

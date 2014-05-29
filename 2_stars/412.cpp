#include <cstdio>
#include <cmath>

using namespace std;

int GetC(int value)
{
        return value * (value - 1) / 2;
}

int GCD(int a, int b)
{
        int big   = a > b ? a : b;
        int small = a > b ? b : a;

        while (small != 0) {
                int tmp = small;
                small   = big % small;
                big     = tmp;
        }

        return big;
}

int main()
{
        int number = 0;

        while (scanf("%d", &number), number != 0) {
                int numbers[50] = {0};
                
                for (int i = 0; i < number; i++)
                        scanf("%d", &numbers[i]);
                
                int value = 0;

                for (int i = 0; i < number; i++) {
                        for (int j = 0; j < number; j++) {
                                if (i >= j) continue;

                                if (numbers[i] == 1 || numbers[j] == 1) {
                                        ++value;
                                        continue;
                                }
                                
                                if (GCD(numbers[i], numbers[j]) == 1)
                                        ++value;
                        }
                }

                if (value == 0) {
                        puts("No estimate for this data set.");
                } else {
                        double pi = sqrt((double)6 * GetC(number) / value);
                        printf("%.6f\n", pi);
                }
        }

	return 0;
}

#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int round = 0;
    scanf("%d", &round);
    int dpa[500] = {1};

    for (int i = 0; i < round; i++) {
        int num = 0;
        scanf("%d", &num);

        int half = (int)sqrt((double)num);
        int dpa_num = 1;

        for (int j = 2; j <= half; j++) {
            int r = num % j;

            if (r == 0) {
                int q = num / j;

                dpa[dpa_num] = j;
                dpa_num++;

                if (q != j) {
                    dpa[dpa_num] = q;
                    dpa_num++;
                }
            }
        }

        int sum = 0;
        for (int j = 0; j < dpa_num; j++) {
            sum += dpa[j];
        }
        

        if (sum == num)
            puts("perfect");
        else if (sum < num)
            puts("deficient");
        else
            puts("abundant");
    }
	return 0;
}

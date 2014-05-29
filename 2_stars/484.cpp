#include <cstdio>

using namespace std;

int main()
{
        const size_t max_num          = 100000;
        size_t num_of_appear[max_num] = {0};
        size_t num_order[max_num]     = {0};
        int num                       = 0;
        int total_num                 = 0;

        while (EOF != scanf("%d", &num)) {
                if (num_of_appear[num] == 0)
                        num_order[total_num++] = num;

                ++num_of_appear[num];
        }

        for (int i = 0; i < total_num; i++)
                printf("%d %d\n", num_order[i], num_of_appear[num_order[i]]);

	return 0;
}

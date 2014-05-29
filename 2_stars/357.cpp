#include <cstdio>

using namespace std;

int main()
{
        int money[5]           = {1, 5, 10, 25, 50};
        long long ways[30001]  = {1};

        for (int i = 0; i < 5; i++) {
                for (int j = money[i]; j <= 30000; j++)
                        ways[j] += ways[j - money[i]];
        }
        
        int data = 0;

        while (EOF != scanf("%d", &data)) {
                if (data < 5)
                        printf("There is only 1 way to produce %d cents change.\n", data);
                else
                        printf("There are %lld ways to produce %d cents change.\n", ways[data], data);
        }

	return 0;
}

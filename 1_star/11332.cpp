#include <cstdio>

using namespace std;

int g(int value)
{
        int sum = 0;

        while (value != 0) {
                sum += value % 10;
                value /= 10;
        }
        
        if (sum < 10) 
                return sum;
        else
                return g(sum);
}

int main()
{
        int value;

        while (scanf("%d", &value), value != 0)
                printf("%d\n", g(value));

	return 0;
}

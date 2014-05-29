#include <cstdio>

using namespace std;

int main()
{
        int edge_len = 0;

        while (scanf("%d", &edge_len), edge_len != 0) {
                int result = 0;

                for (int i = 1; i <= edge_len; i++)
                        result += i * i;

                printf("%d\n", result);
        }

	return 0;
}

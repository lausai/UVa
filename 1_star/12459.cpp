#include <cstdio>

using namespace std;

int main()
{
    long long answer[80] = {1, 2};

    for (int i = 2; i < 80; i++)
        answer[i] = answer[i - 1] + answer[i - 2];

    int num = 0;

    while (scanf("%d", &num), num != 0)
        printf("%lld\n", answer[num - 1]);

	return 0;
}

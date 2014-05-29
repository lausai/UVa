#include <cstdio>

using namespace std;

bool IsPrime(int num)
{
        if (num == 0 || num == 1) return false;

        if (num <= 3) return true;

        for (int i = 2; i <= num / 2; i++) {
                if (num % i == 0) return false;
        }

        return true;
}

int main()
{
    int num = 0;

    while (scanf("%d", &num), num != 0) {
        int answer = 0;

        for (int i = 1; i <= num / 2; i++) {
            if (IsPrime(i) && IsPrime(num - i)) {
                answer++;
            }
        }

        printf("%d\n", answer);
    }

	return 0;
}

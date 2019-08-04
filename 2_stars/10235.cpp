#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

bool IsPrime(int i)
{
    if (i == 2 || i == 1)
        return true;

    if (i % 2 == 0)
        return false;

    int ubound = (int)sqrt((double)i);

    for (int j = 2; j <= ubound; j++) {
        if (i % j == 0)
            return false;
    }

    return true;
}



int main()
{
    char line[16] = {};
    while (fgets(line, sizeof(line) - 1, stdin) != NULL) {
        int l = strtol(line, NULL, 10);
        char buf[16] = {};

        if (!IsPrime(l)) {
            printf("%d is not prime.\n", l);
        } else {
            int len = strlen(line) - 1;
            for (int i = 0; i < len; i++)
                buf[i] = line[len - 1 - i];

            int l2 = strtol(buf, NULL, 10);
            if (l2 != l && IsPrime(l2))
                printf("%d is emirp.\n", l);
            else
                printf("%d is prime.\n", l);
        }
    }
	return 0;
}

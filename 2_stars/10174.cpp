#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

bool get_number(long long n1, long long * a, long long * b)
{
    if (n1 == 0) {
        *a = 2;
        *b = 2;
        return true;
    }
    int num_mod_by_2 = 0;
    bool even = n1 % 2 == 0;

    if (even) {
        int tmp = n1;
        while (tmp % 2 == 0) {
            num_mod_by_2++;
            tmp /= 2;
        }

        if (num_mod_by_2 > 1) {
            *a = ((n1 / 2) + 2) / 2;
            *b = *a - 2;
            if (n1 < 0) {
                *a = -(*a);
                *b = -(*b);
            }
            return true;
        } else {
            return false;
        }
    } else {
        *a = (n1 + 1) / 2;
        *b = *a - 1;
        if (n1 < 0) {
            *a = -(*a);
            *b = -(*b);
        }
        return true;
    }
}

int main()
{
    char line[64] = {};
    while (fgets(line, sizeof(line) - 1, stdin) != NULL) {
        long long n1 = 0, n2 = 0;

        if (strstr(line, " ") == NULL) {
            sscanf(line, "%lld", &n1);
            long long a = 0, b = 0;
            if (get_number(n1, &a, &b))
                printf("%lld %lld\n", a, b);
            else
                puts("Bachelor Number.");
        } else {
            sscanf(line, "%lld %lld", &n1, &n2);
            long long a, b;
            int t = 0;
            long long i = n1 % 2 == 0 ? n1 : n1 + 1;
            for (; i <= n2  ; i += 2) {
                if (!get_number(i, &a, &b))
                    t++;
            }

            printf("%d\n", t);
        }
    }
	return 0;
}

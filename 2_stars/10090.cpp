#include <cstdio>
#include <climits>

using namespace std;

long long gcd(long long a, long long b)
{
    long long max = a;
    long long min = b;

    if (a < b) {
        min = a;
        max = b;
    }

    if (max % min == 0)
        return min;
    else
        return gcd(min, (max % min));
}

long long find_price(long long n, long long n1, 
    long long n2, long long c1, long long c2, long long* t1, long long* t2)
{
    long long m1 = n % n1;
    long long m2 = 0;
    long long price = 0;
    *t2 = 0;
    *t1 = n / n1;

    while (m2 = (m1 % n2), m2 != 0 && (*t1) >= 0) {
        m1 = m1 + n1;
        (*t1)--;
    }

    if ((*t1) > 0) {
        *t2 = (n - (n1 * (*t1))) / n2;

        price = (c1 * (*t1)) + (c2 * (*t2));
    }
    return price;
}

int main()
{
    long long n = 0;

    while (scanf("%lld", &n) == 1 && n != 0) {
        long long c1, n1, c2, n2;

        scanf("%lld %lld", &c1, &n1);
        scanf("%lld %lld", &c2, &n2);

        long long gcd_ = 0;
        bool hasResult = false;

        while (gcd_ = gcd(n1, n2), gcd_ != 1) {
            if (n % gcd_ != 0) {
                puts("failed");
                hasResult = true;
                break;
            }

            n = n / gcd_;
            n1 = n1 / gcd_;
            n2 = n2 / gcd_;
        }

        if (hasResult)
            continue;

        long long t1, t2, t3, t4;
        long long p1 = find_price(n, n1, n2, c1, c2, &t1, &t2);

        long long p2 = find_price(n, n2, n1, c2, c1, &t3, &t4);

        if (p1 == 0 && p2 == 0) {
            puts("failed");
            continue;
        }

        if (p1 == 0)
            printf("%lld %lld\n", t4, t3);
        else if (p2 == 0)
            printf("%lld %lld\n", t1, t2);
        else if (p1 <= p2)
            printf("%lld %lld\n", t1, t2);
        else
            printf("%lld %lld\n", t4, t3);
    }

	return 0;
}

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
        int m, n;
        char value_str[16] = {0};
        
        while (EOF != scanf("%d %d %s", &m, &n, value_str)) {
                if (value_str[0] == '0') {
                        printf("0 base %d = 0 base %d\n", m, n);
                        continue;
                }

                char* endptr = value_str;
                long value = strtol(value_str, &endptr, m);
                
                if (*endptr != 0) {
                        printf("%s is an illegal base %d number\n", value_str, m);
                        continue;
                }

                
                long quotient             = value;
                char value_for_base_n[16] = {0};
                char* pos                 = value_for_base_n + sizeof(value_for_base_n) - 1;
                char base_str[]           = "0123456789ABCDEF";
                while (quotient != 0) {
                        int remainder = quotient % n;
                        --pos;
                        *pos          = base_str[remainder];

                        quotient      = (quotient - remainder) / n;
                }

                printf("%s base %d = %s base %d\n", value_str, m, pos, n);
        }

	return 0;
}

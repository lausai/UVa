#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
        int base_from, base_to;
        char num_str[16] = {0};

        while (EOF != scanf("%s %d %d", num_str, &base_from, &base_to)) {
                int len          = strlen(num_str);
                bool str_is_zero = true;

                for (int i = 0; i < len; i++) {
                        if (num_str[i] != '0') {
                                str_is_zero = false;
                                break;
                        }
                }

                if (str_is_zero) {
                        puts("      0");
                        continue;
                }

                long value = strtol(num_str, NULL, base_from);

                long quotient             = value;
                char value_for_base_to[16] = {0};
                char* pos                 = value_for_base_to + sizeof(value_for_base_to) - 1;
                char base_str[]           = "0123456789ABCDEF";
                int num_of_chars          = 0;
                while (quotient != 0) {
                        int remainder = quotient % base_to;
                        --pos;
                        *pos          = base_str[remainder];
                        ++num_of_chars;
                        quotient      = (quotient - remainder) / base_to;
                }
                
                if (num_of_chars <= 7)
                        printf("%7s\n", pos);
                else
                        puts("  ERROR");
        }
	return 0;
}

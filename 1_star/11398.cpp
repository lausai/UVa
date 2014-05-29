#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
        char number[64]        = {0};
        char binary_number[64] = {0};
        int pos                = 0;
        bool number_start      = true;
        
        while (scanf("%s", number), number[0] != '~') {
                if (number[0] == '#') {
                        binary_number[pos] = '\0';
                        printf("%ld\n", strtol(binary_number, NULL, 2));
                        pos          = 0;
                        number_start = true;
                        continue;
                }

                int len = strlen(number);
                char flag;

                if (number_start && len > 2) continue;

                number_start = false;

                if (len == 1) {
                        flag = '1';
                } else if (len == 2) {
                        flag = '0';
                } else {
                        for (int i = 0; i < len - 2; i++)
                                binary_number[pos++] = flag;
                }
        }

	return 0;
}

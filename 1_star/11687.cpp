#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
        char num[1000001] = {0};

        while (scanf("%s", num), num[0] != 'E') {
                if (num[0] == '1' && num[1] == '\0') {
                        puts("1");
                        continue;
                }

                int digit    = strlen(num);
                int result   = 0;
                char str[16] = {0};
                
                for (result = 0; digit != 1; result++) {
                        sprintf(str, "%d", digit);
                        digit = strlen(str);
                }

                printf("%d\n", result + 2);
        }

	return 0;
}

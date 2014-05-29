#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
        char num[128] = {0};

        while (scanf("%s", num), num[0] != '0') {
                for (int len = strlen(num); len > 10; len--) {
                        if (num[len - 1] - '0' < 0) {
                                num[len - 1] += 10;
                                num[len - 2] -= 1;
                        }

                        int d = 5 * (num[len - 1] - '0');
                        
                        num[len - 1] = '\0';
                        num[len - 2] -= d % 10;
                        num[len - 3] -= d / 10;
                }
                
                for (int i = 9; i > 0; i--) {
                        if (num[i] != '\0' && num[i] - '0' < 0) {
                                num[i]     += 10;
                                num[i - 1] -= 1;
                        }
                }

                long value = strtol(num, NULL, 10);
                
                if (value % 17 == 0)
                        puts("1");
                else
                        puts("0");
        }

	return 0;
}

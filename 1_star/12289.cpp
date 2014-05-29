#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
        int round = 0;

        scanf("%d", &round);

        for (int i = 0; i < round; i++) {
                char num[8] = {0};

                scanf("%s", num);
                if (strlen(num) == 5) {
                        puts("3");
                        continue;
                }

                if ((num[0] == 'o' && num[1] == 'n') ||
                    (num[0] == 'o' && num[2] == 'e') ||
                    (num[1] == 'n' && num[2] == 'e'))
                        puts("1");
                else
                        puts("2");
        }

	return 0;
}

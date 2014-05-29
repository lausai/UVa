#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    while (true) {
        char str[256] = {};

        scanf("%s", str);

        if (str[0] == '*') break;

        char* pch = strtok(str, "/");
        int answer = 0;

        while (pch != NULL) {
            int len = strlen(pch);
            int total = 0;

            for (int i = 0; i < len; i++) {
                switch (pch[i]) {
                case 'W':
                    total += 64;
                    break;
                case 'H':
                    total += 32;
                    break;
                case 'Q':
                    total += 16;
                    break;
                case 'E':
                    total += 8;
                    break;
                case 'S':
                    total += 4;
                    break;
                case 'T':
                    total += 2;
                    break;
                case 'X':
                    total += 1;
                    break;
                }
            }

            if (total == 64) answer++;

            pch = strtok(NULL, "/");
        }

        printf("%d\n", answer);
    }

	return 0;
}

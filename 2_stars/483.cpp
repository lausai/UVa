#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
        char str[32] = {0};
        char ch      = 0;

        while (EOF != scanf("%s%c", str, &ch)) {
                int len = strlen(str);

                for (int i = len - 1; i >= 0; i--)
                        printf("%c", str[i]);

                printf("%c", ch);
        }
	return 0;
}

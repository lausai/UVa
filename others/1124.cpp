#include <cstdio>

using namespace std;

int main()
{
    char s[1024] = {};

    while (fgets(s, sizeof(s), stdin) != NULL) {
        printf("%s", s);
    }
	return 0;
}

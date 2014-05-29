#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int G = 0;

    while (scanf("%d", &G), G != 0) {
        char buf[128] = {};

        scanf("%s", buf);

        int len = strlen(buf) / G;
        char* start = buf;
        char* end = buf + len;

        for (int i = 0; i < G; i++) {
            reverse(start, end);
            start += len;
            end += len;
        }

        puts(buf);
    }

	return 0;
}

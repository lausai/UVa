#include <cstdio>
#include <cstring>

using namespace std;

char g_buf[17] = {};
char* g_start = NULL;

void GetHam(char* buf, int dis, int buf_size)
{
    if (dis == buf_size) {
        memset(buf, '1', dis);
        puts(g_start);
        memset(buf, '0', dis);
        return;
    }

    if (dis == 1) {
        for (int i = buf_size - 1; i >= 0; i--) {
            buf[i] = '1';
            puts(g_start);
            buf[i] = '0';
        }

        return;
    }

    for (char* c = buf + (buf_size - dis); c >= buf; c--) {
        *c = '1';
        GetHam(c + 1, dis - 1, buf_size - (c - buf) - 1);
        *c = '0';
    }
}

int main()
{
    int num = 0;
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        int N, H;

        scanf("%d %d", &N, &H);
        g_start = g_buf + 17 - N - 1;
        memset(g_start, '0', N);

        if (i > 0)
            puts("");

        GetHam(g_start, H, N);
    }
	return 0;
}

#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
    int n = 0;
    char tmp;
    scanf("%d%c", &n, &tmp);

    for (int i = 0; i < n; i++) {
        char pre_ch = 0;
        int rx = 0, r = 0, lx = 0, l = 0;
        int* x = &lx, *c = &l;
        int m = 1;
        int num = 0;
        bool hasNum = false;
        char str[256] = {};

        scanf("%s", str);
        int len = strlen(str);
        
        for (int idx = 0; idx < len; idx++) {
            char ch = str[idx];

            switch (ch) {
            case '-':
                m = -1;
                num = 0;
                hasNum = false;
                break;
            case '+':
                m = 1;
                num = 0;
                hasNum = false;
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if (pre_ch >= '0' && pre_ch <= '9') {
                    *c -= num;
                    num = (num*10) + ((ch-'0') * m);
                } else  {
                    num = (ch - '0') * m;
                }

                *c += num;
                hasNum = true;
                break;
            case 'x':
                if (hasNum == false)
                    num = 1 * m;
                else
                    *c -= num;

                *x += num;
                m = 1;
                num = 0;
                hasNum = false;
                break;
            case '=':
                x = &rx;
                c = &r;
                m = 1;
                hasNum = false;
                break;
            }
            
            pre_ch = ch;
        }

        int j = lx - rx;
        int k = r - l;

        if (j == 0 && k != 0)
            puts("IMPOSSIBLE");
        else if (j == 0 && k == 0)
            puts("IDENTITY");
        else
            printf("%lld\n", (long long)floor((double)k / j));
    }
	return 0;
}

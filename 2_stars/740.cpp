#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

void findShift(const char* ch, int* down, int* up)
{
    int count = 0;

    for (int i = 0; i < 32; i++) {
        if (ch[i] == ' ') {
            if (count == 1)
                *down = i;
            else if (count == 2)
                *up = i;

                count++;
        }
    }
}

int main()
{
    char up[33] = {};
    char down[33] = {};
    int down_shift_down = 0;
    int down_shift_up = 0;
    int up_shift_down = 0;
    int up_shift_up = 0;

    gets(down);
    findShift(down, &down_shift_down, &down_shift_up);
    gets(up);
    findShift(up, &up_shift_down, &up_shift_up);

    char code[81] = {};

    while (gets(code)) {
        char* ch = down;
        int len = strlen(code);
        char* code_start = code;
        char code_unit[6] = {};

        for (int i = 0; i < len / 5; i++) {
            memcpy(code_unit, code_start, 5);
            int c = strtol(code_unit, NULL, 2);

            if (c == down_shift_up && ch == down)
                ch = up;
            else if (c == up_shift_down && ch == up)
                ch = down;
            else if (c == up_shift_up && ch == up)
                ;
            else if (c == down_shift_down && ch == down)
                ;
            else
                printf("%c", ch[c]);

            code_start += 5;
        }
        puts("");
    }

	return 0;
}

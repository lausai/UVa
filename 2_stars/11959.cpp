#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

void change(char* in)
{
    char buf[5] = {};
    strncpy(buf, &in[2], 4);

    in[2] = buf[3];
    memcpy(&in[3], buf, 3);
}

void set_to_upper(int pos, char* in, char* out)
{
    switch (pos) {
    case 0:
        memcpy(out, in, 6);
        break;

    case 1:
        out[0] = in[1];
        out[1] = in[0];
        out[2] = in[2];
        out[3] = in[5];
        out[4] = in[4];
        out[5] = in[3];
        break;

    case 2:
        out[0] = in[2];
        out[1] = in[4];
        out[2] = in[1];
        out[3] = in[3];
        out[4] = in[0];
        out[5] = in[5];
        break;

    case 3:
        out[0] = in[3];
        out[1] = in[5];
        out[2] = in[2];
        out[3] = in[1];
        out[4] = in[4];
        out[5] = in[0];
        break;

    case 4:
        out[0] = in[4];
        out[1] = in[2];
        out[2] = in[0];
        out[3] = in[3];
        out[4] = in[1];
        out[5] = in[5];
        break;

    case 5:
        out[0] = in[5];
        out[1] = in[3];
        out[2] = in[2];
        out[3] = in[0];
        out[4] = in[4];
        out[5] = in[1];
        break;
    }
}


int main()
{
    int round = 0;
    scanf("%d", &round);

    for (int i = 0; i < round; i++) {
        char s1[8] = {};
        char s2[8] = {};
        
        scanf("%s %s", s1, s2);
        bool equal = false;

        for (int j = 0; j < 6; j++) {
            char out[8] = {};

            set_to_upper(j, s2, out);

            for (int k = 0; k < 4; k++) {
                change(out);

                if (strncmp(s1, out, 6) == 0) {
                    equal = true;
                    break;
                }
            }

            if (equal)
                break;
        }

        puts(equal ? "Equal" : "Not Equal");
    }
	return 0;
}

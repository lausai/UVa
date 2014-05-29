#include <cstdio>
#include <cstring>

using namespace std;

int g_order1[6][6] = {
    {1, 2, 3, 4, 5, 6},
    {2, 6, 3, 4, 1, 5},
    {3, 2, 6, 1, 5, 4},
    {4, 2, 1, 6, 5, 3},
    {5, 1, 3, 4, 6, 2},
    {6, 5, 3, 4, 2, 1},
};

int g_order2[4][6] = {
    {1, 2, 3, 4, 5, 6},
    {1, 3, 5, 2, 4, 6},
    {1, 5, 4, 3, 2, 6},
    {1, 4, 2, 5, 3, 6},
};

void FlipCube(const char* ori, char* buf, int order[])
{
    for (int i = 0; i < 6; i++)
        buf[i] = ori[order[i] - 1];
}

int main()
{
    
    char buf1[7] = {};
    char buf2[7] = {};
    char buf3[7] = {};

    while (scanf("%6s%6s", buf1, buf3) != EOF) {
        char* c1 = buf1;
        char* c2 = buf2;
        bool find = false;
    
        for (int i = 0; i < 6; i++) {
            FlipCube(c1, c2, g_order1[i]);
    
            char* c11 = c2;

            for (int j = 0; j < 4; j++) {
                char buf[7] = {};
                FlipCube(c11, buf, g_order2[j]);

                if (strcmp(buf3, buf) == 0) {
                    find = true;
                    break;
                }
            }
            
            if (find) break;
        }

        puts(find ? "TRUE" : "FALSE");
    }

	return 0;
}

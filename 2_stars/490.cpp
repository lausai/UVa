#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
        char map[128][128] = {0};
        int num_row        = 0;
        int max_len        = 0;
        
        while (NULL != gets(map[num_row++])) {
                int len = strlen(map[num_row-1]);
                
                if (len > max_len) max_len = len;
        }
        
        for (int j = 0; j < max_len; j++) {
                for (int i = num_row - 2; i >= 0; i--) {
                        if (isprint(map[i][j]))
                                printf("%c", map[i][j]);
                        else
                                printf(" ");
                }
                puts("");
        }

	return 0;
}

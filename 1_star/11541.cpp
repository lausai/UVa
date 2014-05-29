#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
        int round = 0;

        scanf("%d", &round);
        for (int i = 0; i < round; i++) {
                printf("Case %d: ", i + 1);
                
                char encode_str[256] = {0};
                
                scanf("%s", encode_str);
                
                char ch;
                int  num  = 0;
                char* pos = encode_str;
                while (EOF != sscanf(pos, "%c%d", &ch, &num)) {
                        pos += 1;

                        char str[256] = {0};

                        sprintf(str, "%d", num);
                        pos += strlen(str);
                        
                        for (int j = 0; j < num; j++)
                                printf("%c", ch);
                }
                puts("");
        }

	return 0;
}

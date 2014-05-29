#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

int main()
{
        int num_of_data = 0;

        scanf("%d\n", &num_of_data);

        for (int i = 0;i < num_of_data; i++) {
                char str[256] = {0};

                fgets(str, 255, stdin);

                const char* eng = "abcdefghijklmnopqrstuvwxyz";
                int counter[26] = {0};
                int len = strlen(str);
                int num_of_appear = 0;
                
                for (int j = 0; j < len; j++) {
                        if (!isalpha(str[j])) continue;
                        
                        int pos = 0;
                        if (isupper(str[j]))
                                pos = str[j] - 'A';
                        else
                                pos = str[j] - 'a';
                        
                        ++counter[pos];
                        if (counter[pos] > num_of_appear)
                                num_of_appear = counter[pos];
                }
                
                for (int j = 0; j < 26; j++ ) {
                        if (counter[j] == num_of_appear)
                                printf("%c", eng[j]);
                }
                puts("");
        }

	return 0;
}

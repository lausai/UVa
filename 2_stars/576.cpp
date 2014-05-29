#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
        char str[3][200];

        while (scanf("%[a-z ]/%[a-z ]/%[a-z ]\n", str[0], str[1], str[2]), strcmp("e", str[0]) ||
                                                                           strcmp("o", str[1]) ||
                                                                           strcmp("i", str[2])) {
                int haiku[]     = {5, 7, 5};
                bool good_haiku = true;

                for (int i = 0; i < 3; i++) {
                        int value = 0, len = strlen(str[i]);
                        bool pre_char_is_aeiou = false;

                        for (int j = 0; j < len; j++) {
                                switch (str[i][j]) {
                                        case 'a':
                                        case 'e':
                                        case 'i':
                                        case 'o':
                                        case 'u':
                                        case 'y':
                                                if (!pre_char_is_aeiou) {
                                                        ++value;
                                                        pre_char_is_aeiou = true;
                                                }
                                                break;
                                        default:
                                                pre_char_is_aeiou = false;
                                }
                        }
                        
                        if (value != haiku[i]) {
                                printf("%d\n", i + 1);
                                good_haiku = false;
                                break;
                        }
                }

                if (good_haiku) puts("Y");
        }

	return 0;
}

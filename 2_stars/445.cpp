#include <cstdio>
#include <cctype>

using namespace std;

int main()
{
        char ch;
        int len                 = 0;
        bool already_has_number = false;

        while ((ch = getc(stdin)) != EOF) {
                switch (ch) {
                        case '!':
                        case '\n':
                                puts("");
                                break;
                        case 'b':
                                for (int i = 0; i < len; i++)
                                        printf(" ");
                                
                                len = 0;
                                break;
                        default:
                                if (isdigit(ch)) {
                                        len  += ch - '0';
                                } else {
                                        for (int i = 0; i < len; i++)
                                                printf("%c", ch);
                                        
                                        len = 0;
                                }
                                break;
                }
        }

	return 0;
}

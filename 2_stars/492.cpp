#include <cstdio>
#include <cctype>

using namespace std;

bool IsVoWel(char ch)
{
        switch (ch) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                        return true;
                default:
                        return false;
        }
}

int main()
{
        char str[20000] = {0};
        char head;
        
        head = getc(stdin);
        while (EOF != scanf("%[a-zA-Z]", str)) {
                if (IsVoWel(head))
                        printf("%c%say", head, str);
                else
                        printf("%s%cay", str, head);

                str[0] = '\0';
                
                bool exit_program = false;

                while (true) {
                        head = getc(stdin);
                        
                        if (EOF == head) {
                                exit_program = true;
                                break;
                        } else if (isalpha(head)) {
                                break;
                        } else {
                                printf("%c", head);
                        }
                }

                if (exit_program) break;
        }

	return 0;
}

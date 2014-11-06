#include <cstdio>
#include <stack>

using namespace std;

int main()
{
    int n = 0;
    char tmp = 0;
    scanf("%d%c%c", &n, &tmp, &tmp);

    for (int i = 0; i < n; i++) {
        if (i > 0)
            puts("");

        stack<char> stk;
        
        while (true) {
            char buf[3] = {};
            
            gets(buf);
            char c = buf[0];

            if (feof(stdin) || c == 0)
                break;
            
            switch (c) {
            case '(':
                stk.push(c);
                break;
            case ')':
                while (true) {
                    c = stk.top();
                    stk.pop();
                    printf("%c", c);
                    
                    if (c == '(') break;
                }
                break;
            case '+':
            case '-':
                while (true) {
                    if (stk.size() == 0) {
                        stk.push(c);
                        break;
                    }

                    char topc = stk.top();
                    if (topc == '(') {
                        stk.push(c);
                        break;
                    } else {
                        printf("%c", c);
                        stk.pop();
                    }
                }
                break;
            case '*':
            case '/':
                while (true) {
                    if (stk.size() == 0) {
                        stk.push(c);
                        break;
                    }

                    char topc = stk.top();
                    if (topc == '*' || c == '/') {
                        printf("%c", c);
                        stk.pop();
                    } else {
                        stk.push(c);
                        break;
                    }
                }
                break;
            default:
                printf("%c", c);
            }
        }

        while (stk.size() != 0) {
            printf("%c", stk.top());
            stk.pop();
        }

        puts("");
    }

	return 0;
}

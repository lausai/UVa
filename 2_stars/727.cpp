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
            char buf[16] = {};
            
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
                    char topc = stk.top();
                    stk.pop();

                    if (topc == '(') 
                        break;

                    printf("%c", topc);
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
                        printf("%c", topc);
                        stk.pop();
                    }
                }
                break;
            case '/':
            case '*':
                while (true) {
                    if (stk.size() == 0) {
                        stk.push(c);
                        break;
                    }

                    char topc = stk.top();
                    if (topc == '*' || topc == '/') {
                        printf("%c", topc);
                        stk.pop();
                    } else {
                        stk.push(c);
                        break;
                    }
                }
                break;
            default:
                printf("%c", c);
                break;
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


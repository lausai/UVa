#include <cstdio>
#include <stack>

using namespace std;

int main()
{
    int n = 0;
    char tmp = 0;
    scanf("%d%c", &n, &tmp);

    for (int i = 0; i <= n; i++) {
        stack<char> stk;
        bool getOptor = false;
        
        while (true) {
            char c = 0;
            bool outLoop = false;

            if (scanf("%c", &c) == EOF)
                break;
            
            switch (c) {
            case '\n':
                outLoop = true;
                break;
            case '(':
                getOptor = false;
                break;
            case ')':
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                getOptor = true;
                stk.push(c);
                break;
            default:
                if (getOptor) {
                    char optor = stk.top();

                    stk.pop();
                    printf("%c%c%c", stk.top(), c, optor);
                    stk.pop();
                }  else {
                    stk.push(c);
                }
            }

            if (outLoop)
                break;
            
            scanf("%c", &c);
        }
        puts("");
    }

	return 0;
}

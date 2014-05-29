#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

int main()
{
    int n = 0;
    char ch = 0;
    scanf("%d%c", &n, &ch);

    for (int i = 0; i < n; i++) {
        stack<char> s;
        char buf[256] = {};

        fgets(buf, 130, stdin);
        int len = strlen(buf);
        if (buf[len - 1] == '\n')
            len--;

        for (int j = 0; j < len; j++) {
            bool correct = true;

            if (s.empty()) {
                s.push(buf[j]);
                continue;
            }

            switch (buf[j]) {
            case ')':
                if (s.top() != '(')
                    correct = false;
                else
                    s.pop();

                break;
            case ']':
                if (s.top() != '[')
                    correct = false;
                else
                    s.pop();

                break;
            default:
                s.push(buf[j]);
            }

            if (!correct) break;
        }

        if (s.empty())
            puts("Yes");
        else
            puts("No");
    }

	return 0;
}

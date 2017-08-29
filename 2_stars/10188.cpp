#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

int main()
{
    int n = 0;
    int run = 0;
    const int buf_len = 128;
    char buf[buf_len] = {};

    while (fgets(buf, buf_len - 1, stdin) != NULL) {
        char buf_ans[100][buf_len] = {};
        char buf_user[100][buf_len] = {};
        char digit_ans[12000] = {};
        int num_digit_ans = 0;
        char digit_user[12000] = {};
        int num_digit_user = 0;

        sscanf(buf, "%d", &n);
        if (n == 0)
            break;

        run++;
        for (int i = 0; i < n; i++) {
            fgets(buf_ans[i], buf_len - 1, stdin);
            for (size_t j = 0; j < strlen(buf_ans[i]) - 1; j++) {
                if (isdigit(buf_ans[i][j])) {
                    digit_ans[num_digit_ans] = buf_ans[i][j];
                    num_digit_ans++;
                }
            }
        }

        int m = 0;
        fgets(buf, buf_len - 1, stdin);
        sscanf(buf, "%d", &m);
        for (int i = 0; i < m; i++) {
            fgets(buf_user[i], buf_len - 1, stdin);
            for (size_t j = 0; j < strlen(buf_user[i]) - 1; j++) {
                if (isdigit(buf_user[i][j])) {
                    digit_user[num_digit_user] = buf_user[i][j];
                    num_digit_user++;
                }
            }
        }
        
        if (num_digit_ans != num_digit_user) {
            printf("Run #%d: Wrong Answer\n", run);
            continue;
        }

        bool ok = false;
        for (int i = 0; i < num_digit_ans; i++) {
            if (digit_ans[i] != digit_user[i]) {
                printf("Run #%d: Wrong Answer\n", run);
                ok = true;
                break;
            }
        }

        if (ok) continue;

        if (m != n) {
            printf("Run #%d: Presentation Error\n", run);
            continue;
        }

        for (int i = 0; i < n; i++) {
            int len_ans = strlen(buf_ans[i]);
            if (strncmp(buf_ans[i], buf_user[i], len_ans) != 0) {
                printf("Run #%d: Presentation Error\n", run);
                ok = true;
                break;
            }
        }

        if (!ok)
            printf("Run #%d: Accepted\n", run);
    }
	return 0;
}

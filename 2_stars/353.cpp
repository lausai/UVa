#include <cstdio>
#include <cstring>
#include <map>
#include <string>

using namespace std;

bool palindrome(const char* s, int len)
{
    int half = len / 2;
    for (int i = 0; i < half; i++) {
        if (s[i] != s[len - i - 1])
            return false;
    }

    return true;
}

int main()
{
    char s[84] = {};
    while (scanf("%s", s) == 1) {
        char ans[3200][82] = {};
        int ans_next = 0;

        int len = strlen(s);
        int count = 0;

        for (int i = 1; i <= len; i++) {
            for (int j = 0; j + i <= len; j++) {
                if (palindrome(&s[j], i)) {
                    bool find_same = false;
                    for (int k = 0; k < ans_next; k++) {
                        if (strncmp(ans[k], &s[j], i) == 0) {
                            find_same = true;
                            break;
                        }
                    }

                    if (!find_same) {
                        strncpy(ans[ans_next], &s[j], i);
                        count++;
                        ans_next++;
                    }
                }
            }
        }
        printf("The string \'%s\' contains %d palindromes.\n", s, count);
    }

	return 0;
}

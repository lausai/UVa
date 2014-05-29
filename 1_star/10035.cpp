#include <cstdio>
#include <cstring>

using namespace std;

void ShiftStr(int shift_len, char* buf)
{
        char tmp[16] = {0};
        
        strcpy(tmp, buf);
        sprintf(&buf[shift_len], "%s", tmp);

        memset(buf, '0', shift_len);
}

int main()
{
        char val1[16] = {0}, val2[16] = {0};

        while (scanf("%s %s", val1, val2), val1[0] != '0' || val2[0] != '0') {
                int len1 = strlen(val1), len2 = strlen(val2);
                int len  = len1;

                if (len1 < len2) {
                        ShiftStr(len2 - len1, val1);
                        len = len2;
                } else if (len2 < len1) {
                        ShiftStr(len1 - len2, val2);
                        len = len1;
                }

                int result = 0, carry = 0;
                
                for (int i = 1; i <= len; i++) {
                        if (val1[len - i] - '0' + val2[len - i] - '0' + carry > 9) {
                                carry = 1;
                                ++result;
                        } else {
                                carry = 0;
                        }
                }
                
                if (result == 0)
                        puts("No carry operation.");
                else if (result == 1)
                        puts("1 carry operation.");
                else
                        printf("%d carry operations.\n", result);        
        }

	return 0;
}

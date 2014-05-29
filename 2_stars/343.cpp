#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

int getBase(const char str[])
{
        int len = strlen(str);

        int base = 2;
        for (int i = 0; i < len; i++) {
                if (isdigit(str[i]))
                        base = ((str[i] - '0' + 1) > base) ? (str[i] - '0' + 1) : base;
                else
                        base = ((str[i] - 'A' + 11) > base) ? (str[i] - 'A' + 11) : base;
        }
        return base;
}

bool valueMatchIn(int value, const int values_for_test[], int from, int& x_base_for_match)
{
        for (int i = from; i < 37; i++) {
                if (value == values_for_test[i]) {
                        x_base_for_match = i;
                        return true;
                }
        }

        return false;
}

int main()
{
        while (true) {
                char x_str[32] = {0};
                char y_str[32] = {0};

                if (EOF == scanf("%s %s", x_str, y_str))
                        break;
                
                int base_from_x  = getBase(x_str);
                int base_from_y  = getBase(y_str);
                int x_values[37] = {0};

                for (int i = base_from_x; i < 37; i++)
                        x_values[i] = strtol(x_str, NULL, i);

                bool find_match = false;
                for (int i = base_from_y; i < 37; i++) {
                        int value            = strtol(y_str, NULL, i);
                        int x_base_for_match = 0;
                        if (valueMatchIn(value, x_values, base_from_x, x_base_for_match)) {
                                printf("%s (base %d) = %s (base %d)\n", x_str, x_base_for_match, y_str, i);
                                find_match = true;
                                break;
                        }
                }

                if (!find_match)
                        printf("%s is not equal to %s in any base 2..36\n", x_str, y_str);
        }
	return 0;
}

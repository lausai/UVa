#include <cstdio>

using namespace std;

int main()
{
        while (true) {
                int values[9] = {0};

                if (EOF == scanf("%d %d %d %d %d %d %d %d %d", &values[0], &values[1], &values[2], &values[3], &values[4], &values[5], &values[6], &values[7], &values[8]))
                        break;
                
                bool first_find = true;
                bool all_zero   = true;
                for (int i = 0; i < 9; i++) {
                        char coeffcients[16] = {0};

                        if (values[i] == 0) {
                                if (i == 8 && all_zero) printf("0");

                                continue;
                        }
                        
                        all_zero = false;

                        if (first_find) {
                                if ((values[i] != 1 && values[i] != -1) || i == 8)
                                        sprintf(coeffcients, "%d", values[i]);
                                else if (values[i] == -1)
                                        sprintf(coeffcients, "-");

                                first_find = false;
                        } else {
                                char op;
                                if (values[i] > 0) {
                                        op = '+';
                                } else {
                                        op        = '-';
                                        values[i] = -values[i];
                                }

                                if (values[i] != 1 || i == 8)
                                        sprintf(coeffcients, " %c %d", op, values[i]);
                                else
                                        sprintf(coeffcients, " %c ", op);
                        }

                        char x_degree[4] = {0};
                        if (i != 8) {
                                if (i == 7)
                                        sprintf(x_degree, "x");
                                else
                                        sprintf(x_degree, "x^%d", 8 - i);
                        }

                        printf("%s%s", coeffcients, x_degree);
                }
                puts("");
        }
	return 0;
}

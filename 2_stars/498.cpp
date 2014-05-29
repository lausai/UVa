#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
        int poly[1024] = {0};

        while (true) {
                bool exit_program = false;
                int poly_num      = 0;

                for (poly_num = 0; poly_num < sizeof(poly); poly_num++) {
                        if (EOF == scanf("%d", &poly[poly_num])) {
                                exit_program = true;
                                break;
                        }
                        
                        char ch = getc(stdin);
                        
                        if ('\n' == ch) {
                                break;
                        } else if (EOF == ch) {
                                exit_program = true;
                                break;
                        }
                }

                if (exit_program) break;
        
                while (true) {
                        char ch = 0;
                        int  x  = 0;
        
                        if (EOF == scanf("%d%c", &x, &ch)) {
                                exit_program = true;
                                break;
                        }
                        
                        double result = 0;

                        for (int i = poly_num, degree = 0; i >= 0; i--)
                                result += poly[i] * pow((double)x, degree++);
                        
                        printf("%d%c", (int)result, ch == '\n' ? '\n' : ' ');

                        if ('\n' == ch) {
                                break;
                        } else if (EOF == ch) {
                                exit_program = true;
                                break;
                        }
                }
                
                if (exit_program) break;
        }

	return 0;
}

#include <cstdio>
#include <climits>

using namespace std;

int main()
{
        int L = 0;

        while (scanf("%d\n", &L), L != 0) {
                int dis   = 2000000;
                int d_pos = -2000000;
                int r_pos = -2000000;
 
                for (int i = 0; i < L; i++) {
                        char tmp  = 0;

                        scanf("%c", &tmp);

                        switch (tmp) {
                                case 'R':
                                        if ((i - d_pos) < dis)
                                                dis = i - d_pos;

                                        r_pos = i;
                                        break;
                                case 'D':
                                        if ((i - r_pos) < dis)
                                                dis = i - r_pos;

                                        d_pos = i;
                                        break;
                                case 'Z':
                                        dis = 0;
                                        break;
                                default:
                                        break;
                        }
                }
                printf("%d\n", dis);
        }

	return 0;
}

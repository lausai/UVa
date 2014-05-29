#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
        char str[256] = {0};
        char* prefix  = "";
        int round = 1;

        while (scanf("%s", str), strcmp("END", str)) {
                char direct[4] = {0};
                char* pos = str, tmp = 0;
                int dis_int = 0, num_of_ch = 0;
                long double x = 0, y = 0, NE = 0, SE = 0;

                while (EOF != sscanf(pos, "%d%[^,.]%c%n", &dis_int, direct, &tmp, &num_of_ch)) {
                        long double dis = dis_int;

                        if (0 == strcmp("S", direct)) {
                                y -= dis;
                        } else if (0 == strcmp("W", direct)) {
                                x -= dis;
                        } else if (0 == strcmp("N", direct)) {
                                y += dis;
                        } else if (0 == strcmp("E", direct)) {
                                x += dis;
                        } else if (0 == strcmp("SW", direct)) {
                                NE -= dis;
                        } else if (0 == strcmp("NW", direct)) {
                                SE -= dis;
                        } else if (0 == strcmp("NE", direct)) {
                                NE += dis;
                        } else if (0 == strcmp("SE", direct)) {
                                SE += dis;
                        }

                        pos += num_of_ch;
                }
                
                long double abs_ne = abs(NE);

                if (NE > 0) {
                        x += sqrt(abs_ne * abs_ne / 2);
                        y += sqrt(abs_ne * abs_ne / 2);
                } else if (NE < 0) {
                        x -= sqrt(abs_ne * abs_ne / 2);
                        y -= sqrt(abs_ne * abs_ne / 2);
                }

                long double abs_se = abs(SE);

                if (SE > 0) {
                        x += sqrt(abs_se * abs_se / 2);
                        y -= sqrt(abs_se * abs_se / 2);
                } else if (SE < 0) {
                        x -= sqrt(abs_se * abs_se / 2);
                        y += sqrt(abs_se * abs_se / 2);
                }

                printf("Map #%d\n", round++);
                printf("The treasure is located at (%.3Lf,%.3Lf).\n", x, y);
                printf("The distance to the treasure is %.3Lf.\n\n", sqrt((x*x) + (y*y)));
        }

	return 0;
}

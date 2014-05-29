#include <cstdio>

using namespace std;

int main()
{
        double H, U, D, F;

        while (scanf("%lf %lf %lf %lf", &H, &U, &D, &F), 0 != H) {
                int day = 1;
                double tall = 0, fall = U * F / 100;

                for (day = 1; ; day++) {
                        double dis_up = U - (fall * (day - 1));

                        if (dis_up < 0) dis_up = 0;
                        
                        tall += dis_up;
                        if (tall > H) break;
                        tall -= D;
                        if (tall < 0) break;
                }

                if (tall > H)
                        printf("success on day %d\n", day);
                else
                        printf("failure on day %d\n", day);
        }

	return 0;
}

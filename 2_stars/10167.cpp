#include <cstdio>

using namespace std;

class Point
{
public:
    int X;
    int Y;
};

int main()
{
    int N = 0;
    while (scanf("%d", &N) == 1 && N != 0) {
        Point points[100] = {};
        int point_num = N * 2;
        for (int i = 0; i < point_num; i++) {
            scanf("%d %d", &points[i].X, &points[i].Y);
        }
        
        int a = -500;
        int b = -500;
        bool find = false;
        for (; a <= 500; a++) {
            for (b = -500; b <= 500; b++) {
                int great = 0;
                int less = 0;

                for (int i = 0; i < point_num; i++) {
                    if (a * points[i].X == -(b * points[i].Y))
                        break;
                    else if (a * points[i].X > -(b * points[i].Y))
                        great++;
                    else
                        less++;

                    if (great > N || less > N)
                        break;
                }

                if (great == N && less == N) {
                    find = true;
                    break;
                }

                // printf("a=%d b=%d great=%d less=%d\n", a, b, great, less);
            }

            if (find)
                break;
        }

        printf("%d %d\n", a, b);
    }
	return 0;
}

#include <cstdio>

using namespace std;

class point {
public:
    double x;
    double y;

    bool operator==(point& rhs)
    {
        return this->x == rhs.x && this->y == rhs.y;
    }
};

int main()
{
    point p1, p2, p3, p4;
    while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf",
        &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y, &p4.x, &p4.y) == 8) {

        point* p_same = NULL, *p_1 = NULL, *p_2 = NULL;
        if (p3 == p1) {
            p_same = &p3;
            p_1 = &p2;
            p_2 = &p4;
        } else if (p3 == p2) {
            p_same = &p3;
            p_1 = &p1;
            p_2 = &p4;
        } else if (p4 == p1) {
            p_same = &p4;
            p_1 = &p2;
            p_2 = &p3;
        } else {
            p_same = &p4;
            p_1 = &p1;
            p_2 = &p3;
        }

        printf("%.3f %.3f\n", p_1->x + (p_2->x - p_same->x), p_1->y + (p_2->y - p_same->y));
    }

	return 0;
}

#include <cstdio>
#include <cmath>

using namespace std;

inline double pow2(double d1)
{
        return d1 * d1;
}

class Fig {
public:
        char ch;
        double pos[6];
};

class Vec {
public:
        Vec(double x1, double y1, double x2, double y2) : x(x1 - x2), y(y1 - y2) {}
        double x, y;
};

double VecMulti(Vec& v1, Vec& v2)
{
        return (v1.x * v2.y) - (v1.y * v2.x);
}

bool insideC(Fig& fig, double x, double y)
{

        double d = ((x - fig.pos[0]) * (x - fig.pos[0])) + ((y - fig.pos[1]) * (y - fig.pos[1]));
        double dis = sqrt(d);
        
        return (dis >= fig.pos[2]) ? false : true;
}

bool insideR(Fig& fig, double x, double y)
{
        if ((x >= fig.pos[0] && x >= fig.pos[2]) || (x <= fig.pos[0] && x <= fig.pos[2]))
                return false;

        if ((y >= fig.pos[1] && y >= fig.pos[3]) || (y <= fig.pos[1] && y <= fig.pos[3]))
                return false;

        return true;
}

bool insideT(Fig& fig, double x, double y)
{
        Vec v1(fig.pos[0], fig.pos[1], fig.pos[2], fig.pos[3]); 
        Vec v2(fig.pos[2], fig.pos[3], fig.pos[4], fig.pos[5]); 
        Vec v3(fig.pos[4], fig.pos[5], fig.pos[0], fig.pos[1]); 
        
        Vec ap(x, y, fig.pos[0], fig.pos[1]);
        Vec bp(x, y, fig.pos[2], fig.pos[3]);
        Vec cp(x, y, fig.pos[4], fig.pos[5]);
        
        if (VecMulti(v1, ap) > 0 && VecMulti(v2, bp) > 0 && VecMulti(v3, cp) > 0)
                return true;

        if (VecMulti(v1, ap) < 0 && VecMulti(v2, bp) < 0 && VecMulti(v3, cp) < 0)
                return true;

        return false;
}

int main()
{
        char ch;

        Fig figs[10]    = {0};
        int num_of_figs = 0;

        for (num_of_figs; ; num_of_figs++) {
                scanf("%c", &ch);
                if (ch == '*') break;
                
                int num_of_pos = 0;

                switch (ch) {
                        case 'r':
                                figs[num_of_figs].ch = ch;
                                num_of_pos = 4;
                                break;
                        case 'c':
                                figs[num_of_figs].ch = ch;
                                num_of_pos = 3;
                                break;
                        case 't':
                                figs[num_of_figs].ch = ch;
                                num_of_pos = 6;
                                break;
                        default:
                                ;
                }
                
                for (int j = 0; j < num_of_pos; j++)
                        scanf("%lf", &figs[num_of_figs].pos[j]);
                
                scanf("\n");
        }

        double x = 0, y = 0;
        int num_of_point = 1;

        while (scanf("%lf %lf", &x, &y), x != 9999.9 && y != 9999.9) {
                bool is_contained = false;

                for (int i = 0; i < num_of_figs; i++) {
                        switch (figs[i].ch) {
                                case 'r':
                                        if (insideR(figs[i], x, y)) {
                                                printf("Point %d is contained in figure %d\n", num_of_point, i + 1);
                                                is_contained = true;
                                        }
                                        break;
                                case 'c':
                                        if (insideC(figs[i], x, y)) {
                                                printf("Point %d is contained in figure %d\n", num_of_point, i + 1);
                                                is_contained = true;
                                        }
                                        break;
                                case 't':
                                        if (insideT(figs[i], x, y)) {
                                                printf("Point %d is contained in figure %d\n", num_of_point, i + 1);
                                                is_contained = true;
                                        }
                                        break;
                                default:
                                        ;
                        }
                        
                }

                if (!is_contained)
                        printf("Point %d is not contained in any figure\n", num_of_point);

                ++num_of_point;
        }

	return 0;
}

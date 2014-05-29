#include <cstdio>
#include <cmath>

#define square(x) (x)*(x)

//����I�����O
class Point
{
	public :
		double x, y;

		Point (double _x, double _y):x(_x), y(_y) {}
		Point () {}
};

//�p����I�������Z��
double distance(Point &p1, Point &p2)
{
	return sqrt(square(p1.x-p2.x) + square(p1.y-p2.y));
}

bool inArea(double len, Point &p)
{
	Point p1(0.0, 0.0), p2(len, 0.0), p3(0.0, len), p4(len, len);

	if (distance(p1, p) <= len &&
		distance(p2, p) <= len &&
		distance(p3, p) <= len &&
		distance(p4, p) <= len )
		return true;
	else
		return false;
}

int main()
{
	int N, a;

	while (scanf("%d %d", &N, &a), N!=0 && a!=0) {
		int M = 0;

		//Ū�J����
		for (int i=0; i<N; i++) {
			Point p;

			scanf("%lf %lf", &p.x, &p.y);
			if (inArea((double)a, p)) M++;		//�p�G�b�׽u�ϰ줤�h�֥[ M
		}

		printf("%0.5lf\n", ((double)M/N)*a*a);	//�� M �ন�B�I�� �p�⵲�G�~�|�O�B�I��
	}

	return 0;
}
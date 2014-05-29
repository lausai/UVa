#include <cstdio>
#include <cmath>

class rectangle
{
	public:
		double left_high[2], right_low[2];
		
		void setCoords(double left_high[], double right_low[])
		{
			this->left_high[0] = left_high[0];
			this->left_high[1] = left_high[1];
			this->right_low[0] = right_low[0];
			this->right_low[1] = right_low[1];
		}
};

class point
{
	public:
		double coord[2];
};

class circle
{
	public:
		double center[2];
		double radius;

		void setCoords(double center[], double radius)
		{
			this->center[0] = center[0];
			this->center[1] = center[1];
			this->radius    = radius;
		}
};

bool inRec(const point &pt, const rectangle &rec)
{
	if (pt.coord[0] < rec.right_low[0] &&
		pt.coord[0] > rec.left_high[0] &&
		pt.coord[1] > rec.right_low[1] &&
		pt.coord[1] < rec.left_high[1])
		return true;
	else
		return false;
}

bool inCircle(const point &pt, const circle &cir)
{
	if (sqrt((pt.coord[0]-cir.center[0])*(pt.coord[0]-cir.center[0]) + (pt.coord[1]-cir.center[1])*(pt.coord[1]-cir.center[1])) < cir.radius)
		return true;
	else
		return false;
}

int main()
{
	char picture_type[20] = {0};
	int num_pictures      = 0;
	rectangle recs[20];
	circle cirs[20];
	
	char c;
	while ('*' != (c=getc(stdin))) {
		double d[4];
		
		if ('r' == c) {
			for (int i=0; i<4; i++)
				scanf("%lf", &d[i]);
		
			rectangle rec;
			rec.setCoords(&d[0], &d[2]);
			recs[num_pictures] = rec;
			picture_type[num_pictures] = 'r';
		} else {
			for (int i=0; i<3; i++)
				scanf("%lf", &d[i]);

			circle cir;
			cir.setCoords(&d[0], d[2]);
			cirs[num_pictures] = cir;
			picture_type[num_pictures] = 'c';
		}

		num_pictures++;
		getc(stdin);
	}

	int num_pts = 0;
	point pt    = point();
	point pts[10000];

	while (scanf("%lf%lf", &pt.coord[0], &pt.coord[1])) {
		if (9999.9==pt.coord[0] && 9999.9==pt.coord[1]) break;
		pts[num_pts] = pt;
		num_pts++;
	}

	for (int i=0; i<num_pts; i++) {
		bool in_pic = false;

		for (int j=0; j<num_pictures; j++) {
			if ('r' == picture_type[j]) {
				if (inRec(pts[i], recs[j])) {
					printf("Point %d is contained in figure %d\n", i+1, j+1);
					in_pic = true;
				}
			} else {
				if (inCircle(pts[i], cirs[j])) {
					printf("Point %d is contained in figure %d\n", i+1, j+1);
					in_pic = true;
				}
			}
		}

		if (false == in_pic) printf("Point %d is not contained in any figure\n", i+1);
	}

	return 0;
}
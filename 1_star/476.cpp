#include <cstdio>

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

int main()
{
	int num_recs = 0;
	rectangle recs[10];
	
	while ('*' != getc(stdin)) {
		double d[4];
		
		for (int i=0; i<4; i++)
			scanf("%lf", &d[i]);
		
		rectangle rec;
		rec.setCoords(&d[0], &d[2]);
		recs[num_recs] = rec;
		num_recs++;
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
		bool in_rec = false;

		for (int j=0; j<num_recs; j++) {
			if (inRec(pts[i], recs[j])) {
				printf("Point %d is contained in figure %d\n", i+1, j+1);
				in_rec = true;
			}
		}
		if (false == in_rec) printf("Point %d is not contained in any figure\n", i+1);
	}

	return 0;
}
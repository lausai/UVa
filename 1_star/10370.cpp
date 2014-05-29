#include <cstdio>

int main()
{
	int C;									//共做幾循環

	scanf("%d", &C);
	for (int i=0; i<C; i++) {
		double grades[1000] = {0};
		double grade_sum    = 0;
		double people;						//該班學生有幾人

		scanf("%lf", &people);
		for (int j=0; j<people; j++) {
			scanf("%lf", &grades[j]);		//讀進學生成績
			grade_sum += grades[j];			//學生成績加總
		}

		double aver = grade_sum / people;	//平均成績

		double count = 0.0;					//高於平均成績的人數
		for (int j=0; j<people; j++)
			if (grades[j] > aver) count++;

		printf("%.3lf%\n", (count*100) / people);
	}

	return 0;
}
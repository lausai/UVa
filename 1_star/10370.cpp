#include <cstdio>

int main()
{
	int C;									//�@���X�`��

	scanf("%d", &C);
	for (int i=0; i<C; i++) {
		double grades[1000] = {0};
		double grade_sum    = 0;
		double people;						//�ӯZ�ǥͦ��X�H

		scanf("%lf", &people);
		for (int j=0; j<people; j++) {
			scanf("%lf", &grades[j]);		//Ū�i�ǥͦ��Z
			grade_sum += grades[j];			//�ǥͦ��Z�[�`
		}

		double aver = grade_sum / people;	//�������Z

		double count = 0.0;					//���󥭧����Z���H��
		for (int j=0; j<people; j++)
			if (grades[j] > aver) count++;

		printf("%.3lf%\n", (count*100) / people);
	}

	return 0;
}
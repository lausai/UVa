#include <cstdio>
#include <cmath>

int main()
{
	int H, M;

	while (scanf("%d:%d", &H, &M), H!=0 || M!=0) {
		H = (H == 12) ? 0 : H;								//�ɰw���� 12 �ɨ��׬�0

		double angle_h = (H*30) + (0.5*M);					//�q 12 ��ɰw������
		double angle_m = M * 6;								//�q 12 ����w������
		double result  = fabs(angle_m - angle_h);			//�ɰw�P���w������

		result = (result > 180) ? (360-result) : result;
		printf("%0.3lf\n", result);
	}
	
	return 0;
}
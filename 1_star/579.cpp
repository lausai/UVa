#include <cstdio>
#include <cmath>

int main()
{
	int H, M;

	while (scanf("%d:%d", &H, &M), H!=0 || M!=0) {
		H = (H == 12) ? 0 : H;								//時針指到 12 時角度為0

		double angle_h = (H*30) + (0.5*M);					//從 12 到時針的角度
		double angle_m = M * 6;								//從 12 到分針的角度
		double result  = fabs(angle_m - angle_h);			//時針與分針的夾角

		result = (result > 180) ? (360-result) : result;
		printf("%0.3lf\n", result);
	}
	
	return 0;
}
#include <cstdio>
#include <cmath>

#define toasc(x) (x+48)		//將整數轉成該數字的 ascii 字元

//計算 n 換算成三進位時最高的位數是幾位數 prod 為該位數的值 為 0~2
int maxPow(int n, int &prod)
{
	int i = 0;

	prod = 1;
	while (true) {
		int tmp = pow(3, (double)i);

		if (tmp > n) {
			if ((tmp/3)*2 <= n)
				prod = 2;

			return i-1;
		} else if (tmp == n) {
			return i;
		}
		i++;
	}
}

int main()
{
	int N;

	while (scanf("%d", &N), 0 <= N) {
		char result[100] = {0};

		//前置處理 0 這個特別的 case
		if (0 == N) {
			puts("0");
			continue;
		}

		int count	  = 0;
		int max_power = 0;
		bool first	  = true;	//表示是不是第一次進入迴圈

		while (0 != N) {
			int prod, power;

			power = maxPow(N, prod);
			N	 -= pow(3, (double)power) * prod;
			
			//把 result 中需要用到的空間都初始化成 '0' 
			if (true == first) {
				for (int i=0; i<=power; i++)
					result[i] = toasc(0);

				first = false;
				result[0] = toasc(prod);
				max_power = power;
				continue;
			}

			result[max_power-power] = toasc(prod);		//依次方大小依序填上數值
		}
		puts(result);
	}

	return 0;
}
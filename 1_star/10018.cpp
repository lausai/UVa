#include <cstdio>
#include <cstdlib>
#include <cmath>

//計算數字有多少位數
int digitLen(long long int num)
{
	int len_digit = 0;

	while (0 != num) {
		num /= 10;
		len_digit++;
	}

	return len_digit;
}

//將數字反轉
long long int reverse(long long int num)
{
	long long int result     = 0;
	int           len_digits = digitLen(num);

	for (int i=len_digits-1; i>=0; i--) {
		int max_digit = (num/pow(10.0, (double)i));			//num 最高位數字

		//num 一步步將最高位數字去掉 result 一步步從最小位開始加 num 的最高位數字
		result += max_digit * pow(10.0, (double)len_digits-i-1);
		num    -= pow(10.0, (double)i) * max_digit;
	}

	return result;
}

//是否為迴文(palindrome)
bool isPalin(long long int num)
{
	long long int after_re = reverse(num);					//如果是迴文的話反轉後的數字應該會一樣

	if (after_re == num)
		return true;
	else
		return false;
}

int main()
{
	int rounds;

	scanf("%d", &rounds);

	for (int i=0; i<rounds; i++) {
		long long int result;

		scanf("%lld", &result);			//讀進測資
		result += reverse(result);		//不管一開始是不是迴文都要先做第一次反轉

		int count = 1;					//因為一開始先做了一次反轉 所以初始值為 1

		while (!isPalin(result)) {
			result += reverse(result);
			count++;
		}

		printf("%d %lld\n", count, result);
	}

	return 0;
}
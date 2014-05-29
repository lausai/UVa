#include <cstdio>
#include <cmath>

bool isPrime(int num)
{
	//前置檢查
	if (num == 2)   return true;		//2是質數
	if (num == 1)   return false;		//1不是質數
	if (num%2 == 0) {					//偶數不是質數
		//*divisor = 2;
		return false;
	}
	
	int limit = sqrt((double)num);
	for (int i=2; i<=limit; i++) {		//如果有一個整數能整除 num 則該數必定小於等於 num 開根號
		if (num%i == 0) {
			//*divisor = i;
			return false;
		}
	}

	return true;
}

int main()
{
	int sets;

	scanf("%d\n", &sets);				//讀入 \n 把換行字元吃掉
	for (int i=1; i<=sets; i++) {
		int  record[123] = {0};
		char ch			 = 0;

		while (ch=getc(stdin), '\n'!=ch)		//用 ascii 值當成 index
			record[ch]++;						//陣列的中該 index 的值就是該字元出現的次數

		char result[100] = {0};
		int  count		 = 0;
		for (char j=48; j<=122; j++) {			//0~9 a~z A~Z 的 ascii 值都在 48~122 之間
			if (0!=record[j] && isPrime(record[j])) {
				result[count] = j;
				count++;
			}
		}

		if (0 == count)
			printf("Case %d: empty\n", i);
		else
			printf("Case %d: %s\n", i, result);
	}

	return 0;
}
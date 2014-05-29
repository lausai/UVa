#include <cstdio>
#include <cmath>

int primes[]	= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int primes_size = sizeof(primes) / sizeof(primes[0]);

//判斷 num 是否為質數  如果不是質數則把最小的能整除 num 的除數紀錄在 divisor
bool isPrime(int num, int *divisor)
{
	//前置檢查
	if (num == 2)   return true;		//2是質數
	if (num == 1)   return false;		//1不是質數
	if (num%2 == 0) {					//偶數不是質數
		*divisor = 2;
		return false;
	}
	
	int limit = sqrt((double)num);
	for (int i=2; i<=limit; i++) {		//如果有一個整數能整除 num 則該數必定小於等於 num 開根號
		if (num%i == 0) {
			*divisor = i;
			return false;
		}
	}

	return true;
}

//找出 num 在 primes[] 陣列中的位置
int primePos(int num)
{
	for (int i=0; i<primes_size; i++)
		if (primes[i] == num) return i;

	return -1;
}

//將 num 質因數分解並且將質數出現的次數紀錄到 prime_rec 中
void analysis(int primes_rec[], int num)
{
	int divisor;
	while (!isPrime(num, &divisor)) {
		primes_rec[primePos(divisor)]++;
		num = num / divisor;
	}

	primes_rec[primePos(num)]++;
}

/*
void dumpArr(int arr[], int size)
{
	for (int i=0; i<size; i++)
		printf("%d ", arr[i]);

	printf("\n");
}
*/

//將結果照題目所需格式印出
void printResult(int num, int primes_rec[])
{
	printf("%3d! =", num);

	int max_prime_pos = primes_size-1;
	while (primes_rec[max_prime_pos] == 0)
		max_prime_pos--;

	for (int i=0; i<=max_prime_pos; i++) {
		printf("%3d", primes_rec[i]);
		if ((i+1)%15==0 && max_prime_pos>14) printf("\n      ");		//剛好15個質數時不需換行
	}

	printf("\n");
}

int main()
{
	while (true) {
		int num;
		int primes_rec[25] = {0};	//紀錄 num 階乘中那25個質數出現的次數

		scanf("%d", &num);
		if (num == 0) break;

		for (int i=num; i>1; i--)
			analysis(primes_rec, i);

		printResult(num, primes_rec);
	}

	return 0;
}
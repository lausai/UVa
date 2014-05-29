#include <iostream>
#include <cmath>

using namespace std;

/*bool isPrime(int num)
{
	//前置檢查
	if (num == 2) return true;					//2是質數
	if ((num%2)==0 || num==1) return false;		//偶數跟 1 不是質數
	
	int limit = sqrt((double)num);
	for (int i=2; i<=limit; i++) {		//如果有一個整數能整除 num 則該數必定小於等於 num 開根號
		if (num%i == 0) return false;
	}

	return true;
}*/

//算出 num 的所有除數
int divisors(int num)
{
	int divs  = 0;
	int limit = sqrt((double)num);
	for (int i=1; i<=limit; i++) {
		if (num%i == 0) ++divs;
	}

	return ((limit*limit) == num) ? ((divs*2) - 1) : (divs * 2);
}

int main()
{
	int N, P;

	cin >> N;						//讀入總共有幾組測資
	for (int i=1; i<=N; i++) {
		int L, U, divs, pre_divs = 0;

		cin >> L >> U;				//讀入測資

		for (int j=L; j<=U; j++) {
			divs = divisors(j);
			if (divs > pre_divs) {
				P = j;
				pre_divs = divs;
			}
		}

		cout << "Between " << L << " and " << U << ", " << P << " has a maximum of " << pre_divs << " divisors.\n";
	}
	return 0;
}
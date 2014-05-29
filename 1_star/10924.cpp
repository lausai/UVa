//肈 1 璶粄琌借计 玥ぃ穦 AC

#include <cstdio>
#include <cmath>

bool isPrime(int num)
{
	//玡竚浪琩
	if (num == 2)   return true;		//2琌借计
	if (num == 1)   return true;		//1ぃ琌借计
	if (num%2 == 0) {					//案计ぃ琌借计
		//*divisor = 2;
		return false;
	}
	
	int limit = sqrt((double)num);
	for (int i=2; i<=limit; i++) {		//狦Τ俱计俱埃 num 玥赣计ゲ﹚单 num 秨腹
		if (num%i == 0) {
			//*divisor = i;
			return false;
		}
	}

	return true;
}

int main()
{
	int table[123] = {0};
	int count	   = 1;

	//  index 琌 a~z A~Z  asc 
	for (int i=97; i<=122; i++) {
		table[i] = count;
		count++;
	}

	for (int i=65; i<=90; i++) {
		table[i] = count;
		count++;
	}

	char ch;
	int num = 0;
	while (EOF != (ch=getc(stdin))) {
		if ('\n' == ch) {
			if (isPrime(num))
				puts("It is a prime word.");
			else
				puts("It is not a prime word.");

			num = 0;
			continue;
		}

		num += table[ch];
	}

	return 0;
}
#include <cstdio>

int main()
{
	long long int odd_numbers;		//魁–︽块计

	while (EOF != scanf("%ld", &odd_numbers)) {
		//衡Τ odd_numbers 计ê︽程计
		long long int last_number = (((odd_numbers+1)*(odd_numbers+1)) / 2) - 1;

		//赣︽程计 = 程计搭
		long long int result = (last_number*3) - 6;

		printf("%ld\n", result);
	}

	return 0;
}
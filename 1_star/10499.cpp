#include <cstdio>

int main()
{
	long long int n;

	while (scanf("%lld", &n), n>0) {
		if (1 == n)
			printf("0%%\n");
		else
			printf("%lld%%\n", n*25);		//���ά� n ���� �Q��N�� n*25 %
	}

	return 0;
}
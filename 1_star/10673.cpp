#include <cstdio>

int main()
{
	int sets;			//�@���h�ֲմ������

	scanf("%d", &sets);

	for (int i=0; i<sets; i++) {
		long long x, k;
		
		scanf("%lld %lld", &x, &k);

		if (x%k == 0)
			printf("%d %lld\n", 0, k);
		else
			printf("%lld %lld\n", -x, x);
	}
	return 0;
}
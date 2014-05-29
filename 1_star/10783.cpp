#include <cstdio>

//計算 a b 之間的奇數個數有幾個
inline int numEntrys(int a, int b)
{
	return (b-a+2)/2;
}

int main()
{
	int sets;

	scanf("%d", &sets);
	for (int i=1; i<=sets; i++) {
		int i1, i2;

		scanf("%d\n%d", &i1, &i2);

		if (i1!=1 && i1%2==0) i1 += 1;
		if (i2!=1 && i2%2==0) i2 -= 1;

		printf("Case %d: %d\n", i, numEntrys(i1, i2)*(i1+i2) / 2);
	}

	return 0;
}
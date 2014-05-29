#include <cstdio>

int main()
{
	int t, v;

	while (EOF != scanf("%d %d", &v, &t))
		printf("%d\n", 2*t*v);

	return 0;
}
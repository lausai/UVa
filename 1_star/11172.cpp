#include <cstdio>

int main()
{
	int sets;

	scanf("%d", &sets);

	for (int i=0; i<sets; i++) {
		int a, b;

		scanf("%d %d", &a, &b);

		if (a > b)
			puts(">");
		else if (a < b)
			puts("<");
		else
			puts("=");
	}

	return 0;
}
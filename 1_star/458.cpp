#include <cstdio>

int main()
{
	char c;
	while (EOF != scanf("%c", &c)) {
		if ('\n' != c)
			printf("%c", c-7);
		else
			printf("\n");
	}

	return 0;
}
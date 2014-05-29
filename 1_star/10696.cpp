#include <cstdio>

unsigned int f91(unsigned int data)
{
	if (data <= 100)
		return f91(f91(data+11));
	else
		return data-10;
}

int main()
{
	unsigned int data;

	while (scanf("%u", &data), 0 != data)
		printf("f91(%u) = %u\n", data, f91(data));

	return 0;
}
#include <cstdio>
#include <cstdlib>
#include <cctype>

int main()
{
	char num[11] = {0};

	//���_Ū�i���ꪽ����ꬰ�t��
	while (scanf("%s", num), num[0] != '-') {
		unsigned long int i;

		if (num[1] == 'x') {
			i = strtoul(num, NULL, 16);		//�� strtoul �N 16 �i��r���ন���

			printf("%u\n", i);
		} else {
			i = atoi(num);					//�� atoi �N 10 �i��r���ন���

			printf("0x%X\n", i);			//�� %X �ӿ�X�j�g 16 �i��r��
		}
	}

	return 0;
}
#include <cstdio>

int main()
{
	long long int odd_numbers;		//�����C�@���J���Ʀr

	while (EOF != scanf("%ld", &odd_numbers)) {
		//��X�� odd_numbers �ө_�ƨ��@��̫᭱���Ʀr
		long long int last_number = (((odd_numbers+1)*(odd_numbers+1)) / 2) - 1;

		//�Ӧ�̫᭱�T�ӼƦr�ۥ[ = �̫᭱���Ʀr���T�A��@
		long long int result = (last_number*3) - 6;

		printf("%ld\n", result);
	}

	return 0;
}
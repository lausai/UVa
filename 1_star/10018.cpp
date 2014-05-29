#include <cstdio>
#include <cstdlib>
#include <cmath>

//�p��Ʀr���h�֦��
int digitLen(long long int num)
{
	int len_digit = 0;

	while (0 != num) {
		num /= 10;
		len_digit++;
	}

	return len_digit;
}

//�N�Ʀr����
long long int reverse(long long int num)
{
	long long int result     = 0;
	int           len_digits = digitLen(num);

	for (int i=len_digits-1; i>=0; i--) {
		int max_digit = (num/pow(10.0, (double)i));			//num �̰���Ʀr

		//num �@�B�B�N�̰���Ʀr�h�� result �@�B�B�q�̤p��}�l�[ num ���̰���Ʀr
		result += max_digit * pow(10.0, (double)len_digits-i-1);
		num    -= pow(10.0, (double)i) * max_digit;
	}

	return result;
}

//�O�_���j��(palindrome)
bool isPalin(long long int num)
{
	long long int after_re = reverse(num);					//�p�G�O�j�媺�ܤ���᪺�Ʀr���ӷ|�@��

	if (after_re == num)
		return true;
	else
		return false;
}

int main()
{
	int rounds;

	scanf("%d", &rounds);

	for (int i=0; i<rounds; i++) {
		long long int result;

		scanf("%lld", &result);			//Ū�i����
		result += reverse(result);		//���ޤ@�}�l�O���O�j�峣�n�����Ĥ@������

		int count = 1;					//�]���@�}�l�����F�@������ �ҥH��l�Ȭ� 1

		while (!isPalin(result)) {
			result += reverse(result);
			count++;
		}

		printf("%d %lld\n", count, result);
	}

	return 0;
}
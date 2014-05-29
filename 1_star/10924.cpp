//���D�� 1 �n�{���O��� �_�h���| AC

#include <cstdio>
#include <cmath>

bool isPrime(int num)
{
	//�e�m�ˬd
	if (num == 2)   return true;		//2�O���
	if (num == 1)   return true;		//1���O���
	if (num%2 == 0) {					//���Ƥ��O���
		//*divisor = 2;
		return false;
	}
	
	int limit = sqrt((double)num);
	for (int i=2; i<=limit; i++) {		//�p�G���@�Ӿ�Ư�㰣 num �h�Ӽƥ��w�p�󵥩� num �}�ڸ�
		if (num%i == 0) {
			//*divisor = i;
			return false;
		}
	}

	return true;
}

int main()
{
	int table[123] = {0};
	int count	   = 1;

	//���ت� �� index �O a~z A~Z �� asc ��
	for (int i=97; i<=122; i++) {
		table[i] = count;
		count++;
	}

	for (int i=65; i<=90; i++) {
		table[i] = count;
		count++;
	}

	char ch;
	int num = 0;
	while (EOF != (ch=getc(stdin))) {
		if ('\n' == ch) {
			if (isPrime(num))
				puts("It is a prime word.");
			else
				puts("It is not a prime word.");

			num = 0;
			continue;
		}

		num += table[ch];
	}

	return 0;
}
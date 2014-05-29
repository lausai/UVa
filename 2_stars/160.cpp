#include <cstdio>
#include <cmath>

int primes[]	= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int primes_size = sizeof(primes) / sizeof(primes[0]);

//�P�_ num �O�_�����  �p�G���O��ƫh��̤p����㰣 num �����Ƭ����b divisor
bool isPrime(int num, int *divisor)
{
	//�e�m�ˬd
	if (num == 2)   return true;		//2�O���
	if (num == 1)   return false;		//1���O���
	if (num%2 == 0) {					//���Ƥ��O���
		*divisor = 2;
		return false;
	}
	
	int limit = sqrt((double)num);
	for (int i=2; i<=limit; i++) {		//�p�G���@�Ӿ�Ư�㰣 num �h�Ӽƥ��w�p�󵥩� num �}�ڸ�
		if (num%i == 0) {
			*divisor = i;
			return false;
		}
	}

	return true;
}

//��X num �b primes[] �}�C������m
int primePos(int num)
{
	for (int i=0; i<primes_size; i++)
		if (primes[i] == num) return i;

	return -1;
}

//�N num ��]�Ƥ��ѨåB�N��ƥX�{�����Ƭ����� prime_rec ��
void analysis(int primes_rec[], int num)
{
	int divisor;
	while (!isPrime(num, &divisor)) {
		primes_rec[primePos(divisor)]++;
		num = num / divisor;
	}

	primes_rec[primePos(num)]++;
}

/*
void dumpArr(int arr[], int size)
{
	for (int i=0; i<size; i++)
		printf("%d ", arr[i]);

	printf("\n");
}
*/

//�N���G���D�ةһݮ榡�L�X
void printResult(int num, int primes_rec[])
{
	printf("%3d! =", num);

	int max_prime_pos = primes_size-1;
	while (primes_rec[max_prime_pos] == 0)
		max_prime_pos--;

	for (int i=0; i<=max_prime_pos; i++) {
		printf("%3d", primes_rec[i]);
		if ((i+1)%15==0 && max_prime_pos>14) printf("\n      ");		//��n15�ӽ�Ʈɤ��ݴ���
	}

	printf("\n");
}

int main()
{
	while (true) {
		int num;
		int primes_rec[25] = {0};	//���� num ��������25�ӽ�ƥX�{������

		scanf("%d", &num);
		if (num == 0) break;

		for (int i=num; i>1; i--)
			analysis(primes_rec, i);

		printResult(num, primes_rec);
	}

	return 0;
}
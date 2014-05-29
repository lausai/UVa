#include <cstdio>
#include <cmath>

#define toasc(x) (x+48)		//�N����ন�ӼƦr�� ascii �r��

//�p�� n ���⦨�T�i��ɳ̰�����ƬO�X��� prod ���Ӧ�ƪ��� �� 0~2
int maxPow(int n, int &prod)
{
	int i = 0;

	prod = 1;
	while (true) {
		int tmp = pow(3, (double)i);

		if (tmp > n) {
			if ((tmp/3)*2 <= n)
				prod = 2;

			return i-1;
		} else if (tmp == n) {
			return i;
		}
		i++;
	}
}

int main()
{
	int N;

	while (scanf("%d", &N), 0 <= N) {
		char result[100] = {0};

		//�e�m�B�z 0 �o�ӯS�O�� case
		if (0 == N) {
			puts("0");
			continue;
		}

		int count	  = 0;
		int max_power = 0;
		bool first	  = true;	//��ܬO���O�Ĥ@���i�J�j��

		while (0 != N) {
			int prod, power;

			power = maxPow(N, prod);
			N	 -= pow(3, (double)power) * prod;
			
			//�� result ���ݭn�Ψ쪺�Ŷ�����l�Ʀ� '0' 
			if (true == first) {
				for (int i=0; i<=power; i++)
					result[i] = toasc(0);

				first = false;
				result[0] = toasc(prod);
				max_power = power;
				continue;
			}

			result[max_power-power] = toasc(prod);		//�̦���j�p�̧Ƕ�W�ƭ�
		}
		puts(result);
	}

	return 0;
}
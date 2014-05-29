#include <iostream>
#include <cmath>

using namespace std;

/*bool isPrime(int num)
{
	//�e�m�ˬd
	if (num == 2) return true;					//2�O���
	if ((num%2)==0 || num==1) return false;		//���Ƹ� 1 ���O���
	
	int limit = sqrt((double)num);
	for (int i=2; i<=limit; i++) {		//�p�G���@�Ӿ�Ư�㰣 num �h�Ӽƥ��w�p�󵥩� num �}�ڸ�
		if (num%i == 0) return false;
	}

	return true;
}*/

//��X num ���Ҧ�����
int divisors(int num)
{
	int divs  = 0;
	int limit = sqrt((double)num);
	for (int i=1; i<=limit; i++) {
		if (num%i == 0) ++divs;
	}

	return ((limit*limit) == num) ? ((divs*2) - 1) : (divs * 2);
}

int main()
{
	int N, P;

	cin >> N;						//Ū�J�`�@���X�մ���
	for (int i=1; i<=N; i++) {
		int L, U, divs, pre_divs = 0;

		cin >> L >> U;				//Ū�J����

		for (int j=L; j<=U; j++) {
			divs = divisors(j);
			if (divs > pre_divs) {
				P = j;
				pre_divs = divs;
			}
		}

		cout << "Between " << L << " and " << U << ", " << P << " has a maximum of " << pre_divs << " divisors.\n";
	}
	return 0;
}
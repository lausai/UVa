#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//��X�Y�ƪ������
inline int fastSquare(int x)
{
	return x * x;
}

int main()
{
	int n;

	cout << setfill('0');				//�]�w�L�X�ɸɹs

	while (cin >> n) {
		int div   = pow(10.0, n/2);		
		int limit = pow(10.0, n) - 1;	//�e�׬� n ���̤j��

		cout << setw(n);				//�]�w�L�X�ɪ��Ʀr�e��
		cout << 0 << endl;				//�`�O���L�X 0

		for (int i=1; i<=limit; i++) {
			int n1 = i / div;			//�Ʀr i ���e�b����
			int n2 = i % div;			//�Ʀr i ����b����

			if (fastSquare(n1+n2) == i) {
				cout << setw(n);
				cout << i << endl;
			}
		}
	}

	return 0;
}
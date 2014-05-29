#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//衡琘计キよ
inline int fastSquare(int x)
{
	return x * x;
}

int main()
{
	int n;

	cout << setfill('0');				//砞﹚干箂

	while (cin >> n) {
		int div   = pow(10.0, n/2);		
		int limit = pow(10.0, n) - 1;	//糴 n 程

		cout << setw(n);				//砞﹚计糴
		cout << 0 << endl;				//羆琌 0

		for (int i=1; i<=limit; i++) {
			int n1 = i / div;			//计 i 玡场
			int n2 = i % div;			//计 i 场

			if (fastSquare(n1+n2) == i) {
				cout << setw(n);
				cout << i << endl;
			}
		}
	}

	return 0;
}
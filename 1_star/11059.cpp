#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

//�q data ���쪺��}�W���s�� num �Ӿ�ƭ��_�ӶǦ^
long long int product(int *data, int num)
{
	long long int result = 1;

	for (int i=0; i<num; i++) {
		long long int tmp;

		tmp = data[i];
		result *= tmp;
	}

	return result;
}

int main()
{
	int num_data;											//�`�@���h�־��
	int counter = 1;										//�����o���ĴX��case

	while (EOF != scanf("%d", &num_data)) {
		int data[18] = {0};									//�x�s����
		vector<long long int> products;						//�x�s�Ҧ������n

		for (int i=0; i<num_data; i++)						//�N�Ҧ����Ū�i��
			scanf("%d", &data[i]);
		
		for (int i=1; i<=num_data; i++) {					//�ۭ�����Ƽƶq�q 1 �}�l�� num_data ����
			for (int j=0; j<=num_data-i; j++)				//�q��} 0 �}�l �C���ۭ� i �Ӿ�� ���� ��}num_data-i
				products.push_back(product(&data[j], i));
		}

		sort(products.begin(), products.end());

		long long int result;
		if (0 < products.back())
			result = products.back();
		else
			result = 0;

		printf("Case #%d: The maximum product is %lld.\n\n", counter, result);
		counter++;
	}

	return 0;
}
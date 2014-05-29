#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

//從 data 指到的位址上面連續 num 個整數乘起來傳回
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
	int num_data;											//總共有多少整數
	int counter = 1;										//紀錄這次第幾個case

	while (EOF != scanf("%d", &num_data)) {
		int data[18] = {0};									//儲存測資
		vector<long long int> products;						//儲存所有的乘積

		for (int i=0; i<num_data; i++)						//將所有整數讀進來
			scanf("%d", &data[i]);
		
		for (int i=1; i<=num_data; i++) {					//相乘的整數數量從 1 開始到 num_data 為止
			for (int j=0; j<=num_data-i; j++)				//從位址 0 開始 每次相乘 i 個整數 直到 位址num_data-i
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
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> nums;									//纗代戈
	int i;												//赣Τぶ代戈

	while (EOF != scanf("%d", &i)) {
		nums.push_back(i);								//盢代戈 vector
		sort(nums.begin(), nums.end());					//パ暗逼

		vector<int>::size_type size = nums.size();

		if (1 == size) {								//Τじ い计碞琌赣计
			printf("%d\n", nums[0]);
		} else if (0 == size%2) {						//Τ案计じ
			int tmp = (nums[(size/2) - 1] + nums[size/2]) / 2;

			printf("%d\n", tmp);
		} else {										//Τ计じ
			printf("%d\n", nums[size/2]);
		}
	}

	return 0;
}
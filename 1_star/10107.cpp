#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> nums;									//�x�s����
	int i;												//�ӦC���h�ִ���

	while (EOF != scanf("%d", &i)) {
		nums.push_back(i);								//�N����s�J vector
		sort(nums.begin(), nums.end());					//�Ѥp��j���Ƨ�

		vector<int>::size_type size = nums.size();

		if (1 == size) {								//�u���@�Ӥ����� ����ƴN�O�Ӽ�
			printf("%d\n", nums[0]);
		} else if (0 == size%2) {						//�����ƪ�������
			int tmp = (nums[(size/2) - 1] + nums[size/2]) / 2;

			printf("%d\n", tmp);
		} else {										//���_�ƭӤ�����
			printf("%d\n", nums[size/2]);
		}
	}

	return 0;
}
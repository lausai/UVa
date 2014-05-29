#include <cstdio>
#include <cstdlib>

int main()
{
	int n;							//�����ӦC���h�ִ���

	while (EOF != scanf("%d", &n)) {
		int nums[3000] = {0};		//�x�s����

		//Ū�i����
		for (int i=0; i<n; i++)
			scanf("%d", &nums[i]);

		int diffs[2999] = {0};		//�x�s�۾F��ƪ��t

		//�p�G�۾F��ƪ��t�b 1 ~ n-1 ���� �h diffs �}�C�� index ���t�Ȫ���m�]�w�� 1
		for (int i=0; i<n-1; i++) {
			int diff = abs(nums[i]-nums[i+1]);
			if (diff <= n-1) diffs[diff-1] = 1;
		}

		//�p�G diffs �}�C���e n-1 �Ӥ����� 1  �N��۾F��ƪ��t��n�O 1 ~ n-1
		bool flag = true;
		for (int i=0; i<n-1; i++) {
			if (1 != diffs[i]) {
				flag = false;
				break;
			}
		}

		if (true == flag)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}

	return 0;
}
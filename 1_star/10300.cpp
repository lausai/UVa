#include <cstdio>

int main()
{
	int n;									//���X�մ���

	while (EOF != scanf("%d", &n)) {
		for (int i=0; i<n; i++) {
			int f;

			scanf("%d", &f);				//���X�ӹA��

			int reward = 0;					//����
			for (int j=0; j<f; j++) {
				int a, b, c;
				scanf("%d %d %d", &a, &b, &c);
				reward += a * c;			//�����N�O�A�����n * �A�����O����
			}

			printf("%d\n", reward);
		}
	}

	return 0;
}
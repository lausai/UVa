#include <cstdio>
#include <cstring>

int main()
{
	while (true) {
		char num[1001] = {0};

		scanf("%s", num);
		if (num[0]=='0' && num[1]==0) break;	//��J�� 0 �h���X�j��

		int len = strlen(num);					//���o�r�����
		int i = 0, j = 0;
		bool flag = true;

		for (int k=0; k<len; k++) {
			if (true == flag) {
				i += num[k]-48;					//ascii ��Ʀr�n�� 48
				flag = false;
			} else {
				j += num[k]-48;
				flag = true;
			}
		}

		if (0 == (i-j)%11)
			printf("%s is a multiple of 11.\n", num);
		else
			printf("%s is not a multiple of 11.\n", num);
	}

	return 0;
}
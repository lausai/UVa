#include <cstdio>
#include <cstring>

int main()
{
	char str[1002] = {0};
	bool first     = true;		//�����O�_���Ĥ@����X

	while (NULL != fgets(str, 1002, stdin)) {
		int record[256] = {0};					//�����r���X�{�X�� index �N�O�Ӧr���� ascii ��
		int len         = strlen(str) - 1;		//�r����� ��@�O�]������r���]�|�Q�s��}�C��

		//�}�l�O���C�Ӧr�����X�{����
		for (int i=0; i<len; i++)
			record[str[i]]++;

		if (first != true) printf("\n");		//�p�G���O�Ĥ@����X �h����X����r��

		//�]���n�ӥX�{���ƥѤp��j��X
		//�ҥH �q i = 1~1000 �}�l�j�M�}�C�����S�����Ӥ����O�X�{ i ����
		for (int i=1; i<=1000; i++) {

			//�]���n�� ascii �ȥѤj��p��X �ҥH index �q 255~0 �}�l�j��
			for (int j=255; j>=0; j--)
				if (i == record[j]) printf("%d %d\n", j, record[j]);
		}

		first = false;
	}

	return 0;
}
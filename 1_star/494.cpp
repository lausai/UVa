#include <cstdio>
#include <cctype>

int main()
{
	char line[500] = {0};						//�x�s�C�@��Ū�i�Ӫ��r��

	while (NULL != fgets(line, 500, stdin)) {	//fgets Ū������|�^�� NULL
		int counter = 0;						//�����C�@�檺 Word �Ӽ�
		int i       = 0;

		while ('\n' != line[i]) {
			//�@���ˬd����Y�r���O�^��r���ӥB�U�Ӧr�������^��r�� �h Word �ƥ[�@
			if (isalpha(line[i]) && !isalpha(line[i+1])) counter++;
			i++;
		}

		printf("%d\n", counter);
	}

	return 0;
}
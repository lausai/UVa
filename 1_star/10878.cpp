#include <cstdio>
#include <cmath>

int main()
{
	char line[15] = {0};

	while (NULL != gets(line)) {
		char binary[8] = {0};

		if (line[0] == '_') continue;		//Ū�� "________" �h�����B�z

		//����r�ꤤ�� 'o' �M ' ' ��i binary �}�C��
		int i = 0, j = 0;
		while ('\0' != line[i]) {
			if ('o'==line[i] || ' '==line[i]) {
				binary[j] = line[i];
				j++;
			}
			i++;
		}

		//�p��Ӧ��Ķ�X�ӬO���Ӧr�� 
		char ch = 0;
		for (int i=0; i<8; i++) {
			if ('o' == binary[i])
				ch += pow(2, (double)7-i);
		}

		printf("%c", ch);
	}

	return 0;
}
#include <cstdio>

int main()
{
	char ch;									//�x�s����
	int flag  = 1;								//�����X�r��������޸��Υk��޸�

	//Ū�J���ꪽ���J����
	while (EOF != scanf("%c", &ch)) {
		const char *quote;
		//�p�G�N�n��X���O���޸�  �h�i��N��
		if (ch == '"') {						
			quote = (flag == 1) ? "``" : "''";
			printf("%s", quote);
			flag *= -1;
		} else {
			printf("%c", ch);
		}
	}
	
	return 0;
}
#include <cstdio>
#include <cmath>

bool isPrime(int num)
{
	//�e�m�ˬd
	if (num == 2)   return true;		//2�O���
	if (num == 1)   return false;		//1���O���
	if (num%2 == 0) {					//���Ƥ��O���
		//*divisor = 2;
		return false;
	}
	
	int limit = sqrt((double)num);
	for (int i=2; i<=limit; i++) {		//�p�G���@�Ӿ�Ư�㰣 num �h�Ӽƥ��w�p�󵥩� num �}�ڸ�
		if (num%i == 0) {
			//*divisor = i;
			return false;
		}
	}

	return true;
}

int main()
{
	int sets;

	scanf("%d\n", &sets);				//Ū�J \n �⴫��r���Y��
	for (int i=1; i<=sets; i++) {
		int  record[123] = {0};
		char ch			 = 0;

		while (ch=getc(stdin), '\n'!=ch)		//�� ascii �ȷ� index
			record[ch]++;						//�}�C������ index ���ȴN�O�Ӧr���X�{������

		char result[100] = {0};
		int  count		 = 0;
		for (char j=48; j<=122; j++) {			//0~9 a~z A~Z �� ascii �ȳ��b 48~122 ����
			if (0!=record[j] && isPrime(record[j])) {
				result[count] = j;
				count++;
			}
		}

		if (0 == count)
			printf("Case %d: empty\n", i);
		else
			printf("Case %d: %s\n", i, result);
	}

	return 0;
}
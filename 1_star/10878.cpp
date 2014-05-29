#include <cstdio>
#include <cmath>

int main()
{
	char line[15] = {0};

	while (NULL != gets(line)) {
		char binary[8] = {0};

		if (line[0] == '_') continue;		//讀到 "________" 則不做處理

		//把整行字串中的 'o' 和 ' ' 放進 binary 陣列中
		int i = 0, j = 0;
		while ('\0' != line[i]) {
			if ('o'==line[i] || ' '==line[i]) {
				binary[j] = line[i];
				j++;
			}
			i++;
		}

		//計算該行解譯出來是哪個字元 
		char ch = 0;
		for (int i=0; i<8; i++) {
			if ('o' == binary[i])
				ch += pow(2, (double)7-i);
		}

		printf("%c", ch);
	}

	return 0;
}
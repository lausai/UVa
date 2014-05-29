#include <cstdio>
#include <cctype>

int main()
{
	char line[500] = {0};						//儲存每一行讀進來的字元

	while (NULL != fgets(line, 500, stdin)) {	//fgets 讀到文件尾會回傳 NULL
		int counter = 0;						//紀錄每一行的 Word 個數
		int i       = 0;

		while ('\n' != line[i]) {
			//一直檢查直到某字元是英文字母而且下個字元不為英文字母 則 Word 數加一
			if (isalpha(line[i]) && !isalpha(line[i+1])) counter++;
			i++;
		}

		printf("%d\n", counter);
	}

	return 0;
}
#include <cstdio>

int main()
{
	char ch;									//儲存測資
	int flag  = 1;								//控制輸出字元為左單引號或右單引號

	//讀入測資直到輸入結束
	while (EOF != scanf("%c", &ch)) {
		const char *quote;
		//如果將要輸出的是雙引號  則進行代換
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
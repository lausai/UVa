#include <cstdio>
#include <cstring>

int main()
{
	while (true) {
		char num[1001] = {0};

		scanf("%s", num);
		if (num[0]=='0' && num[1]==0) break;	//輸入為 0 則跳出迴圈

		int len = strlen(num);					//取得字串長度
		int i = 0, j = 0;
		bool flag = true;

		for (int k=0; k<len; k++) {
			if (true == flag) {
				i += num[k]-48;					//ascii 轉數字要減 48
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
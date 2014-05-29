#include <cstdio>
#include <cstdlib>
#include <cctype>

int main()
{
	char num[11] = {0};

	//不斷讀進測資直到測資為負數
	while (scanf("%s", num), num[0] != '-') {
		unsigned long int i;

		if (num[1] == 'x') {
			i = strtoul(num, NULL, 16);		//用 strtoul 將 16 進位字串轉成整數

			printf("%u\n", i);
		} else {
			i = atoi(num);					//用 atoi 將 10 進位字串轉成整數

			printf("0x%X\n", i);			//用 %X 來輸出大寫 16 進位字母
		}
	}

	return 0;
}
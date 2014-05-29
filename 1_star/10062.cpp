#include <cstdio>
#include <cstring>

int main()
{
	char str[1002] = {0};
	bool first     = true;		//紀錄是否為第一次輸出

	while (NULL != fgets(str, 1002, stdin)) {
		int record[256] = {0};					//紀錄字元出現幾次 index 就是該字元的 ascii 值
		int len         = strlen(str) - 1;		//字串長度 減一是因為換行字元也會被存到陣列中

		//開始記錄每個字元的出現次數
		for (int i=0; i<len; i++)
			record[str[i]]++;

		if (first != true) printf("\n");		//如果不是第一次輸出 則先輸出換行字元

		//因為要照出現次數由小到大輸出
		//所以 從 i = 1~1000 開始搜尋陣列中有沒有哪個元素是出現 i 次的
		for (int i=1; i<=1000; i++) {

			//因為要照 ascii 值由大到小輸出 所以 index 從 255~0 開始搜索
			for (int j=255; j>=0; j--)
				if (i == record[j]) printf("%d %d\n", j, record[j]);
		}

		first = false;
	}

	return 0;
}
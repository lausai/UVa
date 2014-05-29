#include <cstdio>

int main()
{
	int sets;

	scanf("%d", &sets);

	for (int i=0; i<sets; i++) {
		if (i > 0) puts("");			//不是第一次輸出則換行

		int cols;

		scanf("%d", &cols);				//讀取有多少直行

		int distance;
		bool flag = true;

		for (int j=0; j<cols; j++) {
			int y_axis[2] = {0};

			scanf("%d %d", &y_axis[0], &y_axis[1]);
			//把第一條直行的距離記起來
			if (0 == j) {
				distance = y_axis[0]-y_axis[1];
				continue;
			}
			
			int tmp = distance;

			if (y_axis[0]-y_axis[1] != tmp)
				flag = false;
		}

		if (true == flag)
			puts("yes");
		else
			puts("no");
	}

	return 0;
}
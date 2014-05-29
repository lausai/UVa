#include <cstdio>
#include <cstdlib>

int main()
{
	int num_stacks;
	int sets = 1;

	while (scanf("%d", &num_stacks), num_stacks != 0) {
		int heights[50] = {0};
		int num_boxes   = 0;

		//讀進資料並且算出所有 boxes 數量
		for (int i=0; i<num_stacks; i++) {
			scanf("%d", &heights[i]);
			num_boxes += heights[i];
		}

		int avg_height = num_boxes / num_stacks;	//平均高度 也就是移動 box 之後的 stack 高度
		int moves      = 0;							//紀錄移動次數

		//移動次數其實就是每一個 stack 的高度減去平均高度
		//但是這樣會算到兩次(大於和小於平均高度都算到) 所以最後要除以2
		for (int i=0; i<num_stacks; i++)
			moves += abs(heights[i]-avg_height);

		printf("Set #%d\n", sets);
		printf("The minimum number of moves is %d.\n\n", moves/2);

		sets++;
	}

	return 0;
}
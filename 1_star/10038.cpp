#include <cstdio>
#include <cstdlib>

int main()
{
	int n;							//紀錄該列有多少測資

	while (EOF != scanf("%d", &n)) {
		int nums[3000] = {0};		//儲存測資

		//讀進測資
		for (int i=0; i<n; i++)
			scanf("%d", &nums[i]);

		int diffs[2999] = {0};		//儲存相鄰兩數的差

		//如果相鄰兩數的差在 1 ~ n-1 之間 則 diffs 陣列中 index 為差值的位置設定為 1
		for (int i=0; i<n-1; i++) {
			int diff = abs(nums[i]-nums[i+1]);
			if (diff <= n-1) diffs[diff-1] = 1;
		}

		//如果 diffs 陣列中前 n-1 個元素為 1  代表相鄰兩數的差剛好是 1 ~ n-1
		bool flag = true;
		for (int i=0; i<n-1; i++) {
			if (1 != diffs[i]) {
				flag = false;
				break;
			}
		}

		if (true == flag)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}

	return 0;
}
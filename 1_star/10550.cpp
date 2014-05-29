#include <cstdio>

int main()
{
	int start, i1, i2, i3;

	while (true) {
		scanf("%d %d %d %d", &start, &i1, &i2, &i3);
		if (start==0 && i1==0 && i2==0 && i3==0) break;

		int angle = 0;

		angle += (start > i1) ? (start - i1) : (40 - i1 + start);
		angle += (i1 > i2) ? (40 - i1 + i2) : (i2 - i1);
		angle += (i2 > i3) ? (i2 - i3) : (40 - i3 + i2);
		angle += 120;					//題目中一定會轉三圈 是 120 個刻度

		printf("%d\n", angle*9);		//一個刻度是 9 度
	}

	return 0;
}
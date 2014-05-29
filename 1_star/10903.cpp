#include <cstdio>

/*猜拳比賽結果: 
 *	1: s1 贏 s2
 *	0: 平手
 * -1: s2 贏 s1
 */
int RPS(const char *s1, const char *s2)
{
	if (s1[0] == s2[0])
		return 0;
	else if (s1[0]=='r' && s2[0]=='s' ||
			 s1[0]=='s' && s2[0]=='p' ||
			 s1[0]=='p' && s2[0]=='r' )
		return 1;
	else
		return -1;
}

int main()
{
	int n, j = 0;		//j 表示這是第幾次的輸出資料

	while (scanf("%d", &n), 0 != n) {
		if (j > 0) puts("");			//輸出結果間要換行 第一次的輸出不用換行
		j++;

		int k;

		scanf("%d", &k);

		int round = k*n*(n-1) / 2;		//總共有多少場比賽
		int game_result[110][2] = {0};	//紀錄比賽結果 預設最多有 100 個玩家
										//第二維陣列的第一項為贏的次數 第二項為輸的次數

		for (int i=0; i<round; i++) {
			int p1, p2;
			char s1[10] = {0}, s2[10] = {0};

			scanf("%d %s %d %s", &p1, s1, &p2, s2);

			int result = RPS(s1, s2);

			if (1 == result) {			//p1 贏 p2
				game_result[p1][0]++;
				game_result[p2][1]++;
			} else if (-1 == result) {	//p2 贏 p1
				game_result[p2][0]++;
				game_result[p1][1]++;
			}
		}

		for (int i=1; i<=n; i++) {
			int w_add_l = game_result[i][0]+game_result[i][1];

			if (0 == w_add_l)
				puts("-");		//勝率無意義則輸出 "-"
			else
				printf("%.3f\n", (double)game_result[i][0] / w_add_l);
		}
	}

	return 0;
}
#include <cstdio>

using namespace std;

int main()
{
	int T = 0;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int N = 0;
		int walls[50] = {};
		int highJump = 0, lowJump = 0;

		scanf("%d", &N);
		scanf("%d", &walls[0]);
		
		for (int j = 1; j < N; j++) {
			scanf("%d", &walls[j]);

			if (walls[j] > walls[j - 1])
				highJump++;
			else if (walls[j] < walls[j - 1])
				lowJump++;
		}

		printf("Case %d: %d %d\n", i + 1, highJump, lowJump);
	}
	return 0;
}

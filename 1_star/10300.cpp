#include <cstdio>

int main()
{
	int n;									//有幾組測資

	while (EOF != scanf("%d", &n)) {
		for (int i=0; i<n; i++) {
			int f;

			scanf("%d", &f);				//有幾個農夫

			int reward = 0;					//獎金
			for (int j=0; j<f; j++) {
				int a, b, c;
				scanf("%d %d %d", &a, &b, &c);
				reward += a * c;			//獎金就是農場面積 * 農夫環保等級
			}

			printf("%d\n", reward);
		}
	}

	return 0;
}
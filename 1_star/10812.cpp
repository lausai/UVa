#include <cstdio>

int main()
{
	int sets;

	scanf("%d", &sets);

	for (int i=0; i<sets; i++) {
		int s, d;

		scanf("%d\n%d", &s, &d);

		//�p�G��㰣�~�~�򰵤U�h
		if ((s-d)%2 == 0) {
			int v1, v2;

			v1 = (s-d) / 2;
			v2 = s - v1;

			//���j�����Ƴ]�� v1
			if (v2 > v1) {
				int tmp = v1;

				v1 = v2;
				v2 = tmp;
			}

			if (v1>=0 && v2>=0)
				printf("%d %d\n", v1, v2);
			else
				puts("impossible");
		} else {
			puts("impossible");
		}
	}

	return 0;
}
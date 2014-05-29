#include <cstdio>

/*�q�����ɵ��G: 
 *	1: s1 Ĺ s2
 *	0: ����
 * -1: s2 Ĺ s1
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
	int n, j = 0;		//j ��ܳo�O�ĴX������X���

	while (scanf("%d", &n), 0 != n) {
		if (j > 0) puts("");			//��X���G���n���� �Ĥ@������X���δ���
		j++;

		int k;

		scanf("%d", &k);

		int round = k*n*(n-1) / 2;		//�`�@���h�ֳ�����
		int game_result[110][2] = {0};	//�������ɵ��G �w�]�̦h�� 100 �Ӫ��a
										//�ĤG���}�C���Ĥ@����Ĺ������ �ĤG�����骺����

		for (int i=0; i<round; i++) {
			int p1, p2;
			char s1[10] = {0}, s2[10] = {0};

			scanf("%d %s %d %s", &p1, s1, &p2, s2);

			int result = RPS(s1, s2);

			if (1 == result) {			//p1 Ĺ p2
				game_result[p1][0]++;
				game_result[p2][1]++;
			} else if (-1 == result) {	//p2 Ĺ p1
				game_result[p2][0]++;
				game_result[p1][1]++;
			}
		}

		for (int i=1; i<=n; i++) {
			int w_add_l = game_result[i][0]+game_result[i][1];

			if (0 == w_add_l)
				puts("-");		//�Ӳv�L�N�q�h��X "-"
			else
				printf("%.3f\n", (double)game_result[i][0] / w_add_l);
		}
	}

	return 0;
}
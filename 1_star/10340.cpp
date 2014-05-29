#include <cstdio>
#include <cstring>

#define LEN 90001

int main()
{
	char s[LEN] = {0};
	char t[LEN] = {0};

	while (EOF != scanf("%s %s", s, t)) {
		int len_s = strlen(s);
		int len_t = strlen(t);
		int pt    = 0;
		int count = 0;			//�r�� s �b t ����쪺�r����

		//�b t ���o�{�r�� s �� t �����U�@�Ӧr���~��d��
		//������� i or pt ���� s �� t �����ݬ���
		for (int i=0; i<len_s && pt<len_t; i++) {
			for (pt; pt<len_t; pt++) {
				if (t[pt] == s[i]) {
					pt++;
					count++;
					break;
				}
			}
		}

		printf("%s\n", (count==len_s) ? "Yes" : "No");
	}

	return 0;
}
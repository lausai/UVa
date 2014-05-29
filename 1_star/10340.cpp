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
		int count = 0;			//字串 s 在 t 中找到的字元數

		//在 t 中發現字元 s 跟 t 都取下一個字元繼續查找
		//直到指標 i or pt 指到 s 或 t 的尾端為止
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
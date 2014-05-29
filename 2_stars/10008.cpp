#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Record {
	char ch;
	int times;
};

int compare(const void* left, const void* right)
{
	Record* r1 = (Record*)left;
	Record* r2 = (Record*)right;

	if (r1->times < r2->times)
		return -1;
	else if (r1->times > r2->times)
		return 1;
		
	return r1->ch < r2->ch ? 1 : -1;
}

int main()
{
	int num = 0;
	char tmp = 0;

	scanf("%d%c", &num, &tmp);

	Record records[26] = {};

	for (int j = 0; j < 26; j++)
		records[j].ch = 'A' + j;			

	for (int i = 0; i < num; i++) {
		char str[1024] = {};

		if (!fgets(str, sizeof(str), stdin))
			break;
		
		int len = strlen(str) - 1;	// -1 for line feed

		for (int j = 0; j < len; j++) {
			int index = 0;

			if (str[j] >= 'A' && str[j] <= 'Z')
				index = str[j] - 'A';
			else if (str[j] >= 'a' && str[j] <= 'z')
				index = str[j] - 'a';
			else
				continue;
			
			records[index].times++;
		}
	}

	qsort(records, 26, sizeof(Record), compare);

	for (int i = 25; i >= 0; i--) {
		if (records[i].times == 0) break;

		printf("%c %d\n", records[i].ch, records[i].times);
	}

	return 0;
}

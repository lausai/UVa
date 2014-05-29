#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool DnaCompare(const char* dna1, const char* dna2)
{
	int len = strlen(dna1);
	int num1 = 0, num2 = 0;

	for (int i = 0; i < len - 1; i++) {
		char ch1 = dna1[i];
		char ch2 = dna2[i];

		for (int j = i; j < len; j++) {
			if (dna1[j] < ch1)
				num1++;

			if (dna2[j] < ch2)
				num2++;
		}
	}

	return num1 < num2;
}

int main()
{
	int numTests = 0;
	
	scanf("%d", &numTests);

	for (int i = 0; i < numTests; i++) {
		int n = 0, m = 0;
		char dna[100][51] = {};
		vector<char*> dnaList;

		scanf("%d %d", &n, &m);
		
		for (int j = 0; j < m; j++) {
			scanf("%s", dna[j]);
			dnaList.push_back(dna[j]);
		}

		stable_sort(dnaList.begin(), dnaList.end(), DnaCompare);

		int size = dnaList.size();

		for (int j = 0; j < size; j++)
			printf("%s\n", dnaList[j]);
        
        if (i < numTests - 1)
		    puts("");
	}

	return 0;
}

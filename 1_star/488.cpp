#include <cstdio>

//根據振幅將一個完整的波印出來
void printWave(int amp)
{
	int wave_len = (amp*2) - 1;			//波的長度

	for (int i=1; i<=wave_len; i++) {
		int j = i;

		if (i > amp) j = (2*amp) - i;
		for (int k=1; k<=j; k++)
			printf("%d", j);

		printf("\n");
	}
}

int main()
{
	int num_data;	//幾組測資
	int amp;		//振幅
	int freq;		//頻率

	scanf("%d", &num_data);

	for (int round=0; round<num_data; round++) {
		scanf("%d\n%d", &amp, &freq);

		for (int i=0; i<freq; i++) {
			printWave(amp);
			if (i!=freq-1 || round<num_data-1) printf("\n");
		}
	}

	return 0;
}
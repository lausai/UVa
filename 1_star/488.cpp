#include <cstdio>

//�ھڮ��T�N�@�ӧ��㪺�i�L�X��
void printWave(int amp)
{
	int wave_len = (amp*2) - 1;			//�i������

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
	int num_data;	//�X�մ���
	int amp;		//���T
	int freq;		//�W�v

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
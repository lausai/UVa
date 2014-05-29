#include <cstdio>
#include <cmath>

//��X�`�@���h�֤p��
int totalNum(int split_num, int split_times)
{
	int i, total = 1;
	for (i=1; i<=split_times; i++)
		total += pow((double)split_num, (double)i);

	return total;
}

//��X�����p�߰��ת��[�`
int totalTall(int tall, int split_num, int split_times)
{
	int i, total_tall = tall, _tall;
	for (i=1; i<=split_times; i++) {
		_tall		= tall / pow((double)split_num+1, (double)i);
		total_tall += (pow((double)split_num, (double)i) * _tall);
	}
	return total_tall;
}

int main()
{
	while (1) {
		int tall = 1, work = 1, split_num = 0, split_times = 0, idle, total_tall;

		scanf("%d%d", &tall, &work);
		if (tall==0 && work==0) break;

		//��X�������p�߼ƶq�H���`�@�����F�h�֦�
		for (double i=1; i<=tall; i++) {
			for (double j=1; pow(i+1, j)<=tall; j++) {
				if (pow(i+1, j)==tall && pow(i, j)==work) {
					split_times = j;
					split_num   = i;
					i			= tall+1;						//���X�Ĥ@�h�^��
					break;
				}
			}
		}

		work	   = pow((double)split_num, (double)split_times);
		idle	   = totalNum(split_num, split_times) - work;
		total_tall = totalTall(tall, split_num, split_times);
		printf("%d %d\n", idle, total_tall);
	}
	return 0;
}
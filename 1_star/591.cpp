#include <cstdio>
#include <cstdlib>

int main()
{
	int num_stacks;
	int sets = 1;

	while (scanf("%d", &num_stacks), num_stacks != 0) {
		int heights[50] = {0};
		int num_boxes   = 0;

		//Ū�i��ƨåB��X�Ҧ� boxes �ƶq
		for (int i=0; i<num_stacks; i++) {
			scanf("%d", &heights[i]);
			num_boxes += heights[i];
		}

		int avg_height = num_boxes / num_stacks;	//�������� �]�N�O���� box ���᪺ stack ����
		int moves      = 0;							//�������ʦ���

		//���ʦ��ƨ��N�O�C�@�� stack �����״�h��������
		//���O�o�˷|���⦸(�j��M�p�󥭧����׳����) �ҥH�̫�n���H2
		for (int i=0; i<num_stacks; i++)
			moves += abs(heights[i]-avg_height);

		printf("Set #%d\n", sets);
		printf("The minimum number of moves is %d.\n\n", moves/2);

		sets++;
	}

	return 0;
}
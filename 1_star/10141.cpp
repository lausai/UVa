#include <cstdio>
#include <cstring>

#define LEN 82

int main()
{
	int  n, p;
	int  count  = 1;							//�����O�ĴX�մ���

	//scanf �[ \n �⴫��r���]Ū�i�� �_�h����r���|�s�b input buffer ��
	while (scanf("%d %d\n", &n, &p), 0!=n || 0!=p) {
		char req[LEN] = {0};

		//Ū�i�U���ݨD
		for (int i=0; i<n; i++)
			fgets(req, LEN, stdin);

		char   comp[LEN] = {0};					//���������̦n�����q
		double d         = 0;					//�Ӥ��q������
		int    req_mets  = 0;					//�Ӥ��q�ŦX������
		for (int i=0; i<p; i++) {
			char cur_comp[LEN] = {0};
			int cur_req_mets;
			double cur_d;

			fgets(cur_comp, LEN, stdin);
			scanf("%lf %d\n", &cur_d, &cur_req_mets);

			//Ū�i�Ӥ��q�ŦX������
			char tmp[LEN] = {0};
			for (int j=0; j<cur_req_mets; j++)
				fgets(tmp, LEN, stdin);

			//�p�G�ŦX���ؼƶq�j��e�@�Ӥ��q �άO �ŦX���ؼƶq�ۦP���������� �h�N�e�@�Ӥ��q����
			if (cur_req_mets > req_mets) {
				req_mets = cur_req_mets;
				d = cur_d;
				strncpy(comp, cur_comp, strlen(cur_comp)+1);
			} else if (cur_req_mets == req_mets) {
				if (cur_d < d) {
					d = cur_d;
					strncpy(comp, cur_comp, strlen(cur_comp)+1);
				}
			}
		}

		if (count > 1) printf("\n");
		printf("RFP #%d\n%s", count++, comp);
	}

	return 0;
}
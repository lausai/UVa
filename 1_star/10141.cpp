#include <cstdio>
#include <cstring>

#define LEN 82

int main()
{
	int  n, p;
	int  count  = 1;							//紀錄是第幾組測資

	//scanf 加 \n 把換行字元也讀進來 否則換行字元會存在 input buffer 中
	while (scanf("%d %d\n", &n, &p), 0!=n || 0!=p) {
		char req[LEN] = {0};

		//讀進各項需求
		for (int i=0; i<n; i++)
			fgets(req, LEN, stdin);

		char   comp[LEN] = {0};					//紀錄報價最好的公司
		double d         = 0;					//該公司的報價
		int    req_mets  = 0;					//該公司符合的項目
		for (int i=0; i<p; i++) {
			char cur_comp[LEN] = {0};
			int cur_req_mets;
			double cur_d;

			fgets(cur_comp, LEN, stdin);
			scanf("%lf %d\n", &cur_d, &cur_req_mets);

			//讀進該公司符合的項目
			char tmp[LEN] = {0};
			for (int j=0; j<cur_req_mets; j++)
				fgets(tmp, LEN, stdin);

			//如果符合項目數量大於前一個公司 或是 符合項目數量相同但報價較少 則將前一個公司換掉
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
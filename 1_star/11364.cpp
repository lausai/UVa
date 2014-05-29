#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
        int round = 0;

        scanf("%d", &round);
        while (round-- > 0) {
                int num_of_stores = 0;
                
                scanf("%d", &num_of_stores);
                
                vector<int> store_list;
                for (int i = 0; i < num_of_stores; i++) {
                        int tmp;

                        scanf("%d", &tmp);
                        store_list.push_back(tmp);
                }

                sort(store_list.begin(), store_list.end());
                
                int result = 0;
                int pre_value = store_list[0];
                for (vector<int>::iterator it = store_list.begin(); it != store_list.end(); it++) {
                        result    += *it - pre_value;
                        pre_value = *it;
                }
                printf("%d\n", result * 2);
        }

	return 0;
}

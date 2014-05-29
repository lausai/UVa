#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
        int round = 0;

        scanf("%d", &round);
        while (round-- > 0) {
                int num_of_price = 0;
                
                scanf("%d", &num_of_price);
                vector<int> price_list;
                for (int i = 0; i < num_of_price; i++) {
                        int price = 0;

                        scanf("%d", &price);
                        price_list.push_back(price);
                }

                sort(price_list.begin(), price_list.end());
                
                int num    = num_of_price / 3;
                int index  = num_of_price - 3;
                int result = 0;

                for (int i = 0; i < num; i++, index -= 3)
                        result += price_list[index];

                printf("%d\n", result);
        }

	return 0;
}

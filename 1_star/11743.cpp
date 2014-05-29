#include <cstdio>

using namespace std;

int main()
{
        int round = 0;

        scanf("%d", &round);

        for (int i = 0; i < round; i++) {
                int odd = 0, even = 0;

                for (int j = 0; j < 4; j++) {
                        char num[8] = {0};

                        scanf("%s", num);
                        
                        int tmp1 = (num[0]-'0') * 2;
                        int tmp2 = (num[2]-'0') * 2;

                        even += (tmp1/10) + (tmp1%10) + (tmp2/10) + (tmp2%10);
                        odd  += (num[1]-'0') + (num[3]-'0');
                }

                if ((odd+even) % 10 != 0)
                        puts("Invalid");
                else
                        puts("Valid");
        }

	return 0;
}

#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
        int round = 0;
        
        scanf("%d", &round);

        for (int i = 0; i < round; i++) {
                char num[8] = {0};

                scanf("%s", num);

                long num1, num2;
                char op;

                num1 = strtol(num, NULL, 16);
                scanf(" %c ", &op);

                scanf("%s", num);
                num2 = strtol(num, NULL, 16);
                
                for (int i = 12; i >= 0; i--)
                        printf("%d", (num1 >> i) & 0x1);

                printf(" %c ",  op);

                for (int i = 12; i >= 0; i--)
                        printf("%d", (num2 >> i) & 0x1);
                
                printf(" = ");
                switch (op) {
                        case '+':
                                printf("%d\n", num1 + num2);
                                break;
                        case '-':
                                printf("%d\n", num1 - num2);
                                break;
                        default:
                                ;
                   }
        }

	return 0;
}

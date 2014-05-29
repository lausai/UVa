#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int num = 0;

    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        int D = 0, I = 0;
        
        scanf("%d %d", &D, &I);
        
        unsigned leaves = (unsigned )pow(2.0, D - 1);
        unsigned left_start = leaves;
        unsigned right_start = left_start + (leaves / 2);
        unsigned steps = I % leaves;
        unsigned answer = 0;
        
        if (steps == 0)
            steps = leaves;
        
        if (steps % 2 != 0) {
            if (steps > leaves / 2)
                answer = left_start + 1 + steps - 1 - (leaves / 2);
            else
                answer = left_start + steps - 1;
        } else {
            if ((steps - 1) > leaves / 2)
                answer = right_start + 1 + (steps - (leaves / 2) - 2);
            else
                answer = right_start + steps - 2;
        }

        printf("%u\n", answer);
    }

    scanf("%d", &num);

	return 0;
}

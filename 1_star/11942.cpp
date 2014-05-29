#include <cstdio>

using namespace std;

int main()
{
        int round = 0;

        scanf("%d", &round);

        puts("Lumberjacks:");
        for (int i = 0; i < round; i++) {
                bool ordered = true;
                int i1, i2;

                scanf("%d %d", &i1, &i2);

                bool is_inc = false;

                if (i1 < i2) 
                        is_inc = true;
                else if (i1 > i2)
                        is_inc = false;
                else
                        ordered = false;
                
                int pre_int = i2;

                for (int j = 0; j < 8; j++) {
                        int num = 0;

                        scanf("%d", &num);
                        if (!ordered) continue;

                        if (is_inc) {
                                if (num <= pre_int) ordered = false;
                        } else {
                                if (num >= pre_int) ordered = false;
                        }

                        pre_int = num;
                }

                if (ordered)
                        puts("Ordered");
                else
                        puts("Unordered");
        }

	return 0;
}

#include <cstdio>

using namespace std;

int main()
{
        int round = 0;

        scanf("%d", &round);

        for (int i = 0; i < round; i++) {
                int num_of_people;

                scanf("%d", &num_of_people);

                for (int j = 0; j < num_of_people; j++) {
                        int num = 0;

                        scanf("%d", &num);
                        if (j == (num_of_people-1) / 2)
                                printf("Case %d: %d\n", i + 1, num);
                }
        }

	return 0;
}

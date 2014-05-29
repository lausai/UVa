#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int numTestData = 0;

    scanf("%d\n", &numTestData);

    for (int i = 0; i < numTestData; i++) {
        char letters[5] = {};
        int num = 3;

        scanf("%3s-%d", letters, &num);

        int num2 = ((letters[0] - 'A') * 26 * 26) +
                   ((letters[1] - 'A') * 26) +
                   ((letters[2] - 'A'));
        
        int diff = abs(num - num2);

        if (diff <= 100)
            puts("nice");
        else
            puts("not nice");
    }

	return 0;
}

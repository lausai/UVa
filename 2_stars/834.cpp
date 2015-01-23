#include <cstdio>

using namespace std;

int main()
{
    int a, b;
    
    while (scanf("%d %d", &a, &b) != EOF) {
        int j = a / b;
        printf("[%d;", j);

        int i = a - (b * j);
        
        while (i != 1) {
            a = b;
            b = i;
            j = a / b;
            printf("%d,", j);
            i = a - (b * j);
        }
        printf("%d]\n", b);
    }

	return 0;
}

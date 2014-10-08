#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void process(int a, int b)
{
    if (a == 0) {
        printf(".\nThis expansion terminates.\n\n");
        return;
    }

    vector<int> list;
    bool repeat = true;
    int count = 1;

    printf(".");
    vector<int>::iterator it;

    while ((it = find(list.begin(), list.end(), a)) == list.end()) {
        list.push_back(a);

        int c = (a * 10) < b ? 0 : (a * 10) / b;
        a = c == 0 ? a * 10 : (a * 10) % b;

        if (count == 50) {
            puts("");
            count = 0;
        }

        printf("%d", c);
        count++;

        if (a == 0) {
            repeat = false;
            break;
        }
    }

    if (repeat)
        printf("\nThe last %d digits repeat forever.\n\n", list.end() - it);
    else
        puts("\nThis expansion terminates.\n");
}

int main()
{
    int a, b;
    
    while (scanf("%d %d", &a, &b), a != 0 || b != 0) {
        process(a, b);
    }

	return 0;
}

#include <cstdio>
#include <cmath>
#include <climits>

using namespace std;

int get_leaf(int depth, int num)
{
    int leaf_num = pow(2.0, depth - 1);
    int half = leaf_num / 2;
    int result = 0;

    if (depth == 1)
        return 1;

    if (depth == 2) {
        if (num == 1)
            return 2;
        else
            return 3;
    }

    if (num > half) {
        result = get_leaf(depth, num - half) + 1;
    } else {
        result = get_leaf(depth - 1, num) * 2;
    }
    
    return result;
}

int main()
{
    int num = 0;
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        int D = 0, I = 0;
        
        scanf("%d %d", &D, &I);
        printf("%u\n", get_leaf(D, I));
    }

    return 0;
}

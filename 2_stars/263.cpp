#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(const void* a, const void* b)
{
    char a1 = *(char*)a;
    char b1 = *(char*)b;
    
    return a1 - b1;
}

int cmpi(const void* a, const void* b)
{
    return cmp(a, b) * -1;
}

int main()
{
    unsigned num = 0;

    while (scanf("%u", &num), num != 0) {
        vector<unsigned> list;
        unsigned chain = 1;
        char num_s[16] = {};

        printf("Original number was %u\n", num);
        sprintf(num_s, "%u", num);

        while (true) {
            char big_s[16] = {};
            char small_s[16] = {};

            size_t len = strlen(num_s);

            qsort(num_s, len, sizeof(char), cmpi);
            strcpy(big_s, num_s);
            qsort(num_s, len, sizeof(char), cmp);
            strcpy(small_s, num_s);

            unsigned big = strtoul(big_s, NULL, 10);
            unsigned small = strtoul(small_s, NULL, 10);

            num = big - small;
            printf("%u - %u = %u\n", big, small, num);

            if (find(list.begin(), list.end(), num) != list.end())
                break;

            chain++;
            sprintf(num_s, "%u", num);
            list.push_back(num);
        }
        
        printf("Chain length %u\n\n", chain);
    }

	return 0;
}

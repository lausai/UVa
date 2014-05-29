#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Obj {
public:
        int i, order;
};

bool comp(Obj obj1, Obj obj2)
{
        return obj1.i < obj2.i;
}

int main()
{
        int round = 0;

        scanf("%d", &round);
        
        char numbers[20000][32] = {0};

        for (int i = 0; i < round; i++) {
                char ch = 0;
                int num = 0;
                vector<Obj> list;
                
                while (ch != '\n') {
                        Obj obj;

                        scanf("%d%c", &obj.i, &ch);
                        obj.order = num;
                        list.push_back(obj);
                        ++num;
                }

                for (int j = 0; j < num; j++)
                        scanf("%s", numbers[j]);
                
                sort(list.begin(), list.end(), comp);

                for (int j = 0; j < num; j++)
                        printf("%s\n", numbers[list[j].order]);
                
                if (i != round - 1)
                        puts("");
        }

	return 0;
}

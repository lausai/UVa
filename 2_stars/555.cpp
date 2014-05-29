#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Poke {
public:
        char colour;
        char value;
};

void ReadPoke(int& begin, vector<Poke> list[])
{
        for (int i = 0; i < 26; i++) {
                Poke poke;

                scanf("%c%c", &poke.colour, &poke.value);
                list[begin].push_back(poke);

                begin = (begin + 1) % 4;
        }
}

bool compare(const Poke& p1, const Poke& p2)
{
        if (p1.colour == p2.colour) {
                char values[] = "0123456789TJQKA";

                for (int i = 0; i < sizeof(values); i++) {
                        if (p1.value == values[i]) return true;
                        if (p2.value == values[i]) return false;
                }
        }

        if (p1.colour == 'C') return true;
        if (p2.colour == 'C') return false;
        if (p1.colour == 'D') return true;
        if (p2.colour == 'D') return false;
        if (p1.colour == 'S') return true;
        if (p2.colour == 'S') return false;

        return true;    // for remove warning
}

int main()
{
        char dealer = 0;
        
        while (scanf("%c\n", &dealer), dealer != '#') {
                vector<Poke> list[4];
                
                int begin = 0;

                ReadPoke(begin, list);
                getc(stdin);
                ReadPoke(begin, list);
                getc(stdin);
               
                sort(list[0].begin(), list[0].end(), compare);
                sort(list[1].begin(), list[1].end(), compare);
                sort(list[2].begin(), list[2].end(), compare);
                sort(list[3].begin(), list[3].end(), compare);
                
                switch (dealer) {
                        case 'S':
                                begin = 3;
                                break;
                        case 'W':
                                begin = 2;
                                break;
                        case 'N':
                                begin = 1;
                                break;
                        case 'E':
                                begin = 0;
                                break;
                        default:
                                ;
                }
                
                char colours[4] = {'S', 'W', 'N', 'E'};

                for (int i = 0; i < 4; i++) {
                        printf("%c:", colours[i]);

                        for (int j = 0; j < 13; j++)
                                printf(" %c%c", list[begin][j].colour, list[begin][j].value);

                        puts("");
                        begin = (begin + 1) % 4;
                }
        }

	return 0;
}

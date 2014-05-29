#include <cstdio>

using namespace std;

struct Stack {
    char color[4];
    int point[4];
    int num;
};

int Point(char ch)
{
    switch (ch) {
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return ch - '0';
    case 'A':
        return 1;
    case 'T':
        return 10;
    case 'J':
        return 11;
    case 'Q':
        return 12;
    case 'K':
        return 13;
    }

    return 0;
}

char PtoC(int point)
{
    switch (point) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        return point + '0';
    case 1:
        return 'A';
    case 10:
        return 'T';
    case 11:
        return 'J';
    case 12:
        return 'Q';
    case 13:
        return 'K';
    }

    return 0;
}

void SetPoke(Stack* s, const char* line)
{
    for (int i = 12; i >= 0; i--) {
        int index = 3 - s[i].num;

        s[i].point[index] = Point(*line);
        line++;
        s[i].color[index] = *line;
        line += 2;
        s[i].num++;
    }
}

int main()
{
    while (true) {
        char line[64] = {};
        Stack s[13] = {};

        fgets(line, sizeof(line), stdin);
        if (line[0] == '#') break;
        
        SetPoke(s, line); 

        for (int i = 0; i < 3; i++) {
            fgets(line, sizeof(line), stdin);
            SetPoke(s, line);
        }
        
        int pos = 12;
        int pre_point = 0;
        char pre_color = 0;
        int answer = 0;

        while (true) {
            if (s[pos].num < 1) {
                printf("%02d,%c%c\n", answer, PtoC(pre_point), pre_color);
                break;
            }
            
            int index = s[pos].num - 1;
            s[pos].num--;
            pre_point = s[pos].point[index];
            pre_color = s[pos].color[index];
            pos = s[pos].point[index] - 1;
            answer++;
        }
    }

	return 0;
}

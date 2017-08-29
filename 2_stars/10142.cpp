#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

int main()
{
    int r = 0;
    scanf("%d", &r);

    for (int i = 0; i < r; i++) {
        char name[20][82] = {};
        int num = 0;
        char buf[128] = {};
        int vote[1000][20] = {};

        scanf("%d\n", &num);
        for (int j = 0; j < num; j++) {
            fgets(name[j], 81, stdin);
        }
        
        int count = 0;
        for (; ; count++) {
            char* pc = fgets(buf, 127, stdin);
            if (buf[0] == '\n' || pc == NULL)
                break;
            
            buf[strlen(buf) - 1] = 0;
            char* p = buf;

            for (int k = 0; k < num; k++) {
                sscanf(p, "%d", &vote[count][k]);
                p += (vote[count][k] < 10) ? 2 : 3;
            }
        }
        
        bool find = false;
        bool multi_win = true;
        int find_p = 0;
        int result[21] = {};
        int round = 0;
        int max = 0;
        int min = INT_MAX;
        int pos_p[1000] = {};

        for (int k = 0; k < count; k++)
            result[vote[k][round]]++;

        for (; round < num; round++) {
            max = 0;
            min = INT_MAX;
            int val = 0;

            for (int k = 1; k < num + 1; k++) {
                if (result[k] > count / 2) {
                    find = true;
                    find_p = k;
                    break;
                }

                if (result[k] > max) {
                    max = result[k];
                    val = max;
                }

                if (result[k] >= 0 && result[k] < min)
                    min = result[k];
            }

            if (find)
                break;

            multi_win = true;
            for (int j = 1; j < num + 1; j++) {
                if (result[j] > 0 && result[j] != val) {
                    multi_win = false;
                    break;
                }
            }

            if (multi_win)
                break;

            for (int j = 1; j < num + 1; j++) {
                if (result[j] <= min) {
                    result[j] = INT_MIN;
                }
            }


            for (int j = 0; j < count; j++) {
                int person_num = vote[j][pos_p[j]];

                if (result[person_num] < 0) {
                    for (int k = pos_p[j] + 1; k < num; k++) {
                        int next_person_num = vote[j][k];

                        if (result[next_person_num] >= 0) {
                            result[next_person_num]++;
                            pos_p[j] = k;
                            break;
                        }
                    }
                }
            }
        }

        printf("%s", (i == 0) ? "" : "\n");
        if (find) {
            printf("%s", name[find_p - 1]);
        }
        else {
            for (int j = 1; j < num + 1; j++) {
                if (result[j] == max)
                    printf("%s", name[j - 1]);
            }
        }
    }
	return 0;
}

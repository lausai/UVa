#include <cstdio>
#include <algorithm>

using namespace std;

class up_info {
public:
    int correct_num;
    int ctt;
    int penalty_time;

    up_info() :
        correct_num(0),
        ctt(101),
        penalty_time(0) {}

    bool operator<(const up_info& rhs) 
    {
        if (correct_num > rhs.correct_num)
            return true;
        else if (correct_num < rhs.correct_num)
            return false;

        if (penalty_time < rhs.penalty_time)
            return true;
        else if (penalty_time > rhs.penalty_time)
            return false;

        if (ctt < rhs.ctt)
            return true;
        else if (ctt > rhs.ctt)
            return false;

        return false;
    }
};

int main()
{
    int round = 0;
    scanf("%d\n", &round);
    for (int i = 0; i < round; i++) {
        int fail_record[101][10] = {};
        bool success_record[101][10] = {};
        up_info infos[100] = {};

        while (true) {
            char line[16] = {};
            int ctt, prob, time;
            char L;
            fgets(line, sizeof(line) - 1, stdin);
            if (sscanf(line, "%d %d %d %c", &ctt, &prob, &time, &L) != 4)
                break;

            infos[ctt-1].ctt = ctt;
            if (L == 'C') {
                if (!success_record[ctt][prob]) {
                    infos[ctt-1].correct_num++;
                    infos[ctt-1].penalty_time += time + (fail_record[ctt][prob] * 20);
                    success_record[ctt][prob] = true;
                }
            } else if (L == 'I') {
                fail_record[ctt][prob]++;
            }
        }

        sort(infos, infos + 100);
        const char* prefix = i == 0 ? "" : "\n";
        printf("%s", prefix);
        for (int i = 0; i < 100; i++) {
            if (infos[i].ctt != 101)
                printf("%d %d %d\n", infos[i].ctt, infos[i].correct_num, infos[i].penalty_time);
        }
    }
	return 0;
}

#include <cstdio>
#include <list>

using namespace std;

int main()
{
        int num_people     = 0;
        int allow_vacation = 0;
        int poke[20]       = {0};
        int round          = 1;
        
        const char* format = "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d";
        while (EOF != scanf(format, &num_people, &allow_vacation, &poke[0], &poke[1], &poke[2], &poke[3], &poke[4], &poke[5], &poke[6], &poke[7],
                &poke[8], &poke[9], &poke[10], &poke[11], &poke[12], &poke[13], &poke[14], &poke[15], &poke[16], &poke[17], &poke[18], &poke[19])) {
                
                list<int> pos_list;
                for (int i = 0; i < num_people; i++)
                        pos_list.push_back(i + 1);

                bool finish_delete = false;
                for (int i = 0; i < 20; i++) {
                        int num_delete             = 0;
                        int list_size              = pos_list.size();
                        int num_people_need_delete = list_size / poke[i];
                        
                        list<int>::iterator it = pos_list.begin();

                        for (int j = 1; j <= list_size; j++) {
                                if (pos_list.size() == allow_vacation) {
                                        finish_delete = true;
                                        break;
                                }

                                if (j % poke[i] == 0)
                                        it = pos_list.erase(it);
                                else
                                        it++;
                        }

                        if (finish_delete) break;
                }

                printf("Selection #%d\n", round++);

                list<int>::iterator it = pos_list.begin();
                printf("%d", *it);
                it++;
                for (; it != pos_list.end(); it++)
                        printf(" %d", *it);

                puts("\n");
        }
	return 0;
}

#include <cstdio>

using namespace std;

int main()
{
        int round = 0;

        scanf("%d", &round);
        
        char *day[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

        for (int i = 0; i < round; i++) {
                int M, D;

                scanf("%d %d", &M, &D);
                
                int total_days = 4 + D;

                for (int j = 1; j < M; j++) {
                        switch(j) {
                                case 1:
                                case 3:
                                case 5:
                                case 7:
                                case 8:
                                case 10:
                                case 12:
                                        total_days += 31;
                                        break;
                                case 2:
                                        total_days += 28;
                                        break;
                                case 4:
                                case 6:
                                case 9:
                                case 11:
                                        total_days += 30;
                                        break;
                                default:
                                        ;// ignore
                            }
                }
                printf("%s\n", day[total_days % 7]);
        }

	return 0;
}

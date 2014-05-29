#include <cstdio>

using namespace std;

int main()
{
        int round = 0;

        scanf("%d", &round);
        
        for (int i = 0; i < round; i++) {
                int num_of_char = 0;

                scanf("%d\n", &num_of_char);
                
                int if_point  = 0;      // 0 means insert scarecrow, 1 means move scarecrow, 2 means do nothing
                int if_number = 1;      // 0 means move scarecrow, 1 means do nothing 
                int num_of_scarecrow = 0;
                for (int j = 0; j < num_of_char; j++) {
                        int c = getc(stdin);
                        
                        if ('.' == c) {
                                switch(if_point) {
                                        case 0:
                                                num_of_scarecrow++;
                                                if_point = 1;
                                                if_number = 0;
                                                break;
                                        case 1:
                                                if_point = 2;
                                                if_number = 1;
                                                break;
                                        case 2:
                                                if_point = 0;
                                                if_number = 1;
                                                break;
                                        default:
                                                ;
                                }
                        } else {
                                switch(if_number) {
                                        case 0:
                                                if_point = 2;
                                                if_number = 1;
                                                break;
                                        case 1:
                                                if_point = 0;
                                                if_number = 1;
                                                break;
                                        default:
                                                ;
                                }
                        }
                }
                getc(stdin);
                printf("Case %d: %d\n", i+1, num_of_scarecrow);
        }

	return 0;
}

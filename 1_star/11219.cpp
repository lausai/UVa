#include <cstdio>

using namespace std;

int main()
{
        int round = 0, Case = 1;

        scanf("%d", &round);

        while (round-- > 0) {
                int day_old, month_old, year_old, day_now, month_now, year_now;

                scanf("%d/%d/%d", &day_now, &month_now, &year_now);
                scanf("%d/%d/%d", &day_old, &month_old, &year_old);
                
                int age = year_now - year_old;
                
                if (age < 0) {
                        printf("Case #%d: Invalid birth date\n", Case++);
                } else if (age == 0) {
                        if (month_old > month_now)
                                printf("Case #%d: Invalid birth date\n", Case++);
                        else if (month_old == month_now && day_old > day_now)
                                printf("Case #%d: Invalid birth date\n", Case++);
                        else
                                printf("Case #%d: %d\n", Case++, age);
                } else {
                        if (month_now < month_old)
                                age -= 1;
                        else if (month_now == month_old && day_now < day_old)
                                age -= 1;
                        
                        if (age > 130)
                                printf("Case #%d: Check birth date\n", Case++);
                        else
                                printf("Case #%d: %d\n", Case++, age);
                }
        }

	return 0;
}

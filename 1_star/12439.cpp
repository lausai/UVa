#include <cstdio>
#include <cstring>

using namespace std;

char *months[] = {"January", "February", "March", "April", "May", "June", "July", 
                  "August", "September", "October", "November", "December"};

int GetMonth(const char* str)
{
        for (int i = 0; i < 12; i++) {
                if (0 == strcmp(months[i], str))
                        return i + 1;
        }

        return 0;
}

bool IsLeapYear(int year)
{
        if (year % 4 == 0) {
                if (year % 100 == 0 && year % 400 != 0)
                                return false;

                return true;
        }

        return false;
}

int LeapCompare(int month, int day)
{
        switch (month) {
                case 1:
                        return -1;
                case 2:
                        if (day == 29) return 0;

                        return -1;
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                        return 1;
                default:
                        return 0;
        }
}

int main()
{
        int round = 0;

        scanf("%d", &round);
 
        for (int i = 0; i < round; i++) {
                char month_begin_str[16] = {0}, month_end_str[16] = {0};
                int year_begin, day_begin, year_end, day_end, month_begin, month_end;

                scanf("%s %d, %d", month_begin_str, &day_begin, &year_begin);
                scanf("%s %d, %d", month_end_str, &day_end, &year_end);

                month_begin = GetMonth(month_begin_str);
                month_end   = GetMonth(month_end_str);
               
                int result = 0;
                int year_begin_4   = year_begin + 4 - (year_begin % 4);
                int year_end_4     = year_end % 4 == 0 ? year_end - 4 : year_end - (year_end % 4);
                int year_begin_100 = year_begin + 100 - (year_begin % 100);
                int year_end_100   = year_end % 100 == 0 ? year_end - 100 : year_end - (year_end % 100);
                int year_begin_400 = year_begin + 400 - (year_begin % 400);
                int year_end_400   = year_end % 400 == 0 ? year_end - 400 : year_end - (year_end % 400);

                int tmp = (year_end_4 - year_begin_4) / 4;

                if (tmp > 0) 
                        result = tmp + 1;
                else if (tmp == 0)
                        result += 1;
                
                tmp = (year_end_100 - year_begin_100) / 100;
                if (tmp > 0)
                        result -= tmp + 1;
                else if (tmp == 0)
                        result -= 1;

                tmp = (year_end_400 - year_begin_400) / 400;
                if (tmp > 0)
                        result += tmp + 1;
                else if (tmp == 0)
                        result += 1;
                
                if (year_begin != year_end) {
                        if (IsLeapYear(year_begin) && LeapCompare(month_begin, day_begin) <= 0)
                                result += 1;
                        
                        if (IsLeapYear(year_end) && LeapCompare(month_end, day_end) >= 0)
                                result += 1;
                } else {
                        if (IsLeapYear(year_begin) && IsLeapYear(year_end) &&
                            LeapCompare(month_begin, day_begin) <= 0 &&
                            LeapCompare(month_end, day_end) >= 0 )
                                result += 1;
                }

                printf("Case %d: %d\n", i + 1, result);
        }

	return 0;
}

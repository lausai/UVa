#include <cstdio>

using namespace std;

// Check if the date is after 9/2/1752
bool after1752_9_2(int year, int month, int date)
{
    if (year > 1752)
        return true;

    if (year < 1752)
        return false;

    if (month > 9)
        return true;

    if (month < 9)
        return false;

    return (date > 2) ? true : false;
}

bool isLeapYear(int year)
{
    if (year <= 1752) {
        if ((year % 4) == 0)
            return true;
        else
            return false;
    } else {
        if ((year % 400) == 0)
            return true;
        else if ((year % 100) == 0)
            return false;
        else if ((year % 4) == 0)
            return true;
        else
            return false;
    }
}

int main()
{
    const char* monthText[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",
    };

    const char* dayText[] = {
        "Friday",
        "Saturday",
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday"
    };

    int daysLeapYear = (4 * 30) + (7 * 31) + 29;
    int daysNonLeapYear = (4 * 30) + (7 * 31) + 28;

    while (true) {
        int month = -1;
        int date = -1;
        int year = -1;

        scanf("%d %d %d", &month, &date, &year);

        if (month == 0 && date == 0 && year == 0)
            break;

        if (month > 12) {
            printf("%d/%d/%d is an invalid date.\n", month , date, year);
            continue;
        }
        
        switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (date > 31) {
                printf("%d/%d/%d is an invalid date.\n", month , date, year);
                continue;
            }

            break;
        case 2:
            if (isLeapYear(year)) {
                if (date > 29) {
                    printf("%d/%d/%d is an invalid date.\n", month , date, year);
                    continue;
                }
            } else {
                if (date > 28) {
                    printf("%d/%d/%d is an invalid date.\n", month , date, year);
                    continue;
                }
            }

            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (date > 30) {
                printf("%d/%d/%d is an invalid date.\n", month , date, year);
                continue;
            }
        }

        if (year == 1752 && month == 9) {
            if (date <= 13 && date >= 3) {
                printf("%d/%d/%d is an invalid date.\n", month , date, year);
                continue;
            }
        }
        
        int day = 0;
        int days = 0;
        int leapYears = 0;
        int nonLeapYears = 0;
        
        for (int i = 1; i < year; i++) {
            if (isLeapYear(i))
                leapYears++;
            else
                nonLeapYears++;
        }
        
        days = (leapYears * daysLeapYear) + (nonLeapYears * daysNonLeapYear);

        for (int i = 1; i < month; i++) {
            switch (i) {
            case 2:
                days += (isLeapYear(year)) ? 29 : 28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                days += 30;
                break;
            default:
                days += 31;
            }
        }

        days += date;

        if (after1752_9_2(year, month, date))
            days -= 11;

        day = days % 7;
        printf("%s %d, %d is a %s\n", monthText[month - 1], date, year, dayText[day]);
    }

    return 0;
}

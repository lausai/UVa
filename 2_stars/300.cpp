#include <cstdio>
#include <cstring>

using namespace std;

const char* Haab_month[] = {
    "pop", 
    "no", 
    "zip", 
    "zotz", 
    "tzec", 
    "xul", 
    "yoxkin", 
    "mol", 
    "chen", 
    "yax", 
    "zac", 
    "ceh", 
    "mac", 
    "kankin", 
    "muan", 
    "pax", 
    "koyab", 
    "cumhu", 
    "uayet"
};

const char* Tzolkin_date[] = {
    "imix", 
    "ik", 
    "akbal", 
    "kan", 
    "chicchan", 
    "cimi", 
    "manik", 
    "lamat", 
    "muluk", 
    "ok", 
    "chuen", 
    "eb", 
    "ben", 
    "ix", 
    "mem", 
    "cib", 
    "caban", 
    "eznab", 
    "canac", 
    "ahau"
};

int main()
{

    int n = 0;
    
    scanf("%d", &n);
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        int day, year;
        char month[16] = {};

        scanf("%d. %s %d", &day, month, &year);
        
        int tmp = 0;

        for (int i = 0; i < 19; i++) {
            if (strcmp(month, Haab_month[i]) == 0) {
                tmp = day + (20 * i);
                break;
            }
        }

        int days = (365 * year) + tmp;
        
        int Tzolkin_year = days / 260;
        days = days % 260;

        printf("%d %s %d\n", days % 13 + 1, Tzolkin_date[days % 20], Tzolkin_year);
    }

	return 0;
}

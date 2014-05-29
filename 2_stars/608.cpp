#include <cstdio>
#include <cstring>

using namespace std;

int gInitStatus = 2;

enum Result {
    UP,
    EVEN,
    DOWN
};

Result getResult(const char* result)
{
    if (strcmp(result, "up") == 0)
        return UP;
    else if (strcmp(result, "even") == 0)
        return EVEN;
    else
        return DOWN;
}

void setStatus(const char* dollars, int* dollarStatus, int status)
{
    int len = strlen(dollars);

    for (int i = 0; i < len; i++)
        dollarStatus[dollars[i] - 'A'] = status;
}

void setStatusByPreviousStatus(const char* dollars, int* dollarStatus, int status)
{
    int len = strlen(dollars);

    for (int i = 0; i < len; i++) {
        int index = dollars[i] - 'A';

        if (status * dollarStatus[index] == -1)
            dollarStatus[index] = 0;
        else if (dollarStatus[index] == gInitStatus)
            dollarStatus[index] = status;
    }
}

Result handleDollarResult(char* leftDollars, char* rightDollars, char* result, int* dollarStatus)
{
       scanf("%s %s %s", leftDollars, rightDollars, result);
       Result ret = getResult(result);

       switch (ret) {
       case UP:
           setStatusByPreviousStatus(leftDollars, dollarStatus, 1);
           setStatusByPreviousStatus(rightDollars, dollarStatus, -1);
           break;
       case DOWN:
           setStatusByPreviousStatus(leftDollars, dollarStatus, -1);
           setStatusByPreviousStatus(rightDollars, dollarStatus, 1);
           break;
       case EVEN:
           setStatus(leftDollars, dollarStatus, 0);
           setStatus(rightDollars, dollarStatus, 0);
           break;
       }

       return ret;
}

int main()
{
    int numTestCases = 0;

    scanf("%d", &numTestCases);

    for (int j = 0; j < numTestCases; j++) {
        char leftDollars[3][7] = {};
        char rightDollars[3][7] = {};
        char result1[5] = {};
        char result2[5] = {};
        char result3[5] = {};
        Result results[3] = {};
        int dollarStatus[12] = {};

        for (int i = 0; i < 12; i++)
            dollarStatus[i] = gInitStatus;

        scanf("%s %s %s", leftDollars[0], rightDollars[0], result1);
        results[0] = getResult(result1);

        switch (results[0]) {
        case UP:
            setStatus(leftDollars[0], dollarStatus, 1);
            setStatus(rightDollars[0], dollarStatus, -1);
            break;
        case DOWN:
            setStatus(leftDollars[0], dollarStatus, -1);
            setStatus(rightDollars[0], dollarStatus, 1);
            break;
        case EVEN:
            setStatus(leftDollars[0], dollarStatus, 0);
            setStatus(rightDollars[0], dollarStatus, 0);
            break;
        }

        results[1] = handleDollarResult(leftDollars[1], rightDollars[1], result2, dollarStatus);
        results[2] = handleDollarResult(leftDollars[2], rightDollars[2], result3, dollarStatus);
       
        for (int i = 0; i < 12; i++) {
            int status = dollarStatus[i];
            char ch = i + 'A';
            bool findAnswer = true;
            const char* statusText = "";

            if (status != 1 && status != -1) continue;

            for (int k = 0; k < 3; k++) {
                int len = strlen(leftDollars[k]);
                Result expectResult = EVEN;

                for (int l = 0; l < len; l++) {
                    if (leftDollars[k][l] == ch) {
                        expectResult = (status == 1 ? UP : DOWN);
                        statusText = (expectResult == UP ? "heavy" : "light");
                        break;
                    }

                    if (rightDollars[k][l] == ch) {
                        expectResult = (status == 1 ? DOWN : UP);
                        statusText = (expectResult == UP ? "light" : "heavy");
                        break;
                    }
                }

                if (expectResult != results[k]) {
                    findAnswer = false;
                    break;
                }
            }
            
            if (findAnswer) {
                printf("%c is the counterfeit coin and it is %s.\n", ch, statusText);
                break;
            }
        }
    }

	return 0;
}

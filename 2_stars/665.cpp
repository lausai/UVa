#include <cstdio>

using namespace std;

void ReadCoins(int num_coins, int* coins)
{
    for (int i = 0; i < num_coins; i++)
        scanf("%d", &coins[i]);
}

void DumpStatus(int num, int* status)
{
    for (int i = 0; i < num; i++)
        printf("%d ", status[i]);

    puts("");
}

int main()
{
    int M = 0;

    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        int N = 0, K = 0;
        int coin_status[100] = {};
        char results[100] = {};
        int left_coins[100][50] = {};
        int right_coins[100][50] = {};
        int num_coins[100] = {};

        scanf("%d %d", &N, &K);
        
        for (int j = 0; j < K; j++) {
            char tmp = 0;
            
            scanf("%d", &num_coins[j]);
            ReadCoins(num_coins[j], left_coins[j]);
            ReadCoins(num_coins[j], right_coins[j]);
            
            scanf("%c%c", &tmp, &results[j]);

            switch (results[j]) {
            case '<':
                for (int l = 0; l < num_coins[j]; l++) {
                    if (coin_status[left_coins[j][l] - 1] == 0)
                        coin_status[left_coins[j][l] - 1] = -1;
                    else if (coin_status[left_coins[j][l] - 1] == 1)
                        coin_status[left_coins[j][l] - 1] = 2;

                    if (coin_status[right_coins[j][l] - 1] == 0)
                        coin_status[right_coins[j][l] - 1] = 1;
                    else if (coin_status[right_coins[j][l] - 1] == -1)
                        coin_status[right_coins[j][l] - 1] = 2;
                }

                break;
            case '>':
                for (int l = 0; l < num_coins[j]; l++) {
                    if (coin_status[left_coins[j][l] - 1] == 0)
                        coin_status[left_coins[j][l] - 1] = 1;
                    else if (coin_status[left_coins[j][l] - 1] == -1)
                        coin_status[left_coins[j][l] - 1] = 2;

                    if (coin_status[right_coins[j][l] - 1] == 0)
                        coin_status[right_coins[j][l] - 1] = -1;
                    else if (coin_status[right_coins[j][l] - 1] == 1)
                        coin_status[right_coins[j][l] - 1] = 2;
                }
                break;
            case '=':
                for (int l = 0; l < num_coins[j]; l++) {
                    coin_status[left_coins[j][l] - 1] = 2;
                    coin_status[right_coins[j][l] - 1] = 2;
                }
                break;
            }
        }

        bool find_answer = true;
        int answer = 0;
        int num_answers = 0;

        for (int j = 0; j < N; j++) {
            int current_coin = j + 1;
            find_answer = true;
            
            if (coin_status[j] != -1 && coin_status[j] != 1 && coin_status[j] != 0)
                continue;
            
            for (int l = 0; l < K; l++) {
                char expect_result = '=';

                for (int m = 0; m < num_coins[l]; m++) {
                    if (current_coin == left_coins[l][m]) {
                        expect_result = (coin_status[j] == 1 ? '>' : '<');
                        break;
                    }

                    if (current_coin == right_coins[l][m]) {
                        expect_result = (coin_status[j] == 1 ? '<' : '>');
                        break;
                    }
                }

                if (expect_result != results[l]) {
                    find_answer = false;
                    break;
                }
            }

            if (find_answer) {
                answer = current_coin;
                num_answers++;
            }
        }
        
        if (i > 0) puts("");

        if (num_answers == 1)
            printf("%d\n", answer);
        else
            puts("0");

    }
	return 0;
}

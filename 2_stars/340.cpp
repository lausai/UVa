#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
        int game_round = 0;

        while (true) {
                int code_length = 0;

                scanf("%d", &code_length);
                if (0 == code_length) break;

                printf("Game %d:\n", ++game_round);

                int code_content[1000]   = {0};
                int code_1_to_9_nums[10] = {0};
                for (int i = 0; i < code_length; i++) {
                        scanf("%d", &code_content[i]);
                        ++code_1_to_9_nums[code_content[i]];
                }

                while (true) {
                        int guess_code_content[1000] = {0};
                        int num_code_zero            = 0;

                        int num_a = 0;
                        int num_b = 0;
                        int tmp_code_1_to_9_nums[10] = {0};

                        memcpy(tmp_code_1_to_9_nums, code_1_to_9_nums, sizeof(code_1_to_9_nums));

                        for (int i = 0; i < code_length; i++) {
                                scanf("%d", &guess_code_content[i]);

                                if (0 == guess_code_content[i])
                                        ++num_code_zero;

                                if (guess_code_content[i] == code_content[i]) {
                                        ++num_a;

                                        if (0 == tmp_code_1_to_9_nums[guess_code_content[i]] && num_b > 0)
                                                --num_b;
                                        else
                                                --tmp_code_1_to_9_nums[guess_code_content[i]];
                                        
                                        continue;
                                }
                                
                                if (tmp_code_1_to_9_nums[guess_code_content[i]] > 0) {
                                        ++num_b;
                                        --tmp_code_1_to_9_nums[guess_code_content[i]];
                                }
                        }

                        if (num_code_zero == code_length) break;

                        printf("    (%d,%d)\n", num_a, num_b);
                }
        }

	return 0;
}

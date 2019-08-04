#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char dict[100][7] = {};
char sort_dict[100][7] = {};
int word_len[100] = {};
char** match  = new char* [100];

bool cmp_func(char* s1, char* s2) 
{
    return strcmp(s1, s2) < 0;
}

int main()
{
    char* input = &dict[0][0];
    int dict_num = -1;
    while (strcmp(input, "XXXXXX") != 0) {
        dict_num++;
        input = &dict[dict_num][0];
        scanf("%s%n\n", input, &word_len[dict_num]);
        memcpy(&sort_dict[dict_num], &dict[dict_num], word_len[dict_num]);
    }
    // dict input end

    // sort dict
    for (int i = 0; i < dict_num + 1; i++) {
        sort((char*)&sort_dict[i], (char*)(&sort_dict[i]) + word_len[i]);
    }

    // check word in dict
    char word[7] = {};
    int cnt = 0;
    while (scanf("%s%n\n", word, &cnt), strcmp(word, "XXXXXX") != 0) {
        word[cnt] = 0;
        sort(word, word + cnt);
        int match_cnt = 0;
        for (int i = 0; i < dict_num + 1; i++) {
            if (strcmp(word, sort_dict[i]) == 0) {
                match[match_cnt] = dict[i];
                match_cnt++;
            }
        }

        if (match_cnt == 0) {
            puts("NOT A VALID WORD");
        } else {
            sort(match, match + match_cnt, cmp_func);
            for (int i = 0; i < match_cnt; i++)
                printf("%s\n", match[i]);
        }

        puts("******");
    }
    
	return 0;
}

#include <cstdio>
#include <cstring>

char hey_point_words[1000][17] = {};
int hey_point_values[1000] = {};

int main()
{
    int m, n;
    char word[128] = {};
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%s %d", hey_point_words[i], &hey_point_values[i]);
    }

    int hey_point = 0;
    while (scanf("%s", word) != EOF) {
        for (int i = 0; i < m; i++) {
            if (strcmp(hey_point_words[i], word) == 0) {
                hey_point += hey_point_values[i];
                break;
            }
        }
        if (word[0] == '.' && word[1] == 0) {
            printf("%d\n", hey_point);
            hey_point = 0;
        }
    }

    return 0;
}

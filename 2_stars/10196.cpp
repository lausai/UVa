#include <cstdio>
#include <cstring>

using namespace std;

char table[8][11] = {};

bool attack_p(int i, int j, char p, char king)
{
    if (p == 'p') {
        if ((i + 1 < 8 && j - 1 >= 0 && table[i+1][j-1] == king) ||
            (i + 1 < 8 && j + 1 < 8 && table[i+1][j+1] == king))
            return true;
    } else {
        if ((i - 1 >= 0 && j - 1 >= 0 && table[i-1][j-1] == king) ||
            (i - 1 >= 0 && j + 1 < 8 && table[i-1][j+1] == king))
            return true;
    }
    return false;
}

bool attack_r(int i, int j, char king)
{
    for (int n = 1; n+i < 8; n++) {
        if (table[n+i][j] == king)
            return true;
        else if (table[n+i][j] != '.')
            break;
    }

    for (int n = 1; i-n >= 0; n++) {
        if (table[i-n][j] == king)
            return true;
        else if (table[i-n][j] != '.')
            break;
    }

    for (int n = 1; n+j < 8; n++) {
        if (table[i][n+j] == king)
            return true;
        else if (table[i][n+j] != '.')
            break;
    }

    for (int n = 1; j-n >= 0; n++) {
        if (table[i][j-n] == king)
            return true;
        else if (table[i][j-n] != '.')
            break;
    }

    return false;
}

bool attack_b(int i, int j, char king)
{
    for (int n = 1; i-n >= 0 && j-n >= 0; n++) {
        if (table[i-n][j-n] == king)
            return true;
        else if (table[i-n][j-n] != '.')
            break;
    }

    for (int n = 1; i+n < 8 && j+n < 8; n++) {
        if (table[i+n][j+n] == king)
            return true;
        else if (table[i+n][j+n] != '.')
            break;
    }

    for (int n = 1; i+n < 8 && j-n >= 0; n++) {
        if (table[i+n][j-n] == king)
            return true;
        else if (table[i+n][j-n] != '.')
            break;
    }

    for (int n = 1; i-n >= 0 && j+n < 8; n++) {
        if (table[i-n][j+n] == king)
            return true;
        else if (table[i-n][j+n] != '.')
            break;
    }

    return false;
}

bool attack_q(int i, int j, char king)
{
    if (attack_r(i, j, king))
        return true;

    if (attack_b(i, j, king))
        return true;

    return false;
}

bool attack_k(int i, int j, char king)
{
    if ((i-1 >= 0 && table[i-1][j] == king) ||
        (i+1 < 8 && table[i+1][j] == king) ||
        (j-1 >= 0 && table[i][j-1] == king) ||
        (j+1 < 8 && table[i][j+1] == king) ||
        (i-1 >= 0 && j-1 >= 0 && table[i-1][j-1] == king) || 
        (i+1 < 8 && j+1 < 8 && table[i+1][j+1] == king) ||
        (i-1 >= 0 && j+1 < 8 && table[i-1][j+1] == king) ||
        (i+1 < 8 && j-1 >= 0 && table[i+1][j-1] == king))
        return true;

    return false;
}

bool attack_n(int i, int j, char king)
{
    if ((i-1 >= 0 && j-2 >= 0 && table[i-1][j-2] == king) ||
        (i-2 >= 0 && j-1 >= 0 && table[i-2][j-1] == king) || 
        (i-2 >= 0 && j+1 < 8 && table[i-2][j+1] == king) ||
        (i-1 >= 0 && j+2 < 8 && table[i-1][j+2] == king) ||
        (i+1 < 8 && j-2 >= 0 && table[i+1][j-2] == king) ||
        (i+2 < 8 && j-1 >= 0 && table[i+2][j-1] == king) ||
        (i+1 < 8 && j+2 < 8 && table[i+1][j+2] == king) ||
        (i+2 < 8 && j+1 < 8 && table[i+2][j+1] == king))
        return true;

    return false;
}


int main()
{
    int round = 1;
    while (true) {
        bool end = true;
        const char* endline = "........";
        char buf[11] = {};

        for (int i = 0; i < 8; i++) {
            fgets(table[i], 11, stdin);
            if (strncmp(table[i], endline, 8) != 0)
                end = false;
        }

        if (end || fgets(buf, 11, stdin) == NULL) break;

        bool white_king_check = false;
        bool black_king_check =false;

        for (int i = 0; i < 8 && !white_king_check && !black_king_check; i++) {
            for (int j = 0; j < 8 && !white_king_check && !black_king_check; j++) {
                switch (table[i][j]) {
                case 'p':
                    white_king_check = attack_p(i, j, 'p', 'K');
                    break;
                case 'r':
                    white_king_check = attack_r(i, j, 'K');
                    break;
                case 'b':
                    white_king_check = attack_b(i, j, 'K');
                    break;
                case 'q':
                    white_king_check = attack_q(i, j, 'K');
                    break;
                case 'k':
                    white_king_check = attack_k(i, j, 'K');
                    break;
                case 'n':
                    white_king_check = attack_n(i, j, 'K');
                    break;
                case 'P':
                    black_king_check = attack_p(i, j, 'P', 'k');
                    break;
                case 'R':
                    black_king_check = attack_r(i, j, 'k');
                    break;
                case 'Q':
                    black_king_check = attack_q(i, j, 'k');
                    break;
                case 'B':
                    black_king_check = attack_b(i, j, 'k');
                    break;
                case 'K':
                    black_king_check = attack_k(i, j, 'k');
                    break;
                case 'N':
                    black_king_check = attack_n(i, j, 'k');
                    break;
                }

                if (white_king_check)
                    printf("Game #%d: white king is in check.\n", round);
                else if (black_king_check)
                    printf("Game #%d: black king is in check.\n", round);
            }
        }

        if (!white_king_check && !black_king_check)
            printf("Game #%d: no king is in check.\n", round);

        round++;
    }

	return 0;
}

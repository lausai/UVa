#include <cstdio>

using namespace std;

bool IsParity(int matrix[][100], int degree)
{
        int val1 = 0, val2 = 0;

        for (int i = 0; i < degree; i++) {
                for (int j = 0; j < degree; j++) {
                        val1 += matrix[i][j];
                        val2 += matrix[j][i];
                }
                
                if (val1 % 2 != 0) return false;
                if (val2 % 2 != 0) return false;

                val1 = 0;
                val2 = 0;
        }

        return true;
}

int main()
{
        int matrix[100][100] = {0};
        int degree           = 0;

        while (scanf("%d", &degree), degree != 0) {
                for (int i = 0; i < degree; i++) {
                        for (int j = 0; j < degree; j++)
                                scanf("%d", &matrix[i][j]);
                }

                if (IsParity(matrix, degree)) {
                        puts("OK");
                } else {
                        bool is_parity = false;

                        for (int i = 0; i < degree; i++) {
                                for (int j = 0; j < degree; j++) {
                                        matrix[i][j] = (matrix[i][j] == 0) ? 1 : 0;
                                        if (IsParity(matrix, degree)) {
                                                printf("Change bit (%d,%d)\n", i + 1, j + 1);
                                                is_parity = true;
                                                break;
                                        }
                                        matrix[i][j] = (matrix[i][j] == 0) ? 1 : 0;

                                        matrix[j][i] = (matrix[j][i] == 0) ? 1 : 0;
                                        if (IsParity(matrix, degree)) {
                                                printf("Change bit (%d,%d)\n", j + 1, i + 1);
                                                is_parity = true;
                                                break;
                                        }
                                        matrix[j][i] = (matrix[j][i] == 0) ? 1 : 0;
                                }

                                if (is_parity) break;
                        }

                        if (!is_parity) puts("Corrupt");
                }
        }

	return 0;
}

#include <cstdio>
#include <cmath>

using namespace std;

int cube_values[200] = {0};

bool find_d(int a, int b, int c, int& d)
{
        if (cube_values[a] == 0) cube_values[a] = pow((double)a, 3);
        if (cube_values[b] == 0) cube_values[b] = pow((double)b, 3);
        if (cube_values[c] == 0) cube_values[c] = pow((double)c, 3);

        for (d = c + 1; d < a; d++) {
                if (cube_values[d] == 0) cube_values[d] = pow((double)d, 3);
                
                int value = cube_values[b] + cube_values[c] + cube_values[d];

                if (value == cube_values[a]) return true;
        }
        return false;
}

int main()
{

        for (int i = 6; i <= 200; i++) {
                for (int j = 2; j <= i - 3; j++) {
                        for (int k = j + 1; k <= i - 2; k++) {
                                int d = 0;

                                if (find_d(i, j, k, d))
                                        printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, k, d);
                        }
                }
        }

	return 0;
}

#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
        int n            = 0;
        bool first_round = true;

        while (EOF != scanf("%d", &n)) {
                int segment_in_circle = 0;
                int inside_circle     = 0;
                double radius         = n - 0.5;
                
                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                                double value = i*i + j*j;
                                
                                if (sqrt(value) > radius) 
                                        continue;
                                
                                value = ((i+1) * (i+1)) + ((j+1) * (j+1));
                                if (sqrt(value) < radius) {
                                        ++inside_circle;
                                        continue;
                                }

                                ++segment_in_circle;
                        }
                }
                
                if (first_round)
                        first_round = false;
                else
                        puts("");

                printf("In the case n = %d, %d cells contain segments of the circle.\n", n, 4 * segment_in_circle);
                printf("There are %d cells completely contained in the circle.\n", 4 * inside_circle);
        }

	return 0;
}

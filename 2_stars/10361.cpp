#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n = 0;
    char c = 0;
    scanf("%d%c", &n, &c);

    for (int i = 0; i < n; i++) {
        char l1[128] = {};
        char l2[128] = {};
        
        fgets(l1, sizeof(l1), stdin);
        fgets(l2, sizeof(l2), stdin);
        
        char* s2l = strchr(l1, '<');
        char* s2r = strchr(l1, '>');
        char* s4l = strrchr(l1, '<');
        char* s4r = strrchr(l1, '>');
        char* dot = strchr(l2, '.');

        *s2l = 0;
        *s2r = 0;
        *s4l = 0;
        *s4r = 0;
        *dot = 0;

        printf("%s%s%s%s%s", l1, s2l + 1, s2r + 1, s4l + 1, s4r + 1);
        printf("%s%s%s%s%s", l2, s4l + 1, s2r + 1, s2l + 1, s4r + 1);
    }

	return 0;
}

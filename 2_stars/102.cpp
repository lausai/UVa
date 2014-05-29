#include <stdio.h>
#include <string.h>
#include <limits.h>

int num_moved(int bin[], int pos)
{
        int num=0;
        for (int i=0; i<3; i++) {
                if (i == pos)
                        continue;

                num+=bin[i];
        }

        return num;
}

int main()
{
        int bin1[3], bin2[3], bin3[3];
        while (scanf("%d%d%d%d%d%d%d%d%d", &bin1[0], &bin1[1], &bin1[2], &bin2[0], &bin2[1], &bin2[2], &bin3[0], &bin3[1], &bin3[2]) == 9) {
                int length=INT_MAX, tmplen=0;
                char order[4]="BGC", cur[4]={0}, tmp[4]={0};

                for (int i=0; i<3; i++) {
                        for (int j=0; j<3; j++) {
                                for (int z=0; z<3; z++) {
                                        if (i==j || j==z || i==z)
                                                continue;

                                        tmplen=num_moved(bin1, i)+num_moved(bin2, j)+num_moved(bin3, z);
                                        tmp[0]=order[i];
                                        tmp[1]=order[j];
                                        tmp[2]=order[z];

                                        if (length > tmplen) {
                                                length=tmplen;
                                                strncpy(cur, tmp, 3);
                                        }
                                        else if (length==tmplen && strncmp(tmp, cur, 3)<0) {
                                                strncpy(cur, tmp, 3);
                                        }
                                }
                        }
                }

                printf("%s %d\n", cur, length);
        }
}

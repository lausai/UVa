#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int dim, num_box;//dimension and number of boxes

/*  b1 < b2 return -1
 *  b1 > b2 return 1
 *  can't decide b1 is bigger or b2 is bigger, then return 0
 */
int boxcmp(vector<int> b1, vector<int> b2)
{
        int counter=0;
        for (int i=0; i<dim; i++)
        {
                if (b1[i] < b2[i])
                        counter--;
                else if (b1[i] > b2[i])
                        counter++;
        }

        if (counter == -dim)
                return -1;
        else if (counter == dim)
                return 1;
        else
                return 0;
}

int get_lis(vector<vector<int> > &all_box, vector<int> box_order, int lis_order[], int &index)
{
        //record[i] means the length of a lis which the lis's biggest box is box_order[i]
        int record[num_box];
        for (int i=0; i<num_box; i++)
                record[i]=1;

        for (int i=0; i<num_box-1; i++)
        {
                for (int j=i+1; j<num_box; j++)
                {
                        if (boxcmp(all_box[i], all_box[j])==-1 && record[j]<record[i]+1)
                        {
                                record[j]=record[i]+1;
                                lis_order[j]=i;
                        }
                }
        }

        int max=0;
        for (int i=0; i<num_box; i++)
        {
                if (record[i] > max)
                {
                        max=record[i];
                        index=i;
                }
        }
        return max;
}

int main()
{
        while (scanf("%d%d", &num_box, &dim) == 2)
        {
                vector<vector<int> > all_box;
                for (int j=0; j<num_box; j++)
                {
                        vector<int> box;
                        for (int i=0; i<dim; i++)
                        {
                                int tmp;
                                scanf("%d", &tmp);
                                box.push_back(tmp);
                        }
                        sort(box.begin(), box.end());
                        all_box.push_back(box);
                }

                vector<int> box_order;
                for (int i=1; i<=num_box; i++)
                        box_order.push_back(i);

                for (int i=1; i<num_box; i++)
                {
                        for (int j=0; j<i; j++)
                        {
                                if (boxcmp(all_box[i], all_box[j]) == -1)
                                {
                                        vector<int> tmp=all_box[i];
                                        all_box[i]=all_box[j];
                                        all_box[j]=tmp;

                                        int tmpi=box_order[i];
                                        box_order[i]=box_order[j];
                                        box_order[j]=tmpi;
                                }
                        }
                }

                int lis_order[num_box], index, ans[num_box];
                memset(lis_order, 0, num_box*sizeof(int));
                int max=get_lis(all_box, box_order, lis_order, index);

                printf("%d\n", max);
                for (int i=max-1; i>=0; i--)
                {
                        ans[i]=box_order[index];
                        index=lis_order[index];
                }

                int i;
                for (i=0; i<max-1; i++)
                        printf("%d ", ans[i]);

                printf("%d\n", ans[i]);
        }
}

#include <iostream>

using namespace std;

int cycle_length(int i)
{
        int length=1;

        while (i != 1) {
                if (i%2 != 0) {
                        i=i*3+1;
                        length++;
                }
                else {
                        i=i/2;
                        length++;
                }
        }

        return length;
}

int main()
{
        int begin, end;

        while (cin >> begin >> end) {
                cout << begin << " " << end << " ";

                if (begin > end) {
                        int tmp=end;
                        end=begin;
                        begin=tmp;
                }

                int max=0;
                for (int i=begin; i<=end; i++) {
                        int tmp=cycle_length(i);
                        if (max < tmp)
                                max=tmp;
                }

                cout << max << endl;
        }
}

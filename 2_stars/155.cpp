#include <cstdio>

using namespace std;

struct Rec {
    float x;
    float y;
    int k;
};

void CreateRec(Rec* rec_arr, int* index, Rec* base)
{
    int small_k = base->k / 2;
    int ind1, ind2, ind3, ind4;
    float length = (float)base->k;

    if (small_k == 0) return;
    if (base->x - length < 0) return;
    if (base->y - length < 0) return;
    if (base->x + length > 2049) return;
    if (base->y + length > 2049) return;

    rec_arr[*index].x = base->x - length;
    rec_arr[*index].y = base->y - length;
    rec_arr[*index].k = small_k;
    ind1 = *index;
    (*index)++;

    rec_arr[*index].x = base->x + length;
    rec_arr[*index].y = base->y - length;
    rec_arr[*index].k = small_k;
    ind2 = *index;
    (*index)++;

    rec_arr[*index].x = base->x + length;
    rec_arr[*index].y = base->y + length;
    rec_arr[*index].k = small_k;
    ind3 = *index;
    (*index)++;

    rec_arr[*index].x = base->x - length;
    rec_arr[*index].y = base->y + length;
    rec_arr[*index].k = small_k;
    ind4 = *index;
    (*index)++;

    CreateRec(rec_arr, index, &rec_arr[ind1]);
    CreateRec(rec_arr, index, &rec_arr[ind2]);
    CreateRec(rec_arr, index, &rec_arr[ind3]);
    CreateRec(rec_arr, index, &rec_arr[ind4]);
}

bool InRec(int x, int y, const Rec* rec)
{
    float len = (((float)rec->k * 2) + 1) / 2;

    if ((x < rec->x - len) || (x > rec->x + len))
        return false;

    if ((y > rec->y + len) || (y < rec->y - len))
        return false;
    
    return true;
}

int main()
{
    int k = 0, x = 0, y = 0;

    while (scanf("%d %d %d", &k, &x, &y), k != 0 && x != 0 && y != 0) {
        Rec* recs = new Rec[1024 * 1024]();
        int num_rec = 1;
        
        recs[0].x = recs[0].y = 1024;
        recs[0].k = k;

        CreateRec(recs, &num_rec, &recs[0]);
        
        int answer = 0;

        for (int i = 0; i < num_rec; i++) {
            if (InRec(x, y, &recs[i]))
                answer++;
        }
        
        printf("%3d\n", answer);
        delete [] recs;
    }

	return 0;
}

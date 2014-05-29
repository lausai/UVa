#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void find_position(map<int, vector<int> > &m, int pos, int &pinm, int &pinv)
{
        //cout << "call find_position" << endl;

        map<int, vector<int> >::size_type i;
        for (i=0; i!=m.size(); i++) {
                vector<int>::size_type j;

                for (j=0; j!=m[i].size(); j++) {
                        if (pos == m[i][j]) {
                                pinm=i;
                                pinv=j;

                                //cout << "find position return" << endl;
                                return;
                        }
                }
        }
}

bool is_ilegal(map<int, vector<int> > &m, int from, int to)
{
        //cout << "call is_ilegal" << endl;

        if (from == to)
                return true;
        else {
                int pinm_f, pinv_f, pinm_t, pinv_t;

                find_position(m, from, pinm_f, pinv_f);
                find_position(m, to, pinm_t, pinv_t);

                if (pinm_f == pinm_t)
                        return true;
        }

        return false;
}

void recover(map<int, vector<int> > &m, int pos)
{
        //cout << "call recover" << endl;

        int pinm, pinv;

        find_position(m, pos, pinm, pinv);

        vector<int>::size_type i;
        while ((i=m[pinm].size()) != pinv+1) {// must have the () of i=m[pinm].size()!! or will cause infinite loop
                cout << i << " " << pinv+1 << endl;
                m[m[pinm][i-1]].push_back(m[pinm][i-1]);
                m[pinm].pop_back();
        }

        //cout << "recover return" << endl;
}

void move(map<int, vector<int> > &m, string action2, int from, int to)
{
        //cout << "call move" << endl;
        if (!is_ilegal(m, from, to)) {
                if (action2 == "onto")
                        recover(m, to);

                recover(m, from);

                int pinm_f, pinv_f, pinm_t, pinv_t;
                find_position(m, from, pinm_f, pinv_f);
                find_position(m, to, pinm_t, pinv_t);

                m[pinm_t].push_back(m[pinm_f][m[pinm_f].size()-1]);
                m[pinm_f].pop_back();
        }
}

void pile(map<int, vector<int> > &m, string action2, int from, int to)
{
        //cout << "call pile" << endl;
        if (!is_ilegal(m, from, to)) {
                if (action2 == "onto")
                        recover(m, to);

                int pinm_f, pinv_f, pinm_t, pinv_t;
                find_position(m, to, pinm_t, pinv_t);
                find_position(m, from, pinm_f, pinv_f);

                m[pinm_t].insert(m[pinm_t].begin()+pinv_t+1, m[pinm_f].begin()+pinv_f, m[pinm_f].end());
                m[pinm_f].erase(m[pinm_f].begin()+pinv_f, m[pinm_f].end());
        }
}

int main()
{
        int num;
        while (cin >> num) {
                string action;
                map<int, vector<int> > m;

                for (int i=0; i<num; i++) {
                        vector<int> v(1, i);
                        m[i]=v;
                }

                while (cin >> action) {
                        int from, to;
                        string action2;

                        if (action == "quit")
                                break;
                        else {
                                cin >> from >> action2 >> to;

                                if (action == "move")
                                        move(m, action2, from, to);
                                else
                                        pile(m, action2, from, to);
                        }
                }

                for (int i=0; i<num; i++) {
                        cout << i << ": ";

                        if (!m[i].empty()) {
                                for (int j=0; j!=m[i].size(); j++)
                                        cout << m[i][j] << " ";
                        }
                        cout << endl;
                }
        }
}

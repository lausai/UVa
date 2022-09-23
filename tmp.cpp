#include<iostream>
#include<sstream>
#include <algorithm>
using namespace std;

struct Contest{
    int id;
    int problem[10][2];
    int AC;
    int time; 
    bool have;
};

bool cmp( Contest a, Contest b )
{
    if( a.AC > b.AC )
        return 1;
    else if( a.AC == b.AC && a.time < b.time )
        return 1;
    else if( a.AC == b.AC && a.time == b.time && a.id < b.id )
        return 1;
    return 0;
}

int main()
{
    int N;
    while( cin >> N )
    {
        string s;
        stringstream ss;
        cin.get();
        getline( cin, s );
        for( int i = 0 ; i < N ; i++ )
        {
            if( i )
                cout << endl;
            
            int contestant, problem, time;
            char L;
            Contest team[105];
            for( int j = 0 ; j < 105 ; j++ )
            {
                team[j].id = j;
                memset( team[j].problem, 0, sizeof(team[j].problem) );
                team[j].AC = 0;
                team[j].time = 0;
                team[j].have = 0;
            }
            
            while( getline( cin, s ) && s != "" )
            {
                ss.clear();
                ss.str(s);
                ss >> contestant >> problem >> time >> L;
                team[contestant].have = 1;
                if( L == 'C' && team[contestant].problem[problem][0] != -1 )
                {
                    team[contestant].problem[problem][1] = time + team[contestant].problem[problem][0] * 20;
                    team[contestant].problem[problem][0] = -1;
                }
                else if( L == 'I' && team[contestant].problem[problem][0] != -1 )
                    team[contestant].problem[problem][0]++;
            }
            for( int j = 0 ; j < 105 ; j++ )
                if( team[j].have )
                    for( int k = 0 ; k < 10 ; k++ )
                        if( team[j].problem[k][0] == -1 )
                        {
                            team[j].AC++;
                            team[j].time += team[j].problem[k][1];
                        }
            sort( team, team+105, cmp );
            for( int j = 0 ; j < 105 ; j++ )
                if( team[j].have )
                    cout << team[j].id << ' ' << team[j].AC << ' ' << team[j].time << endl;            
        }
    }
    
    return 0;
}


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Position {
public:
	int x, y;
	char direction;
};

char E[256], W[256], S[256], N[256];

vector<Position> mark;				//儲存被 mark 過的位置

//機器人走完一步之後朝向哪個方向
char direct(char dire, char turn)
{
	switch (dire) {
		case 'E':
			return E[turn];
		case 'W':
			return W[turn];
		case 'S':
			return S[turn];
		case 'N':
			return N[turn];
	}
}

//函式呼叫前 cur_pos 表示機器人當前位置 函式呼叫後 cur_pos 為機器人遵照 ins 指令動作後的位置
void step(Position &cur_pos, char ins)
{
	if (ins != 'F') {
		cur_pos.direction = direct(cur_pos.direction, ins);
	} else {
		switch(cur_pos.direction) {
			case 'E':
				++cur_pos.x;
				break;
			case 'W':
				--cur_pos.x;
				break;
			case 'S':
				--cur_pos.y;
				break;
			case 'N':
				++cur_pos.y;
				break;
		}
	}
}

//機器人所在位置是否在土地外
bool outMap(const Position &pos, const int map[])
{
	if (pos.x>map[0] || pos.x<0 || pos.y>map[1] || pos.y<0)
		return true;

	return false;
}

//查看位置 pos 是否被 mark 起來了
bool inMark(const Position &pos)
{
	vector<Position>::size_type size = mark.size();

	for (int i=0; i<size; i++) {
		if (pos.x==mark[i].x && pos.y==mark[i].y) return true;
	}
	return false;
}

//機器人開始遵照指令 ins_s 來移動 若是機器人釣出土地 則回傳 false
bool walk(const Position &init_pos, Position &fin_pos, const int map[], const string &ins_s)
{
	Position cur_pos;

	fin_pos = cur_pos = init_pos;
	string::size_type size = ins_s.size();
	for (int i=0; i<size; i++) {
		char ins = ins_s.at(i);				//取出一個指令

		step(fin_pos, ins);
		if (outMap(fin_pos, map) ) {		//機器人執行完 ins 指令後掉出土地
			if (inMark(cur_pos) ) {			//檢查掉出土地的位置是否被 mark 過了
				fin_pos = cur_pos;			//如果被 mark 過則機器人忽略該指令
				continue;
			} else {
				fin_pos = cur_pos;			//沒有被 mark 過則紀錄掉出土地的位置到 fin_pos 回傳 false
				return false;
			}
		}
		cur_pos = fin_pos;
	}
	return true;
}

void setDireArrays()
{
	E['R'] = W['L'] = S['F'] = 'S';
	E['L'] = W['R'] = N['F'] = 'N';
	S['R'] = N['L'] = W['F'] = 'W';
	S['L'] = N['R'] = E['F'] = 'E';
}

int main()
{
	int map[2];
	Position init_pos, fin_pos;
	string ins_s;
	
	setDireArrays();
	cin >> map[0] >> map[1];

	while (cin >> init_pos.x >> init_pos.y >> init_pos.direction >> ins_s) {
		if (walk(init_pos, fin_pos, map, ins_s) ) {			//如果機器人走完而沒有掉出土地
			cout << fin_pos.x << " " << fin_pos.y << " " << fin_pos.direction << endl;
		} else {
			mark.push_back(fin_pos);	//機器人掉出土地 將位置 mark 起來
			cout << fin_pos.x << " " << fin_pos.y << " " << fin_pos.direction << " LOST" << endl;
		}
	}

	return 0;
}
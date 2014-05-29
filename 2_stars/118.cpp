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

vector<Position> mark;				//�x�s�Q mark �L����m

//�����H�����@�B����¦V���Ӥ�V
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

//�禡�I�s�e cur_pos ��ܾ����H��e��m �禡�I�s�� cur_pos �������H��� ins ���O�ʧ@�᪺��m
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

//�����H�Ҧb��m�O�_�b�g�a�~
bool outMap(const Position &pos, const int map[])
{
	if (pos.x>map[0] || pos.x<0 || pos.y>map[1] || pos.y<0)
		return true;

	return false;
}

//�d�ݦ�m pos �O�_�Q mark �_�ӤF
bool inMark(const Position &pos)
{
	vector<Position>::size_type size = mark.size();

	for (int i=0; i<size; i++) {
		if (pos.x==mark[i].x && pos.y==mark[i].y) return true;
	}
	return false;
}

//�����H�}�l��ӫ��O ins_s �Ӳ��� �Y�O�����H���X�g�a �h�^�� false
bool walk(const Position &init_pos, Position &fin_pos, const int map[], const string &ins_s)
{
	Position cur_pos;

	fin_pos = cur_pos = init_pos;
	string::size_type size = ins_s.size();
	for (int i=0; i<size; i++) {
		char ins = ins_s.at(i);				//���X�@�ӫ��O

		step(fin_pos, ins);
		if (outMap(fin_pos, map) ) {		//�����H���槹 ins ���O�ᱼ�X�g�a
			if (inMark(cur_pos) ) {			//�ˬd���X�g�a����m�O�_�Q mark �L�F
				fin_pos = cur_pos;			//�p�G�Q mark �L�h�����H�����ӫ��O
				continue;
			} else {
				fin_pos = cur_pos;			//�S���Q mark �L�h�������X�g�a����m�� fin_pos �^�� false
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
		if (walk(init_pos, fin_pos, map, ins_s) ) {			//�p�G�����H�����ӨS�����X�g�a
			cout << fin_pos.x << " " << fin_pos.y << " " << fin_pos.direction << endl;
		} else {
			mark.push_back(fin_pos);	//�����H���X�g�a �N��m mark �_��
			cout << fin_pos.x << " " << fin_pos.y << " " << fin_pos.direction << " LOST" << endl;
		}
	}

	return 0;
}
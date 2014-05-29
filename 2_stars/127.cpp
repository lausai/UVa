#include <iostream>
#include <string>
#include <vector>

using namespace std;

class pile {
public:
	vector<string> vs;
	pile *pre_node, *next_node;
	pile(string s);
};

pile::pile(string s)
{
	vs.push_back(s);
}

void play(pile*);
void release();
bool isMovable(pile*, pile*);
void rmNodeFromList(pile*);
int piles();

pile *head, *tail;

int main()
{
	string s;
	while (true) {
		cin >> s;
		// �p�G�r���O # �����j��
		if (s == "#") break;

		head = tail = new pile(s);
		head->pre_node = NULL;				//��C�Y�� pre_node �n�]�� NULL

		// �N�ѤU�� 51 �i�PŪ�i��
		for (int i = 0; i < 51; i++) {
			cin >> s;
			pile *node = new pile(s);
			node->pre_node = tail;
			tail->next_node = node;
			tail = node;
		}
		tail->next_node = NULL;
		//�}�l���P
		play(head);
		//���o�P���
		int _pile = piles();
		if (_pile == 1)
			cout << "1 pile remaining: 52" << endl;
		else {
			cout << _pile << " piles remaining:";
			
			pile *node = head;
			//�`�ǦL�X�P�諸�P��
			while (node) {
				cout << " " << node->vs.size();
				node = node->next_node;
			}
			cout << endl;
		}
		release();
	}
	return 0;
}

//�^���`�@���X�ӵP��
int piles()
{
	int i = 0;
	pile *node = head;
	while (node) {
		++i;
		node = node->next_node;
	}
	return i;
}

void play(pile *node)
{
	pile *left1, *left3;

	// �b�j��̭��N�@�i�P�������ʪ��줣��A���ʬ���
	while (true) {
		left1 = left3 = NULL;
		//���ˬd����@�� node �O�_�s�b
		if (node->pre_node) left1 = node->pre_node;

		//�A�ˬd����ĤT�� node �O�_�s�b
		if (node->pre_node && node->pre_node->pre_node && node->pre_node->pre_node->pre_node)
			left3 = node->pre_node->pre_node->pre_node;

		//�Y�`�I�s�b �ˬd�P����I�ƬO�_����ĤT�Ӹ`�I�ۦP
		if (left3 && isMovable(node, left3)) {
			//���ʼ��J�P
			left3->vs.push_back(node->vs.back());		
			node->vs.pop_back();
			//�p�G node �o�ӵP��w�g�S�P�F �N�`�I�R��
			if (node->vs.size() == 0) rmNodeFromList(node);
			//�q�P���ʹL�h���`�I�}�l�ˬd
			node = left3;
			continue;
		}
		//�Y�`�I�s�b �ˬd�O�_�P����I�ƬO�_����Ĥ@�Ӹ`�I�ۦP
		if (left1 && isMovable(node, left1)) {
			//���ʼ��J�P
			left1->vs.push_back(node->vs.back());
			node->vs.pop_back();
			//�p�G node �o�ӵP��w�g�S�P�F �N�`�I�R��
			if (node->vs.size() == 0) rmNodeFromList(node);
			//�q�P���ʹL�h���`�I�}�l�ˬd
			node = left1;
			continue;
		}

		if (node->next_node)
			node = node->next_node;
		else
			break;
	}
}

// �����C�O����
void release()
{
	pile *node = head, *node2;
	while (true) {
		node2 = node->next_node;
		delete node;
		if (node2)
			node = node2;
		else
			break;
	}
}

bool isMovable(pile *n1, pile *n2)
{
	bool ret = ((n1->vs.back()).at(0)==(n2->vs.back()).at(0) ) || ((n1->vs.back()).at(1)==(n2->vs.back()).at(1) );
	return ret;
}

void rmNodeFromList(pile *node)
{
	node->pre_node->next_node = node->next_node;
	if (node->next_node) node->next_node->pre_node = node->pre_node;
	delete node;
}
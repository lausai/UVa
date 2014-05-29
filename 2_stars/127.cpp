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
		// 如果字元是 # 結束迴圈
		if (s == "#") break;

		head = tail = new pile(s);
		head->pre_node = NULL;				//串列頭的 pre_node 要設為 NULL

		// 將剩下的 51 張牌讀進來
		for (int i = 0; i < 51; i++) {
			cin >> s;
			pile *node = new pile(s);
			node->pre_node = tail;
			tail->next_node = node;
			tail = node;
		}
		tail->next_node = NULL;
		//開始玩牌
		play(head);
		//取得牌堆數
		int _pile = piles();
		if (_pile == 1)
			cout << "1 pile remaining: 52" << endl;
		else {
			cout << _pile << " piles remaining:";
			
			pile *node = head;
			//循序印出牌堆的牌數
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

//回傳總共有幾個牌堆
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

	// 在迴圈裡面將一張牌往左移動直到不能再移動為止
	while (true) {
		left1 = left3 = NULL;
		//先檢查左邊一個 node 是否存在
		if (node->pre_node) left1 = node->pre_node;

		//再檢查左邊第三個 node 是否存在
		if (node->pre_node && node->pre_node->pre_node && node->pre_node->pre_node->pre_node)
			left3 = node->pre_node->pre_node->pre_node;

		//若節點存在 檢查牌色或點數是否跟左邊第三個節點相同
		if (left3 && isMovable(node, left3)) {
			//移動撲克牌
			left3->vs.push_back(node->vs.back());		
			node->vs.pop_back();
			//如果 node 這個牌堆已經沒牌了 將節點刪除
			if (node->vs.size() == 0) rmNodeFromList(node);
			//從牌移動過去的節點開始檢查
			node = left3;
			continue;
		}
		//若節點存在 檢查是否牌色或點數是否跟左邊第一個節點相同
		if (left1 && isMovable(node, left1)) {
			//移動撲克牌
			left1->vs.push_back(node->vs.back());
			node->vs.pop_back();
			//如果 node 這個牌堆已經沒牌了 將節點刪除
			if (node->vs.size() == 0) rmNodeFromList(node);
			//從牌移動過去的節點開始檢查
			node = left1;
			continue;
		}

		if (node->next_node)
			node = node->next_node;
		else
			break;
	}
}

// 釋放串列記憶體
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
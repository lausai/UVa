#include <iostream>

using namespace std;

class Person {
public:
	int no, pos;
};

//從 start 所指的人的下一個開始數 k 個人 會跳過已死的人 移動到 end 時會回到陣列頭部 font
Person *move(Person *start, Person *font, Person *end, int k)
{
	Person *p = start;
	while (k > 0) {
		++p;
		if (p == end) p = font;
		if (p->no == 0)
			continue;
		else
			--k;
	}
	return p;
}

//初始化陣列
void setPersonArray(int n, Person person[])
{
	for (int i=0; i<n; i++)
		person[i].no = person[i].pos = i + 1;
}

/*
void printArray(Person *start, Person *end)
{
	cout << endl;
	for (Person *p=start; p!=end; p++) {
		cout << "no: " << p->no << " pos: " << p->pos << endl;
	}
}*/

int main()
{
	int n, k;
	Person person[100];

	while (true) {
		cin >> n >> k;
		if (n==0 && k==0) break;		//測資結束 程式退出
		if (n == 1) {					//只有一個人時 答案都會是 1
			cout << 1 << endl;
			continue;
		}

		setPersonArray(n, person);

		Person *start = person - 1;		//移動起點 減1 是因為一開始從位置 1 的人算起
		Person *font  = person;			//陣列頂端
		Person *end   = person + n;		//陣列最後一個元素的下一個位置

		int alive = n;					//存活人數
		while (alive > 1) {
			Person *dead = move(start, font, end, k);
			dead->no = 0;				//no 為 0 表示該位置沒人或人已死

			if (--alive == 1) break;	//人死後只剩下一個人 退出迴圈

			Person *helper = move(dead, font, end, k);		//找出幫忙埋葬的人
			*(dead) = *(helper);							//幫忙牌葬的人移動到死掉的人位置
			helper->no = 0;									//於是幫忙埋葬的人位置就沒人
			start = dead;									//從死掉的人位置開始算人數
		}

		Person *i;
		for (i=person; i!=end; i++) {	//找到沒死的人
			if (i->no != 0) break;
		}
		
		for (int j = 1; j <= n; j++) {	//算出答案
			if ((j+(i->no-1)) % n == 1) {
				cout << j << endl;
				break;
			}
		}
	}

	return 0;
}
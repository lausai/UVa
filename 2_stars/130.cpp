#include <iostream>

using namespace std;

class Person {
public:
	int no, pos;
};

//�q start �ҫ����H���U�@�Ӷ}�l�� k �ӤH �|���L�w�����H ���ʨ� end �ɷ|�^��}�C�Y�� font
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

//��l�ư}�C
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
		if (n==0 && k==0) break;		//���굲�� �{���h�X
		if (n == 1) {					//�u���@�ӤH�� ���׳��|�O 1
			cout << 1 << endl;
			continue;
		}

		setPersonArray(n, person);

		Person *start = person - 1;		//���ʰ_�I ��1 �O�]���@�}�l�q��m 1 ���H��_
		Person *font  = person;			//�}�C����
		Person *end   = person + n;		//�}�C�̫�@�Ӥ������U�@�Ӧ�m

		int alive = n;					//�s���H��
		while (alive > 1) {
			Person *dead = move(start, font, end, k);
			dead->no = 0;				//no �� 0 ��ܸӦ�m�S�H�ΤH�w��

			if (--alive == 1) break;	//�H����u�ѤU�@�ӤH �h�X�j��

			Person *helper = move(dead, font, end, k);		//��X�����I�����H
			*(dead) = *(helper);							//�����P�����H���ʨ즺�����H��m
			helper->no = 0;									//��O�����I�����H��m�N�S�H
			start = dead;									//�q�������H��m�}�l��H��
		}

		Person *i;
		for (i=person; i!=end; i++) {	//���S�����H
			if (i->no != 0) break;
		}
		
		for (int j = 1; j <= n; j++) {	//��X����
			if ((j+(i->no-1)) % n == 1) {
				cout << j << endl;
				break;
			}
		}
	}

	return 0;
}
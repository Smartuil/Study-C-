#include<iostream>
using namespace std;

class BankWorker {
public:
	void save() {
		cout << "���" << endl;
	}

	void zhuanzhang() {
		cout << "ת��" << endl;
	}

	void jiaofei() {
		cout << "�ɷ�" << endl;
	}
};

class AbBankWorker {
	virtual void dothing() = 0;
};

class saveBanker:public AbBankWorker {
	virtual void dothing() {
		cout << "���" << endl;
	}
};

void main1() {
	BankWorker *bw = new BankWorker;
	bw->jiaofei();
	bw->jiaofei();
	bw->zhuanzhang();
}
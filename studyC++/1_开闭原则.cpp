#include<iostream>
using namespace std;

class BankWorker {
public:
	void save() {
		cout << "存款" << endl;
	}

	void zhuanzhang() {
		cout << "转账" << endl;
	}

	void jiaofei() {
		cout << "缴费" << endl;
	}
};

class AbBankWorker {
	virtual void dothing() = 0;
};

class saveBanker:public AbBankWorker {
	virtual void dothing() {
		cout << "存款" << endl;
	}
};

void main1() {
	BankWorker *bw = new BankWorker;
	bw->jiaofei();
	bw->jiaofei();
	bw->zhuanzhang();
}
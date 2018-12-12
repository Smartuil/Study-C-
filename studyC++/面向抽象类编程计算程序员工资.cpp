#include<iostream>
using namespace std;

class programmer{
public:
	virtual void getSal() = 0;
};

class junior_programmer : public programmer {
public:
	junior_programmer(const char *name, const char *job, int sal) {
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal() {
		cout << name << " " << job << " " << sal << endl;
	}

private:
	const char *name;
	const char *job;
	int sal;
};

class mid_programmer : public programmer {
public:
	mid_programmer(const char *name, const char *job, int sal) {
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal() {
		cout << name << " " << job << " " << sal << endl;
	}

private:
	const char *name;
	const char *job;
	int sal;
};

class adv_programmer : public programmer {
public:
	adv_programmer(const char *name, const char *job, int sal) {
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal() {
		cout << name << " " << job << " " << sal << endl;
	}

private:
	const char *name;
	const char *job;
	int sal;
};

class architect : public programmer {
public:
	architect(const char *name, const char *job, int sal) {
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal() {
		cout << name << " " << job << " " << sal << endl;
	}

private:
	const char *name;
	const char *job;
	int sal;
};

void CalProgrammer(programmer *base) {
	base->getSal();
}

void main(){
	junior_programmer jp("Chu","初级", 4000);
	mid_programmer mp("Liu","中级", 8600);
	adv_programmer ap("Gao","高级", 15000);
	architect ar("Jia", "架构师", 24000);

	CalProgrammer(&jp);
	CalProgrammer(&mp);
	CalProgrammer(&ap);
	CalProgrammer(&ar);
}
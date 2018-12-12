#include<iostream>
using namespace std;

//�õ��Կ�ܺ;��峧�̽��н����

class HardDisk {
public:
	virtual void work()=0;
};

class Memory {
public:
	virtual void work()=0;
};

class Cpu {
public:
	virtual void work()=0;
};

class Computer {
public:
	//HardDisk
	//Memory
	//Memory
	Computer(HardDisk *harddisk, Memory *memory, Cpu *cpu) {
		m_harddisk = harddisk;
		m_memory = memory;
		m_cpu = cpu;
	}

public:
	void work() {
		m_harddisk->work();
		m_memory->work();
		m_cpu->work();
	}

private:
	HardDisk *m_harddisk;
	Memory *m_memory;
	Cpu *m_cpu;
};

class InterCpu :public Cpu{
public:
	void work() {
		cout << "�������ض�" << endl;
	}
};

class XSHardDisk :public HardDisk {
public:
	void work() {
		cout << "��������" << endl;
	}
};

class JSDMemory :public Memory {
public:
	void work() {
		cout << "���ǽ�ʿ��" << endl;
	}
};

void main2() {
	HardDisk *harddisk = NULL;
	Memory *memory = NULL;
	Cpu *cpu = NULL;
	harddisk = new XSHardDisk;
	memory = new JSDMemory;
	cpu = new InterCpu;

	Computer *mycomputer = new Computer(harddisk, memory, cpu);
	mycomputer->work();
	delete mycomputer;
	delete cpu;
	delete memory;
	delete harddisk; 
	system("pause");
}
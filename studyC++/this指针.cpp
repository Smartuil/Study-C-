#include<iostream>
using namespace std;


class Test{
public:
	Test(int a, int b) {
		this->a = a;
		this->b = b;
	}

	//constд��ʲô�ط�û�й�ϵ
	//const����˭�������β�a.
	//����thisָ����ڴ�ռ�
	void OpVar(int a, int b) const{//======>void OpVar(Test *const this, int a, int b) 
		//this->a = 100;
		cout << a << endl;
		cout << b << endl;
	}
protected:
private:
	int a;
	int b;
};
void main(){

}
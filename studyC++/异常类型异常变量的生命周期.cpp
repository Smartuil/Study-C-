#include<iostream>
using namespace std;


void my_strcpy1(char *to, char *from) {
	if (from == NULL) {
		throw 1;
	}
	if (to == NULL) {
		throw 2;
	}
	if (*from == 'a')throw 3;
	while (*from != '\0') {
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}

void my_strcpy2(char *to, char *from) {
	if (from == NULL) {
		throw "源buf出错";
	}
	if (to == NULL) {
		throw "目的buf出错";
	}
	if (*from == 'a') {
		throw "copy出错";
	}

	while (*from != '\0') {
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}

class BadSrcErr{
public:
protected:
private:
};


class BadDesErr {
public:
protected:
private:
};


class BadProcessErr {
public:
	BadProcessErr() {
		cout << "构造函数" << endl;
	}

	BadProcessErr(const BadProcessErr &b) {
		cout << "copy构造函数" << endl;
	}

	~BadProcessErr()
	{
		cout << "析构函数" << endl;
	}
protected:
private:
};


void my_strcpy3(char *to, char *from) {
	if (from == NULL) {
		throw BadSrcErr();
	}
	if (to == NULL) {
		throw BadDesErr();//产生一个匿名对象
	}
	if (*from == 'a')throw BadProcessErr();
	if (*from == 'b')throw &(BadProcessErr());
	if (*from == 'c')throw new BadProcessErr;
	while (*from != '\0') {
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}


void main() {
	int ret = 0;
	char buf1[] = "aaaa";
	char buf2[1024] = { 0 };
	
	try
	{
		my_strcpy2(buf2, buf1);
	}
	catch (int e)
	{
		cout << e << "int 异常" << endl;
	}
	catch (const char *e)//语法有变   记得用const
	{
		cout << e << "  char* 异常" << endl;
	}
	catch (BadSrcErr e)
	{
		cout << "  BadSrcErr 异常" << endl;
	}
	catch (BadDesErr e)
	{
		cout  << "  BadDesErr 异常" << endl;
	}
	//catch (BadProcessErr e)//匿名对象copy给e     调用copy构造函数
	//{
	//	cout << "  BadProcessErr异常" << endl;
	//}
	//catch (BadProcessErr &e)//会使用throw的那个对象
	//{
	//	cout << "  BadProcessErr异常" << endl;//引用和指针可以在一起   指针也可以和元素    元素和引用不能一起
	//}
	catch (BadProcessErr *e)//
	{
		cout << "  BadProcessErr异常" << endl;
		delete e;
	}
	catch (...)
	{
		cout << "未知 异常" << endl;
	}

}



//传统出错处理机制
int my_strcpy(char *to, char *from) {
	if (from == NULL) {
		return 1;
	}
	if(to == NULL) {
		return 2;
	}
	if (*from = 'a')return 3;
	while (*from != '\0') {
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}

void main11111111(){


	int ret = 0;
	char buf1[] = "sasaada";
	char buf2[1024] = {0};
	ret = my_strcpy(buf2, buf1);
	if (ret != 0) {
		switch (ret)
		{
		case 1:
			cout << "源buf出错" << endl;
			break;
		case 2:
			cout << "目的buf出错" << endl;
			break;
		case 3:
			cout << "copy出错" << endl;
			break;
		default:
			break;
		}
	}
	cout << buf2 << endl;
}
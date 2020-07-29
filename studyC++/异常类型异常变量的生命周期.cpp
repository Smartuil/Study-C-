//#include<iostream>
//using namespace std;
//
//
//void my_strcpy1(char *to, char *from) {
//	if (from == NULL) {
//		throw 1;
//	}
//	if (to == NULL) {
//		throw 2;
//	}
//	if (*from == 'a')throw 3;
//	while (*from != '\0') {
//		*to = *from;
//		to++;
//		from++;
//	}
//	*to = '\0';
//}
//
//void my_strcpy2(char *to, char *from) {
//	if (from == NULL) {
//		throw "源buf出错";
//	}
//	if (to == NULL) {
//		throw "目的buf出错";
//	}
//	if (*from == 'a') {
//		throw "copy出错";
//	}
//
//	while (*from != '\0') {
//		*to = *from;
//		to++;
//		from++;
//	}
//	*to = '\0';
//}
//
//class BadSrcErr{
//public:
//protected:
//private:
//};
//
//
//class BadDesErr {
//public:
//protected:
//private:
//};
//
//
//class BadProcessErr {
//public:
//	BadProcessErr() {
//		cout << "构造函数" << endl;
//	}
//
//	BadProcessErr(const BadProcessErr &b) {
//		cout << "copy构造函数" << endl;
//	}
//
//	~BadProcessErr()
//	{
//		cout << "析构函数" << endl;
//	}
//protected:
//private:
//};
//
//
//void my_strcpy3(char *to, char *from) {
//	if (from == NULL) {
//		throw BadSrcErr();
//	}
//	if (to == NULL) {
//		throw BadDesErr();//产生一个匿名对象
//	}
//	if (*from == 'a')throw BadProcessErr();
//	if (*from == 'b')throw &(BadProcessErr());
//	if (*from == 'c')throw new BadProcessErr;
//	while (*from != '\0') {
//		*to = *from;
//		to++;
//		from++;
//	}
//	*to = '\0';
//}
//
//
//void main1() {
//	int ret = 0;
//	char buf1[] = "aaaa";
//	char buf2[1024] = { 0 };
//	
//	try
//	{
//		my_strcpy2(buf2, buf1);
//	}
//	catch (int e)
//	{
//		cout << e << "int 异常" << endl;
//	}
//	catch (const char *e)//语法有变   记得用const
//	{
//		cout << e << "  char* 异常" << endl;
//	}
//	catch (BadSrcErr e)
//	{
//		cout << "  BadSrcErr 异常" << endl;
//	}
//	catch (BadDesErr e)
//	{
//		cout  << "  BadDesErr 异常" << endl;
//	}
//	//catch (BadProcessErr e)//匿名对象copy给e     调用copy构造函数
//	//{
//	//	cout << "  BadProcessErr异常" << endl;
//	//}
//	//catch (BadProcessErr &e)//会使用throw的那个对象
//	//{
//	//	cout << "  BadProcessErr异常" << endl;//引用和指针可以在一起   指针也可以和元素    元素和引用不能一起
//	//}
//	catch (BadProcessErr *e)//
//	{
//		cout << "  BadProcessErr异常" << endl;
//		delete e;
//	}
//	catch (...)
//	{
//		cout << "未知 异常" << endl;
//	}
//
//}
//
//
//
////传统出错处理机制
//int my_strcpy(char *to, char *from) {
//	if (from == NULL) {
//		return 1;
//	}
//	if(to == NULL) {
//		return 2;
//	}
//	if (*from = 'a')return 3;
//	while (*from != '\0') {
//		*to = *from;
//		to++;
//		from++;
//	}
//	*to = '\0';
//}
//
//void main11111111(){
//
//
//	int ret = 0;
//	char buf1[] = "sasaada";
//	char buf2[1024] = {0};
//	ret = my_strcpy(buf2, buf1);
//	if (ret != 0) {
//		switch (ret)
//		{
//		case 1:
//			cout << "源buf出错" << endl;
//			break;
//		case 2:
//			cout << "目的buf出错" << endl;
//			break;
//		case 3:
//			cout << "copy出错" << endl;
//			break;
//		default:
//			break;
//		}
//	}
//	cout << buf2 << endl;
//}

#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

//使用异常的方式进行处理


void my_strcpy1(char *dst, char *from) {
	if (dst == NULL) {
		throw 1; //1 代表目的地址有问题
	}
	else if (from == NULL) {
		throw 2; //2 代表源地址有问题
	}

	if (*from == 'a') {
		throw 3; //代表copy过程出现问题
	}


	while (*from != '\0') {
		*dst = *from;
		dst++;
		from++;
	}
	*dst = '\0';
}


void my_strcpy2(char* dst, char *from)
{
	if (dst == NULL) {
		throw "目的地址有问题"; //1 代表目的地址有问题
	}
	else if (from == NULL) {
		throw "源地址有问题"; //2 代表源地址有问题
	}

	if (*from == 'a') {
		throw "copy过程出现问题"; //代表copy过程出现问题
	}


	while (*from != '\0') {
		*dst = *from;
		dst++;
		from++;
	}
	*dst = '\0';
}

//目的地址有问题的异常类型
class BadDstAddrType {};
class BadSrcAddrType {};
class BadProcessAddrType {
public:
	BadProcessAddrType()
	{
		cout << "BadProcessAddrType().." << endl;
	}
	BadProcessAddrType(const BadProcessAddrType & obj)
	{
		cout << "BadProcessAddrType(const BadProcessAddrType &)..." << endl;
	}
	void print() {
		cout << "copy过程出现了异常" << endl;
	}
	~BadProcessAddrType() {
		cout << "~BadProcessAddrType()..." << endl;
	}
};

void my_strcpy3(char *dst, char *from)
{
	if (dst == NULL) {
		throw BadDstAddrType(); //1 代表目的地址有问题
	}
	else if (from == NULL) {
		throw BadSrcAddrType(); //2 代表源地址有问题
	}

	if (*from == 'a') {
		//throw new BadProcessAddrType(); //在抛出这个BadProcessAddrType() 会创建一个匿名对象 
		throw BadProcessAddrType();
	}


	while (*from != '\0') {
		*dst = *from;
		dst++;
		from++;
	}
	*dst = '\0';
}

int main(void)
{
	char buf1[] = "a234567";
	char buf2[128] = { 0 };

	try {
		my_strcpy3(buf2, buf1);
	}
	catch (int e)
	{
		cout << "捕获到异常代码e = " << e << endl;
	}
	catch (char *e)
	{
		cout << "捕获到char*类型异常e = " << e << endl;
	}
	//catch (BadProcessAddrType e) { //BadProcessAddrType e = 匿名对象temp //在捕获的时候，如果用一个元素捕获
													//会发生拷贝构造，异常对象e和被抛出来的匿名对象不是一个对象
													//会有深拷贝和浅拷贝的风险
//		cout << "捕获到了BadProcessAddrType 异常类型e  " << endl;
//		e.print();
//	}
	catch (BadProcessAddrType *e) { //此时那个匿名对象已经被释放了，e是一个野指针
		cout << "捕获到了BadProcessAddrType* 异常类型e" << endl;
		delete e; //如果抛出的异常类型是new出来的，需要显示的delete掉
	}
	catch (BadProcessAddrType &e) { //1 普通元素类型的异常捕获，不能够跟 引用捕获同时存在。
		cout << "捕获到了 BadProcessAddrType & 异常类型" << endl;
		//编译器发现使用引用捕获的，那么不会立刻释放掉匿名对象， 而是在异常处理完之后，才把e释放。
		//可以理解为 BadProcessAddrType &e = BadProcessAddrType()
	}
	catch (...)
	{
		cout << "捕获到未知异常" << endl;
	}
}

#if 0
int my_strcpy(char *dst, char *from)
{
	if (dst == NULL) {
		return 1; //1 代表目的地址有问题
	}
	else if (from == NULL) {
		return 2; //2 代表源地址有问题
	}

	if (*from == 'a') {
		return 3; //代表copy过程出现问题
	}


	while (*from != '\0') {
		*dst = *from;
		dst++;
		from++;
	}
	*dst = '\0';

	return 0;
}

//传统的捕获错误方法
int main(void)
{
	char buf1[] = "a234567";
	char buf2[128] = { 0 };
	int ret = 0;

	ret = my_strcpy(buf2, buf1);
	if (ret != 0) {
		switch (ret)
		{
		case 1:
			cout << "目的地址有问题" << endl;
			break;
		case 2:
			cout << "原地址有问题" << endl;

			break;
		case 3:
			cout << "拷贝过程有问题" << endl;

			break;
		default:
			break;
		}
	}
	else {
		cout << "buf2 = " << buf2 << endl;
	}


	return 0;
}
#endif
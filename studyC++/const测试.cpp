#include "iostream"
#include "string"

using namespace std;


int find_char(string&s, char c)
{
	return 0;
}

bool isSentence(const string &s)

{

	//return find_char(s, 'o');//错误，s是常量引用不能赋给非常量变量
	return 0;
}

void bar(int a, int *b)
{

}
void bar(int a, int i)
{

}


int main()
{
	int a = 0, *b =&a;
	//find_char("Hello", 'o');//错误，普通引用无法接收字面值
	bar(a, b);
	bar(a, 0);
	return 0;
}
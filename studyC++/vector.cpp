#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	vector<vector<int> > vecTest;
	vector<int> vec_int;
	vector<int> vec_intTest;

	vec_int.push_back(0);
	vec_int.push_back(1);
	vec_int.push_back(2);
	vec_int.push_back(3);

	vec_intTest.push_back(9);
	vec_intTest.push_back(10);
	vec_intTest.push_back(11);
	vec_intTest.push_back(12);

	vecTest.push_back(vec_int);
	vecTest.push_back(vec_intTest);

	auto iter = vecTest.begin();
	for (; iter != vecTest.end(); ++iter)
	{
		for (int i = 0; i < vec_int.size(); ++i)
		{
			cout << (*iter)[i] << endl;
		}
	}
	return 0;
}

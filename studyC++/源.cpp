#include "iostream"

using namespace std;

class Bear {
public:
	int total;
	int gaizi;
	int pingzi;

	Bear(int m_total, int m_gaizi, int m_pingzi) {
		total = m_total;
		gaizi = m_gaizi;
		pingzi = m_pingzi;
	}
	void getA(int n) {
		total += n;
		gaizi += n;
		pingzi += n;
	}

	void _4gaizi(int n) {
		gaizi -= 4 * n;
	}
	void _2pingzi(int n) {
		pingzi -= 2 * n;
	}
	void print() {
		cout << "喝了" << total << "瓶,还有盖子" << gaizi << "个，还有瓶子" << pingzi << "个" << endl;
	}
};
int main() {
	Bear *b = new Bear(5, 5, 5);
	b->print();
	while (b->gaizi >= 4 || b->pingzi >= 2) {
		if (b->gaizi >= 4) {
			int tmp = b->gaizi / 4;
			b->_4gaizi(b->gaizi / 4);
			b->getA(tmp);
		}
		if (b->pingzi >= 2) {
			int tmp = b->pingzi / 2;
			b->_2pingzi(b->pingzi / 2);
			b->getA(tmp);
		}
	}

	b->print();
}
#include<iostream>
using namespace std;
#include "string"
#include "vector"
#include "list"
#include "set"
#include "algorithm"
#include "functional"
#include "iterator"
#include "map"
#include "deque"
#include "deque"
#include "numeric"

class Speaker {
public:
	string name;
	int m_score[3];
protected:
private:
};

int GenSpeaker(map<int, Speaker> &mapSpeaker, vector<int> &v) {
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	random_shuffle(str.begin(), str.end());
	for (int i = 0; i < 24; i++) {
		Speaker tmp;
		tmp.name = "选手";
		tmp.name = tmp.name + str[0];
		//tmp->m_score = 0;
		mapSpeaker.insert(pair<int, Speaker>(100 + i, tmp));
	}

	for (int i = 0; i < 24; i++) {
		v.push_back(100 + i);
	}

	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
	//	cout << *it << "   ";
	//}
	return 0;
}

int speech_contest_draw(vector<int> &v) {
	random_shuffle(v.begin(), v.end());
	return 0;
}

int speech_contest(int index, vector<int> &v1, map<int, Speaker> &mapSpeaker, vector<int> &v2) {

	multimap<int, int, greater<int>> multimapGroup;
	int tmpCount = 0;
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		tmpCount++;
		deque<int> dscore;
		for (int j = 0; j < 10; j++) {
			int score = 50 + rand() % 50;
			dscore.push_back(score);
		}
		sort(dscore.begin(), dscore.end());
		dscore.pop_back();
		dscore.pop_front();
		int scoresum = accumulate(dscore.begin(), dscore.end(), 0);
		int scoreavg = scoresum / dscore.size();
		mapSpeaker[*it].m_score[index] = scoreavg;
		multimapGroup.insert(pair<int, int>(scoreavg, *it));
		if (tmpCount % 6 == 0) {
			cout << "小组的比赛成绩" << endl;
			for (multimap<int, int, greater<int>>::iterator mit = multimapGroup.begin(); mit != multimapGroup.end(); mit++) {
				cout << mit->second << "\t" << mapSpeaker[mit->second].name << mit->first << endl;
			}

			while (multimapGroup.size() > 3) {
				multimap<int, int, greater<int>>::iterator it1 = multimapGroup.begin();
				v2.push_back(it1->second);
				multimapGroup.erase(it1);
			}
			multimapGroup.clear();
		}
	}
	return 0;
}

int speech_contest_print(int index, vector<int> &v, map<int, Speaker> &mapSpeaker) {
	cout << "第" << index + 1 << "轮晋级名单" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << "参赛编号" << *it << "\t" << mapSpeaker[*it].name << "\t" << mapSpeaker[*it].m_score[index] << endl;
}
	return 0;
}

void main(){
	map<int, Speaker> mapSpeaker;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	GenSpeaker(mapSpeaker, v1);
	//抽签  比赛  结果

	cout << "\n\n\n任意键开始第1轮比赛\n";
	cin.get();
	speech_contest_draw(v1);
	speech_contest(0, v1, mapSpeaker, v2);
	speech_contest_print(0, v2, mapSpeaker);


	cout << "\n\n\n任意键开始第2轮比赛\n";
	cin.get();
	speech_contest_draw(v2);
	speech_contest(1, v2, mapSpeaker, v3);
	speech_contest_print(1, v3, mapSpeaker);


	cout << "\n\n\n任意键开始第3轮比赛\n";
	cin.get();
	speech_contest_draw(v3);
	speech_contest(2, v3, mapSpeaker, v4);
	speech_contest_print(2, v4, mapSpeaker);
}
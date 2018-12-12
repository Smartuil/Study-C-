#include<iostream>
using namespace std;

class HeroFighter{
public:
	virtual int power() {
		return 10;
	}
};


class EnemyFighter {
public:
	int attack() {
		return 15;
	}
};

class AvdHeroFighter : public HeroFighter {
public:
	virtual int power() {
		return 20;
	}
};

class SuperAvdHeroFighter : public HeroFighter {
public:
	virtual int power() {
		return 30;
	}
};

void play(HeroFighter *hf, EnemyFighter *ef) {
	if (hf->power() > ef->attack()) {
		cout << "Hero Win£¡" << endl;
	}
	else {
		cout << "Hero Lose£¡" << endl;
	}
}

void main(){
	HeroFighter hf;
	AvdHeroFighter ahf;
	EnemyFighter ef;
	SuperAvdHeroFighter sahf;

	play(&hf, &ef);
	play(&ahf, &ef);
	play(&sahf, &ef);

}
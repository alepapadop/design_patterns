#include <iostream>

using namespace std;

class Animal {
	public:
		virtual void make_sound() = 0;
};

class Dog : public Animal {
	void make_sound() {
		cout << " wow " << endl;
	}
};

class NullDog : public Animal {
	void make_sound() {}
};

int main()
{

	Animal *animals[2];

	animals[0] = new Dog();
	animals[1] = new NullDog();

	animals[0]->make_sound();
	animals[1]->make_sound();


}

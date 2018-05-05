#include<iostream>


struct Anonimal{ // anon animal(interface)
virtual	void speak(void) = 0;
};

struct Dog : public Anonimal{
	void speak(void) override{
		std::cout << "Bark-bark" << std::endl;
	}
};

struct Cat : public Anonimal{
	virtual void speak(void){
		std::cout << "Meow-meow" << std::endl;
	}
};

void doSound( struct Anonimal & anonImal ){
	anonImal.speak();
}

int main(void){
	Anonimal * anon;

	anon=new Dog;
	doSound( *anon );
	delete anon;

	anon= new Cat;
	doSound( *anon );
	delete anon;

}

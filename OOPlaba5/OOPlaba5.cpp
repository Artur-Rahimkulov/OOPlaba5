#include <iostream>
using namespace std;

class Animal {
public:
	virtual void voice() {
	}

	void Do1() {					//метод, который будет перекрываться
		printf("Animal::Do1\n");
	}

	void Do2() {					//метод, который будет наследоваться в Lion
		printf("Animal::Do2\n");
	}

	virtual void Do3() {			//виртуальный метод
		printf("Animal::DoSmth3\n");
	}
	virtual string classname() {
		return "Animal";
	}
	virtual bool isAnimal(string classname) {
		return(classname == "Animal");
	}

	virtual~Animal() {
		//printf("~Animal\n");
	}

};
int main()
{
    
}


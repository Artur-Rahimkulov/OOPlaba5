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
class Duck : public Animal {
public:
	Duck() {

	}
	void sit() {
		printf("Duck::hunt\n");
	}
	void voice() {
		printf("kryak");
	}
	void Do1() {
		printf("Duck::Do1\n");
	}

	void Do3() {
		printf("Duck::Do3\n");
	}
	string classname() {
		return "Duck";
	}
	bool isDuck(string classname) {
		return(classname == "Duck");
	}


	~Duck() {
		//printf("~Duck\n");
	}
};

class Goose : public Animal {
public:
	Goose() {

	}

	void run() {
		printf("Goose::run\n");
	}

	void voice() {
		printf("gagaga");
	}

	string classname() {
		return "Goose";
	}

	bool isGoose(string classname) {
		return(classname == "Goose");
	}
};
int main()
{
    
}


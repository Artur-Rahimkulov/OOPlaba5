#include <iostream>
using namespace std;

class Animal {
public:
	virtual void voice() {
	}
	Animal() {
		//printf("Animal()\n");

	}
	void Do1() {					//метод, который будет перекрываться
		printf("Animal::Do1\n");
	}

	void Do2() {					//метод, который будет наследоваться в Duck
		printf("Animal::Do2\n");
	}

	virtual void Do3() {			//виртуальный метод
		printf("Animal::Do3\n");
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
		printf("Duck()\n");

	}
	void sit() {
		printf("Duck::sit\n");
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
	bool isAnimal(string classname) {
		return(classname == "Duck");
	}


	~Duck() {
		//printf("~Duck\n");
	}
};

class Goose : public Animal {
public:
	Goose() {
		printf("Goose()\n");

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

	bool isAnimal(string classname) {
		return(classname == "Goose");
	}
};
class Base {
public:
	Base() {
		printf("Base()\n");
	}

	Base(Base* obj) {
		printf("Base(Base* obj)\n");
	}

	Base(Base& obj) {
		printf("Base(Base& obj)\n");
	}

	virtual~Base() {
		printf("~Base()\n");
	}
};
class Desc : public Base {
public:
	Desc() {
		printf("Desc()\n");
	}

	Desc(Base* obj) {
		printf("Desc(Desc* obj)\n");
	}

	Desc(Base& obj) {
		printf("Desc(Desc& obj)\n");
	}

	~Desc() {
		printf("~Desc()\n");
	}
};

void func1(Base obj) {
	printf("void func1(Base obj)\n");
}

void func2(Base* obj) {
	printf("void func2(Base *obj)\n");
}

void func3(Base& obj) {
	printf("void func3(Base& obj)\n");
}

Base func11(Base obj) {
	printf("Base func11()\n");
	return obj;
}

Base* func22(Base* obj) {
	printf("Base* func22()\n");
	return obj;
}

Base& func33(Base& obj) {
	printf("Base& func33()\n");
	return obj;
}



int main()
{
	setlocale(LC_ALL, "rus");
    srand(time(NULL));
	printf("создание объекта наследника, находящееся в переменной наследника \n");
	Duck* a = new Duck();//создание объекта наследника, находящееся в переменной наследника  
	printf("вызов переопределяемого метода  \n");
	a->Do1();//вызов переопределяемого метода 
	printf("вызов наследуемого метода  \n");
	a->Do2();//вызов наследуемого метода
	delete a;

	printf("создание объекта базового класса, находящееся в переменной базового класса   \n");
	Animal* b = new Animal();;//создание объекта базового класса, находящееся в переменной базового класса  
	printf("вызов виртуального метода базового класса \n");
	b->Do3();//вызов витруального метода базового класса
	delete b;

	printf("создание объекта наследника, находящееся в переменной базового класса  \n");
	Animal* c = new Duck();//создание объекта наследника, находящееся в переменной базового класса  
	printf("вызов наследуемого виртуального метода\n");
	c->Do3();//вызов наследуемого виртуального метода
	delete c;


	printf("\n\n\n");


	Animal* d;
	if (rand() % 2 == 0) {
		d = new Duck();
	}
	else{
		d = new Goose();
	}

	if (d->classname() == "Duck") { //проверка на принадлежность некоторому классу 
		((Duck*)d)->sit();          //c помощью метода classname
	}
	else {
		((Goose*)d)->run();
	}
	delete d;




	Animal* e;
	if (rand() % 2 == 0) {
		e = new Duck();
	}
	else {
		e = new Goose();
	}

	if (e->isAnimal("Duck")) { //проверка на принадлежность некоторому классу 
		((Duck*)e)->sit();//c помощью метода isAnimal
	}
	else {
		((Goose*)e)->run();
	}
	delete e;




	Animal* f;
	if (rand() % 2 == 0) {
		f = new Duck();
	}
	else {
		f = new Goose();
	}
	((Duck*)f)->sit(); //опасное приведение типов
	delete f;



	
	Animal* g;
	if (rand() % 2 == 0) {
		g = new Duck();
	}
	else {
		g = new Goose();
	}
	if (dynamic_cast<Duck*>(g)) {//безопасное приведение типов 
		((Duck*)g)->sit();       //с помощью dynamic_cast
	}
	else {
		((Goose*)g)->run();
	}
	delete g;
	printf("\n\n\n\n\n\n\n");


	Base* h = new Base();
	func1(h);
	func2(h);
	func3(*h);
	printf("\n\n");
	

	Desc* i = new Desc();
	func1(*i);
	func2(i);
	func3(*i);
	delete i;
	printf("\n\n");

	func11(*h);
	func22(h);
	func33(*h);
	delete h;


	
	printf("\n\n");
	{
		unique_ptr<Base> unq(new Desc());
	}

	printf("\n\n");

	Base* j = new Desc();
	shared_ptr<Base> p1(j);
	{
		shared_ptr<Base> p2(p1);
	}




}


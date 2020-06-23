#include <iostream>
using namespace std;

/*	EJERCICIO 1		*/
/*
void mostrar(int i) { cout << i << "?[entero]" << endl; }
void mostrar(float f) { cout << f << "?[real]" << endl; }

int main()
{
 mostrar(2);
 mostrar(2.0);	//MAL
 mostrar('a');
}
*/



/*	EJERCICIO 2		*/
/*
void f(char);
void f(double);
void f(void *);

int main()
{
	 f(0.0);
	 //f(0);	//MAL
	 f(0.0f);
	 f("Hola");		//MAL
}
*/



/*	EJERCICIO 3		*/
/*
class B{
	public:	
		B(int x):x_(x){}	
		virtual void f(){cout<<"Soy B"<<endl;};
	
	protected:	
		int x_;
};

class D:public B{
	
	public:
		D(int x, int y):B(x),y_(y){}
		void f(){cout<<"Soy D"<<endl; cout<<"x "<<x_<<"y "<<y_<<endl;};
	private:	
		int y_;
};

int main(){
	/*
	B b, *bp;
 	D d, *dp;
 	
 	bp = &d;
 	cout<<"bp->f();"<<endl;
 	bp->f();
 	
 	//dp = &b;
 	//cout<<"dp->f();"<<endl;		//MAL, CON VIRTUAL Y SIN VIRTUAL
 	//dp->f();
 	
 	dp = &d;
 	cout<<"dp->f();"<<endl;
 	dp->f();
 	*/
 	
	 
	 
	/*	SOLO DE PRUEBA	*/	
 	/*
 	B b(5), *bp;
 	D d(7,6), *dp;
 	
 	bp = &d;
 	cout<<"bp->f();"<<endl;
 	bp->f();
	*/
//}

/*	EJERCICIO 4		*/
/*
struct B {
	
	 B() { std::cout << "Constructor de B\n"; }
 	 ~B() { std::cout << "Destructor de B\n"; }
 	
};

struct D: B {
	
 	D() { std::cout << "Constructor de D\n"; }
 	~D() { std::cout << "Destructor de D\n"; }
 	
};
 
int main() {
	
 	B *pb = new D;
 	delete pb;
 	
}

*/

/*	EJERCICIO 5	*/
struct A {

 	~A() { std::cout << "Destructor de A\n"; }
 	
};

struct B: public A {

 	virtual ~B() { std::cout << "Destructor de B\n"; }
 	
};
struct C: public B {

 	virtual ~C() { std::cout << "Destructor de C\n"; }
 	
};

struct D: public C {

 	virtual ~D() { std::cout << "Destructor de D\n"; }
 	
};

int main()
{
	
	B *pb = new C;
	delete pb;
	
}

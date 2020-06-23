#include <iostream>
#include <vector>
using namespace std;
/*
void mostrar(int i) { cout << i << "?[entero]" << endl; }
void mostrar(float f) { cout << f << "?[real]" << endl; }

int main()
{
 	mostrar(2);
 	mostrar(2.0);
 	mostrar('a');
}
*/
void f(char);
void f(double f) {};
void f(void *);
/*
class rectangulo {
	
	public:
		rectangulo(double a, double l): ancho(a), largo(l) {}
	 double area() {return ancho * largo;}
	
	private:
		double ancho, largo;
};
class cuadrado: public rectangulo {
	
	public:
		cuadrado (double l): rectangulo(l, l) {}
	//	double area() {cout<<"lo llama";return rectangulo::area();}
};
*/
/*
class A { public: ~A(); };
class B : public A { public: virtual ~B(); };
class C : public B { public: virtual ~C(); };
class D : public C { public: ~D(){cout<<"destructor de D";}};
*/

int main() {
/*
	int i = 3;                   
    const int& i_noconst = i; 
    const_cast<int&>(i_noconst) = 4;
    const_cast<int&>(i_noconst) = 5;
	cout<<i<<endl;
*/
	std::vector<int> v(5);
	v.push_back(10);
}
/*
1 	class rectangulo { 
2 	public:
 3 		rectangulo(double a, double l): ancho(a), largo(l) {}
 4 		virtual double area() { return ancho * largo; } 
5 	private: 
6 		double ancho, largo; 
7 	};
 9 	class cuadrado: public rectangulo { 
10 		public: 
11 		cuadrado (double l): rectangulo(l, l) {} 
12		 double area() { return rectangulo::area(); } 
13 	}; 
S� cambiar�a el comportamiento en tiempo de ejecuci�n. 	
Por ejemplo cuando creamos un puntero de la clase rect�ngulo y lo apuntamos a un objeto del tipo cuadrado, al llamar a la funci�n area(), �sta s�lo se llamar�a en la definida en la clase rect�ngulo, mientras que si definimos la funcion �rea como virtual, se llamar�a a la funci�n �rea de la clase cuadrado.
Un ejemplo pr�ctico (sin virtual) :
rectangulo* r = new cuadrado(3.0);
cout<<r->area()	//Llama a rectangulo::area()
Ejemplo pr�ctico (con virtual) :
rectangulo* r = new cuadrado(3.0);
cout<<r->area()	//Llama a cuadrado::area()

En nuestro caso, si eliminamos virtual de la funci�n area() no ocurr�a nada, ya que tanto rectagulo como cuadrado tienen el mismo �rea, aunque en otros casos, podr�a dar a lugar a un comportamiento no deseado.
*/

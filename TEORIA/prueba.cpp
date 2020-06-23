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
Sí cambiaría el comportamiento en tiempo de ejecución. 	
Por ejemplo cuando creamos un puntero de la clase rectángulo y lo apuntamos a un objeto del tipo cuadrado, al llamar a la función area(), ésta sólo se llamaría en la definida en la clase rectángulo, mientras que si definimos la funcion área como virtual, se llamaría a la función área de la clase cuadrado.
Un ejemplo práctico (sin virtual) :
rectangulo* r = new cuadrado(3.0);
cout<<r->area()	//Llama a rectangulo::area()
Ejemplo práctico (con virtual) :
rectangulo* r = new cuadrado(3.0);
cout<<r->area()	//Llama a cuadrado::area()

En nuestro caso, si eliminamos virtual de la función area() no ocurría nada, ya que tanto rectagulo como cuadrado tienen el mismo área, aunque en otros casos, podría dar a lugar a un comportamiento no deseado.
*/

#include <iostream>

using namespace std;

class B{
    public:

        void f(){cout << "f() de B"<< endl;}
        virtual void g() { cout << "g() de B" << endl;}
        virtual void h() = 0;
        virtual ~B(){};
    protected:
        int b;
};

class D1: virtual public B{
    public:
        void f(){cout << "f() de D1"<< endl;}
        virtual void g(){cout << "g() de D1" << endl;}
        void h(){cout << "h() de D1"<<endl;}// Se debe de redifinir el virtual puro
    protected:
        int d1;
};

class D2: virtual public B{
  public:
    void f(int i){cout << "f(" << i <<") de D2" << endl;}
    virtual void h(){ cout << "h() de D2 "<< endl;}

   protected:
   int d2;
};

class D3: public D1{
    public:
        void g(){cout << "g() de D3" << endl;}
        void h(){ cout << "h() de D3" << endl;}
    private:
        int d3;
};

class D4: public D1,public D2{
    public:
        void h(){cout << "h() de D4" << endl;}
    private:
        int d4;
};

void f(B& b){
    cout <<"f() externa" << endl;
    b.f();
    b.g();
    b.h();
}

int main(){
//    B b; No se puede instanciar un objeto de la clase abstracta
    B *pB;
    D1 d1;
    D2 d2;
    D3 d3;
    D4 d4;
    f(d1);
    f(d2);
    f(d3);
    f(d4);
    d4.D1::f();
    d4.f(5); //MAL, sol: d4.D2::f(5); Para evitar ambiguedad
   	d4.f(3.7); //MAL, sol: d4.D2::f(3.7); //Para evitar ambigüedad
    d4.g();
    d4.h();
    pB=new D4;
    pB->f();
    pB->D4::f(3); //MAL, D2 no es una base de B,  sol::dynamic_cast<D4*>(pB)->D2::f(3);
    pB->g();
    pB->h();
    delete pB;
}






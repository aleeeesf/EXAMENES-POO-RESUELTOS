#include <iostream>

using namespace std;

template<class T1, class T2> class par{
public:
    par(): prime(T1()), segun(T2()){}
    par(const T1& x, const T2& y): prime(x), segun(y){}
    T1 primero() const {return prime;}
    T1& primero(){return prime;}
    T2 segundo() const {return segun;}
    T2& segundo(){return segun;}
private:
    T1 prime;
    T2 segun;
};

template <class T1, class T2>
ostream& operator <<(ostream& os, const par<T1,T2>& p){
    os<<p.primero()<<endl;
    os<<p.segundo()<<endl;
    return os;
}

class racional{
public:
    racional(){rac.primero() = int(); rac.segundo() = unsigned();}
    racional(int x, unsigned y){rac.primero() = x; rac.segundo() = y;}
    int primero() const {return rac.primero();}
    int& primero(){return rac.primero();}
    unsigned segundo() const {return rac.segundo();}
    unsigned& segundo(){return rac.segundo();}
private:
    par<int, unsigned> rac;
};

racional operator +(const racional& r1, const racional& r2){
    //Cuerpo de la suma... Y lo devuelves.
    return racional(r1.primero(), r2.segundo());
}

ostream& operator <<(ostream& os, const racional& r){
    os<<r.primero()<<endl;
    os<<r.segundo()<<endl;
    return os;
}

class complejo{
public:
    complejo(){com.primero() = double(); com.segundo() = double();}
    complejo(double x, double y){com.primero() = x; com.segundo() = y;}
    double primero() const {return com.primero();}
    double& primero(){return com.primero();}
    double segundo() const {return com.segundo();}
    double& segundo(){return com.segundo();}

    complejo& operator +=(const complejo& c1){
        //Se suma al complejo com el complejo c1 y eso...
        return *this;
    }
private:
    par<double, double> com;
};

ostream& operator <<(ostream& os, const complejo& c){
    os<<c.primero()<<endl;
    os<<c.segundo()<<endl;
    return os;
}

int main(){

    cout<<"PAR"<<endl;
    par<int, int> p1;
    cout<<p1<<endl;
    par<int, int> p2(5,5);
    cout<<p2<<endl;

    cout<<"RACIONALES"<<endl;
    racional r1;
    cout<<r1<<endl;
    racional r2(6,6);
    cout<<r2<<endl;
    cout<<(r1+r2)<<endl;

    cout<<"COMPLEJOS"<<endl;
    complejo c1;
    cout<<c1<<endl;
    complejo c2(7,7);
    cout<<c2<<endl;
    cout<<(c1+=c2)<<endl;

    return 0;
}

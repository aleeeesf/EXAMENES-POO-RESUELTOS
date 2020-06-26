/*

Examen Resuelto 2º Parcial POO 2017 - Javier Jareño Dorado 2019/2020

Usad el examen subido por el compañero GIInfo "2º Parical POO 2017.pdf"

En el tendréis el enunciado de lexamen, aquí tendréis la resoluci�n

*/

#include <iostream>
#include <map>
#include <set>

using namespace std;

// EJERCICIO 1

class C;
class A;
class B;

class D
{
// No hace falta constructor para D
private:
    C* c;
};

class C
{
private: 
    set<A*> as;
    set<D*> ds;
    B bs;
};

class B
{
private:
    set<D*> ds;
    // Apartado 1.c) map<D*,X> ds;
};

class A
{
private:
    map<int,C*> cs;
};


// EJERCICIO 2

class rel4
{
    void asocia(C&, D&);
    void asocia(D& d, C& c){asocia(c,d);}

    C asociados(D& ) const;
    set<D*> asociados(C& ) const;

private:

    map<D*,C*> D_C;
    map<C*,set<D*>> C_D;

};

void rel4::asocia(C& c, D& d)
{
    map<D*,C*>::iterator i = D_C.find(&d);
    if(i != D_C.end())
    {
        C_D[D_C[&d]].erase(&d);
        if(C_D[D_C[&d]].empty())
        {
            C_D.erase(D_C[&d]);
        }
    }
    
    D_C[&d] = &c;
    C_D[&c].insert(&d);
}

C rel4::asociados(D& d) const
{
    map<D*,C*>::const_iterator i = D_C.find(&d);
    if(i != D_C.end())
    {
        return *(i->second);
    }
    else
    {
        return C();
    }
}

set<D*> rel4::asociados(C& c) const
{
    map<C*,set<D*>>::const_iterator i = C_D.find(&c);
    if(i != C_D.end())
    {
        return i->second;
    }
    else
    {
        return set<D*>();
    }
}


// EJERCICIO 3

/*
Considero que la opci�n más acertada sería tomar la clase list como base y heredarla
de forma privada, aplicando la técnica de delegaci�n de operaciones, luego no es una especializaci�n
tal cual de lista, si no que es una composici�n de esta. Esto es porque la lista ordenada no debe poder actuar
como una lista normal, si no que tiene un comportamiento más restrictivo que esta.

Es por esto que debemos delegar las operaciones que nosotros indiquemosx


*/

#include <list>
#include <algorithm>

// Lista ordenada de menor a mayor elementos


/*

IMPORTANTE: He realizado algunos cambios en los métodos de la clase puesto que habían algunos que en el 
enunciado no tenían sentido alguno, como un "iterator begin() const;" ya que no puedes devolver un iterator
cuando tienes puesto el calificador const indicando que no se va a modificar el objeto de la clase en cuesti�n.
*/
class ListaOrdenada: private list<double>
{
public:
    typedef list<double>::const_iterator const_iterator;
    ListaOrdenada();
    void insertar(double e);
    const_iterator buscar(double e) const;
    const_iterator begin() const;
    const_iterator end() const;

    size_t contar(double e) const;
};

inline ListaOrdenada::ListaOrdenada(){}

void ListaOrdenada::insertar(double e)
{
    const_iterator i = list<double>::begin();

    while(i != end() && e > *i ) i++;

    insert(i,e);
}


ListaOrdenada::const_iterator ListaOrdenada::buscar(double e) const
{
    const_iterator i = cbegin();

    while(i != cend() && e != *i ) i++;

    return i;
}


inline ListaOrdenada::const_iterator ListaOrdenada::begin() const
{
    return list<double>::cbegin();
}


inline ListaOrdenada::const_iterator ListaOrdenada::end() const
{
    return list<double>::cend();
}

size_t ListaOrdenada::contar(double e) const
{
    return count_if(begin(),end(), [e](double val){return val == e;});
}

// PROGRAMA EJEMPLO

/*
int main()
{
    ListaOrdenada l;

    l.insertar(3.2);
    l.insertar(-213.2);
    l.insertar(1.1);
    l.insertar(12);
    l.insertar(41);
    l.insertar(1.2);
    l.insertar(5.4);
    l.insertar(4);
    l.insertar(41);

    ListaOrdenada::const_iterator i = l.begin();

    while(i != l.end())
    {
        cout << *i << " ";
        i++;
    }

    cout << endl;

    cout << "Hay " << l.contar(41) << " numeros 41" << endl;


}

*/

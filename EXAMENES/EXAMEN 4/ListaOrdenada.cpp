#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

class ListaOrdenada{
	
	public:
		typedef list<double>::const_iterator const_iterator;
		ListaOrdenada();
		void insertar (double e);
		const_iterator buscar(double e) const;
		size_t contar(double e) const;
	public:
		list<double> l;
};

ListaOrdenada::ListaOrdenada(){}

void ListaOrdenada::insertar (double e){
	
	list<double>::iterator i = l.begin();
	
	while(i != l.end() && e<*i) i++;
	l.insert(i,e);
}

ListaOrdenada::const_iterator ListaOrdenada::buscar(double e) const{
	
	list<double>::const_iterator i = l.begin();
	
	while(i != l.end() && e != *i) i++;
	
	return i;
}


size_t ListaOrdenada::contar(double e) const{

	auto f = [e](double x){return x == e;};
	size_t n = count_if(begin(l),end(l),f);
	return n;
}



int main(){
	
	ListaOrdenada l;
	l.insertar(2.3);
	l.insertar(3.4);
	l.insertar(3.4);
	ListaOrdenada::const_iterator c = l.buscar(3.4);
	cout<<*c<<endl;
	cout<<l.contar(3.4);
	return 0;
}

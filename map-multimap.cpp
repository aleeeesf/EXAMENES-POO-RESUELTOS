#include <iostream>
#include <map>

using namespace std; 

int main(){
	                            
/*		 __  __      _      ____  
		|  \/  |    / \    |  _ \ 
		| |\/| |   / _ \   | |_) |
		| |  | |  / ___ \  |  __/ 
		|_|  |_| /_/   \_\ |_|    
                            
*/
	                     
	/*	INSERTAR EN UN MAP DENTRO DE OTRO MAP	*/
	map<int,map<string,string>> m;


	//Si recorremos con iterator usamos ( -> )
	for(map<int,map<string,string>>::iterator i = m.begin(); i != m.end(); ++i) {
		
		for(map<string,string>::iterator j = (i->second).begin(); j != (i->second).end(); ++j) {
		
			cout<<i->first<<" | "<<j->first<<","<<j->second<<endl;
		}
	}
	
	//Si recorremos con auto, usamos ( . )	
	for(auto i: m){
		
		cout<<i.first<<" ";
		for(auto j : i.second)	cout<<j.first<<endl;
		
	}
	
	/*	SABER SI SE HA INSERTADO O NO	*/
	//insert devuelve un par. El segundo devuelve true o false
	//dependiendo si se ha insertado o no
	auto i = m[3].insert(make_pair("adios","jaja"));
	if(!i.second) cout<<endl<<"No se ha insertado";


	/*	INSERTAR EN UN MAP	*/
	
	m[3].insert(make_pair("hola","adios"));	//Esta no sobreescribe si ya existe la pareja hola | adios
	
	m[3]["hola"] = "adios";	//Esta sobreescribe la pareja hola | adios
	
	
	/*	BUSCAR EN UN MAP	*/
	map<int,map<string,string>>::iterator k = m.find(3);
	//Esto devuelve un par, el primero con true o false, dependiendo
	//de si lo ha encontrado o no
	//Y la segunda pareja devuel el VALOR
   
	
/*

/*	
  __  __   _   _   _       _____   ___   __  __      _      ____  
 |  \/  | | | | | | |     |_   _| |_ _| |  \/  |    / \    |  _ \ 
 | |\/| | | | | | | |       | |    | |  | |\/| |   / _ \   | |_) |
 | |  | | | |_| | | |___    | |    | |  | |  | |  / ___ \  |  __/ 
 |_|  |_|  \___/  |_____|   |_|   |___| |_|  |_| /_/   \_\ |_| 
    
*/	

	/*	INSERTAR EN UN MULTIMAP	*/
	multimap<int,map<string,string>> m2;
	
	//Creamos un map auxiliar
	map<string,string> aux;
	aux.insert(make_pair("hola","adios"));
	
	//Finalmente insertamos en el map principal
	m2.insert(make_pair(3,aux));
	//Multimap no tiene sobrecargado el operador [] como map
	
	//Para recorrer, igual que el map, ( -> ) con iterators y ( . ) con auto
	for(auto i: m2){
		
		cout<<i.first<<" ";
		for(auto j : i.second)	cout<<j.first<<" "<<j.second<<endl;		
	}
	
	
	/*	ELIMINAR en el segundo elemento del map, es decir el map dentro del multimap	*/
	for(auto i: m2){
		
		auto j = i.second;
		j.erase("hola");
	}
	
	//Imprimimos para ver si se ha borrado
	for(auto i: m2){
		
		cout<<i.first<<" ";
		for(auto j : i.second)	cout<<j.first<<" "<<j.second<<endl;		
	}
	
	return 0;
}

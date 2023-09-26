#include <iostream>
#include <List>
#include <string>
#include <iterator>
#include <Windows.h>
#include "Header.h";

class List {
public:
	std::list<int> list = { (1), (2), (3), (4) };

};



	int main() {

		//Сделать выбор в меню 1 2 3 4!!!

		std::cout << "Enter size list! ";
		int World = 0;
		std::list<std::string> listok = {};
		
		sizeList(World, listok);
		
		//for (std::string g : listok) {
			//std::cout << g << "\n";
		//}
		search(World, listok);
		
	}




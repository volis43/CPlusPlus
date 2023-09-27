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

void menu() {
	int choose = 0;
	std::cout << "1) Ener size list!!!" << std::endl;
	std::cout << "2) insert - add" << std::endl;
}

int main() {
	//List mylis;
	//mylis.list;
	//Сделать выбор в меню 1 2 3 4!!!

	std::cout << "Enter size list! ";
	std::list<std::string> listok = {};
	int World = 0;

	sizeList(World, listok);
	
	

	
	search(World, listok);
	


	search(World, listok);

	//timeToDell(World, listok);

	//changeIndex(mylis.listok);
}
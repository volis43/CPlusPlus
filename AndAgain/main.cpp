#include <iostream>
#include <list>


class List {
public:

	std::list<int> list{ 1, 2, 3, 4 };
		
};

class Visual {
public:
	std::string mem = "( 1 ) ( 2 ) ( 3 ) ( 4 )";
	
};

class Ram {
public:
	std::string ram = "  \n \n \t  ( ) ";
	int rami = 1;
};

int main() {
	List mylis;
	Visual myMem;
	Ram myRam;

	std::cout << myMem.mem;
	std::cout << myRam.ram;

	
	int choose = 0;
	std::cin >> choose;

	switch (choose) {

	case 2: 
		std::cout << "change element";
		break;
		
	case 1:
		int y = 0;
		std::cout << "chose element list to delete!!!" << std::endl;
		std::cin >> y;

		auto p = std::find(mylis.list.begin(), mylis.list.end(), y);

		if (p != mylis.list.end()) {
			mylis.list.erase(p);
			std::cout << y << std::endl;

			for (auto it = mylis.list.begin(); it != mylis.list.end(); ++it) {
				std::cout << *it << " ";
			}
			std::cout << std::endl;
		}
		else {
			std::cout << y << " was not found in the list!!!" << std::endl;
		}
		break;
	}
		return 0;
}
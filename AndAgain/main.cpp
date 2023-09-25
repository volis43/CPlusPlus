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

int main() {
	List mylis;
	Visual myMem;

	std::cout << myMem.mem;

	//std::list<int> list{ 1, 2, 3, 4 };
	int choose = 0;
	std::cin >> choose;

	switch (choose) {

	case 2: 
		std::cout << "change element";
		
		
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

	}
		return 0;
}
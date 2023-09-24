#include <iostream>
#include <list>

class Massiv {
public:

	std::string arsi = "It's array --> \n"
		"[----] \n"
		"[----] \n"
		"[----] \n"
		"[----] \n";
};

class List {
public:

	std::string listi = "\n It's list --> \n"
		"(4) \n"
		"(|3) \n"
		"(|2) \n"
		"(|1) \n";

};

class Memory {
public:

	std::string rami = "\n It's memory --> \n"
		"( )";
};


class Answer {
public:
	std::string answer = "(4) = (|1) \n"
		"(|3) = (4) \n"
		"(|2) = () \n"
		"(|1) = (|3) \n"
		"( )";;
};



int main()
{
	Massiv myMassiv;

		std::cout << myMassiv.arsi;
	
	List myList;

		std::cout << myList.listi;

	Memory myRam;

		std::cout << myRam.rami;

		std::string y = "Yes";

		std::cout << "\n Go answer!!! Yes/No" << std::endl;
		std::cin >> y;
	
	
		if (y == "Yes" || y == "yes")
		{
			Answer MyAnswer;

			std::cout << MyAnswer.answer;
		}

		else if (y == "No" || y == "no") {
			
			std::cout << "Return main" << std::endl;
			
			return main();
		}
	
}
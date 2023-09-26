

void sizeList (int World, std::list<std::string> listok) {

	for (int i = 0; i < World; i++) { 
		std::string words;
		std::cout << "Put wrds" << std::endl;
		std::cin >> words;
		listok.push_back(words);

	}

}

//После поиска void удаляет повторяющий элемент! Но 1 остаёться!

void search(int World, std::list<std::string> listok) {
	std::cin >> World;

	for (int i = 0; i < World; i++) {  
		std::string words;
		std::cout << "Put wrds" << std::endl;
		std::cin >> words;
		listok.push_back(words);

	}

	//for (std::string g : listok) {
		//std::cout << "(" << g << ")";
//
	//}

	for (auto it1 = listok.begin(); it1 != listok.end(); ++it1) {
		for (auto it2 = std::next(it1); it2 != listok.end(); ++it2) {

			if (*it1 == *it2) {
				std::cout << " I found repeated words!!! Should I delete them? " << std::endl;
				
				std::string yes;
				std::cin >> yes;
				
				if (yes == "y" || yes == "Y") {
					std::cout << "clc ";
					it2 = listok.erase(it2);
					--it2;
					for (std::string g : listok) {
						std::cout << "(" << g << ")";
					}
				}
				
				
			}
					
		}
	}
}

//void timeToDell(int World, std::list<std::string> listok) {
	//std::cin >> World;

	//for (int i = 0; i < World; i++) {
	//	std::string words;
		//std::cout << "Put wrds" << std::endl;
	//	std::cin >> words;
		//listok.push_back(words);

	//}
//}
void changeIndex(std::list<std::string>& listok) {
	int index, index1;
	std::cout << "Enter the indexes of the words to swap: ";
	std::cin >> index >> index1;
	if (index < 0 || index >= listok.size() || index1 < 0 || index1 >= listok.size() || index == index1) {
		std::cout << "Invalid indexes!\n";
		return;
	}
	auto it1 = std::next(listok.begin(), index);
	auto it2 = std::next(listok.begin(), index1);
	std::swap(*it1, *it2);
	std::cout << "List after swapping:\n";
	for (std::string g : listok) {
		std::cout << g << "\n";
	}
}


//Если делать удаления то +визуал и надо int ( )!!!!!!
//Если делать удаления то +визуал и надо int ( )!!!!!!
//Если делать удаления то +визуал и надо int ( )!!!!!!
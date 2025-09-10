#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <algorithm>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

HANDLE hConsole;

int main()
{
	setlocale(LC_ALL, "rus");
	/*PlaySound(TEXT("p1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);*/

	

	//std::string arrEnglishWords[] = { "able", "above", "across", "act", "actually", "admit", "afraid", "afternoon", "agains", "agree", "ahead", "allow", "almost", "along", "although", "amaze", "annoy" };
	///*{"Fork", "plates", "Nature", "diligence", "jabber", "jaw", "tooth", "fist", "justify", "shelves", "Apparent"};*/
	///*"Fry", "hire", "imaginary", "indeed", "lay", "Leaf", "lip", "mainly", "mess", "Mood", "mud", "nail", "net", "pail", "Pot", "fork"*/ // можно сделать ссылку на массив строк?
	//std::string arrRusWords[] = { "способный", "выше", "через", "действовать", "на самом деле", "признавать", "испуганный", "полдень", "против", "соглашаться", "предстоящий", "позволять", "почти", "вдоль", "хотя", "удивлять", "раздражать" };
	
	// 
	//{"Вилка", "тарелки", "Природа", "старание", "болтать", "челюсть", "зуб", "Кулак", "оправдывать", "полки", "Очевидный"}; /*"Жарить", "Нанимать", "воображение", "действительно", "класть", "Лист", "Губа", "в основном", "беспорядок", "Настроение", "Грязь", "Ноготь", "Сеть", "Бледный", "горшок", "Вилка"*/
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	std::string arrPTR[] = { "able", "above", "across", "act", "actually", "admit", "afraid", "afternoon", "agains", "agree", "ahead", "allow", "almost", "along", "although", "amaze", "annoy" };
	std::string(&arrEnglishWords)[std::size(arrPTR)] = arrPTR;
	std::string arrPTRpack2[]{ "Fork", "plates", "Nature", "diligence", "jabber", "jaw", "tooth", "fist", "justify", "shelves", "Apparent" };

	std::string are[]{ "wing", "cork", "comb", "spatula", "entail", "deem" };
	std::string ares[]{ "крыло", "пробка", "расческа", "шпатель", "влечь за собой", "считать" };

	std::string arrPer[]{ "способный", "выше", "через", "действовать", "на самом деле", "признавать", "испуганный", "полдень", "против", "соглашаться", "предстоящий", "позволять", "почти", "вдоль", "хотя", "удивлять", "раздражать" };
	std::string(&arrRusWords)[std::size(arrPer)] = arrPer;
	int sizeWords = sizeof(arrEnglishWords) / sizeof(arrEnglishWords[0]);

	std::srand(static_cast<unsigned int>(std::time(0)));
	int souls = 0;
	while (true)
	{
		std::string x;
		int RandomWord = std::rand() % sizeWords;
		std::string RussianWord = arrRusWords[RandomWord];
		std::string CorrectAnswer = arrEnglishWords[RandomWord];

		std::cout << RussianWord;
		std::cout << std::endl;

		std::cin >> x;
		std::transform(x.begin(), x.end(), x.begin(), ::tolower);
		std::string corE = CorrectAnswer;
		std::transform(corE.begin(), corE.end(), corE.begin(), ::tolower);

		if (x == corE)
		{
			SetConsoleTextAttribute(hConsole, 2);
			souls++;
			std::cout << "You right " << x << " " << souls << std::endl;
			SetConsoleTextAttribute(hConsole, 15);
		}

		else
		{
			SetConsoleTextAttribute(hConsole, 4);
			souls--;
			std::cout << "\nYou don't right \n" + CorrectAnswer << " " << souls << std::endl;
			SetConsoleTextAttribute(hConsole, 15);

		}
	}
}
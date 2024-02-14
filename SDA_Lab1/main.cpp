//
//  main.cpp
//  sda.lab.1
//
//  Created by Rima Mihova on 03.02.2024.
//

//осталось сделать по работе:
/*
 3.    Запись элементов массива в файл.
 4.    Считывание элементов массива из файла.
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include "Header.h"

using namespace std;

int main() {
    int n, operationNumber, k = 1, isOver, index;
    char* searchName;// Dynamic memory allocation
    char ch;
    int len = 0;
    const char* filename = "films.txt"; // Имя файла
    
    cout << "Введите количество фильмов: ";
    while (true) {
        cin >> n;
        if (cin.fail()) {
            cout << "Ошибка: Количество фильмов должно быть числом. Пожалуйста, введите количество снова: ";
            cin.clear(); // Сбрасываем флаг ошибки ввода
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода до новой строки
        } else {
            break; // Если считывание прошло успешно, выходим из цикла
        }
    }
    cin.ignore(); // Очистка буфера после ввода числа

    // Выделение памяти для массива структур film
    Film* films = new Film[n];
    PFilm* p = new PFilm[n];

    // Ввод массива структур о фильмах
    for (int i = 0; i < n; i++) {
        inputFilm(films, i, p);
    }
    // Вывод массива на экран
    printFilm(p, n);

    while (k) {
        cout << "Выберите необходимую операцию и введите ее номер:\n"
            << "1. Сортировка списка фильмов по названию\n"
            << "2. Сортировка списка фильмов по году\n"
            << "3. Удаление необходимого фильма из списка\n"
            << "4. Добавление нового фильма\n"
            << "5. Поиск по названию фильма\n"
            << "6. Поиск по году фильма\n"
            << "7. Отредактировать данные выбранного фильма\n"
            << "8. Запись списка фильмов в файл\n"
            << "9. Вывод списка фильмов\n"
            << "Впишите число: ";
        cin >> operationNumber;
        cin.ignore();
        switch (operationNumber) {
        case 1:
            // Сортировка массива структур film по полю name
            filmSort(p, n);
            printFilm(p, n);
            break;
        case 2:
            //сортировка по году
            filmYearSort(p, n);
            printFilm(p, n);
            break;
        case 3:
            // Удаление элемента
            cout << "Укажите номер элемнта, который требуется удалить: ";
            cin >> index;
            cin.ignore();
            deleteFilm(films, n, index - 1);
            printFilm(p, n);
            break;
        case 4:
            // Вставка нового элемента
            insertFilm(films, n, p);
            printFilm(p, n);
            break;
        case 5:
                //Поиск по названию фильма
            cout << "Введите название фильма для поиска: ";
            while (cin.get(ch) && ch != '\n') { // Read until newline
            char* temp = new char[len + 1];
                if (searchName) {
                    strcpy(temp, searchName);
                }
                searchName = temp;
                searchName[len++] = ch;
                searchName[len] = '\0';
            }
            if (len > 0) { // Perform search only if input is not empty
                searchFilmByName(p, n, searchName);
            } else {
                cout << "Пустой ввод. Повторите попытку.\n";
            }
        delete[] searchName;
            break;
        case 6:
            //Поиск по году фильма
            cout<<"Введите год фильма для поиска: ";
            cin>>index;
            searchFilmByYear(p, n, index);
            break;
        case 7:
            cout << "Введите номер фильма, который необходимо отредактировать: ";
            cin >> index;
            cin.ignore();
            redactFilm(films, n, index);
            printFilm(p, n);
            break;
        case 8:
          
//            writeFilmsToFile(filename, p, n);
//            cout << "Данные записаны в файл \"" << filename << "\"" << endl;
//            break;
        case 9:
                //вывод списка фильмов
            printFilm(p, n);
            break;
        default:
            cout << "несуществующий номер операции\n";
        }

        cout << "Звершить программу?\n";
        cout << "1.Нет, осуществить еще одну оперцию\n"
            << "2(или любое другое число кроме 1). Да, завершить\n"
            << "Впишите число: ";
        cin >> isOver;
        if (isOver != 1) {
            k--;
            cout << "Программа завершена.\n";
        }
    }
   
    // Освобождение памяти
    freeFilm(films,n);
    delete[] films;
    delete[] p;
    return 0;
}

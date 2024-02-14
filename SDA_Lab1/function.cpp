//
//  func.cpp
//  sda.lab.1
//
//  Created by Rima Mihova on 03.02.2024.
//

#include<fstream>
#include <stdio.h>
#include <iostream>
#include "Header.h"

using namespace std;

//Функция позволяющая ввести с клавиатуры элементв структуры с помощью динамического выделения памяти
void inputFilm(Film* f,int i, Film* a[]) {
    cout << "Введите название фильма: ";
    string name;
    getline(cin, name);
    f[i].name = new char[name.length() + 1];
    strcpy(f[i].name, name.c_str());
    cout << "Введите год выпуска: ";
    while (true) {
        cin >> f[i].year;
        if (cin.fail()) {
            cout << "Ошибка: Год должен быть числом. Пожалуйста, введите год снова: ";
            cin.clear(); // Сбрасываем флаг ошибки ввода
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода до новой строки
        } else {
            break; // Если считывание прошло успешно, выходим из цикла
        }
    }
    a[i] = &f[i];
    cin.ignore(); // Очистка буфера после ввода числа
}

void insertFilm(Film* &films, int &n, PFilm *a) {
    inputFilm(films,n,a);
    n++;
}


//Функция, выводящая элементы структуры(имя  и в скобках год выпуска)
void printFilm(Film *a[], int n) {
    if(n>0){
        cout<<"Cписок фильмов:\n";
        for(int i = 0;i<n;i++){
            cout << i+1<<"."<<a[i]->name << " (" << a[i]->year << ")\n";
        }
    }else cout<<"Список пуст.\n";
    
}

// Функция для освобождения памяти, выделенной для структуры film
void freeFilm(Film* f,int &n) {
    for (int i = 0; i < n; i++) {
        delete[] f->name;
    }
}

// Функция для сравнения названий фильмов при сортировке
int compareFilms(char *a, char *b) {
    while(*a && *a==*b){
        *a++;*b++;
    }
    if(*a<*b)
        return -1;
    else if(*a>*b)
        return 1;
    else return 0;
    
}

void filmSort(Film *a[], int n) {
    int i, j;
    if(n>0){
        for (i = 0; i < n-1; i++) {
            for (j = 0; j < n-i-1; j++) {
                if (compareFilms(a[j]->name, a[j+1]->name) > 0) {
                    // Обмен указателями
                    Film *temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
    }
   
}
void filmYearSort(Film *a[], int n) {
    int i, j;
    if(n>0){
        for (i = 0; i < n-1; i++) {
            for (j = 0; j < n-i-1; j++) {
                if (a[j]->year > a[j+1]->year) {
                    // Обмен указателями
                    Film *temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
    }
   
}
void searchFilmByName(Film *a[], int n, char* name) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (compareFilms(a[i]->name, name) == 0) {
            cout << "Фильмы \"" << name << "\" найдены:\n";
            cout << i + 1 << a[i]->year<<"\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Фильм с названием \"" << name << "\" не найден.\n";
    }
}
void searchFilmByYear(Film *a[], int n, int year) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (a[i]->year  == year) {
            cout << "Фильмы \"" << year << "\" года найдены:\n";
            cout << i + 1 <<a[i]->name << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Фильм с названием \"" << year << "\" не найден.\n";
    }
}
void deleteFilm(Film* &films, int &n, int index) {
    if(n>0){
        if (index < 0 || index >= n) {
            cout << "Invalid index\n";
            return;
        }
        int k = 1;
        freeFilm(films,k);
        for (int i = index; i < n - 1; i++) {
            films[i] = films[i + 1];
        }
        n--;
    }
}
void redactFilm(Film* films, int n, int index) {
    if(n>0){
        if (index < 0 || index >= n) {
            cout << "Invalid index\n";
            return;
        }
        cout << "Введите новое название фильма: ";
        string name;
        getline(cin, name);
        delete[] films[index].name;
        films[index].name = new char[name.length() + 1];
        strcpy(films[index].name, name.c_str());
        cout << "Введите новый год выпуска: ";
        cin >> films[index].year;
        cin.ignore(); // Очистка буфера после ввода числа
    }
   
}
//void writeFilmsToFile(const char* filename, Film *a[], int n) {
//    ofstream outFile(filename); // Открытие файла для записи
//    if (!outFile.is_open()) {
//        cout << "Ошибка открытия файла для записи." << endl;
//        return;
//    }
//
//    // Запись данных в файл
//    for (int i = 0; i < n; ++i) {
//        outFile << a[i]->name << "," << a[i]->year << endl;
//    }
//
//    outFile.close(); // Закрытие файла
//}

//void readFilmsFromFile(const char* filename, Film** a, int& n) {
//    ifstream inFile(filename); // Открытие файла для чтения
//    if (!inFile.is_open()) {
//        cout << "Ошибка открытия файла для чтения." << endl;
//        return;
//    }
//
//    // Считывание данных из файла
//    n = 0; // Сброс счетчика фильмов
//    char buffer[256]; // Буфер для считывания строки из файла
//    while (inFile.getline(buffer, 256)) {
//        char* token = strtok(buffer, ","); // Разделение строки по запятой
//        a[n] = new Film;
//        a[n]->name = new char[strlen(token) + 1];
//        strcpy(a[n]->name, token);
//        token = strtok(NULL, ",");
//        a[n]->year = atoi(token);
//        n++; // Увеличение счетчика фильмов
//    }
//
//    inFile.close(); // Закрытие файла
//}


//
//  func.cpp
//  sda.lab.1
//
//  Created by Rima Mihova on 03.02.2024.
//

#include <stdio.h>
#include <iostream>
#include "Header.h"

using namespace std;

//Функция позволяющая ввести с клавиатуры элементв структуры с помощью динамического выделения памяти
void inputFilm(Film* f) {
    cout << "Введите название фильма: ";
    string name;
    getline(cin, name);
    f->name = new char[name.length() + 1];
    strcpy(f->name, name.c_str());
    cout << "Введите год выпуска: ";
    cin >> f->year;
    cin.ignore(); // Очистка буфера после ввода числа
}
//Функция, выводящая элементы структуры(имя  и в скобках год выпуска)
void printFilm(const Film& f,int i) {
    cout << i+1<<"."<<f.name << " (" << f.year << ")\n";
}
// Функция для освобождения памяти, выделенной для структуры film
void freeFilm(Film* f) {
    delete[] f->name;
}

// Функция для сравнения названий фильмов при сортировке
int compareFilms(char *a, char *b) {
    while(*a && *a==*b){
        *a++;*b++;
    }
    if(*a<*b)
        return 1;
    else if(*a>*b)
        return -1;
    else return 0;
    
}


void filmSort(Film a[],int n){
    int i ,j,nMin;
    char *c;
    
    for(i=0;i<n;i++){
        nMin=i;
        for(j=i;j<n;j++){
            //if(strcmp(a[j].name, a[nMin].name))
            if(compareFilms(a[j].name, a[nMin].name))
                nMin = j;
        }
        c=a[i].name;a[i].name=a[nMin].name; a[nMin].name=c;
    }
    
}
// Функция для удаления указанного элемента из массива
void deleteFilm(Film* &films, int &n, int index) {
    //Проверка на наличие данного номера
    if (index < 0 || index > n) {
        cout << "Недествительный номер\n";
        return;
    }
    //Копирование существующих фильмов в новый массив, меньший исходного на 1 элемент, без элемента под введенным индексом
    Film* newFilms = new Film[n - 1];
    for (int i = 0, j = 0; i < n; i++) {
        if (i != index-1) {
            newFilms[j] = films[i];
            j++;
        }
    }
    delete[] films; // освобождение памяти исходного массива
    films = newFilms;// присваивание нового массива
    n--;//уменьшение объема массива на 1 элемент
}
//Функция добавления элемента после необходимого
void addFilmAfter(Film* &films, int &n, int index) {
    //Проверка на наличие данного номера
    if (index-1 < 0 || index-1 >n) {
        cout << "Недествительный номер\n";
        return;
    }
    //Копирование существующих фильмов в новый массив, ,больший исходного на 1 элемент, с добавлением под введенным индексом
    Film* newFilms = new Film[n + 1];
    // Копирование существующих фильмов в новый массив
    int i = 0;int j = 0;
    while(i < n) {
        if(index-1 == i){
            inputFilm(&newFilms[i]);j++;
        }
        newFilms[j++] = films[i++];
    }
    
    delete[] films; // освобождение памяти исходного массива
    films = newFilms;// присваивание нового массива
    n++;//уменьшение объема массива на 1 элемент
}
//Функция для вставки фильма
void insertFilm(Film* &films, int &n) {
    Film* newFilms = new Film[n + 1];
    
    // Копирование существующих фильмов в новый массив
    for (int i = 0; i < n; i++) {
        newFilms[i] = films[i];
    }

    // Добавление нового элемента
    inputFilm(&newFilms[n]);

    delete[] films; // освобождение памяти исходного массива
    films = newFilms; // присваивание нового массива
    n++;//увеличение объема массива на 1 элемент
}

//Функция для редактации фильма
void redactFilm(Film* &films, int &n,int i){
    addFilmAfter(films, n,i);
    deleteFilm(films, n, i+1);
}
// Функция для записи массива структур в файл
void writeToFile(Film* &films, int n) {
    FILE* file = fopen("File", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return;
    }
    fwrite(films, sizeof(struct Film), n, file);
    fclose(file);
}


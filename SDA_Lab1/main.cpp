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
    int n,numOfDel, operationNumber,k=1,isOver,numOfAdd,numOfRed;
    cout << "Введите количество фильмов: ";
    cin >> n;
    cin.ignore(); // Очистка буфера после ввода числа

    // Выделение памяти для массива структур film
    Film* films = new Film[n];

    // Ввод массива структур о фильмах
    for (int i = 0; i < n; i++) {
        inputFilm(&films[i]);
    }
    // Вывод массива на экран
    cout << "Список фильмов:\n";
    for (int i = 0; i < n; i++) {
        printFilm(films[i],i);
    }
    
    while(k){
        cout<<"Выберите необходимую операцию и введите ее номер:\n"<<"1.Сортировка списка фильмов по названию\n"<<"2.Удаление необходимого фильма из списка\n"<<"3.Добавление нового фильма в конец списка\n"<<"4.Добавление фильма после необходимого элемента\n"<<"5.Отредактировать данные выбранного фильма\n"<<"6.Вывод списка фильмов\n"<<"Впишите число: ";
        cin>>operationNumber;
        cin.ignore();
        switch (operationNumber) {
            case 1:
                // Сортировка массива структур film по полю name
                filmSort(films, n);
                // Вывод нового массива на экран
                cout << "Новый список фильмов:\n";
                for (int i = 0; i < n; i++) {
                    printFilm(films[i],i);
                }
                break;
            case 2:
                // Удаление элемента
                cout<<"Укажите номер элемнта, который требуется удалить: ";
                cin>>numOfDel;
                cin.ignore();
                deleteFilm(films, n, numOfDel);
                cout << "Новый список фильмов:\n";
                    for (int i = 0; i < n; i++) {
                        printFilm(films[i],i);
                    }
                break;
            case 3:
                // Вставка нового элемента
                insertFilm(films, n);
                cout << "Новый список фильмов:\n";
                    for (int i = 0; i < n; i++) {
                        printFilm(films[i],i);
                    }
                break;
            case 4:
                cout<<"Введите под каким номером вставить фильм: ";
                cin>>numOfAdd;
                cin.ignore();
                addFilmAfter(films,n,numOfAdd);
                cout << "Новый список фильмов:\n";
                    for (int i = 0; i < n; i++) {
                        printFilm(films[i],i);
                    }
                break;
            case 5:
                cout<<"Введите номер фильма, который необходимо отредактировать: ";
                cin>>numOfRed;
                cin.ignore();
                redactFilm(films, n, numOfRed);
                cout << "Новый список фильмов:\n";
                    for (int i = 0; i < n; i++) {
                        printFilm(films[i],i);
                    }
                break;
            case 6:
                // Вывод массива на экран
                cout << "Список фильмов:\n";
                for (int i = 0; i < n; i++) {
                    printFilm(films[i],i);
                }
                break;
            default:
                cout<<"несуществующий номер операции\n";
        }
        
        cout<<"Звершить программу?\n";
        cout<<"1.Нет, осуществить еще одну оперцию\n"<<"2(или любое другое число кроме 1). Да, завершить\n"<<"Впишите число: ";
        cin>>isOver;
        if(isOver!=1){
            k--;
            cout<<"Программа завершена.\n";
        }
           
        
    }
    //пример записи в файл
    writeToFile(films,n);
    for (int i = 0; i < n; i++) {
        freeFilm(&films[i]);
    }
    delete[] films;
    return 0;
}



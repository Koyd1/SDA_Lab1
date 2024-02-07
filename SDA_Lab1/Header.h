//
//  Header.h
//  sda.lab.1
//
//  Created by Rima Mihova on 03.02.2024.
//

#ifndef Header_h
#define Header_h

struct Film {
    char* name;
    int year;
};

#endif /* Header_h */


void inputFilm(Film* f) ;
void printFilm(const Film& f,int i);
void freeFilm(Film* f);
void deleteFilm(Film* &films, int &n, int index) ;
void insertFilm(Film* &films, int &n) ;
void addFilmAfter(Film* &films, int &n, int index);
void filmSort(Film a[],int n);
int compareFilms(char *a, char *b);
void redactFilm(Film* &films, int &n,int i);
void writeToFile(Film* &films, int n);

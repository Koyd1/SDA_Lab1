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
typedef Film* PFilm;

void inputFilm(Film* f, int i, Film *a[]);
void printFilm(Film *a[], int n);
void freeFilm(Film* f,int &n);
void insertFilm(Film* &films, int &n, Film *a[]);
void filmSort(Film *a[], int n);
void filmYearSort(Film *a[], int n);
int compareFilms(char *a, char *b);
void deleteFilm(Film* &films, int &n, int index);
void redactFilm(Film* films, int n, int index);
void searchFilmByName(Film *a[], int n, char* name);
void searchFilmByYear(Film *a[], int n, int year);
void writeFilmsToFile(const char* filename, Film *a[], int n);
//void readFilmsFromFile(const char* filename, Film** a, int& n);

#endif /* Header_h */

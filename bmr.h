#ifndef BMR_H_INCLUDED
#define BMR_H_INCLUDED

#define REDUKCJA(A,B) ((A)-(B))
#define MASA(A,B) ((A)+(B))

 // Wspolczyniki zapotrzebowania
#define M1 1.1
#define M2 1.2
#define M3 1.3
#define M4 1.4
#define M5 1.5
#define ERROR -2
 //stala zapotrzeboania
#define SZ 300
 // stale BMR
 #define SWZ 6.25 //stala wzrostu
 #define SWA 9.99 //Stala wagi
 #define SWI 4.92 //stala wieku
 #define SK 161 // Wspolczynnik kobiet
 #define SM 5 //wspolczynnik mezcyzn

double oblicz_bmr(char plec,int wzrost,int waga,int wiek);
double oblicz_zapotrzebowanie(char aktywnosc,double bmr);

void wczytaj_dane(char* plec, int* waga, int* wzrost, int* wiek);

#endif // BMR_H_INCLUDED

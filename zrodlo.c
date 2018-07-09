#include "bmr.h"
#include <stdio.h>

void wczytaj_dane(char* plec, int* waga, int* wzrost, int* wiek)
{
    fprintf(stdout,"Podaj swoja plec (K/M): ");
    fscanf (stdin,"%c", plec);

    fprintf(stdout,"Podaj swoja wage: ");
    fscanf (stdin,"%d", waga);

    fprintf(stdout,"Podaj swoj wzrost: ");
    fscanf (stdin,"%d", wzrost);

    fprintf(stdout,"Podaj swoj wiek: ");
    scanf ("%d", wiek);

    fprintf(stdout,"\n\n");
}

double oblicz_bmr(char plec,int wzrost,int waga,int wiek)
{
    double bmr;
    if (plec=='M')
    {
       return bmr=((SWA * waga) + (SWZ * wzrost) - (SWI * wiek) + SM);

    }
    else if (plec=='K')
    {
       return bmr=((SWA * waga) + (SWZ * wzrost) - (SWI * wiek) - SK);

    }
    else
    {
        return ERROR;
    }

}

double oblicz_zapotrzebowanie(char aktywnosc,double bmr)
{
    double zapotrzebowanie;
     switch(aktywnosc)
  {
    case '1':
        return zapotrzebowanie=M1*bmr;
        break;
    case '2':
        return zapotrzebowanie=M2*bmr;
        break;
    case '3':
        return zapotrzebowanie=M3*bmr;
        break;
    case '4':
        return zapotrzebowanie=M4*bmr;
        break;
    case '5':
        return zapotrzebowanie=M5*bmr;
        break;
    default: return ERROR;
  }
}


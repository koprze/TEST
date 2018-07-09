#include <stdio.h>
#include <stdlib.h>
#include "bmr.h"

int main()
{
    system("color 0A");

    int waga, wzrost, wiek;
    char plec, aktywnosc, cel;
    double zapotrzebowanie, bmr, masa, redukcja;

    while(1)
    {

        fprintf(stdout,"                          ||||||||||||||||||||||||||||||||\n"
                       "                          |||Zapotrzebowanie kaloryczne|||\n"
                       "                          ||||||||||||||||||||||||||||||||\n\n");


        wczytaj_dane(&plec, &waga, &wzrost, &wiek);

        fprintf(stdout,"                            ~~~~~~~~~~~~~~~~~~~~~~~~\n"
                       "                                       PPM\n"
                       "                            ~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

        bmr = oblicz_bmr(plec,wzrost,waga,wiek);

        if(bmr == ERROR)
        {
            fprintf(stdout,"Podano niewlasciwa plec\n");
            system("PAUSE");
            system("CLS");
            continue;

        }

        fprintf(stdout,"Potrzebujesz %.2fl kcal aby zachowac podstawowe funkcje organizmu\n\n"
                       "\n\n"
                       "                         Okresl swoja aktywnosc fizyczna\n\n\n\n"
                       "-siedzacy tryb zycia - 1\n\n"
                       "-praca siedzaca, bez dodatkowej aktywnosci sportowej - 2\n\n"
                       "-dodatkowa aktywnosc typu umiarkowany spacer, niezbyt ciezki trening  - 3\n\n"
                       "-umiarkowana aktywnosc oraz trening - tu jest wiekszosc ludzi - 4\n\n"
                       "-praca fizyczna i trening lub praca niefizyczna i 2 treningi dziennie  - 5\n\n", bmr);

        fprintf(stdout,"Twoja aktywnosc to: ");
        fscanf (stdin,"%s", &aktywnosc);


        zapotrzebowanie = oblicz_zapotrzebowanie(aktywnosc,bmr);

        if(zapotrzebowanie == ERROR)
        {
            fprintf(stdout,"\n\nNieprawidlowe dane\n\n");
            continue;
        }


        fprintf(stdout,"\n\nAby utrzymac wage potrzebujesz %.2fl kcal \n\n", zapotrzebowanie);




        fprintf(stdout,"Co jest Twoim celem ?\n  redukcja - A\n  masa - B\n\n");
        fscanf (stdin,"%s", &cel );
        fprintf(stdout,"\n\n");


        if(cel=='A' || cel=='a')
        {
            redukcja = REDUKCJA(zapotrzebowanie,SZ);
            fprintf(stdout,"Twoje zapotrzebowanie aby schudnac wynosi %.2fl kcal", redukcja);
        }
        else if(cel=='B'|| cel=='b')
        {
            masa = MASA(zapotrzebowanie,SZ);
            fprintf(stdout,"Twoje zapotrzebowanie aby zwiekszyc mase wynosi %.2fl kcal", masa);
        }

        else
        {
            fprintf(stdout,"Nie wybrales celu");
            system("PAUSE");
            system("CLS");
            continue;
        }
        break;
    }


    fprintf(stdout,"\n\n");
    system("pause");
    return 0;
}


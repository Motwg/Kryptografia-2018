#ifndef BLOK_H
#define BLOK_H

#include <iostream>

class blok
{
    private:
        char *bajt;             //8 bajtów


    public:
        blok(char*);            //tworzy blok z ciągu znaków
        blok(blok*);            //tworzy kopie bloku
        ~blok();

        bool Wartosc_bitu(unsigned int n);                //zwraca wartosc bitu na n-tej pozycji, n e <0,63>
        void Zmien_bit(unsigned int n);                     //zmienia bit na n-tej pozycji
        void Zamien_bity_miejscami(unsigned int n, unsigned int m); //zamienia bity na n-tej i m-tej pozycjach
        blok &operator>>(unsigned int n);    //przesuwa blok o n pozycji w prawo
        blok &operator<<(unsigned int n);    // --||--  tylko, że w lewo

        void Permutacja_poczatkowa();

        void Wyswietl();
        void Wyswietl_bin();
};

#endif // BLOK_H

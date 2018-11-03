#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream>
#include <blok.h>


blok generuj_klucz();       //tworzy blok generujący klucz
char* algorytmDES(char*);   //funkcja wykonująca algorytm DES, pobiera tekst jawny i zwraca szyfrogram
void pokazBit( unsigned int n ); // wypisuje graficzny wskażnik na n-ty bit bloku "   ^    " numeracja od 1,  n e <1,64>
void separator(); // wypisuje "---------------------" o długości rownej długości zapisu binarnego bloku

blok & f(blok R, blok Klucz, int ** sbox);  //Proszę o opis Pawełku dokładny, czy aby na 100% sbox powinien być macierzą?

#endif // FUNKCJE_H

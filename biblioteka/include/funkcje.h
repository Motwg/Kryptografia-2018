#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream>
#include <blok.h>


blok generuj_klucz();       //tworzy blok generujący klucz
char* algorytmDES(char*);   //funkcja wykonująca algorytm DES, pobiera tekst jawny i zwraca szyfrogram
void pokazBit( unsigned int n ); // wypisuje graficzny wskażnik na n-ty bit bloku "   ^    " numeracja od 1,  n e <1,64>
void separator(); // wypisuje "---------------------" o długości rownej długości zapisu binarnego bloku

#endif // FUNKCJE_H

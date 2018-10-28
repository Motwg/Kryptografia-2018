#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream>
#include <blok.h>


blok generuj_klucz();       //tworzy blok generujący klucz
void pokazBit( unsigned int n ); // wypisuje graficzny wskażnik na n-ty bit bloku "   ^    " numeracja od 1!!!
void separator(); // wypisuje "---------------------" o długości rownej długości zapisu binarnego bloku

#endif // FUNKCJE_H

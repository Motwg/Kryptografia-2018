#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream>
#include <klucz.hpp>
#include <bitset>


blok generuj_klucz();       //tworzy blok generujący klucz
char* algorytmDES(char*, Klucz, bool deszyfrowanie);   //funkcja wykonująca algorytm DES, pobiera tekst jawny + klucz i zwraca szyfrogram/tekst w zależności od wyboru boola
char* algorytmDES(blok , Klucz, bool deszyfrowanie);


void pokazBit( unsigned int n ); // wypisuje graficzny wskażnik na n-ty bit bloku "   ^    " numeracja od 1,  n e <1,64>
void separator(); // wypisuje "--------------------" o długości rownej długości zapisu binarnego bloku
int* Sbox(int i);       //Zwraca tablicę jednowymiarową zwracanych przez i-tego S-boxa bitów

blok f(blok P);

#endif // FUNKCJE_H

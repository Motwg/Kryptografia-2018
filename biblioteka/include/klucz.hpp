#ifndef KLUCZ_HPP
#define KLUCZ_HPP

#include <blok.h>
//#include <funkcje.h>

class klucz
{
public:
    blok klucz64;  // przechowuje 64 bitowy klucz główny z bitami parzystości
    blok kluczPC1; // przechowóje 56 bitowy klucz główny po permutacji PC1

    void PC1();    // Permutacja PC1 - urzywana w konstruktorach

public:
    //Oba konstruktory automatycznie generują kluczPC1 z klucza64
    klucz();                         // Sam generuje losowy klucz
    klucz( blok k64 );                    // Przyjmuje klucz64 jako argument

    inline blok k64() { return klucz64; }   // zwraca klucz główny
    inline blok kPC1() { return kluczPC1; } // zwraca klucz po permutacji pc1
    blok kluczRundy( int nr ); // Zwraca klucz rundy - zawiera przesunięcie i permutacja PC2
};



#endif

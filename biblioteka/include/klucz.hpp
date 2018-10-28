#ifndef KLUCZ_HPP
#define KLUCZ_HPP

#include "blok.h"
#include "funkcje.h"

class klucz
{
private:
    blok klucz64;  // przechowuje 64 bitowy klucz główny z bitami parzystości
    blok kluczPC1; // przechowóje 56 bitowy klucz główny po permutacji PC1
    void PC1();

public:
    klucz(); // Zawiera permutację PC1 i usunięcie bitów parzystości
    ~klucz();
    blok kluczRundy( int nr ); // Generuje klucz rundy - przesunięcie i permutacja PC2
};



#endif
#ifndef KLUCZ_HPP
#define KLUCZ_HPP

#include "blok.h"
#include "funkcje.h"

class klucz
{
private:
    blok *kluczPC1; // przechowóje klucz główny po permutacji PC1

public:
    klucz();
    ~klucz();
    blok kluczRundy( int nr ); // Generuje klucz rundy
};



#endif
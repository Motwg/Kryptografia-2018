#include "funkcje.h"

#include <iostream>
#include <blok.h>
#include <bitset>

using namespace std;

blok generuj_klucz()
{
    blok klucz;
    klucz.generuj_klucz();
    return klucz;
}

char* algorytmDES(char* tekst_jawny)
{
    blok L(&tekst_jawny[0]);
    blok P(&L);
    (L>>32)<<32;
    (P<<32);
    cout<<"L0: ";    L.Wyswietl_bin();
    cout<<"P0: ";    P.Wyswietl_bin();
    return "/0";
}

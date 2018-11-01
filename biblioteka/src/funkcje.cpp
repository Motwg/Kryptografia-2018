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

void pokazBit( unsigned int n )
{
    for( int i=0 ; i<n-1 ; i++ )
    {
        std::cout << ' ';
        if( i%8 == 0 && i != 0 ) std::cout << ' ';
    }
    std::cout << "^\n";
}

void separator() { std::cout << "-----------------------------------------------------------------------" << endl; }
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
    cout<<"DES: "<<endl;    L.Wyswietl_bin();
    L.Permutacja_poczatkowa();
    cout<<"Po Permutacji początkowej: "<<endl; L.Wyswietl_bin();

    separator();
    blok P(&L);
    (L>>32)<<32;                            //L zapisane na 32 bitach
    (P<<32);                                //P zapisane na 32 bitach

    cout<<"P0: ";    P.Wyswietl_bin();
    cout<<"L0: ";    L.Wyswietl_bin();

    //Tutaj brakuje dalszej części algorytmu, zapraszam do tworzenia

    P.Permutacja_rozszerzajaca();           //rozszerzenie P do 48

    //Tutaj brakuje dalszej części algorytmu, zapraszam do tworzenia

    separator();
    L.Permutacja_koncowa();
    cout<<"Po Permutacji końcowej: "<<endl; L.Wyswietl_bin();

    return "/0";
}

void pokazBit( unsigned int n )
{
    for( int i=0 ; i<n-1 ; i++ )
    {
        cout << ' ';
        if( i%8 == 0 && i != 0 ) cout << ' ';
    }
    cout << "^\n";
}

void separator() { cout << "-----------------------------------------------------------------------" << endl; }

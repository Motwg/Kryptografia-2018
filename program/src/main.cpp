#include <bitset>
#include <time.h>
#include <funkcje.h>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

ostream & operator<< ( ostream &out , vector<char> vec )
{
    for( char c : vec )
    {
        out << c;
    }
    return out;
}

int main(int liczArg, char *arg[])
{
    //unsigned int iklucz[8]={0b00010011, 0b00110100, 0b01010111, 0b01111001, 0b10011011, 0b10111100, 0b11011111, 0b11110001 };

    Klucz klucz;
    blok kluczRozmywajacy1, kluczRozmywajacy2;
    kluczRozmywajacy1.generuj_klucz(false);
    kluczRozmywajacy2.generuj_klucz(false);

    vector<char> tekstJawny;
    vector<char> szyfrogram;
    vector<blok> szyfrogramBin;
    vector<char> tekstOdszyfrowany;

    if( liczArg > 1 )
    {
        for( int i=0 ; arg[1][i]!='\0' ; i++ )
        {
            tekstJawny.push_back(arg[1][i] );
        }
    }
    else
    {
        char *tmp = "Ala ma koteła";
        for( int i=0 ; tmp[i]!='\0' ; i++ )
        {
            tekstJawny.push_back( tmp[i] );
        }
    }
    tekstJawny.push_back('\0');

    

    cout << "Tekst jawny: " << tekstJawny << endl;

    cout << "Klucz rozmywajacy nr1:  "; kluczRozmywajacy1.Wyswietl();
    cout << "Klucz algorytmu DES:    "; klucz.k64().Wyswietl();
    cout << "Klucz rozmywajacy nr2:  "; kluczRozmywajacy2.Wyswietl();
               
    cout<<"Działanie algorytmu DESX:"<<endl;

    for( int i=0 ; i < (tekstJawny.size()+7)/8 ; i++ )
    {
        char jawny[8];
       // jawny = &tekstJawny[i*8];

        for( int j=0 ; j < 8 ; j++ )
        {
            if( tekstJawny[ i*8 + j ] == 0 ) break;
            jawny[j] = tekstJawny[ i*8 + j ];
        }

        char jawnyPoXor[8];
        char szyfrPoXor[8];

        for( int i=0 ; i<8 ; i++ )
            jawnyPoXor[i] = jawny[i] ^ kluczRozmywajacy1.Zwroc_bajt(i);

        char *szyfr   = algorytmDES( jawnyPoXor , klucz , false);

        for( int i=0 ; i<8 ; i++ )
            szyfr[i] ^= kluczRozmywajacy2.Zwroc_bajt(i);

        for( int i=0 ; i<8 ; i++ )
            szyfrPoXor[i] = szyfr[i] ^ kluczRozmywajacy2.Zwroc_bajt(i);

        char *deszyfr = algorytmDES( szyfrPoXor , klucz , true);

        for( int i=0 ; i<8 ; i++ )
            deszyfr[i] ^= kluczRozmywajacy1.Zwroc_bajt(i);

        blok szyfrBin(szyfr);


        szyfrogramBin.push_back(szyfrBin);
        for( int j=0 ; j < 8 ; j++ )
        {
            szyfrogram.push_back( szyfr[j] );
            if( tekstJawny[ i*8 + j ] == 0 ) continue;
            tekstOdszyfrowany.push_back( deszyfr[j] );
        }
    }
    cout << "Szyfrogram:  " << szyfrogram << endl;
    for( int i=0 ; i < szyfrogramBin.size() ; i++ )
        szyfrogramBin[i].Wyswietl_bin();
    cout << "Sprawdzenie: " << tekstOdszyfrowany << endl;

    tekstJawny.clear();
    szyfrogram.clear();
    tekstOdszyfrowany.clear();

    return 0;
}

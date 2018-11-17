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
    srand(time(NULL));

    cout<<"Działanie algorytmu DES:"<<endl;
    //unsigned int iklucz[8]={0b00010011, 0b00110100, 0b01010111, 0b01111001, 0b10011011, 0b10111100, 0b11011111, 0b11110001 };

    Klucz klucz;

    vector<char> tekstJawny;
    vector<char> szyfrogram;
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

    int liczbaBlokow = tekstJawny.size()/8;
    if( tekstJawny.size()%8 != 0 ) liczbaBlokow++;

    for( int i=0 ; i < liczbaBlokow ; i++ )
    {
        char jawny[8];

        for( int j=0 ; j < 8 ; j++ )
        {
            if( tekstJawny[ i*8 + j ] == 0 ) break;
            jawny[j] = tekstJawny[ i*8 + j ];
        }

        //cout << "j: " << jawny << endl;
        char *szyfr  = algorytmDES( jawny , klucz , false);
        char *deszyfr= algorytmDES( szyfr , klucz , true);
        //cout << "s: " << szyfr << endl;
        //cout << "d: " << deszyfr << endl;
        //cout << "---------------------------------" << endl;

        for( int j=0 ; j < 8 ; j++ )
        {   
            if( tekstJawny[ i*8 + j ] == 0 ) break;
            szyfrogram.push_back( szyfr[j] );
            tekstOdszyfrowany.push_back( deszyfr[j] );
        }
    }

    cout << "Tekst jawny: " << tekstJawny << endl;
    cout << "Szyfrogram:  " << szyfrogram << endl;
    cout << "Sprawdzenie: " << tekstOdszyfrowany << endl;

    //vector<blok>szyfrbin;
    //char *tekst_jawny=new char[8];

    /*for( int i=0 ; i<tekst.length() ; i=i+8 )
    {
        tekst_jawny = &tekst[i];
        blok a( tekst_jawny );

        char *szyfrogram = algorytmDES( tekst_jawny , Klucz , false );
        char *sprawdzenie = algorytmDES( szyfrogram , Klucz , true );

        blok S( szyfrogram );
        szyfr += szyfrogram;
        szyfrbin.push_back(S);
        spr += sprawdzenie;
    }

    cout << "Tekst jawny: " << tekst << endl;
    //cout << "Szyfrogram:  " << szyfr << endl;

    for( int i=0 ; i < static_cast<int>( szyfrbin.size() ) ; i++ )
        szyfrbin[i].Wyswietl_bin();
    
    cout << "Sprawdzenie: " << spr << endl;


//Test przesuwania z zapętleniem
/*
cout<<"Start: "<<endl;
    blok A(&tekst_jawny[0]);
    A.Wyswietl_bin();
    A.Przesun_w_lewo(15,3);
    A.Wyswietl_bin();
    A.Przesun_w_lewo(15,3);
    A.Wyswietl_bin();
    A.Przesun_w_lewo(15,3);
    A.Wyswietl_bin();
    A.Przesun_w_lewo(15,3);
    A.Wyswietl_bin();
    A.Przesun_w_prawo(15,3);
    A.Wyswietl_bin();
*/

//Test działania na blokach
/*
    blok A(&tekst_jawny[0]);
    //blok B(&A);                 // przykład kopiowania bloku A do bloku B
    cout<<"Start: "<<endl;
    A.Wyswietl_bin();
    B.Wyswietl_bin();
    cout<<"B=A: "<<endl;
    B=A;
    A.Wyswietl_bin();
    B.Wyswietl_bin();
    cout<<"Przesuwam A: "<<endl;
    A>32;
    A.Wyswietl_bin();
    B.Wyswietl_bin();
    cout<<"Dodaje do B A: "<<endl;
    B+=(A);
    A.Wyswietl_bin();
    B.Wyswietl_bin();
    cout<<"Przesuwam A: "<<endl;
    A<16;
    A.Wyswietl_bin();
    B.Wyswietl_bin();
    cout<<"Tworzę C=A+B: "<<endl;
    blok C=A+B;
    A.Wyswietl_bin();
    B.Wyswietl_bin();
    C.Wyswietl_bin();
*/
    return 0;
}

#include <bitset>
#include <time.h>
#include <funkcje.h>
#include <klucz.hpp>
#include <iostream>

using namespace std;


int main()
{
    srand(time(NULL));

    cout<<"Działanie algorytmu DES:"<<endl;
    klucz Klucz;
    //char *tekst_jawny="\1\1\1\1\1\3\7\0a12857128";
    char *tekst_jawny="Ala ma K";
    char *szyfrogram=algorytmDES(tekst_jawny,Klucz,false);
    char *sprawdzenie=algorytmDES(szyfrogram,Klucz,true);

    cout << "Tekst jawny: " << tekst_jawny << endl
         << "Szyfrogram:  " << szyfrogram << endl
         << "Sprawdzenie: " << sprawdzenie << endl;

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

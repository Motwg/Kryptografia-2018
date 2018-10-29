#include <bitset>
#include <time.h>
#include <funkcje.h>


using namespace std;


int main()
{
    srand(time(NULL));

    char *tekst_jawny="\3\1\7\7\7\3\0a12857128";
    algorytmDES(tekst_jawny);

//Test przesuwania z zapętleniem
/*
cout<<"Start: "<<endl;
    blok A(&tekst_jawny[0]);
    A.Wyswietl_bin();
    A.Przesun_w_lewo(7,3);
    A.Wyswietl_bin();
    A.Przesun_w_lewo(7,3);
    A.Wyswietl_bin();
    A.Przesun_w_lewo(7,3);
    A.Wyswietl_bin();
    A.Przesun_w_lewo(7,3);
    A.Wyswietl_bin();
    A.Przesun_w_prawo(7,3);
    A.Wyswietl_bin();
*/

//Test działania na blokach
/*
    blok A(&tekst_jawny[0]);
    blok B(&A);                 // przykład kopiowania bloku A do bloku B
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

//  Test tworzenia klucza
/*
    cout<<"Tworzę klucz: "<<endl;
    blok klucz;
    klucz.generuj_klucz();
    klucz.Wyswietl_bin();
    cout<<"Sprawdzam drugi sposób tworzenia klucza: "<<endl;
    klucz=generuj_klucz();
    klucz.Wyswietl_bin();
*/
    return 0;
}

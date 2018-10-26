#include <bitset>
#include <time.h>
#include <funkcje.h>


using namespace std;


int main()
{
    srand(time(NULL));

    char *tekst_jawny="\3\1\0a12857128";
    blok L(&tekst_jawny[0]);
    blok P(&L);
    L.Wyswietl_bin();
    P.Wyswietl_bin();
    (L>>32)<<32;
    (P<<32);
    L.Wyswietl_bin();
    P.Wyswietl_bin();

    blok A(&tekst_jawny[0]);
    A.Wyswietl_bin();
    A.Permutacja_poczatkowa();
    A.Wyswietl_bin();
    A.Permutacja_koncowa();
    A.Wyswietl_bin();
    A.Przesun_w_lewo(8,32);
    A.Wyswietl_bin();


//blok B(&A);  // przykład kopiowania bloku A do bloku B

//Test działania na blokach
/*
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

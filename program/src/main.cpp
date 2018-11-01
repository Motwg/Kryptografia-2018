#include <bitset>
#include <time.h>
#include <funkcje.h>
#include <klucz.hpp>
#include <iostream> 

using namespace std;


int main()
{
    srand(time(NULL));
    cout << "          1111111 11122222 22222333 33333334 44444444 45555555 55566666" << endl
         << "12345678 90123456 78901234 56789012 34567890 12345678 90123456 78901234" << endl << endl;
    
    const char *tekst_jawny="\3\1\0a12857128";
   
    blok A;
    klucz k;
    k.kluczRundy(1);
    

   
    //klucz key;
    //key.k64().Wyswietl_bin();
    //key.kPC1().Wyswietl_bin();
    //for( int i=1 ; i<=16 ; i++ )
    //    key.kluczRundy(16).Wyswietl_bin();

   /* blok A, B;
    A.generuj_klucz();
    for( int i=0 ; i<64 ; i++ )
        B.Zmien_bit_na( i , A , 63-i );

    A.Wyswietl_bin();
    B.Wyswietl_bin();*/

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

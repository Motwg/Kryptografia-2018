#include <bitset>
#include <time.h>
#include <funkcje.h>


using namespace std;


int main()
{
    srand(time(NULL));

    char *tekst_jawny="\3\7\1\200\0a12857128";
    char *w =&tekst_jawny[0];
    blok blokA(w);
    //blok blokB(&blokA);  // przykład kopiowania blokuA do blokuB
    blok klucz=generuj_klucz();

    cout<<"Klucz: "<<endl;
    klucz.Wyswietl_bin();
    cout<<"Start: "<<endl;
    blokA.Wyswietl_bin();
    blokA.Permutacja_poczatkowa();
    blokA.Wyswietl_bin();
    blokA>9;
    blokA.Wyswietl_bin();
    blokA<2;
    blokA.Wyswietl_bin();

    return 0;
}

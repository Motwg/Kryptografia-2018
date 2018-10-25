#include <bitset>
#include <time.h>
#include <funkcje.h>


using namespace std;


int main()
{
    srand(time(NULL));

    char *tekst_jawny="\3\7\1\1\0a12857128";
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

    return 0;
}




 /*   long long a[tekst_jawny.size()/8]={0};
for(int j=0;j<=(tekst_jawny.size())/8;j++)
    {
        for(int i=0;i<8;i++)
        {
            a[j]=a[j]<<8;
            cout<<"j: "<<j<<endl;
            bitset<8> b=(tekst_jawny.c_str()[i+j*8]);
            cout<<"literka binarnie  "<<b<<endl;
            a[j]=a[j]+b.to_ullong();
            cout<<"blok  "<<a[j]<<endl<<"blok binarnie  "<<bitset<64>(a[j])<<endl;
            cout<<endl;
        }
    }
    for(int i=0;i<=tekst_jawny.size()/8;i++)
        cout<<bitset<64>(a[i])<<endl;   */

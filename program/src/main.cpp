#include <bitset>
#include <time.h>
#include <funkcje.h>


using namespace std;


int main()
{
    srand(time(NULL));

    char *tekst_jawny="\3\7\1\1\1\1\1\3\0a12857128";
    char *w =&tekst_jawny[0];
    blok bl(w);

    blok klucz=generuj_klucz();

    cout<<"Klucz: "<<endl;
    klucz.Wyswietl_bin();
    cout<<"Start: "<<endl;
    bl.Wyswietl_bin();
   // bl.Permutacja_poczatkowa();
   // bl.Wyswietl_bin();
   // bl<<6;
   // bl.Wyswietl_bin();
    bl<<2;
    bl.Wyswietl_bin();
    cout<<bitset<8>('a'<<2)<<endl;
    cout<<bitset<8>(('a'<<2)>>2)<<endl;
    delete w;
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

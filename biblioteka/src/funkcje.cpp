#include "funkcje.h"

#include <iostream>
#include <blok.h>
#include <bitset>

using namespace std;

blok generuj_klucz()
{
    char* slowo=new char [8];
    for(int i=0;i<8;i++)
        {
        *(slowo+i)=rand()%256;                     //generowanie bajtów klucza

        bitset<8>a=( *(slowo+i) );
        if(a.count()%2)                          //kontrola parzystości
            (*(slowo+i)) = (*(slowo+i)) xor 1;  //dobranie odpowiednio ostatniego bitu
        }
    blok klucz(slowo);
    return klucz;
}

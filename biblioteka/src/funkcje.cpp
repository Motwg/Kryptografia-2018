#include "funkcje.h"

#include <iostream>
#include <blok.h>
#include <bitset>

using namespace std;

blok generuj_klucz()
{
    blok klucz;
    klucz.generuj_klucz();
    return klucz;
}

char* algorytmDES(char* tekst_jawny)
{
    blok L(&tekst_jawny[0]);
    cout<<"DES: "<<endl;    L.Wyswietl_bin();
    L.Permutacja_poczatkowa();
    cout<<"Po Permutacji początkowej: "<<endl; L.Wyswietl_bin();

    separator();
    blok P(&L);
    (L>>32)<<32;                            //L zapisane na 32 bitach
    (P<<32);                                //P zapisane na 32 bitach

    cout<<"P0: ";    P.Wyswietl_bin();
    cout<<"L0: ";    L.Wyswietl_bin();

    //Tutaj brakuje dalszej części algorytmu, zapraszam do tworzenia

    P.Permutacja_rozszerzajaca();           //rozszerzenie P do 48

    //Tutaj brakuje dalszej części algorytmu, zapraszam do tworzenia

    separator();
    L.Permutacja_koncowa();
    cout<<"Po Permutacji końcowej: "<<endl; L.Wyswietl_bin();

    return "/0";
}

void pokazBit( unsigned int n )
{
    for( int i=0 ; i<n-1 ; i++ )
    {
        cout << ' ';
        if( i%8 == 0 && i != 0 ) cout << ' ';
    }
    cout << "^\n";
}

void separator() { cout << "-----------------------------------------------------------------------" << endl; }



blok & f(blok R, blok Klucz, int ** sbox)
{
	blok tmp;

    tmp.Permutacja_rozszerzajaca();

	tmp += Klucz;       //<== Jakie to ma zadanie?
	int i,
		j,
		x;

	for(int k = 0; k < 8; k++)
	{
		i = 2 * tmp.Wartosc_bitu(k * 6 + 4) + tmp.Wartosc_bitu(k * 6 + 5);
		j = 8 * tmp.Wartosc_bitu(k * 6) + 4 * tmp.Wartosc_bitu(k * 6 + 1) + 2 * tmp.Wartosc_bitu(k * 6 + 2) + tmp.Wartosc_bitu(k * 6 + 3);

		x = *(*(sbox + i) + j);

		R.Zmien_bajt(0, 0);
		R.Zmien_bajt(1, 0);

		for(int l = 0; l < 4; l++)
		{
			if(x%2)
			{
				R.Zmien_bit(k * 4 + l);
				x--;
			}
			x /= 2;
		}
	}

	return R;
}

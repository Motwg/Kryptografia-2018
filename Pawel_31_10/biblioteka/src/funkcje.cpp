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
    blok P(&tekst_jawny[0]);
    P.Permutacja_poczatkowa();
    
    blok L,
		 R;
	
	P.Podziel_na_pol(L, P);
	
	// K* = Stworzy_klucze();		// część Andrzeja w wyniku, której otrzymamy wskaźnik do początku 16-sto elementowej tablicy 48bitowych kluczy 
	
	for(int i = 0; i < 16; i++)
	{
		blok tmp(&L);
		L = R;
		
		// R = tmp + f(&R, K.kluczRundy(i), *(sbox + i));		// oczekuje na Andrzeja
	}
	
	
    return 0;
}

blok & f(blok R, blok Klucz, int ** sbox)
{
	blok tmp;
	
	for(int j = 0; j < 8; j++)
		for(int i = 0; i < 6; i++)
			tmp.Zmien_bit_na((j * 6 + i), R, (j * 4 + i));
	
	tmp += Klucz;
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

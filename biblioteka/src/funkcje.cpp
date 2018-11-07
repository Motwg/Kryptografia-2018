#include "funkcje.h"


using namespace std;

blok generuj_klucz()
{
    blok klucz;
    klucz.generuj_klucz();
    return klucz;
}

char* algorytmDES(char* tekst_jawny, klucz Klucz, bool deszyfrowanie)
{
    blok L(&tekst_jawny[0]);
    cout<<"DES: "<<endl;    L.Wyswietl_bin();

    L.Permutacja_poczatkowa();

    cout<<"Po Permutacji początkowej: "<<endl; L.Wyswietl_bin();

    separator();
    blok P(&L);
    blok Temp;

    blok K;
    (L>>32)<<32;                            //L zapisane na 32 bitach
    (P<<32);                                //P zapisane na 32 bitach

    cout<<"P0: ";    P.Wyswietl_bin();
    cout<<"L0: ";    L.Wyswietl_bin();


    short i;
    if(deszyfrowanie)
        i=15;
    else
        i=0;


    while(i>=0 && i<16)
    {
        separator();
        cout<<"Runda "<<i+1<<endl;

        K=Klucz.kluczRundy(i+1);                                                 // <-- sprawdzone
        P.Permutacja_rozszerzajaca();           //rozszerzenie P do 48              <-- sprawdzone
        P=P^K;                                  //sumowanie modulo 2 (XOR)          <-- sprawdzone
        P=f(P);                                 //S-boxy , P zmienione do 32 bitów  <-- sprawdzone
        P.Permutacja_Pblok();                   //permutacja wyjściowa z S-boxów    <-- sprawdzone

        cout<<"K"<<i+1<<": "; K.Wyswietl_bin();
        cout<<"P"<<i+1<<": "; P.Wyswietl_bin();
        cout<<"L"<<i+1<<": "; L.Wyswietl_bin();

        Temp=P;
        P=P^L;
        L=Temp;

        cout<<"Po zamianie i xorowaniu/sumowaniu: "<<endl;
        cout<<"P"<<i+1<<": "; P.Wyswietl_bin();
        cout<<"L"<<i+1<<": "; L.Wyswietl_bin();

        if(deszyfrowanie)
            i--;
        else
            i++;
    }

    separator();
    P.Wyswietl_bin();
    L.Wyswietl_bin();
    P>>32;
    L=L+P;
    L.Wyswietl_bin();

    separator();
    L.Permutacja_koncowa();
    cout<<"Po Permutacji końcowej: "<<endl; L.Wyswietl_bin();

    return L.Zwroc_bajty();
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



int* Sbox(int i)
{
    switch(i)
    {
        case 1:
        {
            static int tab[64]={    14,	4, 	13, 1, 	2, 	15,	11,	8, 	3, 	10,	6, 	12,	5, 	9, 	0, 	7,
                                    0,	15,	7, 	4,	14,	2,	13,	1,	10,	6,	12,	11,	9, 	5, 	3, 	8,
                                    4, 	1, 	14,	8, 	13,	6, 	2, 	11,	15,	12,	9, 	7, 	3, 	10,	5, 	0,
                                    15,	12,	8,	2,	4,	9, 	1, 	7, 	5, 	11,	3, 	14,	10,	0, 	6, 	13 };
             return tab;
        }
        case 2:
        {
            static int tab[64]={    15,	1 ,	8 ,	14,	6,	11,	3,	4,	9,	7,	2,	13,	12,	0,	5,	10,
                                    3 ,	13,	4 ,	7,	15,	2,	8,	14,	12,	0,	1,	10,	6,	9,	11,	5,
                                    0 ,	14,	7 ,	11,	10,	4,	13,	1,	5,	8,	12,	6,	9,	3,	2,	15,
                                    13, 8 ,	10,	1,	3,	15,	4,	2,	11,	6,	7,	12,	0,	5,	14,	9  };
             return tab;
        }
        case 3:
        {
            static int tab[64]={    10,	0,	9,	14,	6,	3,	15,	5,	1,	13,	12,	7,	11,	4,	2,	8,
                                    13,	7,	0,	9,	3,	4,	6,	10,	2,	8,	5,	14,	12,	11,	15,	1,
                                    13,	6,	4,	9,	8,	15,	3,	0,	11,	1,	2,	12,	5,	10,	14,	7,
                                    1,	10,	13,	0,	6,	9,	8,	7,	4,	15,	14,	3,	11,	5,	2,	12 };
             return tab;
        }
        case 4:
        {
            static int tab[64]={    7,	13,	14,	3,	0,	6,	9,	10,	1,	2,	8,	5,	11,	12,	4,	15,
                                    13,	8,	11,	5,	6,	15,	0,	3,	4,	7,	2,	12,	1,	10,	14,	9,
                                    10,	6,	9,	0,	12,	11,	7,	13,	15,	1,	3,	14,	5,	2,	8,	4,
                                    3,	15,	0,	6,	10,	1,	13,	8,	9,	4,	5,	11,	12,	7,	2,	14 };
             return tab;
        }
        case 5:
        {
            static int tab[64]={ 	2,	12,	4,	1,	7,	10,	11,	6,	8,	5,	3,	15,	13,	0,	14,	9,
                                    14,	11,	2,	12,	4,	7,	13,	1,	5,	0,	15,	10,	3,	9,	8,	6,
                                    4,	2,	1,	11,	10,	13,	7,	8,	15,	9,	12,	5,	6,	3,	0,	14,
                                    11,	8,	12,	7,	1,	14,	2,	13,	6,	15,	0,	9,	10,	4,	5,	3  };
             return tab;
        }
        case 6:
        {
            static int tab[64]={    12,	1,	10,	15,	9,	2,	6,	8,	0,	13,	3,	4,	14,	7,	5,	11,
                                    10,	15,	4,	2,	7,	12,	9,	5,	6,	1,	13,	14,	0,	11,	3,	8,
                                    9,	14,	15,	5,	2,	8,	12,	3,	7,	0,	4,	10,	1,	13,	11,	6,
                                    4,	3,	2,	12,	9,	5,	15,	10,	11,	14,	1,	7,	6,	0,	8,	13 };
             return tab;
        }
        case 7:
        {
            static int tab[64]={    4,	11,	2,	14,	15,	0,	8,	13,	3,	12,	9,	7,	5,	10,	6,	1,
                                    13,	0,	11,	7,	4,	9,	1,	10,	14,	3,	5,	12,	2,	15,	8,	6,
                                    1,	4,	11,	13,	12,	3,	7,	14,	10,	15,	6,	8,	0,	5,	9,	2,
                                    6,	11,	13,	8,	1,	4,	10,	7,	9,	5,	0,	15,	14,	2,	3,	12  };
             return tab;
        }
        case 8:
        {
            static int tab[64]={    13,	2,	8,	4,	6,	15,	11,	1,	10,	9,	3,	14,	5,	0,	12,	7,
                                    1,	15,	13,	8,	10,	3,	7,	4,	12,	5,	6,	11,	0,	14,	9,	2,
                                    7,	11,	4,	1,	9,	12,	14,	2,	0,	6,	10,	13,	15,	3,	5,	8,
                                    2,	1,	14,	7,	4,	10,	8,	13,	15,	12,	9,	0,	3,	5,	6,	11 };
             return tab;
        }
    }
}



blok f(blok P)
{
    blok A;
    int pozycja;
    int* sbox;
    for(short i=1; i<=8; i++)
    {
        sbox=Sbox(i);
            pozycja=0;
            if(P.Wartosc_bitu(0)) {pozycja+=32;}
            if(P.Wartosc_bitu(1)) {pozycja+=8;}
            if(P.Wartosc_bitu(2)) {pozycja+=4;}
            if(P.Wartosc_bitu(3)) {pozycja+=2;}
            if(P.Wartosc_bitu(4)) {pozycja+=1;}
            if(P.Wartosc_bitu(5)) {pozycja+=16;}
        //cout<<i<<": "<<*(sbox+pozycja)<<"  =  "<<bitset<4>(*(sbox+pozycja))<<"   pozycja: "<<pozycja<<endl; //do debugowania

        A.Zmien_bajt(0,*(sbox+pozycja));
        A.Przesun_w_lewo(8,4);
        A<4;
        P<<6;
    }
    return A<<32;
}


/*
blok & f(blok R, blok Klucz, int ** sbox)
{
	blok tmp;

    tmp.Permutacja_rozszerzajaca();

	tmp += Klucz;       //<== To nie jest sumowanie modulo 2
	int i,
		j,
		x;

	for(int k = 0; k < 8; k++)        //  <== gdzieś w tym jest błędzik
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
*/

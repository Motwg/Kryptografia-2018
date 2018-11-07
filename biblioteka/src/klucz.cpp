# include "klucz.hpp"


void separator();

klucz::klucz()
{
    klucz64.generuj_klucz();
    PC1();
}

klucz::klucz( blok k64 )
{
    klucz64 = k64;
    PC1();
}

void klucz::PC1()
{
/*
    int nr1 = 0;
    int nr2 = 28;
    int i1, i2 ,k1 ,k2;

    for( i1 = 57 , i2 = 63 ; i1 < 60 ; i1++ , i2-- )
    {
        for( k1 = i1 , k2 = i2 ; k1 > 0 ; k1-=8 , k2-=8 )
        {
            kluczPC1.Zmien_bit_na( nr1++ , klucz64, k1-1 );
            kluczPC1.Zmien_bit_na( nr2++ , klucz64, k2-1 );
        }
    }
    for ( i1 = 60 , i2 = 28 ; i2 > 0 ; i1-=8 , i2-=8  )
    {
        kluczPC1.Zmien_bit_na( nr1++ , klucz64, i1-1 );
        kluczPC1.Zmien_bit_na( nr2++ , klucz64, i2-1 );
    }
*/
    short nr[56]= { 57,	49,	41,	33,	25,	17,	9,
                    1,	58,	50,	42,	34,	26,	18,
                    10,	2,	59,	51,	43,	35,	27,
                    19,	11,	3,	60,	52,	44,	36,
                    63,	55,	47,	39,	31,	23,	15,
                    7,	62,	54,	46,	38,	30,	22,
                    14,	6,	61,	53,	45,	37,	29,
                    21,	13,	5,	28,	20,	12,	4 };
    for(short i=0;i<56;i++)
        kluczPC1.Zmien_bit_na(i,klucz64,nr[i]-1);
}


blok klucz::kluczRundy(int runda)
{
    blok tmp(kluczPC1);
    blok kluczPC2;

    for( int i = 1 ; i <= runda ; i++)
    {
        int pozycje;
        switch(i)
        {
            case 1:
            case 2:
            case 9:
            case 16:
            pozycje = 1;
            break;
            default:
            pozycje = 2;
        }
        tmp.Wyswietl_bin();
        separator();

        //pierwsza połowa
        tmp.Przesun_w_lewo( 28 , pozycje );
        tmp.Wyswietl_bin();
        tmp < 28;
        tmp.Wyswietl_bin();

        //druga połowa
        tmp.Przesun_w_lewo( 28 , pozycje );
        tmp.Wyswietl_bin();
        tmp > 28;
        tmp.Wyswietl_bin();
    }


    // Permutacja PC2
    short nr[48] = {14,17,11,24, 1, 5
                    , 3,28,15, 6,21,10
                    ,23,19,12, 4,26, 8
                    ,16, 7,27,20,13,22
                    ,41,52,31,37,47,55
                    ,30,40,51,45,33,48
                    ,44,49,39,56,34,53
                    ,46,42,50,36,29,32};

    for( int i=0 ; i<48 ; i++ )
    {
        kluczPC2.Zmien_bit_na( i , tmp , nr[i]-1 );
    }

    return kluczPC2;
}

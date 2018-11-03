# include "klucz.hpp"

klucz::klucz()
{
    kluczPC1 = new blok("\0");
    *kluczPC1 = generuj_klucz();


    // premutacja PC1:

    int nr1 = 0;
    int nr2 = 28;
    int i1, i2 ,k1 ,k2;

    for( i1 = 57 , i2 = 63 ; i1 < 60 ; i1++ , i2-- )
    {
        for( k1 = i1 , k2 = i2 ; k1 > 0 ; k1-=8 , k2-=8 )
        {
            kluczPC1->Zamien_bity_miejscami( nr1++ , i1-1 );            
            kluczPC1->Zamien_bity_miejscami( nr2++ , i2-1 );
        }
    }
    for ( i1 = 60 , i2 = 28 ; i2 > 0 ; i1-=8 , i2-=8  )
    {
       kluczPC1->Zamien_bity_miejscami( nr1++ , i1-1 );
       kluczPC1->Zamien_bity_miejscami( nr2++ , i2-1 );
    }
}

klucz::~klucz()
{
    delete kluczPC1;
}

blok klucz::kluczRundy(int runda)
{
    for( int i = 1 ; i <= runda ; i++)
    {
        switch(i)
        {
            case 1:
            case 2:
            case 9:
            case 16:
            ;//przesun o bit
            default:
            ;//przesun o 2 bity
        }
    }


}
#include "blok.h"
#include <iostream>
#include <bitset>

using namespace std;

blok::blok()
{
    bajt=new char[8];
    for(int i=0;i<8;i++)
        *(bajt+i)=0;
}


blok::blok(char *wsk)
{
    bajt=new char [8];
    for(int i=0;i<8;i++)
        *(bajt+i)=0;
    for(int i=0;i<8 && *(wsk+i)!=0;i++)
        *(bajt+i)=*(wsk+i);
}


blok::~blok()
{
    bajt=NULL;
}

void blok::generuj_klucz()
{
    char* slowo=new char [8];
    for(int i=0;i<8;i++)
        {
        *(slowo+i)=rand()%256;                     //generowanie bajtów klucza

        bitset<8>a=( *(slowo+i) );
        if(a.count()%2)                          //kontrola parzystości
            (*(slowo+i)) = (*(slowo+i)) xor 1;  //dobranie odpowiednio ostatniego bitu
        }
    blok A(slowo);
    *this=A;
}


char blok::Zwroc_bajt(unsigned n)
{
    return *(bajt+n);
}

void blok::Zmien_bajt(unsigned n, char znak)
{
    *(bajt+n)=znak;
}

bool blok::Wartosc_bitu(unsigned int pozycja)
{
    if( (*(bajt+pozycja/8)) & (1<<(7-pozycja%8)) )
        return true;
    return false;
}

void blok::Zmien_bit(unsigned int pozycja)
{
    (*(bajt+pozycja/8)) = (*(bajt+pozycja/8)) xor (1<<(7-pozycja%8));
}

void blok::Zmien_bit_na(unsigned int n1, blok B, unsigned int n2)
{
    if( Wartosc_bitu(n1) != B.Wartosc_bitu(n2) )
        Zmien_bit(n1);
}

void blok::Zamien_bity_miejscami(unsigned int a, unsigned int b)
{
    bool temp=Wartosc_bitu(a);
    if(temp!=Wartosc_bitu(b))
        {
            Zmien_bit(a);
            Zmien_bit(b);
        }
}

void blok::Przesun_w_lewo(unsigned int n, unsigned int m)
{
bool Temp;
blok Tblk(this);
    for(int i=0;i<m;i++)
        {
            Temp=Wartosc_bitu(0);
            *(this)<<1;
            if(  Wartosc_bitu(n-1) != Temp)
                Zmien_bit(n-1);
        }
    for(int i=0;i<64;i++)
        if(i>=n)
            Zmien_bit_na(i,Tblk,i);
}

void blok::Przesun_w_prawo(unsigned int n, unsigned int m)
{
bool Temp;
blok Tblk(this);
    for(int i=0;i<m;i++)
        {
            Temp=Wartosc_bitu(n-1);
            *(this)>>1;
            if(  Wartosc_bitu(0) != Temp)
                Zmien_bit(0);
        }
    for(int i=0;i<64;i++)
        if(i>=n)
            Zmien_bit_na(i,Tblk,i);
}


blok & blok::operator>>(unsigned int n)
{
    for(int j=0;j<n;j++)
       {
        for(int i=7;i>=0;i--)
        {
            (*(bajt+i))>>=1;
            if(i!=0 && Wartosc_bitu(i*8)!=Wartosc_bitu(i*8-1))
                Zmien_bit(i*8);
        }
        if(Wartosc_bitu(0))
            Zmien_bit(0);
       }
    return * this;
}

blok & blok::operator<<(unsigned int n)
{
    for(int j=0;j<n;j++)
        for(int i=0;i<8;i++)
        {
            (*(bajt+i))<<=1;
            if(i!=7 && Wartosc_bitu(i*8+8)!=Wartosc_bitu(i*8+7))
                Zmien_bit(i*8+7);
        }
    return * this;
}


blok & blok::operator>(unsigned int n)
{
    bool Temp;
    for(int i=0;i<n;i++)
    {
        Temp=Wartosc_bitu(63);
        *this>>1;
        if(this->Wartosc_bitu(0) != Temp)
            Zmien_bit(0);
    }
    return * this;
}


blok & blok::operator<(unsigned int n)
{
    bool Temp;
    for(int i=0;i<n;i++)
    {
        Temp=Wartosc_bitu(0);
        *this<<1;
        if(this->Wartosc_bitu(63) != Temp)
            Zmien_bit(63);
    }
    return * this;
}

blok & blok::operator+=(blok A)
{
    for(int i=0;i<8;i++)
        *(bajt+i)+=A.bajt[i];
    return * this;
}

blok blok::operator+(blok A)
{
    blok B;
    for(int i=0;i<8;i++)
    {
        B.bajt[i]+=A.bajt[i];
        B.bajt[i]+=bajt[i];
    }
    return B;
}


blok & blok::operator=(blok A)
{
    for(int i=0;i<8;i++)
        this->Zmien_bajt(i,'\0');
    *this+=A;
    return * this;
}


blok::blok(blok *A)
{

    this->bajt=new char [8];
    for(int i=0;i<8;i++)
        this->bajt[i]=0;
    for(int i=0;i<8 && A->bajt[i]!=0;i++)
        this->bajt[i]=A->bajt[i];
}


void blok::Permutacja_poczatkowa()
{
blok Temp(this);               //<== z jakiegoś powodu tu działa tylko w taki sposób
for(int k=0;k<2;k++)
    for(int j=0;j<4;j++)
        for(int i=0;i<8;i++)
            Zmien_bit_na(k*32+j*8+i,Temp,57-i*8+j*2-k);
}

void blok::Permutacja_koncowa()
{
blok *Temp=new blok;              //<== z jakiegoś powodu tu działa tylko w taki sposób
*Temp=*this;
for(int j=0;j<8;j++)
    for(int i=0;i<4;i++)
        {
        Zmien_bit_na(j*8+i*2,*Temp,39+8*i-j);
        Zmien_bit_na(j*8+i*2+1,*Temp,7+8*i-j);
        }
delete Temp;
}

void blok::Permutacja_rozszerzajaca()
{
blok *Temp=new blok;
*Temp=*this;
for(int i=0;i<8;i++)
    for(int j=0; j<6; j++)
        //cout<<i*6+j+1<<" => "<<((31+i*6+j-2*i)%32 +1)<<endl;
        Zmien_bit_na(i*6+j, *Temp, ((31+i*6+j-2*i)%32 ));
delete Temp;
}

void blok::Wyswietl()
{
    for(int i=0;i<8;i++)
        cout<<*(bajt+i);
    cout<<endl;
}

void blok::Wyswietl_bin()
{
    for(int i=0;i<8;i++)
        cout<<bitset<8>(*(bajt+i))<<' ';
    cout<<endl;
}

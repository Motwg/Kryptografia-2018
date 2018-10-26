#include "blok.h"
#include <iostream>
#include <bitset>

using namespace std;

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

void blok::Zamien_bity_miejscami(unsigned int a, unsigned int b)
{
    bool temp=Wartosc_bitu(a);
    if(temp!=Wartosc_bitu(b))
        {
            Zmien_bit(a);
            Zmien_bit(b);
        }
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
blok Temp(this);
for(int k=0;k<2;k++)
    for(int j=0;j<4;j++)
        for(int i=0;i<8;i++)
            if( Wartosc_bitu(k*32+j*8+i) != Temp.Wartosc_bitu(57-i*8+j*2-k) )
                this->Zmien_bit(k*32+j*8+i);
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

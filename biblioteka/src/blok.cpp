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


void blok::Permutacja_poczatkowa()
{
for(int k=0;k<2;k++)
    for(int j=0;j<4;j++)
        for(int i=0;i<8;i++)
            Zamien_bity_miejscami(i,57-i*8+j*2-k);
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

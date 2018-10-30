#ifndef BLOK_H
#define BLOK_H

class blok
{
    protected:
        char *bajt;             //8 bajtów

    public:
        blok();                 //tworzy blok wypełniony zerami
        blok(char*);            //tworzy blok z ciągu znaków
        blok(blok*);            //tworzy kopie bloku
        ~blok();

        void generuj_klucz();   //zmienia blok w pseudo-losowo wygenerowany klucz

        bool Wartosc_bitu(unsigned int n);                   //zwraca wartosc bitu na n-tej pozycji, n e <0,63>
        void Zmien_bit(unsigned int n);                      //zmienia bit na n-tej pozycji, n e <0,63>
        void Zmien_bit_na(unsigned int n1, blok B, unsigned int n2);    //zmienia bit n1 bloku A na bit n2 bloku B, n1,n2 e <0,63>
        void Zamien_bity_miejscami(unsigned int n, unsigned int m);     //zamienia bity na n-tej i m-tej pozycjach, prawdopodobnie nieużyteczne

        char Zwroc_bajt(unsigned n);                         //zwraca bajt na n-tej pozycji, n e <0,7>
        void Zmien_bajt(unsigned n, char znak);              //zmienia n-ty bajt na podany bajt (znak), n e <0,7>

        void Przesun_w_lewo(unsigned int n, unsigned int m);       //przesuwa pierwsze n pozycji w bloku w lewo/prawo
        void Przesun_w_prawo(unsigned int n, unsigned int m);      //o m pozycji z zapętleniem, n e <1,64>

        blok &operator>>(unsigned int n);   //przesuwa blok o n pozycji w prawo
        blok &operator<<(unsigned int n);   // --||--  tylko, że w lewo
        blok &operator>(unsigned int n);    //przesuwa blok o n pozycji w prawo z zapętleniem bitów
        blok &operator<(unsigned int n);    // --||--  tylko, że w lewo
        blok &operator+=(blok A);           //Sumuje bloki i nadpisuje blok pierwszy
        blok operator+(blok A);             //Sumuje bloki bez zapisu (używać w sposób blokA=(blokB+blokC))
        blok &operator=(blok A);

        void Permutacja_poczatkowa();
        void Permutacja_koncowa();
        void Permutacja_rozszerzajaca();

        void Wyswietl();
        void Wyswietl_bin();
};

#endif // BLOK_H

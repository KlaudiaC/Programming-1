//Klaudia C - 29.11.2015

#include<cmath>

int Suma(int dl, int tab[]){ // liczba skladnikow, tablica
    int suma = 0;
    for(int i = 0; i < dl; i++) suma += tab[i];
    return suma;
}

bool SredniaWazona(double tab[], int dl, double &wynik){ // tablica elementow, liczba elementow, wynik
    double srednia = 0;
    double suma = 0;
    for(int i = 0; i < dl - 1; i++){
        suma += tab[2*i + 1];
        if(tab[2*i + 1] < 0 || tab[2*i + 1] > 1 || suma > 1) return false;
    }
    suma = 1;
    for(int i = 0; i < dl - 1; i++) srednia += tab[2*i] * tab[2*i + 1];
    for(int i = 0; i < dl - 1; i++) suma -= tab[2*i + 1];
    suma *= tab[2*dl - 2];
    srednia += suma;
    wynik = srednia;
    return true;
}

short PierwiastkiKwadratowe(double a, double b, double c, double &pierw1, double &pierw2){
    int pierwiastki = 0; // liczba pierwiastkow
    double delta = b*b - 4*a*c;
    if(delta > 0){
        pierwiastki = 2;
        pierw1 = (-b - sqrt(delta)) / (2*a);
        double temp = (-b + sqrt(delta)) / (2*a);
        if(temp >= pierw1)pierw2 = temp;
        else{
            pierw2 = pierw1;
            pierw1 = temp;
        }
    }
    else if(delta == 0){
        pierw1 = -b / (2*a);
        pierwiastki = 1;
    }
    return pierwiastki;
}

void Fibonacci(int tab[], int dl){ // tablica, ostatni element do liczenia
    if(dl == 0) tab[0] = 0;
    else if(dl == 1){
        tab[0] = 0;
        tab[1] = 1;
    }
    else if(dl == 2){
        tab[0] = 0;
        tab[1] = 1;
        tab[2] = 1;
    }
    else{
        tab[0] = 0;
        tab[1] = 1;
        tab[2] = 1;
        for(int i = 3; i <= dl; i++) tab[i] = tab[i - 1] + tab[i - 2];
    }
}

int Licznik(bool logik, int &wywolania){ // wartosc logiczna, liczba wywolan true
    static int powtorzeniaTrue = 0;
    static int powtorzeniaFalse = 0;
    if(logik == true) powtorzeniaTrue++;
    else powtorzeniaFalse++;
    wywolania = powtorzeniaTrue;
    return powtorzeniaFalse; // liczba wywolan false
}

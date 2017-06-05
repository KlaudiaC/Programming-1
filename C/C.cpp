// Klaudia C - 23.11.2015

#include <iostream>
using namespace std;

int main(){
    int n; // dlugosc tablicy
    char operacja;
    int b, e; // poczatek i koniec zakresu (operacje s, r) lub poczatki fragmentow (operacja m)
    int k; // ilosc pozycji do przesuniecia (operacja s) lub dlugosc fragmentu (operacja m)
    int temp; // wartosc pomocnicza

    cin >> n;
    int data[n]; // tablica
    for(int i = 0; i < n; i++) cin >> data[i];
    while(true){
        cin >> operacja;
        if(operacja == 'r'){ // odwracanie
            cin >> b >> e;
            int idx = e; // indeks pomocniczy
            if(b <= e){
                for(int i = b; i <= (e + b)/2; i++){ // i - indeks idacy od poczatku do polowy
                    temp = data[i];
                    data[i] = data[idx];
                    data[idx] = temp;
                    idx--;
                }
            }
            else{
                int i = b;
                int wykonania = (n - b + e)/2; // ilosc zamian do zrobienia
                int pow = 0; // ilosc wykonanych powtorzen
                while(pow <= wykonania)
                {
                    temp = data[i];
                    data[i] = data[idx];
                    data[idx] = temp;
                    if(i == n - 1) i = 0; // i bylo ostatnim indeksem tablicy
                    else i++;
                    if(idx == 0) idx = n - 1; // idx bylo pierwszym indeksem
                    else idx--;
                    pow++;
                }
            }
        }
        else if(operacja == 's'){ //przesuwanie
            cin >> b >> e >> k;
            if(k >= 0){
                for(int pow = 0; pow < k; pow++){
                    if(b <= e){
                        temp = data[e];
                        for(int i = e; i > b; i--) data[i] = data[i - 1];
                        data[b] = temp;
                    }
                    else{
                        temp = data[e];
                        for(int i = e; i > 0; i--) data[i] = data[i - 1];
                        data[0] = data[n - 1];
                        for(int i = n - 1; i > b; i--) data[i] = data[i - 1];
                        data[b] = temp;
                    }
                }
            }
            else{
                for(int pow = 0; pow < -k; pow++){
                    if(b <= e){
                        temp = data[b];
                        for(int i = b; i < e; i++) data[i] = data[i + 1];
                        data[e] = temp;
                    }
                    else{
                        temp = data[0];
                        for(int i = 0; i < e; i++) data[i] = data[i + 1];
                        data[e] = data[b];
                        for(int i = b; i < n -1; i++) data[i] = data[i + 1];
                        data[n - 1] = temp;
                    }
                }
            }
        }
        else if(operacja == 'm'){ // zamienianie
            cin >> b >> e >> k;
            int pom = n; // wartosc pomocnicza
            for(int i = 0; i <= k; i++){
                if(b + i < n && e + i < n){
                    temp = data[b + i];
                    data[b + i] = data[e + i];
                    data[e + i] = temp;
                }
                else{
                    if(b <= e){
                        temp = data[n - pom];
                        data[n - pom] = data[b + i];
                        data[b + i] = temp;
                    }
                    else{
                        temp = data[n - pom];
                        data[n - pom] = data[e + i];
                        data[e + i] = temp;
                    }
                    pom--;
                }
            }
        }
        else if(operacja == 'e') break; //zakonczenie
    }
    for(int i = 0; i < n; i++) cout << data[i] << " ";

    return 0;
}

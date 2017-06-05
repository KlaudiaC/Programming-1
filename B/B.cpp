// Klaudia C - 02.11.2015

#include <iostream>
using namespace std;
int main(){
    int i = 0; // numer ciagu
    int pom = 0; // pomocniczy licznik do wewnetrznej petli
    int ilosc; // liczba ciagow
    int aktualny; // aktualny element ciagu
    int poprzedni; // poprzedni element ciagu
    bool rosnie = false;
    bool maleje = false;
    bool staly = false;

    cin >> ilosc;
    while(i != ilosc){
        while(true){
            pom++;
            cin >> aktualny;
            if(aktualny < 0) break;
            if(pom > 1){
                if(poprzedni == aktualny) staly = true;
                else if(poprzedni > aktualny) maleje = true;
                else if(poprzedni < aktualny) rosnie = true;
            }
            poprzedni = aktualny;
        }
        if(staly == true && rosnie == false && maleje == false) cout << "staly" << endl;
        else if(staly == false && rosnie == true && maleje == false) cout << "rosnacy" << endl;
        else if(staly == false && rosnie == false && maleje == true) cout << "malejacy" << endl;
        else if(staly == true && rosnie == true && maleje == false) cout << "niemalejacy" << endl;
        else if(staly == true && rosnie == false && maleje == true) cout << "nierosnacy" << endl;
        else if((staly == true && rosnie == true && maleje == true) || (staly == false && rosnie == true && maleje == true)) cout << "nieokreslony" << endl;

        rosnie = false;
        maleje = false;
        staly = false;
        pom = 0;
        i++;
    }
    return 0;
}

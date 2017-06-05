// Klaudia C - 29.10.2015

#include <iostream>
using namespace std;
int main(){
    int ilosc; // liczba rozgrywek
    int i = 0;
    char g1, g2; // a, b lub c
    char wybor1, wybor2; // J, K, N, P, S - jaszczurka, kamien, nozyce, papier lub Spock
    float wygraneA = 0;
    float wygraneB = 0;
    float wygraneC = 0;
    float przegraneA = 0;
    float przegraneB = 0;
    float przegraneC = 0;
    float remisyA = 0;
    float remisyB = 0;
    float remisyC = 0;
    int gryA = 0;
    int gryB = 0;
    int gryC = 0;
    char nazwaA = 'a';
    char nazwaB = 'b';
    char nazwaC = 'c';

    cin >> ilosc;
    while(i < ilosc){
        cin >> g1 >> wybor1 >> g2 >> wybor2;
		if(g1 == 'a'){
            gryA++;
            if((wybor1 == 'K' && (wybor2 == 'N' || wybor2 == 'J')) ||
               (wybor1 == 'P' && (wybor2 == 'K' || wybor2 == 'S')) ||
               (wybor1 == 'N' && (wybor2 == 'P' || wybor2 == 'J')) ||
               (wybor1 == 'J' && (wybor2 == 'P' || wybor2 == 'S')) ||
               (wybor1 == 'S' && (wybor2 == 'K' || wybor2 == 'N'))){
                wygraneA++;
                if(g2 == 'b'){
                    gryB++;
                    przegraneB++;
                }
                else if(g2 == 'c'){
                    gryC++;
                    przegraneC ++;
                }
            }
            else if((wybor1 == 'K' && (wybor2 == 'P' || wybor2 == 'S')) ||
                    (wybor1 == 'P' && (wybor2 == 'N' || wybor2 == 'J')) ||
                    (wybor1 == 'N' && (wybor2 == 'K' || wybor2 == 'S')) ||
                    (wybor1 == 'J' && (wybor2 == 'N' || wybor2 == 'K')) ||
                    (wybor1 == 'S' && (wybor2 == 'P' || wybor2 == 'J'))){
                przegraneA++;
                if(g2 == 'b'){
                    gryB++;
                    wygraneB++;
                }
                else if(g2 == 'c'){
                    gryC++;
                    wygraneC++;
                }
            }
            else if((wybor1 == 'K' && wybor2 == 'K') || (wybor1 == 'P' && wybor2 == 'P')
                    || (wybor1 == 'N' && wybor2 == 'N') || (wybor1 == 'J' && wybor2 == 'J')
                    || (wybor1 == 'S' && wybor2 == 'S')){
                remisyA++;
                if(g2 == 'b'){
                    gryB++;
                    remisyB++;
                }
                else if(g2 == 'c'){
                    gryC++;
                    remisyC++;
                }
            }
        }

		if(g1 == 'b'){
            gryB++;
            if((wybor1 == 'K' && (wybor2 == 'N' || wybor2 == 'J')) ||
               (wybor1 == 'P' && (wybor2 == 'K' || wybor2 == 'S')) ||
               (wybor1 == 'N' && (wybor2 == 'P' || wybor2 == 'J')) ||
               (wybor1 == 'J' && (wybor2 == 'P' || wybor2 == 'S')) ||
               (wybor1 == 'S' && (wybor2 == 'K' || wybor2 == 'N'))){
                wygraneB++;
                if(g2 == 'a'){
                    gryA++;
                    przegraneA++;
                }
                else if(g2 == 'c'){
                    gryC++;
                    przegraneC ++;
                }
            }
            else if((wybor1 == 'K' && (wybor2 == 'P' || wybor2 == 'S')) ||
                    (wybor1 == 'P' && (wybor2 == 'N' || wybor2 == 'J')) ||
                    (wybor1 == 'N' && (wybor2 == 'K' || wybor2 == 'S')) ||
                    (wybor1 == 'J' && (wybor2 == 'N' || wybor2 == 'K')) ||
                    (wybor1 == 'S' && (wybor2 == 'P' || wybor2 == 'J'))){
                przegraneB++;
                if(g2 == 'a'){
                    gryA++;
                    wygraneA++;
                }
                else if(g2 == 'c'){
                    gryC++;
                    wygraneC++;
                }
            }
            else if((wybor1 == 'K' && wybor2 == 'K') || (wybor1 == 'P' && wybor2 == 'P')
                    || (wybor1 == 'N' && wybor2 == 'N') || (wybor1 == 'J' && wybor2 == 'J')
                    || (wybor1 == 'S' && wybor2 == 'S')){
                remisyB++;
                if(g2 == 'a'){
                    gryA++;
                    remisyA++;
                }
                else if(g2 == 'c'){
                    gryC++;
                    remisyC++;
                }
            }
        }

		if(g1 == 'c'){
            gryC++;
            if((wybor1 == 'K' && (wybor2 == 'N' || wybor2 == 'J')) ||
               (wybor1 == 'P' && (wybor2 == 'K' || wybor2 == 'S')) ||
               (wybor1 == 'N' && (wybor2 == 'P' || wybor2 == 'J')) ||
               (wybor1 == 'J' && (wybor2 == 'P' || wybor2 == 'S')) ||
               (wybor1 == 'S' && (wybor2 == 'K' || wybor2 == 'N'))){
                wygraneC++;
                if(g2 == 'a'){
                    gryA++;
                    przegraneA++;
                }
                else if(g2 == 'b'){
                    gryB++;
                    przegraneB++;
                }
            }
            else if((wybor1 == 'K' && (wybor2 == 'P' || wybor2 == 'S')) ||
                    (wybor1 == 'P' && (wybor2 == 'N' || wybor2 == 'J')) ||
                    (wybor1 == 'N' && (wybor2 == 'K' || wybor2 == 'S')) ||
                    (wybor1 == 'J' && (wybor2 == 'N' || wybor2 == 'K')) ||
                    (wybor1 == 'S' && (wybor2 == 'P' || wybor2 == 'J'))){
                przegraneC++;
                if(g2 == 'a') {
                    gryA++;
                    wygraneA++;
                }
                else if(g2 == 'b'){
                    gryB++;
                    wygraneB++;
                }
            }
            else if((wybor1 == 'K' && wybor2 == 'K') || (wybor1 == 'P' && wybor2 == 'P')
                    || (wybor1 == 'N' && wybor2 == 'N') || (wybor1 == 'J' && wybor2 == 'J')
                    || (wybor1 == 'S' && wybor2 == 'S')){
                remisyC++;
                if(g2 == 'a'){
                    gryA++;
                    remisyA++;
                }
                else if(g2 == 'b'){
                    gryB++;
                    remisyB++;
                }
            }
        }
        i++;
    }

    if(gryA != 0){
        cout << "gracz " << nazwaA << endl;
        if(wygraneA != 0) cout << "    wygrane: " << (wygraneA * 100)/gryA << "%" << endl;
        if(remisyA != 0) cout << "    remisy: " << (remisyA * 100)/gryA << "%" << endl;
        if(przegraneA != 0) cout << "    przegrane: " << (przegraneA * 100)/gryA << "%" << endl;
        if(gryB != 0 || gryC != 0) cout << endl;
    }

    if(gryB != 0){
        cout << "gracz " << nazwaB << endl;
        if(wygraneB != 0) cout << "    wygrane: " << (wygraneB * 100)/gryB << "%" << endl;
        if(remisyB != 0) cout << "    remisy: " << (remisyB * 100)/gryB << "%" << endl;
        if(przegraneB != 0) cout << "    przegrane: " << (przegraneB * 100)/gryB << "%" << endl;
        if(gryC != 0) cout << endl;
    }

    if(gryC != 0){
        cout << "gracz " << nazwaC << endl;
        if(wygraneC != 0) cout << "    wygrane: " << (wygraneC * 100)/gryC << "%" << endl;
        if(remisyC != 0) cout << "    remisy: " << (remisyC * 100)/gryC << "%" << endl;
        if(przegraneC != 0) cout << "    przegrane: " << (przegraneC * 100)/gryC << "%" << endl;
    }

    return 0;
}

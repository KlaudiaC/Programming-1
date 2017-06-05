// Klaudia Cwioro - 06.12.2015

#include <string>
using namespace std;

string FormatujNapis(string napis, string arg1, string arg2, string arg3){
    int pom = 0; // indeks do chodzenia po poleceniu
    string temp; // napis pomocniczy do ukladania wyniku

    while(pom < napis.size()){
        if(napis[pom] != '{'){
            temp += napis[pom];
            pom++;
        }
        else{
            char polecenie = napis[pom + 1]; // czynnosc z klamry

            if(polecenie == 'p'){ // ABCD{p:n:z}X Y Z - wstawienie znaku z powtorzonego n razy w miejsce polecenia
                char litera = napis[pom + 5]; //powtarzany znak
                int powtorzenia = napis[pom + 3] - 48; // liczba powtorzen znaku z
                for(int i = 0; i < powtorzenia; i++) temp += litera;
                pom += 7;
            }

            else if(polecenie == 'u'){ // ABCD{u:n}X Y Z - usuniecie polecenia i n znakow stojacych za nim
                int usuniecia = napis[pom + 3] - 48; // liczba znakow do usuniecia
                pom += 5 + usuniecia;
            }

            else if(polecenie == 'U'){ // ABCD{U:n}X Y Z - usuniecie polecenia i n znakow stojacych przed nim
                int usuniecia = napis[pom + 3] - 48; // liczba znakow do usuniecia
                temp.resize(temp.size() - usuniecia);
                pom += 5;
            }

            else if(polecenie == 'w'){ // ABCD{w:n}X Y Z - zastapienie polecenia jednym z ciagow-argumentow (n = 1, 2, 3)
                string ciag; // dopisywany ciag
                if(napis[pom + 3] - 48 == 1) ciag = arg1;
                else if(napis[pom + 3] - 48 == 2) ciag = arg2;
                else if(napis[pom + 3] - 48 == 3) ciag = arg3;
                temp += ciag;
                pom += 5;
            }

            else if(polecenie == 'W'){ // ABCD{W:n:m}X Y Z - to co w "w", chyba ze dlugosc argn < m (wtedy nalezy pokryc roznice spacjami) lub argn > m (wtedy obcina ciag do m)
                string ciag; // wybrany ciag
                int dlugosc = napis[pom + 5] - 48; // dlugosc ciagu okreslona w trzecim argumencie
                if(napis[pom + 3] - 48 == 1) ciag = arg1;
                else if(napis[pom + 3] - 48 == 2) ciag = arg2;
                else if(napis[pom + 3] - 48 == 3) ciag = arg3;
                if(ciag.size() == napis[pom + 5] - 48){
                    temp += ciag;
                    pom += 7;
                }
                else if(ciag.size() < dlugosc){
                    temp += ciag;
                    for(int i = 0; i < dlugosc - ciag.size(); i++) temp += " ";
                    pom += 7;
                }
                else{
                    for(int i = 0; i < dlugosc; i++) temp += ciag[i];
                    pom += 7;
                }
            }
        }
    }
    return temp;
}

string UsunSlowo(string napis, int slowo){ // tekst i numer slowa, ktore trzeba z niego usunac
    int pom = 0; // indeks do poruszania sie po napisie
    string temp; // napis pomocniczy do ukladania wyniku
    int numer = 1; // numer aktulanie sprawdzanego slowa
    napis += " "; // spacja do prostszego usuwania ostatniego slowa

    if(slowo == 1){
        while(napis[pom] != ' ') pom++;
        for(int i = pom; i < napis.size(); i++) temp += napis[i];
    }
    else{
        while(numer != slowo){ // szukanie poczatku slowa do usuniecia
            if(napis[pom] == ' ') numer++;
            pom++;
        }
        for(int i = 0; i < pom; i++) temp += napis[i];
        while(napis[pom] != ' ') pom++; // szukanie konca slowa do usuniecia
        for(int i = pom; i < napis.size() - 1; i++) temp += napis[i];
    }
    return temp;
}

string NajwiekszeSlowo(string napis){ // napis, z ktorego trzeba wyciagnac najwieksze (leksykograficznie) slowo
    int pom = 0; // indeks do poruszania sie po napisie
    string temp; // napis pomocniczy do ukladania wyniku
    int najpocz; // indeks poczatku aktualnie najwiekszego slowa
    int najkon; // indeks konca aktualnie najwiekszego slowa

    if((97 <= napis[pom] && napis[pom] <= 122) || (65 <= napis[pom] && napis[pom] <= 90)) najpocz = pom;
    while(napis[pom] != ' ') pom++; // szukanie konca aktualnego slowa
    najkon = pom;
    while(pom < napis.size()){
        while(napis[pom] == ' ') pom++; // szukanie poczatku kolejnego slowa
        if(((97 <= napis[pom] && napis[pom] <= 122) || (65 <= napis[pom] && napis[pom] <= 90)) && napis[pom] > napis[najpocz]){
            najpocz = pom;
            while(napis[pom] != ' ') pom++;
            najkon = pom - 1;
        }
        else
            while(napis[pom] != ' ') pom++; // szukanie konca aktualnego slowa
    }
    for(int i = najpocz; i <= najkon; i++) temp += napis[i];
    temp;
    return temp;
}

string NormalizujNapis(string napis){ // napis, w ktorym nalezy usunac nadmiar spacji
    int pom = 0; // indeks do poruszania sie po napisie
    string temp; // napis pomocniczy do ukladania wyniku

    while(napis[pom] == ' ') pom++; // ominiecie spacji na poczatku tekstu
    for(pom; pom < napis.size() - 2; pom++){ // size() - 1 - ochrona przed wyjsciem poza napis
        if((97 <= napis[pom] && napis[pom] <= 122) || (65 <= napis[pom] && napis[pom] <= 90)){
            temp += napis[pom]; // pom na literze
            if(napis[pom + 1] == 20) temp += " ";
        }
        else if(napis[pom] == 44 || napis[pom] == 46){ // pom na przecinku lub kropce
            temp += napis[pom];
            temp += " "; // wstawienie spacji po znaku interpunkcyjnym
        }
        else if(napis[pom] == 20 && napis[pom - 1] != 20) temp += " ";
    }
    if(napis[pom - 1] != 20) temp += napis[pom + 1]; // sprawdzenie ostatniego znaku napisu
    //cout << '"' << temp << '"' << endl;
    return temp;
}

// Klaudia C - 11.01.2016

#include<iostream>
using namespace std;

struct Elem{
    int val;
    Elem *next;
};

struct Ciag{
    char a, b, c; // identyfikator
    Elem *e; // wskaznik na ciag liczb
    Ciag *next;
} *head; // wskaznik na pierwszy ciag

void print(Ciag *head){
    for(Ciag *ciag = head; ciag != NULL; ciag = ciag -> next){ // przechodzenie po liscie ciagow
        cout << ciag -> a << ciag -> b << ciag -> c; // wypisanie identyfikatora
        for(Elem *elem = ciag -> e; elem != NULL; elem = elem -> next) cout << ' ' << elem -> val; // wypisanie ciagu liczb
        cout << endl;
    }
}

Elem *rev(Elem *cur){
    Elem *res = NULL;
    Elem *temp = NULL;

    while(cur != NULL){ // przepisanie ciagu w odwrotnej kolejnosci ("przesypanie stosu")
        temp = cur;
        cur = temp -> next;
        temp -> next = res;
        res = temp;
    }
    return res;
}

void wczytajZestaw(){
    head = NULL;
    while(true){
        char z; // aktualnie wczytany znak
        do{
            cin.get(z);
        }
        while(z == ' ' || z == '\n'); // pominiecie bialych znakow
        if(z == '$') break;

        Ciag *c = new Ciag; // wpisywany ciag
        Elem *e = NULL;
        c -> e = NULL;
        c -> next = NULL;
        c -> a = z; // uzupelnienie identyfikatora
        cin.get(z);
        c -> b = z;
        cin.get(z);
        c -> c = z;
        cin.get(z); // spacja po literach
        cin.get(z); // poczatek ciagu liczb
        while(z != 'S' && z!= 'R'){ // wczytywanie liczb
            cin.unget(); // cofniecie sie do ostatnio czytanego znaku (liczba)
            Elem *temp = new Elem;
            temp -> next = e;
            e = temp;
            cin >> e -> val;
            cin.get(z); // pominiecie spacji
            cin.get(z); // pobranie kolejnego znaku
        }
        if(z == 'R') c -> e = e;
        else c -> e = rev(e);

        Ciag *cur = head; // wskaznik na aktualnie sprawdzany ciag
        Ciag *prev = NULL; // wskaznik na ciag przed cur
        while(cur != NULL && (c -> a > cur -> a || (c -> a == cur -> a && (c -> b > cur -> b || (c -> b == cur -> b && c -> c > cur -> c))))){ // szukanie odpowiedniego miejsca na liscie ciagow (wedlug porzadku leksykograficznego)
            prev = cur; // przesuniecie wskaznikow o jeden
            cur = cur -> next;
        }
        c -> next = cur; // wstawienie nowego ciagu pomiedzy prev i cur
        if(prev == NULL) head = c; // nie nastapilo przesuniecie, wiec dopisujemy na poczatek listy
        else prev -> next = c; // dopisanie gdzies wewnatrz listy
    }
}

Elem *del(Elem *cur, int coIle, int ktory){
    Elem *res = NULL;
    Elem *temp = NULL;

    while(cur != NULL){ // przepisanie ciagu w odwrotnej kolejnosci ("przesypanie stosu")
        temp = cur;
        cur = temp -> next;
        if(ktory == 0){ // natrafilismy na liczbe do usuniecia
            delete temp;
            ktory = coIle; // odliczanie co drugiego/trzeciego elementu zaczyna sie od poczatku
        }
        else{ // nie usuwamy, przepisujemy do wyniku
            temp -> next = res;
            res = temp;
        }
        ktory--;
    }
    return res;
}

void wczytajPolecenia(){
    int liczbaPolecen;

    cin >> liczbaPolecen;
    for(int i = 0; i < liczbaPolecen; i++){
        char A, B, C;// identyfikator ciagu
        char coKtory, odKtorego, gdziePoczatek; // dane do usuwania
        char z; // aktualnie wczytany znak

        do{
            cin.get(A);
        }
        while(A == ' ' || A == '\n'); // pominiecie bialych znakow
        cin.get(B);
        cin.get(C);
        cin.get(z); // spacja
        cin.get(coKtory);
        cin.get(z); // spacja
        cin.get(odKtorego);
        cin.get(z); // spacja
        cin.get(gdziePoczatek);
        Ciag *cur = head; // wskaznik na aktualnie sprawdzany ciag
        while(cur != NULL && (A != cur -> a || B != cur -> b || C != cur -> c)) cur = cur -> next; // szukanie ciagu do przeprowadzenia usuwania (porownywanie znakow identyfikatorow)
        if (cur == NULL) continue; // szukano ciagu, ktorego nie ma na liscie
        if(gdziePoczatek == 'B') cur -> e = rev(del(cur -> e, (coKtory == 'D') ? 2 : 3, (odKtorego == 'F') ? 0 : ((odKtorego == 'S') ? 1 : 2))); // ustalenie kryteriow do funkcji usun
        else cur -> e = del(rev(cur -> e), (coKtory == 'D') ? 2 : 3, (odKtorego == 'F') ? 0 : ((odKtorego == 'S') ? 1 : 2));
     }
}

void delAll(Ciag *head){ // czyszczenie ciagow
    while(head != NULL){ // dopoki zestaw ma ciagi
        while(head -> e != NULL){ // dopoki ciag sie z czegos sklada
            Elem *temp = head -> e;
            head -> e = temp -> next;
            delete temp; // to jego zawartosc jest usuwana
        }
        Ciag *temp = head;
        head = temp -> next;
        delete temp; // to ciagi sa usuwane
    }
}

int main(){
    int zestawy;

    cin >> zestawy;
    for(int i = 0; i < zestawy; i++){
        wczytajZestaw();
        print(head);
        wczytajPolecenia();
        print(head);
        delAll(head);
    }
    return 0;
}

// Klaudia C - 21.12.2015

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

string ident;
float height;
int age;

void create(string fileName, int amount){
    fstream plik;

    plik.open(fileName.c_str(), fstream::out);
    plik << amount << endl;
    for(int i = 0; i < amount; i++){
        cin >> ident >> height >> age;
        plik << ident << " " << height << " " << age << endl;
    }
    plik.close();
}

void display(string fileName, int position, int amount){
    int ile; // liczba rekordow
    int i = 0; // numer wypisywanego rekordu i aktualnie sprawdzanego rekordu
    fstream plik;

    plik.open(fileName.c_str(), fstream::in);
    plik >> ile;
    while(i != position){ // szukanie rekordu, od ktorego zaczyna sie odczyt
        plik >> ident >> height >> age;
        i++;
    }
    while(amount > 0 && plik >> ident >> height >> age){
        cout << i << ": " << ident << " " << height << " " << age << endl;
        i++;
        amount--;
    }
    cout << " " << endl;
    plik.close();
}

void insert(string fileName, int position, int amount){
    int ile; // liczba rekordow
    int ktory = 0; // aktualnie przepisywany wiersz
    fstream plik;
    fstream temp; // plik pomocniczy

    plik.open(fileName.c_str(), fstream::in);
    temp.open("tmp.txt", fstream::out);
    plik >> ile;
    ile += amount;
    temp << ile << endl;
    if(position > ile - amount - 1){ // pozycja poza pierwotnym plikiem
        while(ktory != ile - amount){ // przepisanie wszystkich rekordow
            plik >> ident >> height >> age;
            temp << ident << " " << height << " " << age << endl;
            ktory++;
        }
        for(int i = 0; i < amount; i++){ // wpisanie nowych rekordow
            cin >> ident >> height >> age;
            temp << ident << " " << height << " " << age << endl;
        }
    }
    else{
        while(ktory != position){ // przepisanie rekordow przed miejscem do dopisywania
            plik >> ident >> height >> age;
            temp << ident << " " << height << " " << age << endl;
            ktory++;
        }
        for(int i = 0; i < amount; i++){ // wpisanie nowych rekordow
            cin >> ident >> height >> age;
            temp << ident << " " << height << " " << age << endl;
        }
        while(plik >> ident >> height >> age) temp << ident << " " << height << " " << age << endl; // przepisanie pozostalych rekordow

    }
    plik.close();
    temp.close();

    plik.open(fileName.c_str(), fstream::out);
    temp.open("tmp.txt", fstream::in);
    temp >> ile;
    plik << ile << endl;
    while(temp >> ident >> height >> age) plik << ident << " " << height << " " << age << endl; // przepisanie temp do plik
    plik.close();
    temp.close();
    remove("tmp.txt");
}

void usun(string fileName, int position, int amount){
    int ile; // liczba rekordow
    fstream plik;
    fstream temp; // plik pomocniczy

    create("tmp.txt", 0);
    plik.open(fileName.c_str(), fstream::in);
    temp.open("tmp.txt", fstream::out);
    plik >> ile;
    temp << ile << endl;
    while(plik >> ident >> height >> age) temp << ident << " " << height << " " << age << endl;
    plik.close();
    temp.close();

    plik.open(fileName.c_str(), fstream::out);
    temp.open("tmp.txt", fstream::in);
    temp >> ile;
    ile -= amount;
    plik << ile << endl;
    for(int i = 0; i < position; i++){ // przepisanie rekordow przed miejscem usuniecia
        temp >> ident >> height >> age;
        plik << ident << " " << height << " " << age << endl;
    }
    for(int i = 0; i < amount; i++) temp >> ident >> height >> age; // pominiecie linii do usuniecia
    while(temp >> ident >> height >> age) plik << ident << " " << height << " " << age << endl; // przepisanie pozostalych rekordow
    plik.close();
    temp.close();

    remove("tmp.txt");
}

void search(string fileName, string searchIdent, int searchAge, float startHeight, float finishHeight){
    int ile; // liczba rekordow
    fstream plik;

    plik.open(fileName.c_str(), fstream::in);
    plik >> ile;
    for(int i = 0; i < ile; i++){
        plik >> ident >> height >> age;
        if(startHeight <= height && height <= finishHeight){
            if(searchIdent == "*"){
                if(searchAge == 0) cout << i << ": " << ident << " " << height << " " << age << endl;
                else if(age == searchAge) cout << i << ": " << ident << " " << height << " " << age << endl;
            }
            else if(ident.compare(searchIdent) == 0){
                if(searchAge == 0) cout << i << ": " << ident << " " << height << " " << age << endl;
                else if(age == searchAge) cout << i << ": " << ident << " " << height << " " << age << endl;
            }
        }
    }
    cout << " " << endl;
    plik.close();
}

void sort(string inputFileName, string outputFileName){ // kopiowanie i usuwanie
    string pomIdent = " ";
    float pomHeight;
    int pomAge;
    int ile; // liczba rekordow
    int pom; // pomocnicza liczba rekordow
    int ktory = 0;
    fstream input;
    fstream output;

    input.open(inputFileName.c_str(), fstream::in);
    output.open(outputFileName.c_str(), fstream::out);
    input >> ile;
    pom = ile;
    output << ile << endl;
    input.close();

    for(int i = 0; i < ile; i++){
        input.open(inputFileName.c_str(), fstream::in);
        input >> pom;
        input >> ident >> height >> age;
        for(int j = 1; j < pom ; j++){ // szukanie najmniejszego rekordu
            input >> pomIdent >> pomHeight >> pomAge;
            if(pomIdent < ident){
                ident = pomIdent;
                height = pomHeight;
                age = pomAge;
                ktory = j;
            }
        }
        output << ident << " " << height << " " << age << endl;
        usun(inputFileName, ktory, 1);
        ktory = 0;
        input.close();
    }
    output.close();

    input.open(inputFileName.c_str(), fstream::in | fstream::out);
    input << endl; // pozbycie sie liczby rekordow
    input.close();
}

void merge(string prevFileName, string nextFileName, string mergeFileName){ // kopiowane bez usuwania
    int prevIle; // dane pliku prev
    string prevIdent = " ";
    float prevHeight;
    int prevAge;
    int nextIle; //dane pliku next
    string nextIdent = " ";
    float nextHeight;
    int nextAge;

    fstream prev; // rekordy juz sa posortowane niemalejaco
    fstream next; // rekordy juz sa posortowane niemalejaco
    fstream merge;

    prev.open(prevFileName.c_str(), fstream::in);
    next.open(nextFileName.c_str(), fstream::in);
    merge.open(mergeFileName.c_str(), fstream::out);

    prev >> prevIle;
    next >> nextIle; // liczba rekordow next
    merge << prevIle + nextIle << endl; // liczba rekordow merge

    if(prevIle) prev >> prevIdent >> prevHeight >> prevAge;
    if(nextIle) next >> nextIdent >> nextHeight >> nextAge;

    while(prevIle > 0 && nextIle > 0){
		if(prevIdent <= nextIdent){
			merge << prevIdent << " " << prevHeight << " " << prevAge << endl;
			prevIle--;
			if(prevIle > 0) prev >> prevIdent >> prevHeight >> prevAge;
		}
		else{
            merge << nextIdent << " " << nextHeight << " " << nextAge << endl;
			nextIle--;
			if(nextIle > 0) next >> nextIdent >> nextHeight >> nextAge;
		}
	}

    while(prevIle > 0){
		merge << prevIdent << " " << prevHeight << " " << prevAge << endl;
		prevIle--;
		if(prevIle > 0) prev >> prevIdent >> prevHeight >> prevAge;
	}

    while(nextIle > 0){
		merge << nextIdent << " " << nextHeight << " " << nextAge << endl;
		nextIle--;
		if(nextIle > 0) next >> nextIdent >> nextHeight >> nextAge;
	}

    prev.close();
    next.close();
    merge.close();
}

int main(){
    int ileFunkcji; // liczba funkcji
    string funkcja; // nazwa wpisanej funkcji
    string nazwa; // nazwa pliku
    string drugi; // nazwa pliku next funkcji merge
    string wynik; // nazwa pliku wynikowego funkcji sort lub merge
    int liczbaPlikow; // liczba plikow
    int ilosc; // liczba rekordow
    int pozycja; // pozycja w pliku
    float heightLow; // dolna granica wysokosci
    float heightUpp; // gorna granica wysokosci


    cin >> ileFunkcji;
    for(int i = 0; i < ileFunkcji; i++){
        cin >> funkcja;

        if(funkcja == "create"){
            cin >> nazwa >> liczbaPlikow;
            create(nazwa, liczbaPlikow);
        }

        if(funkcja == "display"){
            cin >> nazwa >> pozycja >> ilosc;
            display(nazwa, pozycja, ilosc);
        }

        if(funkcja == "insert"){
            cin >> nazwa >> pozycja >> ilosc;
            insert(nazwa, pozycja, ilosc);
        }

        if(funkcja == "delete"){
            cin >> nazwa >> pozycja >> ilosc;
            usun(nazwa, pozycja, ilosc);
        }

        if(funkcja == "search"){
            cin >> nazwa >> ident >> age >> heightLow >> heightUpp;
            search(nazwa, ident, age, heightLow, heightUpp);
        }

        if(funkcja == "sort"){
            cin >> nazwa >> wynik;
            sort(nazwa, wynik);
        }

        if(funkcja == "merge"){
            cin >> nazwa >> drugi >> wynik;
            merge(nazwa, drugi, wynik);
        }
    }
    return 0;
}

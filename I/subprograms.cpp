// Klaudia C - 22.01.2016

void odwroc(string &x){
	for(int i = 0; i < x.size()/2; i++){
		char temp = x[i];
		x[i] = x[x.size() - i - 1];
		x[x.size() - i - 1] = temp;
	}
}

string Sum(const string &a, const string &b){ // a, b - skladniki
	string wynik;
	int p = 0 ; // przeniesienie

	string pomA = a;
	bool minusA = (pomA[0] == '-'); // sprawdzenie, czy skladnik jest ujemny
	if(minusA){
		pomA[0] = '0'; // zastapienie minusa zerem
		p++; // powieksznie przeniesienia jesli tak
	}
	odwroc(pomA);
	if(pomA[pomA.size() - 1] == '+') pomA[pomA.size() - 1] = '0'; // jezeli na poczatku liczby mam plus, to zastepuje go zerem

	string pomB = b;
	bool minusB = (pomB[0] == '-');
	if(minusB){
		pomB[0] = '0';
		p++;
	}
	odwroc(pomB);
    if(pomB[pomB.size() - 1] == '+') pomB[pomB.size() - 1] = '0';

	for(int i = 0, j = 0; i <= pomA.size() || j <= pomB.size(); i++, j++){ // odczyt liczb od poczatku (do size(), zeby bylo miejsce na przeniesienie)
		int cyfraA = i < pomA.size() ? pomA[i] - 48 : 0; // jezeli liczba juz sie skonczyla, to dopelniam ja zerami
		if(minusA) cyfraA = 9 - cyfraA; // jezeli dana liczba jest ujemna to odwracam jej wartosc
		int cyfraB =  j < pomB.size() ? pomB[j] - 48 : 0;
		if(minusB) cyfraB = 9 - cyfraB;
		int temp = cyfraA + cyfraB + p;
		wynik += temp%10 + 48; // dodanie liczb z odpowiedniego slupka do siebie
		p = temp/10; // ustalenie przeniesienia
	}
	bool minusW = (wynik[wynik.size() - 1] >= '5'); // liczba byla ujemna, wiec trzeba ja odwrocic z powrotem
	if(minusW){
		p = 1;
		for(int i = 0; i < wynik.size(); i++){
			int temp = 9 - (wynik[i] - 48) + p; // odwrocenie powrotne
			wynik[i] = temp%10 + 48; // dodanie liczb z odpowiedniego slupka do siebie
			p = temp/10; // ustalenie nowego przeniesienia
		}
	}
	int rozmiar = wynik.size(); // nowy rozmiar wyniku
	while(rozmiar > 1 && wynik[rozmiar - 1] == 48) rozmiar--; // szukanie miejsca, w ktorym konczy sie wynik
	wynik.resize(rozmiar); // pozbycie sie zer z poczatku liczby
	if(minusW) wynik += '-';
	odwroc(wynik);
	return wynik;
}

string Mult(const string &a, const string &b){
	string wynik;
	wynik.resize(a.size() + b.size()); // wstepny rozmiar wyniku
	for(int i = 0; i < wynik.size(); i++) wynik[i] = '0'; //wynik poczatkowy (same zera)

	for(int i = 0; i < a.size() && a[a.size() - 1 - i] != '-' && a[a.size() - 1 - i] != '+'; i++){ // sprawdzenie, czy pierwszy znak ciagu nie jest minusem lub plusem
		int p = 0; // przeniesienie
		int j = 0;
		for(j; j < b.size() && b[b.size() - 1 - j] != '-' && b[b.size() - 1 - j] != '+'; j++){ // sprawdzenie, czy pierwszy znak ciagu nie jest minusem lub plusem
			int temp = (a[a.size() - 1 - i] - 48) * (b[b.size() - 1 - j] - 48) + (wynik[i + j] - 48) + p; // wynik z wymnozenia czynnikow i dodania ich do aktualnego wyniku w ich slupku
			wynik[i + j] = temp%10 + 48;
			p = temp/10;
		}
		if(p != 0) wynik[i + j] = p + 48;
	}

	int rozmiar = wynik.size(); // nowy rozmiar wyniku
	while(rozmiar > 1 && wynik[rozmiar - 1] == '0') rozmiar--; // szukanie miejsca, w ktorym konczy sie wynik
	wynik.resize(rozmiar); // pozbycie sie zer z poczatku liczby
	if(((a[0] == '-') != (b[0] == '-')) && (wynik[wynik.size() - 1] != '0')) wynik += '-'; // dodanie minusa do wyniku jesli tylko jedna z liczb jest ujemna
	odwroc(wynik);
	return wynik;
}

string Sum(int liczbaSkladnikow, const string *liczby){
	string wynik = "0";

	for(int i = 0; i < liczbaSkladnikow; i++) wynik = Sum(wynik, liczby[i]);
	return wynik;
}

string Sum(int liczbaSkladnikow, ...){
	string wynik = "0";
	va_list liczby;

	va_start(liczby, liczbaSkladnikow);
	for(int i = 0; i < liczbaSkladnikow; i++) wynik = Sum(wynik, va_arg(liczby, const char*));
	va_end(liczby);
	return wynik;
}

void Sum(string *wynik, int liczbaSkladnikow, const string *liczby){
	*wynik = Sum(liczbaSkladnikow, liczby);
}

void Sum(string *wynik, int liczbaSkladnikow, ...){
	*wynik = "0";
	va_list liczby;

	va_start(liczby, liczbaSkladnikow);
	for(int i = 0; i < liczbaSkladnikow; i++) *wynik = Sum(*wynik, va_arg(liczby, const char*));
	va_end(liczby);
}

void Sum(string &wynik, int liczbaSkladnikow, const string *liczby){
	wynik = Sum(liczbaSkladnikow, liczby);
}

void Sum(string &wynik, int liczbaSkladnikow, ...){
	wynik = "0";
	va_list liczby;

	va_start(liczby, liczbaSkladnikow);
	for(int i = 0; i < liczbaSkladnikow; i++) wynik = Sum(wynik, va_arg(liczby, const char*));
	va_end(liczby);
}

string Mult(int liczbaCzynnikow, const string* liczby){
    string wynik = "1";

	for(int i = 0; i < liczbaCzynnikow; i++) wynik = Mult(wynik, liczby[i]);
	return wynik;
}

string Mult(int liczbaCzynnikow, ...){
    string wynik = "1";
	va_list liczby;

	va_start(liczby, liczbaCzynnikow);
	for(int i = 0; i < liczbaCzynnikow; i++) wynik = Mult(wynik, va_arg(liczby, const char*));
	va_end(liczby);
	return wynik;
}

void Mult(string *wynik, int liczbaCzynnikow, const string *liczby){
    *wynik = Mult(liczbaCzynnikow, liczby);
}

void Mult(string *wynik, int liczbaCzynnikow, ...){
    *wynik = "1";
	va_list liczby;

	va_start(liczby, liczbaCzynnikow);
	for(int i = 0; i < liczbaCzynnikow; i++) *wynik = Mult(*wynik, va_arg(liczby, const char*));
	va_end(liczby);
}

void Mult(string &wynik, int liczbaCzynnikow, const string* liczby){
    wynik = Mult(liczbaCzynnikow, liczby);
}

void Mult(string &wynik, int liczbaCzynnikow, ...){
	wynik = "1";
	va_list liczby;

	va_start(liczby, liczbaCzynnikow);
	for(int i = 0; i < liczbaCzynnikow; i++) wynik = Mult(wynik, va_arg(liczby, const char*));
	va_end(liczby);
}

string Operation(string(*nazwaFunkcji)(int, const string*), int liczbaElementow, const string *liczby){
    return(*nazwaFunkcji)(liczbaElementow, liczby);
}

string Operation(string(*nazwaFunkcji)(int, const string*), int liczbaElementow, ...){
    string temp[liczbaElementow];
    va_list liczby;

    va_start(liczby, liczbaElementow);
    for(int i = 0; i < liczbaElementow; i++) temp[i] = va_arg(liczby, const char*);
    string wynik = (*nazwaFunkcji)(liczbaElementow, temp);
    return wynik;
}

void Operation(string* wynik, string(*nazwaFunkcji)(int, const string*), int liczbaElementow, ...){
    string temp[liczbaElementow];
    va_list liczby;

    va_start (liczby, liczbaElementow);
    for(int i = 0; i < liczbaElementow; i++) temp[i] = va_arg(liczby, const char*);
    va_end (liczby);
    *wynik = (*nazwaFunkcji)(liczbaElementow, temp);
}

void Operation(string *wynik, string (*nazwaFunkcji)(int, const string*), int liczbaElementow, const string *liczby){
    *wynik = (*nazwaFunkcji)(liczbaElementow, liczby);
}

void Operation(string &wynik, void (*nazwaFunkcji)(string*, int, const string*), int liczbaElementow, const string *liczby){
    nazwaFunkcji(&wynik, liczbaElementow, liczby);
}

void Operation(string &wynik, void (*nazwaFunkcji)(string*, int, const string*), int liczbaElementow, ...){
    string temp[liczbaElementow];
    va_list liczby;

    va_start (liczby, liczbaElementow);
    for(int i = 0; i < liczbaElementow; i++) temp[i] = va_arg(liczby, const char*);
    va_end (liczby);
    nazwaFunkcji(&wynik, liczbaElementow, temp);
}

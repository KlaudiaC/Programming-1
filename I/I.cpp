// Klaudia C - 22.01.2016

#include <cstdarg>
#include <iostream>
#include <string>
using namespace std;
#include "subprograms.cpp"

int main(){
	//cout << char(65);
    string wynik1 = Sum("-199", "+19");
	cout << wynik1 << endl;
	string wynik2 = Mult("0541", "+1");
	cout << wynik2 << endl;
	string wynik3 = Sum(3, "21", "111", "1");
	cout<< wynik3 << endl;
	string wynik4 = Sum(2, "100", "2");
	cout << wynik4 << endl;
	string wynik5 = Mult(3, "-1", "3", "-10");
	cout << wynik5 << endl;
    string s[2] = { "1", "2" };
    cout << s[0] << '+' << s[1] << '=';
    Operation(&s[1], Sum, 2, s); cout << s[1] << endl;
	return 0;
}

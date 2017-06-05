#include <iostream>
using namespace std;
#include "kod.cpp"

int main()
{
    int tab[] = {1, -2, 3, -4, 5, -6};
    int n = 6;

    cout << Suma(n, tab) << endl;
    tab[1] = tab[1] * (-1);
    cout << Suma(n, tab) << endl;

    double c = 1;
    double wagi[] = {0.1, 0.3, 0.15, 0.05, 0.2};
    double srednia[2 * n - 1];
    for(int i = 0; i < n - 1; ++i)
    {
        srednia[2 * i] = tab[i];
        srednia[2 * i + 1] = wagi[i];
    }
    srednia[2 * n - 2] = tab[n - 1];
    cout << SredniaWazona(srednia, n, c) << " ";
    cout << c << endl;
    srednia[2 * n - 3] = 0.45;
    cout << SredniaWazona(srednia, n ,c) << " ";
    cout << c << endl;

    double x1 = 1, x2 = 1;
    cout << PierwiastkiKwadratowe(1, 2, 1, x1, x2);
    cout << " " << x1 << " " << x2 << endl;

    Fibonacci(tab, 4);
    for(int i = 0; i <= 4; ++i) cout << tab[i] << " ";
    cout << endl;

    cout << Licznik(true, n) << " ";
    cout << n << endl;
    cout << Licznik(true, n) << " ";
    cout << n << endl;
    cout << Licznik(false, n) << " ";
    cout << n << endl;

    return 0;
}

#include <iostream>
#include "kod.cpp"

int main()
{
    string napis = "ABCD{p:5:x}X Y Z";
    FormatujNapis(napis, "abc", "cdef", "xyz");
    FormatujNapis("ABCD{u:3}X Y Z", "abc", "cdef", "xyz");
    FormatujNapis("ABCD{U:2}X Y Z", "abc", "cdef", "xyz");
    FormatujNapis("ABCD{w:2}X Y Z", "abc", "cdef", "xyz");
    FormatujNapis("ABCD{W:2:3}X Y Z", "abc", "cdef", "xyz");
    FormatujNapis("ABCD{W:2:5}X Y Z", "abc", "cdef", "xyz");
    FormatujNapis("A{p:4:a}le {w:1}tra nudny t{w:1}t. {u:3}UsuCam{U:2}{W:2:3}{W:3:3}.","eks", "zy", "niebyt");
    UsunSlowo("Smok Wawelski ryczy ku uciesze gawiedzi", 2);
    NajwiekszeSlowo("Smok Wawelski ryczy ku uciesze gawiedzi");
    NormalizujNapis("Oto   Ala   .Ma kota ,lecz nie ma psa     .");
    return 0;
}

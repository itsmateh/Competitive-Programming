#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string txt;
    cin >> txt;

    map<char, int> caracteres;
    for (char c : txt) {
        caracteres[c]++;
    }


    int impar = 0;
    char caracter_impar = '\0';
    for (auto i : caracteres) {
        if (i.second % 2 != 0) {
            impar++;
            caracter_impar = i.first;
        }
    }

    if (impar > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    string primera_mitad = "";
    string segunda_mitad = "";
    
    for (auto letra : caracteres) {
        string mitad(letra.second / 2, letra.first);
        primera_mitad += mitad;
        segunda_mitad = mitad + segunda_mitad;
    }

    string palindromo = primera_mitad;
    if (impar == 1) {
        palindromo += caracter_impar;
    }
    palindromo += segunda_mitad;

    cout << palindromo << endl;
    return 0;
}

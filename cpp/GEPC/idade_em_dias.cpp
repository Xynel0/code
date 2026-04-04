#include <bits/stdc++.h>
using namespace std;
int main(){
    int idade_em_dias;
    int anos;
    int meses;
    cin >> idade_em_dias;
    anos = idade_em_dias / 365;
    idade_em_dias = idade_em_dias - 365 * anos;
    meses = idade_em_dias / 30;
    idade_em_dias = idade_em_dias - 30 * meses;
    cout << anos << " ano(s)\n" << meses << " mes(es)\n" << idade_em_dias << " dia(s)" << endl;
}

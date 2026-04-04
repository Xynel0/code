#include <bits/stdc++.h>
using namespace std;
int main(){
    float x1;
    float y1;
    float x2;
    float y2;
    float distancia;

    //recebe os valores...
    cin >> x1; //x do ponto 1
    cin >> y1; //y do ponto 1
    cin >> x2; //x do ponto 2
    cin >> y2; //y do ponto 2
    distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); //calcula a distância
    cout << fixed << setprecision(4) << distancia << endl; // imprime a distância com 4 casas decimais
}

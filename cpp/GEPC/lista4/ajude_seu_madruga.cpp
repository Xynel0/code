#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, a;
    while (cin >> n >> a){
        //processa o caso final e quebra o while
        if (n == 0 && a == 0){
            break;
        }//se o caso não for o final, processa o resto do código abaixo
        
        //cria um array com os n comprimentos, preenche o array e armazena o valor da soma numa variável
        int comprimentos [n];
        int soma_dos_comprimentos = 0;
        for (int i = 0; i < n; ++i){
            cin >> comprimentos[i];
            soma_dos_comprimentos = soma_dos_comprimentos + comprimentos[i];
        }

        //lida com os casos triviais
        /*
        nota: se a for igual a 0 ou for igual a soma das áreas,
              não precisamos cortar. 
        */
        if (a == 0 || a == soma_dos_comprimentos){
            cout << ":D" << endl;
        }

        /*se a for maior que a soma dos comprimentos, precisariamos de mais área do que o total,
        o que não é possível*/
        else if (a > soma_dos_comprimentos){
            cout << "-.-" << endl;
        }

        /*se nenhum dos casos acima se aplicam,
        sabemos que é possível cortar. assim, a parte abaixo
        realiza o cálculo da altura do corte*/
        else{
            // encontra o maior elemento
            int max_altura = comprimentos[0];
            for (int i = 0; i < n; ++i){
                if (max_altura < comprimentos[i]){
                    max_altura = comprimentos[i];
                }
            }

            double base_pointer = 0; //como estamos supondo que estão alinhadas, a base pode ser representada por 0
            double top_pointer = max_altura;
            double corte;

            /*o loop será executado de forma a reduzir o top_pointer e aumentar o base_pointer para que ambos
            se aproximem do valor procurado até que o intervalo entre eles seja suficientemente pequeno
            para desconsiderarmos a diferença, podendo dizer que top e base são iguais. E como estavam sendo
            levados para cada vez mais próximo do valor procurado, podemos dizer também que eles são iguais
            a esse valor*/
            while (top_pointer - base_pointer > 1e-7){ //enquanto a diferença entre os dois for maior que a margem de tolerância...
                
                //calcula a área acima de um corte feito no meio do intervalo analisado
                double area_recortada = 0; //reseta a área a cada loop para manter a contagem abaixo válida
                double altura_do_corte = (base_pointer + top_pointer) / 2; //decide a altura do corte

                //calcula a área retirada de cada elemento após o corte e adiciona essa área a soma das áreas
                for (int i = 0; i < n; ++i){
                    area_recortada = area_recortada + max((double) 0, comprimentos[i] - altura_do_corte);
                }

                //decide o que faz com os pointers com base na relação entre a e area_recortada
                if (a == area_recortada){
                    corte = altura_do_corte;
                    break;
                }
                else if (a > area_recortada){
                    top_pointer = altura_do_corte;
                }
                else if (a < area_recortada){
                    base_pointer = altura_do_corte;
                }
                corte = altura_do_corte; /*ao fim do loop, torna corte = altura do corte. assim, garante que no momento
                que o loop parar, haverá uma altura do corte para ser impressa*/
            }
            cout << fixed << setprecision(4) << corte << endl; //imprime a altura ideal do corte
        }
    }
}

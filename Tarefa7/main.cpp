#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include "utils.cpp"

int main() {
    cout << "---------------------------------------------" << endl;
    cout << "-------------------Tarefa 7------------------" << endl;
    cout << "---------------------------------------------\n" << endl;

    bool programa = true;

    while(programa){
        int xf;
        cout << "Escreva o valor de c:";
        cin >> xf;
        int xi = -xf;
        double epilson;
        cout << "Escreva o valor do erro:";
        cin >> epilson;
        cout << "Escolha a abordagem desejada:\n";
        cout << "1: Abordagem Aberta" << endl;
        cout << "2: Abordagem Fechada" << endl;
        cout << "3: Gauss Legendre" << endl;
        int metodo;
        cout << "Digite o número da abordagem que voce quer escolher" << endl;
        cin >> metodo;

        cout << "Escolha o problema desejado:\n";
        cout << "1: 1 Problema" << endl;
        cout << "2: 2 Problema" << endl;
        int problema;
        cout << "Digite o número do problema que voce quer escolher" << endl;
        cin >> problema;

        cout << "Escolha que vc quer com exponencial simples ou dupla:\n";
        cout << "1: simples" << endl;
        cout << "2: dupla" << endl;
        int forma;
        cout << "Digite o número que vc quiser" << endl;
        cin >> forma;

        integracao(xi, xf, epilson, problema, forma, metodo);

        cout << "Quer continuar com o programa?\n";
        cout << "1: Sim" << endl;
        cout << "2: Não" << endl;
        int resposta;
        cout << "Digite o número da resposta:" << endl;
        cin >> resposta;
        if(resposta == 2){
            programa=false;
        }
    } 
    return 0;
}
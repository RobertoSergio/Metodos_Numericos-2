#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include "utils.h"

using namespace std;

// Função para calcular coth(x)
double coth(double x) {
    return 1.0 / tanh(x);
}

double problema1_exponecial_dupla(double s) {
    const double pi = M_PI;
    const double factor = pi / 2.0;

    
    double sinh_s = sinh(s);    
    double tanh_val = tanh(factor * sinh_s);
    
    
    double tanh_squared = tanh_val * tanh_val;
    double tanh_power = pow(tanh_squared, 2.0 / 3.0);
    double coth_val = coth(factor * sinh_s);
    
    double result = 3.0 * tanh_power * coth_val;

    return result;
}

double problema1_exponecial_simples(double s) {
    double tanh_s = tanh(s);

    double tanh_s_squared = pow(tanh_s, 2);

    double tanh_s_squared_power = pow(tanh_s_squared, 2.0 / 3.0);

    double coth_s = 1.0 / tanh_s;

    double result = 3.0 * tanh_s_squared_power * coth_s;

    return result;
}

void integracao(double a, double b, double epsilon, int problema, int forma, int metodo) {
    double delta = 0;
    double erro = 0;
    double res = 0;
    double res_ant = 0;
    int N = 2;
    bool integ = true;
    int interacao = 0;

    while (integ) {
        interacao++;
        double res_atual = 0;
        for (int i = 0; i < N; i++) {
            double xi = a;
            double xf = b;
            if(problema==1){
                if(forma==1){
                    if (metodo == 2) {
                        res_atual += abordagem_fechada_grau3_problema_1_simples(xi, xf);
                    } else if (metodo == 1) {
                        res_atual += abordagem_aberta_grau3_problema_1_simples(xi, xf);
                    } else if (metodo== 3) {
                        res_atual += gauss_legendre_4pontos_problema_1_simples(xi, xf);
                    }
                }
                else if (forma == 2){
                    if (metodo == 2) {
                        res_atual += abordagem_fechada_grau3_problema_1_dupla(xi, xf);
                    } else if (metodo == 1) {
                        res_atual += abordagem_aberta_grau3_problema_1_dupla(xi, xf);
                    } else if (metodo== 3) {
                        res_atual += gauss_legendre_4pontos_problema_1_dupla(xi, xf);
                    }
                }
            }
        }

        cout << "---------------------------------------------" << endl;
        cout << "          Interação: " << interacao << endl;
        cout << "          Resultado: " << res_atual << endl;
        cout << "---------------------------------------------" << endl;

        N *= 2;
        res_ant = res;
        res = res_atual;
        erro = abs(res - res_ant);

        if (erro < epsilon || interacao >= 25) {
            integ = false;
        }
    }
}

double gauss_legendre_4pontos_problema_1_simples(double xi, double xf) {
    double a1 = sqrt((3.0 / 7) - (2.0 * sqrt(6.0 / 5)/7));
    double a2 = -sqrt((3.0 / 7) - (2.0 * sqrt(6.0 / 5)/7));
    double a3 = sqrt((3.0 / 7) + (2.0 * sqrt(6.0 / 5)/7));
    double a4 = -sqrt((3.0 / 7) + (2.0 * sqrt(6.0 / 5)/7));

    double w1 = (18 + sqrt(30.0)) / 36;
    double w2 = (18 + sqrt(30.0)) / 36;
    double w3 = (18 - sqrt(30.0)) / 36;
    double w4 = (18 - sqrt(30.0)) / 36;

    return ((xf - xi) / 2) * (problema1_exponecial_simples(((xf - xi) / 2) * a1 + ((xf + xi) / 2)) * w1 +
                              problema1_exponecial_simples(((xf - xi) / 2) * a2 + ((xf + xi) / 2)) * w2 +
                              problema1_exponecial_simples(((xf - xi) / 2) * a3 + ((xf + xi) / 2)) * w3 +
                              problema1_exponecial_simples(((xf - xi) / 2) * a4 + ((xf + xi) / 2)) * w4);
}

double abordagem_aberta_grau3_problema_1_simples(double xi, double xf) {
    double h = (xf - xi) / 5;
    return (5 * h / 24) * (11 * problema1_exponecial_simples(xi) + problema1_exponecial_simples(xi + h) + problema1_exponecial_simples(xi + 2 * h) + 11 * problema1_exponecial_simples(xi + 3 * h));
}

double abordagem_fechada_grau3_problema_1_simples(double xi, double xf) {
    double h = (xf - xi) / 3;
    return (3 * h / 8) * (problema1_exponecial_simples(xi) + 3 * problema1_exponecial_simples(xi + h) + 3 * problema1_exponecial_simples(xi + 2 * h) + problema1_exponecial_simples(xi + 3 * h));
}

double gauss_legendre_4pontos_problema_1_dupla(double xi, double xf) {
    double a1 = sqrt((3.0 / 7) - (2.0 * sqrt(6.0 / 5)/7));
    double a2 = -sqrt((3.0 / 7) - (2.0 * sqrt(6.0 / 5)/7));
    double a3 = sqrt((3.0 / 7) + (2.0 * sqrt(6.0 / 5)/7));
    double a4 = -sqrt((3.0 / 7) + (2.0 * sqrt(6.0 / 5)/7));

    double w1 = (18 + sqrt(30.0)) / 36;
    double w2 = (18 + sqrt(30.0)) / 36;
    double w3 = (18 - sqrt(30.0)) / 36;
    double w4 = (18 - sqrt(30.0)) / 36;

    return ((xf - xi) / 2) * (problema1_exponecial_dupla(((xf - xi) / 2) * a1 + ((xf + xi) / 2)) * w1 +
                              problema1_exponecial_dupla(((xf - xi) / 2) * a2 + ((xf + xi) / 2)) * w2 +
                              problema1_exponecial_dupla(((xf - xi) / 2) * a3 + ((xf + xi) / 2)) * w3 +
                              problema1_exponecial_dupla(((xf - xi) / 2) * a4 + ((xf + xi) / 2)) * w4);
}

double abordagem_aberta_grau3_problema_1_dupla(double xi, double xf) {
    double h = (xf - xi) / 5;
    return (5 * h / 24) * (11 * problema1_exponecial_dupla(xi) + problema1_exponecial_dupla(xi + h) + problema1_exponecial_dupla(xi + 2 * h) + 11 * problema1_exponecial_dupla(xi + 3 * h));
}

double abordagem_fechada_grau3_problema_1_dupla(double xi, double xf) {
    double h = (xf - xi) / 3;
    return (3 * h / 8) * (problema1_exponecial_dupla(xi) + 3 * problema1_exponecial_dupla(xi + h) + 3 * problema1_exponecial_dupla(xi + 2 * h) + problema1_exponecial_dupla(xi + 3 * h));
}

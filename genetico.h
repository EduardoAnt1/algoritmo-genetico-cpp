#ifndef GENETICO_H
#define GENETICO_H

#include <bits/stdc++.h>

using namespace std;

const int TAM_POPULACAO = 200;
const int NUM_GERACOES = 200;
const double TAXA_MUTACAO = 0.1;

struct Alimento {
    string nome;
    double proteina;
    double carboidrato;
    double gordura;
    double calorias;
};

struct Porcao {
    int alimento;
    double quantidade;
};

struct Individuo {
    vector<Porcao> refeicoes[4];
};

struct Nutrientes {
    double proteina = 0;
    double carboidrato = 0;
    double gordura = 0;
    double calorias = 0;
};

Individuo gerar_individuo();
Nutrientes calcular_nutrientes(const Individuo& individuo);
double avaliar_individuo(const Individuo& individuo);
Individuo cruzar_individuos(const Individuo& pai1, const Individuo& pai2);
Individuo torneio(const vector<Individuo>& populacao);
Individuo executar_algoritmo(vector<double>& melhores_fitnesses);
void imprimir_dieta(const Individuo& individuo);

#endif
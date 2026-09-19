#include "genetico.h"
#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    vector<double> melhores_fitnesses;
    Individuo melhor = executar_algoritmo(melhores_fitnesses);

    cout << "MELHOR DIETA ENCONTRADA" << endl;
    imprimir_dieta(melhor);

    return 0;
}

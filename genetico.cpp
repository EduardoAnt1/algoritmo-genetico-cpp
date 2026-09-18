#include "genetico.h"
#include <bits/stdc++.h>

using namespace std;

const vector<Alimento> CAFE_CEREAIS = {
    {"Biscoito Recheado Chocolate", 6, 71, 20, 472},
    {"Biscoito Salgado Cream Cracker", 10, 69, 14, 432},
    {"Cereal Matinal", 7, 84, 1, 382},
    {"Pao Frances", 8, 59, 3, 300}
};

const vector<Alimento> CAFE_FRUTAS = {
    {"Abacate", 1, 6, 8, 96},
    {"Abacaxi", 1, 12, 0, 48},
    {"Banana prata", 1, 26, 0, 98},
    {"Coco", 4, 10, 0, 402},
    {"Goiaba vermelha", 1, 13, 0, 54},
    {"Laranja Pera", 1, 9, 0, 37},
    {"Maça Fuji", 0, 15, 0, 56},
    {"Maracujá", 2, 12, 2, 68},
    {"Melao", 1, 8, 0, 29},
    {"Morango", 1, 7, 0, 30}
};

const vector<Alimento> CAFE_BEBIDAS = {
    {"Cafe", 15, 66, 12, 419},
    {"Agua de coco", 0, 5.3, 0, 21.5},
    {"Suco Laranja Pera", 0.7, 7.6, 0.1, 32.7},
    {"Suco de uva nectar", 0, 29, 0, 115},
    {"Leite UHT integral", 6, 8.8, 4, 113},
    {"Iogurte natural", 4, 2, 3, 51}
};

const vector<Alimento> REFEICAO_CEREAIS = {
    {"Arroz integral cozido", 2.6, 25.8, 0.3, 123.5},
    {"Arroz tipo 1", 2.5, 28.1, 0.2, 128.3},
    {"Macarrao Instantaneo", 9, 62, 17, 432},
    {"Feijao carioca", 20, 63, 1, 336},
    {"Lentilha", 23, 64, 1, 347}
};

const vector<Alimento> REFEICAO_VERDURAS_HORTALICAS = {
    {"Abobrinha Italiana Refogada", 1.1, 4.2, 0.1, 24.4},
    {"Alface Lisa", 2, 2, 0, 14},
    {"Alho cru", 7, 24, 0, 113},
    {"Batata Doce Cozida", 0.6, 18.4, 0, 76.8},
    {"Beterraba Crua", 2, 11, 0, 49},
    {"Cará", 1.5, 18.9, 0, 77.6},
    {"Cenoura Cozida", 0.9, 6.7, 0.1, 29.9},
    {"Couve Crua", 3, 4, 1, 27},
    {"Espinafre Nova Zelândia Refogado", 2.7, 4.2, 0.9, 67.3},
    {"Mandioca Frita", 1.4, 50.3, 1.7, 300.1},
    {"Nabo cru", 1, 4, 0, 18},
    {"Tomate com semente cru", 1, 3, 0, 15},
    {"Vagem crua", 2, 5, 0, 25}
};

const vector<Alimento> REFEICAO_PESCADOS = {
    {"Corimbata Assado", 19, 0, 4.8, 261.5},
    {"Pintado Grelhado", 30.8, 0, 1.1, 152.2},
    {"File de Merluza Frito", 26.9, 0, 1.4, 191.6},
    {"Atum conserva em oleo", 26.2, 0, 1, 165.9}
};

const vector<Alimento> REFEICAO_CARNES = {
    {"Carne bovina acem moida cozida", 26.7, 0, 10.9, 212.4},
    {"Carne bovina contra file sem gordura grelhado", 35.9, 0, 4.5, 193.7},
    {"Carne bovina costela assada", 28.8, 0, 27.7, 373},
    {"File mignon sem gordura grelhado", 33, 0, 9, 220},
    {"Carne bovina fraldinha com gordura cozida", 24, 0, 26, 338},
    {"Carne bovina lagarto cozida", 33, 0, 9, 221}
};

const vector<Alimento> REFEICAO_BEBIDAS = {
    {"Refrigerante Guarana", 0, 10, 0, 38.7},
    {"Suco Laranja Pera", 0.7, 7.6, 0.1, 32.7},
    {"Suco de uva nectar", 0, 29, 0, 115}
};

const double LIMITE_CEREAIS[] = {0.5, 1.5};
const double LIMITE_FRUTAS[] = {1.0, 1.5};
const double LIMITE_BEBIDAS[] = {1.0, 2.0};
const double LIMITE_CARNES[] = {0.8, 2.0};
const double LIMITE_PEIXES[] = {0.5, 2.0};
const double LIMITE_VERDURAS[] = {0.05, 0.2};

mt19937 gerador(random_device{}());

int sortear_inteiro(int minimo, int maximo) {
    return uniform_int_distribution<int>(minimo, maximo)(gerador);
}

double sortear_real(double minimo, double maximo) {
    return uniform_real_distribution<double>(minimo, maximo)(gerador);
}

const vector<Alimento>& obter_tabela(int refeicao, int posicao) {
    if (refeicao % 2 == 0) {
        if (posicao == 0) return CAFE_CEREAIS;
        if (posicao == 1) return CAFE_FRUTAS;
        return CAFE_BEBIDAS;
    }
    if (posicao < 2) return REFEICAO_CEREAIS;
    if (posicao < 4) return REFEICAO_VERDURAS_HORTALICAS;
    if (posicao == 4) {
        if (refeicao == 1) return REFEICAO_CARNES;
        return REFEICAO_PESCADOS;
    }
    return REFEICAO_BEBIDAS;
}

const double* obter_limite(int refeicao, int posicao) {
    if (refeicao % 2 == 0) {
        if (posicao == 0) return LIMITE_CEREAIS;
        if (posicao == 1) return LIMITE_FRUTAS;
        return LIMITE_BEBIDAS;
    }
    if (posicao < 2) return LIMITE_CEREAIS;
    if (posicao < 4) return LIMITE_VERDURAS;
    if (posicao == 4) {
        if (refeicao == 1) return LIMITE_CARNES;
        return LIMITE_PEIXES;
    }
    return LIMITE_BEBIDAS;
}

Individuo gerar_individuo() {
    Individuo individuo;
    for (int i = 0; i < 4; i++) {
        int tamanho = (i % 2 == 0) ? 3 : 6;
        for (int j = 0; j < tamanho; j++) {
            const auto& tabela = obter_tabela(i, j);
            const double* limite = obter_limite(i, j);
            Porcao porcao;
            porcao.alimento = sortear_inteiro(0, static_cast<int>(tabela.size()) - 1);
            porcao.quantidade = sortear_real(limite[0], limite[1]);
            individuo.refeicoes[i].push_back(porcao);
        }
    }
    return individuo;
}

Nutrientes calcular_nutrientes(const Individuo& individuo) {
    Nutrientes total;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < static_cast<int>(individuo.refeicoes[i].size()); j++) {
            const Porcao& porcao = individuo.refeicoes[i][j];
            const Alimento& alimento = obter_tabela(i, j)[porcao.alimento];
            total.proteina += porcao.quantidade * alimento.proteina;
            total.carboidrato += porcao.quantidade * alimento.carboidrato;
            total.gordura += porcao.quantidade * alimento.gordura;
            total.calorias += porcao.quantidade * alimento.calorias;
        }
    }
    return total;
}

double avaliar_individuo(const Individuo& individuo) {
    Nutrientes n = calcular_nutrientes(individuo);
    double total = n.proteina + n.carboidrato + n.gordura;

    double fitness = 2.0 * abs(n.proteina / total * 100 - 25);
    fitness += abs(n.carboidrato / total * 100 - 50);
    fitness += 1.5 * abs(n.gordura / total * 100 - 25);
    fitness += 0.1 * (max(0.0, n.proteina - 0.25 * total)
                   + max(0.0, n.carboidrato - 0.50 * total)
                   + max(0.0, n.gordura - 0.25 * total));

    if (n.calorias > 2500) fitness *= 10;
    if (n.calorias < 2500) fitness += 0.1 * (2500 - n.calorias);

    for (int i = 1; i < 4; i += 2) {
        const auto& refeicao = individuo.refeicoes[i];
        if (refeicao[0].alimento == refeicao[1].alimento) fitness *= 20;
        if (refeicao[2].alimento == refeicao[3].alimento) fitness *= 3;
    }
    for (int i = 1; i < 4; i += 2) {
        const auto& refeicao = individuo.refeicoes[i];
        string cereal1 = REFEICAO_CEREAIS[refeicao[0].alimento].nome;
        string cereal2 = REFEICAO_CEREAIS[refeicao[1].alimento].nome;
        if (cereal1.find("Arroz") != string::npos &&
            cereal2.find("Arroz") != string::npos) fitness *= 50;
    }

    for (int i = 0; i < 4; i += 2) {
        const Porcao& cereal = individuo.refeicoes[i][0];
        fitness *= 20 * cereal.quantidade * CAFE_CEREAIS[cereal.alimento].gordura;
    }
    for (int i = 0; i < 4; i += 2) {
        const auto& cafe = individuo.refeicoes[i];
        string bebida = CAFE_BEBIDAS[cafe[2].alimento].nome;
        if (bebida.find("Cafe") != string::npos) fitness *= (i == 0 ? 0.6 : 0.8);
    }
    for (int i = 0; i < 4; i += 2) {
        const auto& cafe = individuo.refeicoes[i];
        string bebida = CAFE_BEBIDAS[cafe[2].alimento].nome;
        string fruta = CAFE_FRUTAS[cafe[1].alimento].nome;
        if (bebida.find("coco") != string::npos && fruta.find("Coco") == string::npos)
            fitness *= (i == 0 ? 1.6 : 1.8);
    }
    return fitness;
}

Individuo cruzar_individuos(const Individuo& pai1, const Individuo& pai2) {
    Individuo filho;
    filho.refeicoes[0] = pai1.refeicoes[0];
    filho.refeicoes[1] = pai2.refeicoes[1];
    filho.refeicoes[2] = pai1.refeicoes[2];
    filho.refeicoes[3] = pai2.refeicoes[3];
    return filho;
}

Individuo torneio(const vector<Individuo>& populacao) {
    int vencedor = sortear_inteiro(0, static_cast<int>(populacao.size()) - 1);
    double melhor = avaliar_individuo(populacao[vencedor]);
    for (int i = 1; i < 5; i++) {
        int candidato = sortear_inteiro(0, static_cast<int>(populacao.size()) - 1);
        double fitness = avaliar_individuo(populacao[candidato]);
        if (fitness < melhor) {
            vencedor = candidato;
            melhor = fitness;
        }
    }
    return populacao[vencedor];
}

Individuo executar_algoritmo(vector<double>& melhores_fitnesses) {
    vector<Individuo> populacao;
    melhores_fitnesses.clear();
    for (int i = 0; i < TAM_POPULACAO; i++) populacao.push_back(gerar_individuo());

    Individuo melhor_geral;
    double melhor_fitness = 0;
    for (int geracao = 0; geracao < NUM_GERACOES; geracao++) {
        vector<Individuo> nova_populacao;
        for (int i = 0; i < TAM_POPULACAO; i++) {
            Individuo pai1 = torneio(populacao);
            Individuo pai2 = torneio(populacao);
            nova_populacao.push_back(cruzar_individuos(pai1, pai2));
        }

        for (Individuo& individuo : nova_populacao) {
            if (sortear_real(0, 1) < TAXA_MUTACAO) individuo = gerar_individuo();
        }
        populacao = nova_populacao;

        int melhor = 0;
        double fitness_geracao = avaliar_individuo(populacao[0]);
        for (int i = 1; i < TAM_POPULACAO; i++) {
            double fitness = avaliar_individuo(populacao[i]);
            if (fitness < fitness_geracao) {
                melhor = i;
                fitness_geracao = fitness;
            }
        }
        melhores_fitnesses.push_back(fitness_geracao);
        if (geracao == 0 || fitness_geracao < melhor_fitness) {
            melhor_geral = populacao[melhor];
            melhor_fitness = fitness_geracao;
        }
    }
    return melhor_geral;
}

void imprimir_dieta(const Individuo& individuo) {
    const string nomes[] = {"Cafe da manha", "Almoco", "Cafe da tarde", "Janta"};
    cout << fixed << setprecision(2);
    for (int i = 0; i < 4; i++) {
        cout << "\n" << nomes[i] << "\n";
        int tamanho = static_cast<int>(individuo.refeicoes[i].size());
        for (int j = 0; j < tamanho; j++) {
            const Porcao& porcao = individuo.refeicoes[i][j];
            cout << obter_tabela(i, j)[porcao.alimento].nome << " -> "
                 << porcao.quantidade * 100 << (j == tamanho - 1 ? " ml\n" : " g\n");
        }
    }
    Nutrientes n = calcular_nutrientes(individuo);
    cout << "\nProteina: " << n.proteina << " g\n"
         << "Carboidrato: " << n.carboidrato << " g\n"
         << "Gordura: " << n.gordura << " g\n"
         << "Calorias: " << n.calorias << " kcal\n"
         << "Fitness: " << avaliar_individuo(individuo) << "\n";
}

bool salvar_convergencia(const vector<double>& valores) {
    if (valores.empty()) return false;
    ofstream csv("convergencia.csv");
    ofstream svg("convergencia.svg");
    if (!csv || !svg) return false;

    csv << "geracao,melhor_fitness\n" << setprecision(17);
    for (int i = 0; i < static_cast<int>(valores.size()); i++)
        csv << i << ',' << valores[i] << '\n';

    double maximo = *max_element(valores.begin(), valores.end());
    if (maximo <= 0) maximo = 1;
    svg << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"900\" height=\"500\" viewBox=\"0 0 900 500\">\n"
        << "<rect width=\"900\" height=\"500\" fill=\"white\"/>\n"
        << "<g font-family=\"sans-serif\" font-size=\"14\" fill=\"black\">\n"
        << "<text x=\"450\" y=\"30\" text-anchor=\"middle\">Convergencia do Algoritmo Genetico</text>\n";
    for (int i = 0; i <= 5; i++) {
        double y = 420 - i * 70;
        svg << "<path d=\"M 130 " << y << " H 860\" stroke=\"#ddd\"/>\n"
            << "<text x=\"120\" y=\"" << y + 5 << "\" text-anchor=\"end\">"
            << setprecision(4) << maximo * i / 5 << "</text>\n";
    }
    svg << "<path d=\"M 130 70 V 420 H 860\" fill=\"none\" stroke=\"black\"/>\n"
        << "<text x=\"130\" y=\"445\">0</text>\n"
        << "<text x=\"860\" y=\"445\" text-anchor=\"end\">" << valores.size() - 1 << "</text>\n"
        << "<text x=\"495\" y=\"475\" text-anchor=\"middle\">Geracao</text>\n"
        << "<text transform=\"translate(25 245) rotate(-90)\" text-anchor=\"middle\">Melhor fitness</text>\n"
        << "</g>\n<polyline fill=\"none\" stroke=\"#2166ac\" stroke-width=\"2\" points=\"";
    for (int i = 0; i < static_cast<int>(valores.size()); i++) {
        double x = 130 + 730.0 * i / max(1, static_cast<int>(valores.size()) - 1);
        double y = 420 - 350.0 * valores[i] / maximo;
        svg << x << ',' << y << ' ';
    }
    svg << "\"/>\n</svg>\n";
    csv.close();
    svg.close();
    return !csv.fail() && !svg.fail();
}

# algoritmo-genetico-cpp

Algoritmo genético em C++ que gera um **cardápio semanal** (Segunda a Domingo, com café da manhã, almoço, café da tarde e janta), respeitando restrições alimentares (glúten e lactose) e sem repetir a mesma refeição durante a semana.

## Como executar

```
g++ main.cpp genetico.cpp
./a.out (ou ./a.exe)
```

O programa pergunta `Sem gluten? (s/n)` e `Sem lactose? (s/n)` e imprime o cardápio da semana com as quantidades de cada refeição, os totais nutricionais do dia, o número de refeições repetidas (esperado: 0) e o fitness.

## Perguntas de paralelismo

**1. Quais são as principais etapas do algoritmo?**
- Criação dos indivíduos
- Torneio
- Cruzamento dos indivíduos
- Cálculo da Fitness

**2. O paralelismo será de dados, de tarefas ou híbrido?**
- O paralelismo será de tarefas (função de avaliação, torneio) ou híbrido (dividir a população em subconjuntos).

**3. Qual parte pode ser executada simultaneamente?**
- O paralelismo será de tarefas (função de avaliação, torneio) ou híbrido (dividir a população em subconjuntos).

**4. Como o trabalho será dividido entre threads e processos?**
- Processos: Modelo das Ilhas, onde cada processo gerencia um subconjunto da população.
- Threads: Avaliação da fitness e torneio.

**5. Quais etapas ou dados possuem dependências?**
- Cruzamento e mutação só podem acontecer depois que o torneio for finalizado, e o torneio, por sua vez, só pode finalizar assim que a avaliação da fitness dos participantes tenha sido concluída. A população da geração seguinte só pode ser completamente formada quando a geração atual estiver finalizada.

**6. Existe risco de condição de corrida? Desenvolva.**
- Existe se a escrita for feita utilizando ponteiros/contadores dinâmicos ou globais; as threads podem ler o mesmo índice e sobrescrever o indivíduo/fitness.

**7. Será necessário sincronizar ou combinar resultados?**
- Sincronização ao final de cada geração para que nenhuma thread inicie a avaliação da geração seguinte sem antes finalizar a geração atual.
- Dividir o vetor em posições pré-alocadas para que cada thread escreva diretamente nas posições sem precisar disputar locks, garantindo que, ao final, o resultado já esteja combinado no vetor principal.

# O que é esse repositório?

Aqui esta o código do meu TCC. Eu implementei o algoritmo [memplas](https://www.sciencedirect.com/science/article/abs/pii/S0020025516303516) (algoritmo evolucionário) presente nesse artigo e adicionei um componente Path Relinking para o problema Quota Car Traveling Salesman (QCars). Eu utilizei a linguagem C++.

# Conteúdo das pastas

- Instances: cenários de execução que o algoritmo será submetido.
- Irace: Pasta com configurações da ferramenta Irace. Mais informações [aqui](https://cran.r-project.org/).
- Logs: Pasta com logs de execução do programa.
- Pandas: Pasta com scripts Python para analise dos resultados do experimento.
- Project: Pasta com o código fonte.
- Script: Pasta com scripts de execução dos experimentos. Anteriormente eram vários sheel scripts, hoje contém apenas um script Python.


# Como executar o código fonte?

Execute com:

    python pymake.py build

Vai ser criado um executável com nome de memplas, para executar:

    ./memplas 1 1 1 <instance> -strategy <s> --sizePopulation <sp> --elite  <e> --limitIterations <li> --sizePlasmideo <spl> --cross <c>

Onde:
-   instance: Arquivo com cenário de execusão.
-   s: Modo de execusão. 'm' para executar memplas apenas, 'pr' para Path Relinking apenas ou 'mpr' para executar ambos.
-   sp: Tamanho da população.
-   e: Tamanho da população de elite.
-   li: Número de iterações do algoritmo.
-   spl: Tamanho dos plasmídeos do memplas.
-   c: Taxa de cruzamento da população.

Exemplo de comando de execução:

    ./memplas 1 1 1 ../Instances/AfricaSul11e.pcar -strategy m --sizePopulation 150 --elite  0.3 --limitIterations 100 --sizePlasmideo 0.2 --cross 0.4

Execute os testes unitários com:
    
    python pymake.py test

O framework de teste utilizado foi [este](https://github.com/google/googletest).

# Como executar um experimento?

Na pasta Scripts contém o arquivo executor.py, execute-o:

    python executor.py

O script vai executar 30 execuções de cada instância e vai salvar em um log.

# Como analisar os resultados do experimento?

Nas pasta pandas, tem o arquivo main.py. Executar ele vai utilizar os logs da pasta Logs e vai gerar gráficos, testes estatísticos e tabelas para LaTeX em Log/Results.
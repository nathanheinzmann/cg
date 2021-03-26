# Introdução

## Callback vs Threads

### Threads

Threads são linhas de execução em que um processador de uma máquina executa. É a pluralidade das Threads que permite a execução de um programa de modo assíncrono, melhorando a eficiência do programa que pode escalar mais de apenas uma linha de execução. Porém quando são escaladas várias threads por um processo, elas precisam emitir um "aviso" quando finalizadas, e é aí que entra o conceito de callback.

### Callbacks

As callbacks são ponteiros para funções ,ou seja, elas permitem que sejam passadas funções como parâmetro. Mas, seguindo o raciocínio anterior, uma função é passada como parâmetro para que ao final da execução da thread chamada, essa função passada seja chamada.

## Projeções Ortogonais e Perspectiva

### Projeções Ortgonais

Projeções ortogonais, é a projeção dos vértices de um objeto em um plano, formando uma figura.

### Projeções Perspectivas

Projeções perspectivas são formações gráficas que tem como ideia simular profundidade nas projeções, e ainda existem vários tipos de perspectivas como:

- Cônica
  - é mais utilizado em projetos arquitetônicos e de interiores
  - trabalha com conceito de pontos de fuga
  - podem existir casos onde mais de um ponto de fuga são aplicados
- Isométricas
  - utilizada em projetos de engenharia, desenhos mecânicos
  - mantém as proporções de comprimento, alrgura e altura do objeto em questão
  - traço simples
  - as faces tem 30° da horizontal
  - o que gera a perspectiva isométrica é o sistema das três retas em ângulo de 120°
- Cavaleiras
  - também é utilizada na maioria das vezes em projetos de engenharia, desenhos mecânicos
  - uma das faces segue o mesmo plano enquanto que as outras, ficam oblíquas ao plano em 30° 45° ou 60°
  - o ângulo mais usado é o de 45°

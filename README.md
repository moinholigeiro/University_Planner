# University_Planner
Um planejador universitário que te auxilia a gerenciar as disciplinas em cada período letivo

Prioridade de uma disciplina é definida, neste programa, como a quantidade mínima de períodos a mais necessária para se formar, levando em consideração a aprovação na mesma. Ou seja, quantos períodos a disciplina tranca.

Perceba que não tem nada haver com a quantidade de DISCIPLINAS que ela tranca ao mesmo tempo, mas sim a quantidade de PERÍODOS que ela tranca, após realizar uma análise em cadeia dos pré-requisitos das disciplinas.

Funcionalidades:
* Importar disciplinas da grade com pré-requisito ou co-requisitos de outras disciplinas, exportando o planejamento por período ou prioridade, no melhor cenário possível (quantidade ilimitada de disciplinas por período e sem reprovações)
* Análise atualizada: o programa importa do arquivo "Feitas.txt" as disciplinas já cursadas e realiza o planejamento dos novos períodos ignorando as mesmas

A implementar:
* Ter a opção de digitar manualmente, durante a execução, as disciplinas feitas e as disciplinas da grade
* Tratar e notificar erros de formatação ou lógica, como a declaração de duas disciplinas de mesmo código, sejam com nomes/pré-requisitos iguais ou diferentes
* ~~Pular linhas vazias nos arquivos de entrada~~
* Ignorar todos os caracteres não alfanuméricos e deixar todos os minúsculos como maiúsculos, evitando duplicação de disciplinas na importação e análises
* Avaliar e notificar possíveis erros de digitação ou formatação, como o caso das disciplinas não terem o tamanho de seus códigos iguais entre si
* ~~Limpar o terminal sempre que entrar em um novo menu~~
* ~~Prosseguir para o submenu apenas pressionando a tecla desejada (sem enter)~~
* Colocar a funcionalidade de agenda de faltas, para controle de faltas durante o período atual
* Importar diretamente do PDF (esse vai dar bastante trabalho...)
* Implementar o submenu "Configurar", com opções de estipular regras, como a de definir uma quantidade máxima de disciplinas ou carga horária por período, na hora de exportar o planejamento
* Opção de busca por código ou nome, inteligente, sendo feita mesmo com apenas parte da informação, e atualizada com o pressionar de cada tecla, em tempo real, para avaliar informações da disciplina como nome, código, pré-requisitos
* Adicionar a funcionalidade de avaliar se as disciplinas são ofertadas em semestre ímpar/par/ambos e gerar o planejamento em cima dessas informações (fazendo de uma forma que o programa, a princípio, reconheça todas como ofertadas em ambos os períodos, com exceção daquelas que reconheça como diferente pelo arquivo. Se não existir nenhum arquivo, dar um warning p o usuário. Também dar um warning para cada disciplina que não aparece no arquivo, caso o arquivo exista)
* Fazer o planejamento do período, com vários arquivos com as disciplinas ofertadas, por departamento (nomes como "Horario 1", "Horario 2", "Horario 3", etc, onde o programa vai lendo até não achar o "Horario {x+1}"), de acordo com as análises de conflito de horários e prioridades, exportando como um arquivo do excel, bem formatado e tals, se eu conseguir kk

#
Nota: eu ainda não sei mexer muito no README.md :v mas vou aprendendo com o tempo

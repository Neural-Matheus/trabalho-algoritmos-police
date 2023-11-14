# Sistema de Polícia Militar
## Resumo do Sistema da Polícia Militar (SPM)

### A - Introdução
O Sistema da Polícia Militar (SPM) foi desenvolvido para automatizar operações manuais da corporação policial militar. Utiliza arquivos TXT como base de dados para viaturas, pessoas e policiais. Foi um trabalho da faculdade para uso de estrutura de dados, treinamento da linguagem C/C++, uso de modularização, criação de structs e manipulação de dados multiarquivos.

#### Entrada
1. **Viaturas (viaturas.txt):** Identificador e tipo de viatura.
2. **Pessoas (pessoas.txt):** Informações de pessoas fictícias.
3. **Policiais (policiais.txt):** Dados do corpo policial.

### B - Setores e Funcionalidades
O programa é dividido por setores/áreas da polícia, com funcionalidades interdependentes.

#### Etapas Principais
1. **Viatura Login:**
   - Login na viatura, indicando PMs e tipo de viatura.
   - Validação do número de PMs e identificação única.
   - Aguardo ou cancelamento da embarcação.

2. **Inicialização Voluntária:**
   - Atribuição de chamada policial ou indicação de status livre.

3. **Exibição da Chamada Policial:**
   - Informações sobre a ocorrência.
   - Confirmação de intervenção policial.

4. **Funcionalidades para uma Ocorrência:**
   - Busca por CPF.
   - Solicitação de reforço.
   - Realização de prisão.

5. **Viatura em Uso:**
   - Atualização do estado da viatura.
   - Carregamento de chamada policial.

#### COPOM (Centro de Operações Policiais Militares)
- Classificação de chamadas para polícia regular ou especializada.
- Priorização de chamadas.
- Distribuição de chamadas para viaturas.

#### PM (Policial Militar)
- Boletim de ocorrência com login.
- Visualização e escrita de boletins.

#### Oficial
- Exclusão de boletins de ocorrência.
- Geração de relatório oficial.

#### Comandante Geral
- Geração de ofício de ocorrências.

### Criptografia de Senha
A senha é criptografada somando 3 unidades ao valor ASCII de cada caractere e invertendo a ordem.

### Considerações Finais
- Utilização de filas encadeadas para organizar chamadas policiais.
- Escolha entre Insertion Sort, Selection Sort ou Quicksort para ordenação.
- Alocação dinâmica obrigatória.

### Execução
O programa inicia com o menu principal (Etapa 1), permitindo realizar funções de qualquer setor em uma única execução.

### Arquivos de Entrada e Saída
Os arquivos devem seguir os exemplos fornecidos, e a compilação deve ser feita com a opção -Wall.

### Avaliação
- Escrito em C, sem classes.
- Ausência de violação de memória.
- Desalocação de todas as alocações dinâmicas.
- Evitar cópias de trabalhos alheios.

**Observação:** Consulte os anexos no AVA para uma compreensão mais detalhada e confirmação das abstrações utilizadas.

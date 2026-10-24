# Avaliação 2 - ITP (Opção 1)

**Identificação:**
- **Nome:** Samuel Macêdo da Silva
- **Projeto escolhido:** Opção 1 - Boletim de uma pequena turma

**Descrição:**
O programa resolve o problema de registro de notas de uma turma. Ele permite cadastrar de 1 a 10 alunos, ler três notas (com validação de 0 a 10) e calcular a média utilizando alocação dinâmica de memória (Heap). Ao final, o sistema exibe uma tabela formatada com os dados, a situação de cada aluno (Atingiu/Abaixo da meta), a média geral e a maior média da turma.

**Compilação e execução:**
Para compilar e executar este programa, utilize os comandos abaixo no terminal do Linux:
`gcc main.c -o programa`
`./programa`

**Testes realizados:**
- **Caso Inválido (Limite de alunos e nota inválida):**
  - Entrada: Quantidade de alunos = `15` (rejeitado), depois `2` (aceito).
  - Entrada de nota: Aluno 1, nota = `11` (rejeitado), depois `5`.
  - Resultado esperado e obtido: O programa bloqueou as entradas inválidas e solicitou a redigitação corretamente.
- **Caso Válido (Cálculo correto):**
  - Entradas: Aluno Samuel (notas 5, 6 e 7). Aluno Carlos (notas 4, 5 e 4).
  - Resultado esperado e obtido: Samuel com média 6.00 (Atingiu a meta) e Carlos com média 4.33 (Abaixo da meta). Média geral de 5.17 e Maior média sendo do Samuel.

**Vídeo de Apresentação:**
- [Link do vídeo no YouTube](COLE_AQUI_O_LINK_DO_SEU_VIDEO_DO_YOUTUBE)

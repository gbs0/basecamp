##### Especificação:
Escreva uma linha de comando que exiba um ls -l uma linha a cada duas (linha
sim, linha não), a partir da primeira

#### Explicação sobre os comandos:
O exercicio pede que se crie um comando do tipo `ls -l`, porém que em um diretório com diversas pastas ou arquivos, o comando deve mostrar os arquivos de forma alternada, pulando um diretório/arquivo de cada vez.

#### Comandos:
`ls -l | awk 'NR%2==0'`

• awk: Escaneia o input file e mostra de acordo com um padrão especifado como argumento.
  -> NR: Numero total de gravações
  -> %: Operador de módulo
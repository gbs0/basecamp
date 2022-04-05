#### Exercicio 01 - testShell00
##### **Algumas instruções p/ realizar o exercicio em comando Shell**

** Pontos Importantes de Aprendizado:**
• Criar um arquivo com atributos de Timestamp.
• Compilar o arquivo em `.tar` com o comando `tar -cf t`

#### Instruções:
##### **Terminal**
Criar um arquivo com o comando `touch testShell00` na pasta de entrega.

##### **Compilar um novo arquivo .tar**
Precisamos gerar um novo arquivo do tipo `.tar`, então utilizaremos o seguinte comando:

`tar -cf testShell00.tar testShell00`

##### **Mudar as as permissões de leitura e escrita**
Verificar as permissões de `umask` do arquivo no shell Linux. 

##### O valor a ser definido é de: 455. -> Type: -r--r-xr-x 

`chmod 455 testShell00`

As opções definidas são:

|         | owner | group | other |
|---------|-------|-------|-------|
| read    | X     | X     | X     |
| write   |       |       |       |
| execute |       | X     | X     |

[Link da Calculadora]("https://www.webune.com/forums/umask-calculator.html")
[Referência]("https://www.infowester.com/linuxpermissoes.php")

##### Definir nova Timestamp de acesso:
Iremos modificar a data de criação do arquivo `.tar`, com isso, vamos precisar modificar a timestamp gerada automáticamente pelo comando touch:

` touch -m -t 201906020730.00 testShell00.tar*`

O padrão gerado segue a regra do uso de Timestamps como registro da data e horário utilizados no sistema.

[Referência]("https://www.putorius.net/how-to-use-the-linux-touch-command-with-examples.html")

##### Popular o arquivo com 40 caracteres
Para adicionar 39 caracteres (pois a linha é contada como um caractere), rodamos o seguinte comando:

`echo $(`seq 1 39`) >> ./testShell00`
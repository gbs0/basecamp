#### Listar todos os MAC Address:
`ifconfig -a | grep ether | awk -F' ' '{print $0}'`


#### Listar somente os atributos esperados:
`ifconfig -a |   grep txqueuelen  | grep ether | awk -F' ' '{print $2 " " $3 " " $4 " " $5}'`

#### Explicação:
• ifconfig: Usado para configurar os parametros de uma interface de rede
-> -a: Mostrar todas as interaces `--all` 

• grep: Usado p/ procurar arquivos dado alguns parametros
-> ether: Busca pela linha que tem os atributos que queremos.

• awk: Escaneia cada input file for linhas que seguem qualquer padrão especificado no progfile.
-> -F: Define o separador p/ ser uma regex.
-> ' ' '{print $2 " " $3 " " $4 " " $5}': Faz o print dos argumentos conforme Header do output.
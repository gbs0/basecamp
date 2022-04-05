#### Identificar um arquivo mágico
Neste exercicio, precimos identificar atráves de um arquivo `.mgc` 'magico'.

**Compilando o arquivo mágico:**
Para executarmos o arquivo `.mgc`, precisamos compilar seu executável com:
`file -C -m ft_magic`

**Rodando a solução:**
Precisamos rodar o arquivo gerado, assim veremos dois tipos de resultados p/ arquivos diferentes:

> Arquivo **não** é magico:
`file -m ft_magic.mgc file`
`$ file: ASCII File`

> Arquivo **é** mágico:
`file -m ft_magic.mgc 42_file`
`$ file: 42 file`


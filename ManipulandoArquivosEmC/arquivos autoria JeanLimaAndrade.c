// compilado com os parametros do gcc e clang:  -Wall -Wextra -pedantic -Wwrite-strings

#include <stdio.h> // nessa biblioteca que tem o FILE * e outras funções relacionadas a arquivos

int main() {
    // existem diversas flags para abertura de arquivos, e estas podem ser combinadas
    // "r"  modo de leitura, para poder ler o arquivo.
    // "w"  modo de escrita, para poder escrever o arquivo.
    // "b"  usado em conjunto com os de cima, serve para dizer que eh para esperar o
    //         arquivo como um binario qualquer, e nao um de texto puro.
    // "a"  modo de escrita, serve para adicionar no final do arquivo,
    //         nao sobrescreve os conteudos existentes.

    // a extensão não tem nada a ver com o que vai ser escrito/lido do arquivo, apesar de dar a dica do que pode ser
    char const *caminhoArquivoExemplo = "arquivoExemplo.txt";

    // vale lembrar, a operação acima so eh valida porque "arquivoExemplo.txt" eh um string literal e o seu valor eh *guardado no proprio
    // binario* (em um setor imodificavel), logo ao fazermos a operação de colocar o valor na variavel, o compilador sabe o endereço e
    // assim consegue entender e fazer com que caminhoArquivoExemplo aponte para o local correto, isso *nao* funciona com valores lidos
    // em tempo de execução, por isso que devemos copiar as strings quando nao temos o endereço dela alocada no heap (ja que a na stack
    // em algum momento iria ser liberada e consequentemente acessariamos um endereço agora invalido)

    FILE *arquivoLeitura = fopen(caminhoArquivoExemplo, "r"); // por padrao vai ser lido em modo texto
    if (!arquivoLeitura) { // caso entrar aqui, deu erro na abertura do arquivo (arquivo eh nulo), nesse caso vamos escrever algo nele
        printf("Arquivo inexistente, populando ele....\nRode novamente o programa\n\n");
        // criando arquivo para escrita
        FILE * arquivoEscrita = fopen(caminhoArquivoExemplo, "w"); // por padrao vai ser escrito em modo texto

        // array de strings (ponteiros), feito para exemplificar o uso do fprintf e escrever multiplas linhas
        // o NULL no final eh o ponto de parada
        char const *linhas[] = { "// Primeira linha\n", "// Segunda linha\n", "// Exemplo de escrita em arquivo\n", NULL };
        for (int i = 0; linhas[i]; i += 1) {
            // usamos o fprintf como se fosse o printf, com a diferença que a saida agora eh no arquivo
            fprintf(arquivoEscrita, "%s", linhas[i]);
        }

        fclose(arquivoEscrita); // explicacao dessa funcao abaixo
    } else { // caso entre aqui o arquivo existe, logo queremos printar o conteudo dele
        char linha[100];
        while (fgets(linha, 100, arquivoLeitura)) {
            // caso fgets retornar NULL, significa que ele não conseguiu ler nada, caso consiga
            // retornará um ponteiro para a última posição lida
            // nao esta sendo tratado o EOF, nem caso a linha passe de 100, por simplicidade
            // mas se desejarem, da para eu detalhar mais como resolver esse caso
            printf("lido: %s", linha);
        }

        /* codigo comentado, caso deseje testar comente o while acima, e descomente o abaixo */
        /*
          // voce pode usar o fscanf como o scanf e sscanf, so que no caso do fscanf, o primeiro
          // parametro eh o arquivo do qual o fscanf vai ler.
          // o fscanf (e sscanf, scanf, e funcoes irmas) retorna a quantidade de items que ele conseguiu ler e
          // colocar nas variaveis que voce solicitou, o formato suportado pelo fscanf eh o mesmo de suas funcoes irmas
          // por exemplo,
         
          //                "%s %d %c\n", stringVar, &inteiroVar, &caractereVar   
         
          // caso consiga ler os valores para os tres itens, vai retornar 3, caso tenha erro na leitura eh retornado 0,
          // uma leitura mais aprofundada sobre pode ser achada em http://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html
          // um exemplo pratico dessa logica eh o while abaixo, que vai rodar enquanto o fscanf consiga ler o arquivo,
         
          //                                            %99[^\n]\n
         
          // significa "leia ate que receba '\n' ou ate 99 caracteres (a posicao posterior a essa vai receber um '\0'),
          // nao importa o caractere (caso fosse %s ele leria ate ter um espaço ou TAB por exemplo), o \n do final eh descartado nesse caso."
         
          while (fscanf(arquivoLeitura, "%99[^\n]\n", linha) == 1) {
              printf("lido fscanf: %s\n", linha);
          }
         
         */

        // colocando so de exemplo, caso queira checar se o arquivo chegou ao final (EOF, End Of File)
        if (feof(arquivoLeitura)) {
            printf("Recebemos o indicador de End Of File desse arquivo, logo chegamos ao fim dele!\n");
        }

        // um arquivo possui sua posicao interna atual, caso voce queira escrever ou reler algo do começo, voce deve resetar
        // essa posicao para a inicial, o rewind eh uma das formas de fazer isso (pode usar o fseek por exemplo para a mesma coisa)
        rewind(arquivoLeitura); // colocado como exemplo
        fgets(linha, 100, arquivoLeitura);

        // voce, assim como quando aloca dinamicamente um dado e depois deve liberar o recurso
        // alocado, tambem deve fazer o mesmo para um arquivo aberto, para notificar o sistema
        // operacional que voce nao esta mais utilizando o arquivo
        fclose(arquivoLeitura);

        // equivalente ao printf, tambem existe o stderr, que eh a saida de erro, mas nao precisamos dele no momento
        fprintf(stdout, "\nprimeira linha: %s", linha);

        // exemplo de append (adicionar no final e nao sobrescrever o arquivo)
        FILE *arquivoAdicionaNoFinal = fopen(caminhoArquivoExemplo, "a"); // abre o arquivo, com sua posicao no final deste

        fputs("// Novo final\n", arquivoAdicionaNoFinal); // sempre adicionando essa linha, por fins de exemplo do fputs
        printf("Rode o programa novamente para ter uma surpresa :)\n");

        fclose(arquivoAdicionaNoFinal);
    }

    // vale lembrar, existem diversas outras funcoes que lidam com arquivos, como por exemplo, fread e fwrite (leitura e escrita
    // de buffers, array de armazenamento de dados, por exemplo caracteres, em arquivos), ferror (para erros), dentre outros
    // as paginas man do linux sao suas amigas, se pesquisar por "man page <funcao que quer mais informacao>" chances sao que voce
    // vai encontrar uma explicação, tambem pode buscar por exemplos

    return 0;
}

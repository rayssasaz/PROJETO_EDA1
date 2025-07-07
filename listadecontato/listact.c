#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "listact.h"
#include <string.h>
#include <ctype.h>

struct lista{
    CLIENTE dados;
    struct lista *prox;
};

typedef struct lista Contato;

LISTA *criaLista(){
    LISTA *li;
    li = (LISTA*) malloc(sizeof(LISTA));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void abortaPrograma(){
    printf("Erro! Lista não alocada.\n");
    printf("Programa será encerrado...\n\n");
    system("pause");
    exit(1);
}

int tamanhoLista(LISTA *li){
    if(li == NULL){
        abortaPrograma();
    }
    int acum = 0;
    Contato *no = *li;
    while(no != NULL){
        acum++;
        no = no->prox;
    }
    return acum;
}



int insereOrdenado(LISTA *li, CLIENTE cli){
    if(li == NULL){
        abortaPrograma();
    }
    Contato *no = (Contato*) malloc(sizeof(Contato));
    if(no == NULL){
        return 0;
    }
    no->dados = cli;
    if((*li) == NULL){
        no->prox = (*li);
        *li = no;
        return cli.codigo;
    }
    else{
        Contato *ant, *atual = *li;
        while(atual != NULL && atual->dados.codigo < cli.codigo){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){       // se estiver na primeira posição
            no->prox = (*li);
            *li = no;
        } else{         //insere em qualquer posição
            no->prox = ant->prox;
            ant->prox = no;
        }
        return cli.codigo;
    }
}

void verificaDuplicidade(LISTA *li){
    int codigo, resp, x;
    printf("\nCódigo: ");
    scanf("%d", &codigo);

    if(li == NULL){
        abortaPrograma();
    }
    // verifica se o código existe dentro da lista
    Contato *no = *li;
    while(no != NULL && no->dados.codigo != codigo){
        no = no->prox;
    }
    if(no == NULL){     // se o código não for encontrado, coletar dados e inserir
        x = insereOrdenado(li, coletaDados(codigo)); //codigo é passado como parametro em coletaDados, para então ser inserido na estrutura
        if(x){
            printf("\nContato %d inserido com sucesso!\n", x);
        }else{
            printf("\nNao foi possivel inserir o contato.");
        }
        return;
    }
    printf("ERRO! Esse código ja existe.\n");
    printf("1 - Cancelar\n2 - Inserir outro código\n");
    scanf("%d", &resp);
    system("cls");
    if(resp == 1){
        return;     // retorna ao menu
    }
    else{
        verificaDuplicidade(li);    //reinicia o procedimento
    }
}


struct cliente coletaDados(codigo){
    struct cliente cli;

    cli.codigo = codigo;
    getchar();

    printf("\nNome: ");
    fgets(cli.nome, 50, stdin);
    cli.nome[strlen(cli.nome) - 1] = '\0';

    printf("\nEmpresa: ");
    fgets(cli.empresa, 30, stdin);
    cli.empresa[strlen(cli.empresa) - 1] = '\0';

    printf("\nDepartamento: ");
    fgets(cli.depto, 20, stdin);
    cli.depto[strlen(cli.depto) - 1] = '\0';

    printf("\nTelefone: ");
    fgets(cli.telefone, 15, stdin);
    cli.telefone[strlen(cli.telefone) - 1] = '\0';

    printf("\nCelular: ");
    fgets(cli.celular, 15, stdin);
    cli.celular[strlen(cli.celular) - 1] = '\0';

    printf("\nEmail: ");
    fgets(cli.email, 40, stdin);
    cli.email[strlen(cli.email) - 1] = '\0';

    system("cls");
    return cli;  // retorna uma estrutura preenchida para insereOrdenado
};

void relatorioGeral(LISTA *li){
    Contato *no = *li;
    printf("\n\t\tRELATÓRIO GERAL DE CONTATOS\n\n");
    while(no != NULL){
        printf("===================================================");
        printf("\nCódigo:........%d\n", no->dados.codigo);
        printf("Nome:..........%s\n", no->dados.nome);
        printf("Empresa:.......%s\n", no->dados.empresa);
        printf("Departamento:..%s\n", no->dados.depto);
        printf("Telefone:......%s\n", no->dados.telefone);
        printf("Celular:.......%s\n", no->dados.celular);
        printf("Email:.........%s\n", no->dados.email);
        printf("===================================================");
        printf("\n\n");

        no = no->prox;
    }
    printf("\t%d contatos salvos.\n", tamanhoLista(li));
    system("pause");
}

int buscaCodigo(LISTA *li, int codigo, CLIENTE *consulta){
    if(li == NULL){
        abortaPrograma();
    }
    Contato *no = *li;
    while(no != NULL && no->dados.codigo != codigo){
        no = no->prox;
    }
    if(no == NULL){
        return 0;       //retorna 0 caso o código não tenha sido encontrado
    }
    *consulta = no->dados; //insere os dados no nó na estrutura de consulta
    return 1;
}

void buscaNome(LISTA *li, char *nome){
    int sinalizador = 0;        // utilizado para sinalizar caso um nó tenha o nome procurado
    char nome_busca[50];
    char nome_compara[50];

    if(li == NULL){
        abortaPrograma();
    }
    Contato *no = *li;

    while(no != NULL){
        strcpy(nome_busca, strupr(nome));
        strcpy(nome_compara, no->dados.nome);
        strupr(nome_compara);       // separar, para não modificar no->dados.nome
        if(strstr(nome_compara, nome_busca)){
            printf("===================================================");
            printf("\nCódigo:........%d\n", no->dados.codigo);
            printf("Nome:..........%s\n", no->dados.nome);
            printf("Empresa:.......%s\n", no->dados.empresa);
            printf("Departamento:..%s\n", no->dados.depto);
            printf("Telefone:......%s\n", no->dados.telefone);
            printf("Celular:.......%s\n", no->dados.celular);
            printf("Email:.........%s\n", no->dados.email);
            printf("===================================================");
            printf("\n\n");
            sinalizador++;  // caso nao haja nenhum contato com o nome buscado, sinalizador == 0
        }
        no = no->prox;
    }
    if(no == NULL && sinalizador == 0){
        printf("Nome não encontrado.\n");
    }
    system("pause");
    system("cls");
}

int removeOrdenado(LISTA *li, int codigo){
    int resp;
    CLIENTE consulta;

    int cod;
    if(li == NULL){
        abortaPrograma();
    }
    Contato *ant, *no = *li;
    while(no != NULL && no->dados.codigo < codigo){
        ant = no;
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    if(no == *li){
        *li = no->prox;
    }else{
        ant->prox = no->prox;
    }
    cod = no->dados.codigo;
    free(no);
    return cod;
}

void editaContato(LISTA *li, int codigo){
    int resp;
    CLIENTE consulta;
    int x = buscaCodigo(li, codigo, &consulta);
    if(x){
        printf("\n\t\tRELATÓRIO\n\n");              //exibe o contato que se deseja editar
        printf("===================================================");
        printf("\nCódigo:........%d\n", consulta.codigo);
        printf("Nome:..........%s\n", consulta.nome);
        printf("Empresa:.......%s\n", consulta.empresa);
        printf("Departamento:..%s\n", consulta.depto);
        printf("Telefone:......%s\n", consulta.telefone);
        printf("Celular:.......%s\n", consulta.celular);
        printf("Email:.........%s\n", consulta.email);
        printf("===================================================");
        printf("\n\n");

        printf("\nDeseja alterar os dados do contato %d?\n 1 - Alterar \n 2 - Cancelar\n", codigo);
        scanf("%d", &resp);
        printf("\n\n");
    }else{
        printf("Código não encontrado.\n");
        system("pause");
        system("cls");
        return;
    }

    if(resp == 2){
        system("cls");
        return;
    }else{                  // a inserção ocorre com os dados ainda sendo exibidos
        x = removeOrdenado(li, codigo); // remove o contato antigo
        if(x){
            int y = insereOrdenado(li, coletaDados(codigo));    //insere um novo contato com o mesmo código
            if(y){
                printf("\nContato editado com sucesso!\n");
            }else{
                printf("\nErro ao atualizar dados.\n");
            }
        }
    }
    system("pause");
    system("cls");
}

int salvaDados(LISTA *li, char *arquivo){
    if(li == NULL){
        abortaPrograma();
    }
    FILE *f = fopen(arquivo, "wb"); //se o arquivo ja existir, será sobrescrito
    if(f == NULL){
        return 0;
    }
    Contato *no = *li;
    //percorre a lista e escreve cada dado da struct cliente
    while(no != NULL){
        fwrite(&(no->dados), sizeof(CLIENTE), 1, f);
        no = no->prox;
    }
    fclose(f);
    return 1;
}

int carregarArquivo(LISTA *li, char *arquivo){
    if(li == NULL){
        abortaPrograma();
    }
    // se existir, lê os contatos salvos e insere na lista.
    // se não existir, a lista continuará vazia (primeira execução).
    FILE *f = fopen(arquivo, "rb");
    if(f == NULL){
        return 0;
    }
    CLIENTE cli;
    //le uma struct gravada por vez e insere na lista
    while(fread(&cli, sizeof(CLIENTE), 1, f) == 1){ //termina em EOF ou algum erro - fread() retorna 1 quando le com sucesso
        insereOrdenado(li, cli);
    }
    fclose(f);
    return 1;
}

void liberaLista(LISTA *li) {
    if (li != NULL){
        Contato *no;
        while ((*li) != NULL) {
        no = *li;
        *li = (*li)->prox;
        free(no);
        }
    }
    free(li);
}







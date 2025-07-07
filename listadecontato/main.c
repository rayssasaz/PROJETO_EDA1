#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "listact.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");


    LISTA *li = NULL;
    if((li = criaLista()) == NULL){
        abortaPrograma();
    }

    carregarArquivo(li, "arquivo.txt"); // tenta abrir o arquivo, caso exista, lendo os contatos e inserindo na lista

    int x, op, codigo, resp;
    char nome[50];
    CLIENTE consulta;

    printf("\n\n\n");
    printf("\t\t\t\tLISTA DE CONTATOS\n\n");
    printf("\t\t%d Contatos Salvos.\n", tamanhoLista(li));

    printf("\n\n\n\n\n\t\t");
    system("pause");
    system("cls");

    //menu
    while(1){

        printf("\n");

        printf("\t1 - Inserir um contato \n");
        printf("\t2 - Relatório geral de contatos\n");
        printf("\t3 - Buscar contato por código\n");
        printf("\t4 - Buscar contato por nome\n");
        printf("\t5 - Editar contato\n");
        printf("\t6 - Remover contato\n");
        printf("\t7 - Salvar e sair\n");

        scanf("%d", &op);
        system("cls");

        switch(op){
            case 1:             //INSERIR CONTATO
                verificaDuplicidade(li);
                //as funções para coletar e inserir os dados são chamadas dentro de verificaDuplicidade, após verificar o código.
                system("cls");
                break;
            case 2:            // RELATÓRIO GERAL
                relatorioGeral(li);
                system("cls");
                break;
            case 3:            // RELATÓRIO INDIVIDUAL POR CÓDIGO
                printf("\nDigite o código: \n");
                scanf("%d", &codigo);

                system("cls");

                x = buscaCodigo(li, codigo, &consulta);
                if(x){
                    printf("\n\t\tRELATÓRIO\n\n");
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
                }else{
                    printf("Código não encontrado.\n");
                }
                system("pause");
                system("cls");
                break;
            case 4:             // RELATÓRIO POR NOME
                printf("\nDigite o nome: \n");
                getchar();
                fgets(nome, 50, stdin);
                nome[strlen(nome) - 1] = '\0';
                printf("\n");

                buscaNome(li, nome); // pecorre o nó buscando o nome inserido e exibindo os dados.

                break;
            case 5:             // EDITAR CONTATO
                printf("\nCódigo do contato a ser editado: ");
                scanf("%d", &codigo);
                system("cls");
                editaContato(li, codigo);
                break;
            case 6:             //REMOVER CONTATO
                printf("\nCódigo do contato a ser removido: ");
                scanf("%d", &codigo);
                x = buscaCodigo(li, codigo, &consulta);
                if(x){      // busca e exibe o contato antes de ser removido
                    printf("\n\t\tRELATÓRIO\n\n");
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

                    printf("\nDeseja remover o contato %d?\n 1 - Remover \n 2 - Cancelar\n", codigo);
                    scanf("%d", &resp);
                    printf("\n\n");
                }else{
                    printf("Código não encontrado.\n");
                    system("pause");
                    system("cls");
                    return;
                }
                if(resp == 2){  //cancela a remoção
                    system("cls");
                    break;
                }
                x = removeOrdenado(li, codigo);
                if(x){
                    printf("\n\nContato %d removido com sucesso!\n", x);
                }else{
                    printf("\n\nNao foi possivel remover o contato.\n");
                }
                system("pause");
                system("cls");
                break;

            case 7:             //ENCERRAR E SALVAR
                if(salvaDados(li, "arquivo.txt")){
                    printf("\nSalvo. Encerrando o programa...\n");
                }else{
                    printf("\nErro ao salvar os contatos.\n");
                }

                liberaLista(li);        //apos salvar, liberar a memoria alocada
                exit(0);
                break;
            default:
                printf("\nErro! Opcao invalida!\n");
                system("pause");
                system("cls");
                break;
        }
    }
    return 0;
}

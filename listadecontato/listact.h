typedef struct cliente{
    int codigo;
    char nome[50];
    char empresa[30];
    char depto[20];
    char telefone[15];
    char celular[15];
    char email[40];
}CLIENTE;

typedef struct lista* LISTA;

LISTA *criaLista();

void abortaPrograma();

int tamanhoLista(LISTA *li);

int insereOrdenado(LISTA *li, CLIENTE cli);

struct cliente coletaDados(codigo);

void relatorioGeral(LISTA *li);

int buscaCodigo(LISTA *li, int codigo, CLIENTE *consulta);

void buscaNome(LISTA *li, char *nome);

int removeOrdenado(LISTA *li, int codigo);

void editaContato(LISTA *li, int codigo);

void verificaDuplicidade(LISTA *li);

int salvaDados(LISTA *li, char *arquivo);

int carregarArquivo(LISTA *li, char *arquivo);

void liberaLista(LISTA *li);


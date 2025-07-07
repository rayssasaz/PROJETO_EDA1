
# LISTA DE CONTATOS

O projeto consistiu, basicamente, na elaboração de um programa que fosse capaz de
inserir, controlar e manipular uma lista de contatos, baseando-se no código da estrutura de
dados do tipo Lista Dinâmica Encadeada, estudado em sala de aula.

O aplicativo deveria ser capaz de salvar e recuperar os dados gerados entre execuções
anteriores e atuais, bem como possibilitar a inserção de novos clientes, remoção e edição dos
dados de clientes já armazenados, e exibição dos dados por meio de relatórios gerais ou
individuais.

Além disso, o programa deveria verificar a duplicidade de códigos inseridos,
impedindo que haja contatos com códigos iguais, funcionalidade semelhante às chaves
primárias em bancos de dados. Por fim, era necessário que todos os dados inseridos fossem
devidamente gravados num arquivo binário, para posterior recuperação dos mesmos numa
nova seção de trabalho.
## 👩‍💻 Stack utilizada

- Linguagem C



## 🛠 Funcionalidades

- **Encapsulamento**: A lista foi implementada em um TAD composto por três arquivos: o programa principal (main.c), a biblioteca com o tipo de dado armazenado na lista e protótipo das funções (listact.h), e a implementação das funções, bem como a lista encapsulada está presente no arquivo listact.c.

- **Armazenamento dos dados**: Criou-se uma estrutura cliente, contendo os campos código, nome, empresa, departamento, telefone, celular e email. Esses dados são inseridos por meio de funções que permitiam a entrada de dados fornecida pelo usuário, através da função coletaDados, que retorna uma estrutura preenchida que, posteriormente, é inserida pela função insereOrdenado.

- **Verificação de Duplicidade**: A função verificaDuplicidade é chamada logo após o usuário escolher, no menu, a opção 1 (Inserir dados). Ela solicita que o usuário digite o código que ele pretende inserir no contato. A partir daí, é feita uma busca, e caso o código já exista, o usuário é solicitado a digitar outro código ou cancelar a operação. Caso o código seja válido, dentro do mesmo procedimento a função insereOrdenado é chamada, passando a lista alocada e coletaDados como argumento (esta retornará uma estrutura preenchida) e, então, o novo nó (ou contato) é inserido na lista

- **Listagem de Clientes**: A segunda opção do menu initerrupto aciona a função de listagem total de clientes em tela, na forma de relatório, com todos os dados dos clientes armazenados na Lista Dinâmica. A função relatorioGeral basicamente percorre todos os nós, imprimindo os dados de cada elemento da lista. 

- **Relatórios Individuais**: Exibe os dados de clientes específicos. Informa-se o código de identificação, e então a aplicação exibe todos os dados daquele cliente para consulta. A função buscaCodigo percorre a lista, até encontrar o nó cujo o código equivale ao inserido pelo usuário. Assim, os dados desse nó são armazenados numa estrutura de consulta, e, posteriormente, são exibidos no programa principal.

- **Busca por nome**: De forma similar ao anterior, na quarta opção do menu, é possível fazer uma busca por nome dos clientes. Contudo, nessa função é exibido o relatório de todos aqueles que estiverem o mesmo nome buscado. Na função buscaNome é feito, primeiramente, uma conversão do nome que se busca, numa variável de consulta, para caracteres maiúsculos. Isso porque a Linguagem C é Case sensitive e diferencia os caracteres maiúsculos dos minúsculos. Feito isso, a lista é percorrida, comparando os nomes, exibindo-os e sinalizando as coincidências que, caso seja igual a 0, significa que o nome não foi encontrado. 

- **Edição de Contatos**: Possibilita que o usuário edite os dados de um determinado contato, escolhido pelo código identificador. Caso seja enviado um código inexistente, uma mensagem de erro é exibida. Caso o código exista, uma busca é feita e os dados do contato são exibidos. O usuário é solicitado a confirmar se deseja alterar os dados. Caso confirme, ele será capaz de alterar todos os dados, exceto pelo código. A função editaContato funciona removendo o contato anterior e inserindo novamente um novo contato, com o código anterior e novos dados coletados.

- **Remoção de Contato**: Executa uma busca pelo código de identificação do cliente armazenado na lista dinâmica, e em seguida exibirá os dados do cliente em tela. Na sequência, exibe uma mensagem solicitando a confirmação de exclusão. Em caso afirmativo, remove-o da Lista; em caso negativo nada realiza. 

- **Gravação das informações**: Antes do encerramento do aplicativo, é executada a rotina para a gravação de todos os dados que estão presentes na Lista Dinâmica para um arquivo binário, de forma que não há perda de informações. Posteriormente, a memória alocada para a lista é liberada, e o programa, encerrado. A função salvaDados percorre a lista e escreve cada dado da struct cliente, salvado-os no arquivo que, caso já exista, será sobrescrito. 

## 🚀 Sobre mim
Sou estudante de Engenharia de Computação no Instituto Federal de Ciência e Tecnologia de São Paulo - IFSP. Desenvolvi este projeto ao cursar a disciplina Estrutura de Dados 1 no terceiro semestre da minha graduação, atigindo os objetivos propostos em sala de aula. 

Para mim, foi gratificante conhecer e trabalhar com a linguagem C. Devo dizer, inclusive, que se tornou uma das minhas linguagens preferidas de programação, embora eu ainda tenha muito a explorar no vasto universo dessa linguagem magnífica.

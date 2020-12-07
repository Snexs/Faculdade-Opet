#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000

#pragma region Struct

typedef struct SystemLogin{
    char login[60];
	char senha[32];
    char adminUser[60];
} Usuario_st;

typedef struct CadastroClientes{
    int id;
    char nome[60];
	long long int cpf;
    char email[60];
    char endereco[30];
    int numero;
    char complemento[20];
    char cidade_estado[20];
    long long int telefone;
    char senha[32];
} Register_st;

typedef struct CadastroAdmin{
    int id;
    char nome[60];
	long long int cpf;
    char email[40];
    char endereco[30];
    int numero;
    char complemento[15];
    char cidade_estado[12];
    long long int telefone;
    char senha[32];
} RegisterAdmin_st;

int opcao,indiceUsuario = 1,indiceAdmin = 1,indiceCadastroUsuario = 0,indiceCadastroAdmin = 0;

Register_st cadastrar[MAX];
Usuario_st usuario[MAX];
RegisterAdmin_st cadastrarAdmin[MAX];

#pragma endregion

#pragma region Funcao Login
// Esta funcao tem como objetivo validar e efetuar o login
// Dos usuarios baseado nos dados digitados
void login()
{
    printf("------------ Pagina de Login CTA Systems ------------\n");
    MenuOpcoesClientes();

    char *user_entry[60],*senha_entry[32];
	int tentativas = 0,responseLogin = 0,responseSenha = 0;
    do {
        printf("Login: ");
        scanf("%s", &user_entry);
        printf("Senha: ");
        scanf("%s", &senha_entry);
        printf("-----------------------------------------------------\n");
        
        responseLogin = ValidarLogin(user_entry);
        responseSenha = ValidarSenha(senha_entry);

        //Processo de login
        if (!strcmp(user_entry, usuario[responseLogin].login) && !strcmp(senha_entry, usuario[responseSenha].senha)) {
            printf("Bem vindo %s\n", usuario[responseLogin].login);
            return dashboard();
        }else if (!strcmp(user_entry, usuario[responseLogin].adminUser) && !strcmp(senha_entry, usuario[responseSenha].senha)){
            printf("Bem vindo %s\n", usuario[responseLogin].adminUser);
            return dashboardAdmin();
        }
        //Fim processo de login

        //Validar Login
        if (responseLogin == 0 || responseSenha == 0)
        {
            printf("Usuario ou Senha Invalidos!\n");
            tentativas++;
        }
        //Fim validar login
    } while (tentativas < 3);
    printf("Numero maximo de tentativas alcancado!\n");
    main();
}

#pragma endregion

#pragma region Funcao Validar Login
// Esta funcao tem como objetivo buscar o login 
// Inserido com o login cadastrado no banco de dados
int ValidarLogin(char *user_entry){
int i;
for (i = 1; i < MAX; i++){
    if (!strcmp(user_entry,usuario[i].login))
        return i;
    else if (!strcmp(user_entry,usuario[i].adminUser))
        return i;
    
}
if (i >= MAX)
    return 0;
}

#pragma endregion

#pragma region Funcao Validar Senha
// Esta funcao tem como objetivo buscar a senha 
// Inserida com a senha cadastrada no banco de dados
int ValidarSenha(char *senha_entry){
int i;
for (i = 1; i < MAX; i++){
    if (!strcmp(senha_entry,usuario[i].senha))
        return i;
}
if (i >= MAX)
    return 0;
}


#pragma endregion

#pragma region Funcao Incluir
// Esta funcao tem como objetivo cadastrar os usuarios no banco de dados, como Admin e Clientes
void IncluirUsuarios(int indiceUsuario,char *nome,long long int cpf,char *email,char *endereco,int numero,char *complemento,char *cidade_estado,long long int telefone,char *senha,int verifcadorUsuario){
    
    // Se verifcadorUsuario == 0 é considerado Usuario se verifcadorUsuario == 1 é considerado Admin
    if (verifcadorUsuario == 1)
    {
        cadastrarAdmin[indiceUsuario].id = indiceAdmin;
        strcpy(cadastrarAdmin[indiceUsuario].nome, nome);
        cadastrarAdmin[indiceUsuario].cpf = cpf;
        strcpy(cadastrarAdmin[indiceUsuario].email, email);
        strcpy(cadastrarAdmin[indiceUsuario].endereco, endereco);
        cadastrarAdmin[indiceUsuario].numero = numero;
        strcpy(cadastrarAdmin[indiceUsuario].complemento, complemento);
        strcpy(cadastrarAdmin[indiceUsuario].cidade_estado, cidade_estado);
        cadastrarAdmin[indiceUsuario].telefone = telefone;
        strcpy(cadastrarAdmin[indiceUsuario].senha, senha);
        printf("Admin cadastrado com sucesso!\n");
        indiceAdmin++;
    }else{
        cadastrar[indiceUsuario].id = indiceUsuario;
        strcpy(cadastrar[indiceUsuario].nome, nome);
        cadastrar[indiceUsuario].cpf = cpf;
        strcpy(cadastrar[indiceUsuario].email, email);
        strcpy(cadastrar[indiceUsuario].endereco, endereco);
        cadastrar[indiceUsuario].numero = numero;
        strcpy(cadastrar[indiceUsuario].complemento, complemento);
        strcpy(cadastrar[indiceUsuario].cidade_estado, cidade_estado);
        cadastrar[indiceUsuario].telefone = telefone;
        strcpy(cadastrar[indiceUsuario].senha, senha);
        printf("Cliente cadastrado com sucesso!\n");
        RegistrarLoginUsuario();
        indiceUsuario++;
    }    
}

#pragma endregion

#pragma region Funcao Atualizar
// Esta funcao tem como objetivo atualizar os dados antigos pelos dados novos
void AtualizarDados(int id,char *nome,long long int cpf,char *email,char *endereco,int numero,char *complemento,char *cidade_estado,long long int telefone,char *senha){
    strcpy(cadastrar[id].nome, nome);
    cadastrar[id].cpf = cpf;
    strcpy(cadastrar[id].email, email);
    strcpy(cadastrar[id].endereco, endereco);
    cadastrar[id].numero = numero;
    strcpy(cadastrar[id].complemento, complemento);
    strcpy(cadastrar[id].cidade_estado, cidade_estado);
    cadastrar[id].telefone = telefone;
    strcpy(cadastrar[id].senha, senha);
    printf("Atualizacao realizada com sucesso!\n");    
}

#pragma endregion

#pragma region Funcao Excluir
// Esta funcao tem como objetivo excluir o cliente 
// Recebendo um ID
void ExcluirCliente(int id){
    char nome[60];
    char endereco[60];
    char complemento[60];
    char Email[60];
    char cidade_uf[60];
    char senha[60];

    strcpy(nome,cadastrar[id].nome);
    strcpy(endereco,cadastrar[id].endereco);
    strcpy(complemento,cadastrar[id].complemento);
    strcpy(Email,cadastrar[id].email);
    strcpy(cidade_uf,cadastrar[id].cidade_estado);
    strcpy(senha,cadastrar[id].senha);

    strcpy(cadastrar[id].nome,"");
    strcpy(cadastrar[id].endereco,"");
    strcpy(cadastrar[id].complemento,"");
    strcpy(cadastrar[id].email,"");
    strcpy(cadastrar[id].cidade_estado,"");
    strcpy(cadastrar[id].senha,"");
    cadastrar[id].id = id;
    cadastrar[id].telefone = 0;
    cadastrar[id].numero = 0;
    cadastrar[id].cpf = 0;
    printf("Exclusao realizada com sucesso: %d , %s\n",id,nome);
}


#pragma endregion

#pragma region Funcao Listar Cliente
// Esta funcao tem como objetivo listar todos os cadastros do banco de dados
// Como clientes e admin's
void ListarClientes(){
    ListarAdmin();
    for (int i = 1; i < MAX; i++)
        if (!cadastrar[i].id == 0)
            printf("Cliente: %d , %s , %lld , %s , %s , %d , %s ,%lld\n",cadastrar[i].id,
            cadastrar[i].nome,cadastrar[i].cpf,cadastrar[i].email,cadastrar[i].endereco,
            cadastrar[i].numero,cadastrar[i].cidade_estado,cadastrar[i].telefone);        
        
}

// Esta funcao tem como objetivo listar os admin's cadastrados
void ListarAdmin(){
    for (int i = 1; i < MAX; i++)
        if (!cadastrarAdmin[i].id == 0)
            printf("Admin: %d , %s , %lld , %s , %s , %d , %s ,%lld\n",cadastrarAdmin[i].id,
            cadastrarAdmin[i].nome,cadastrarAdmin[i].cpf,cadastrarAdmin[i].email,cadastrarAdmin[i].endereco,
            cadastrarAdmin[i].numero,cadastrarAdmin[i].cidade_estado,cadastrarAdmin[i].telefone);
}

#pragma endregion

#pragma region Banco de dados de clientes
// Esta funcao tem como objetivo inserir clientes e admins no banco de dados
void InsereClientesBancoDeDados(){
    InsereAdmin();
    for (indiceUsuario = 1; indiceUsuario < 6; indiceUsuario++)
        IncluirUsuarios(indiceUsuario,"teste",12312312312,"teste@teste.com","rua teste",indiceUsuario,"Casa","CWB-PR",41123451234,"senha",0);
    
    RegistrarLoginAdmin();
}

void InsereAdmin(){
    for (int indiceUsuario = 6; indiceUsuario < 9; indiceUsuario++)
        IncluirUsuarios(indiceUsuario,"testeAdmin",98798798712,"admin@teste.com","rua admin",indiceAdmin,"Sobrado","Matinhos-PR",41987651234,"senhaAdmin",1);
}

#pragma endregion

#pragma region Pagina Atualizar Dados
// Id -> Id
// Nome -> Nome
// Email -> Email
// Endereco -> Endereco
// Numero -> Numero
// Complemento -> Complemento
// Cidade_Uf -> Cidade_Estado
// Telefone -> Telefone
// Senha -> Senha

// Este metodo tem como objetivo exibir o menu e chamar a funcao
// Atualizar dados que ao receber os dados novos ele substitui
// Os dados antigos pelos novos no Banco de Dados
void AtualizarDadosPage(){

//Variaveis Locais
char *nome[60],*endereco[30],*complemento[20],*email[60],*cidade_uf[20],*senha[32];
long long int cpf = 0,telefone = 0;
int id = 0,numero = 0;
//Fim Variaveis Locais

    printf("----------- Pagina de Alteracao De Dados ------------\n");
    MenuOpcoesClientes();

    printf("Insira o Id para alterar:");
    scanf("%d",&id);    
    printf("-----------------------------------------------------\n");
    printf("Nome: ");
    scanf(" %[^\n]s",&nome);
    printf("CPF: ");
    scanf("%lld", &cpf);
    printf("Email: ");
    scanf(" %[^\n]s", &email);
    printf("Endereco: ");
    scanf(" %[^\n]s", &endereco);
    printf("Numero: ");
    scanf("%d", &numero);
    printf("Complemento: ");
    scanf(" %[^\n]s", &complemento);
    printf("Cidade-UF: ");
    scanf(" %[^\n]s", &cidade_uf);
    printf("Telefone DD123456789: ");
    scanf("%lld", &telefone);
    printf("Senha: ");
    scanf(" %[^\n]s", &senha);

    printf("---------------------------------------------------\n");
    printf("DE: %d , %s , %lld , %s , %s , %d , %s , %s , %lld , %s\n",id,cadastrar[id].nome,cadastrar[id].cpf,cadastrar[id].email,cadastrar[id].endereco,cadastrar[id].numero,cadastrar[id].complemento,cadastrar[id].cidade_estado,cadastrar[id].telefone,cadastrar[id].senha); 
    printf("POR: %s , %lld , %s , %s , %d , %s , %s , %lld , %s\n",nome,cpf,email,endereco,numero,complemento,cidade_uf,telefone,senha);
    printf("---------------------------------------------------\n");
    opcao = 0;
    printf("Para cancelar tecle: 0\nPara confirmar tecle: 1\n");
    scanf("%d", &opcao);

    if (opcao == 0)
    {
        printf("Atualizacao cancelada com sucesso!\n");
        cadastroCliente();
    }else
    {
        AtualizarDados(id,nome,cpf,email,endereco,numero,complemento,cidade_uf,telefone,senha);
        RegistrarLoginUsuario();
        printf("Atualizacao efetuada com sucesso!\n");
        main();
    }
    main();
}

#pragma endregion

#pragma region Pagina Excluir Cliente
// Este metodo tem como objetivo exibir o menu e chamar a funcao
// Excluir cliente que ao receber o ID do usuario ela remove o usuario ID
// Do banco de Dados
// Id -> ID
void ExcluirClientePage(){

//Variaveis Locais
int id = 0;
//Fim Variaveis Locais

printf("---------- Pagina de Exclusao De Clientes -----------\n");
MenuOpcoesAdmin();

printf("Insira o Id para ser excluir:");
scanf("%d",&id);    
printf("-----------------------------------------------------\n");
ExcluirCliente(id);
main();
}

#pragma endregion

#pragma region Funcao Registrar Login Cliente
// Nesta funcao o objetivo é que toda vez que for cadastrado um cliente(usuario)
// O sistema automaticamente gera o login dele baseado nos dados:
// Email -> Login
// Senha -> Senha
void RegistrarLoginUsuario(){  
    strcpy(usuario[indiceCadastroUsuario].login,cadastrar[indiceUsuario].email);
    strcpy(usuario[indiceCadastroUsuario].senha,cadastrar[indiceUsuario].senha);
    indiceCadastroUsuario++;
}

#pragma endregion

#pragma region Funcao Registrar Login Admin
// Nesta funcao o objetivo é que toda vez que for cadastrado um admin
// O sistema automaticamente gera o login dele baseado nos dados:
// Email -> adminUser
// Senha -> Senha
void RegistrarLoginAdmin(){
    for (int i = 1; i < MAX; i++)
        if (!cadastrarAdmin[i].id == 0){
            strcpy(usuario[indiceCadastroAdmin].adminUser,cadastrarAdmin[indiceUsuario].email);
            strcpy(usuario[indiceCadastroAdmin].senha,cadastrarAdmin[indiceUsuario].senha);
            indiceCadastroAdmin++;
        }
}

#pragma endregion

#pragma region Pagina Compra de Voo

void compraVooPage(){

printf("--------- Pagina De Compra De Voo CTA Airlines ---------\n");
MenuOpcoesClientes();

printf("Voos Disponiveis:\n");
printf("010 - Curitiba-PR -> Sao Paulo-SP\n");
printf("160 - Rio de Janeiro-RJ -> Manaus-AM\n");
printf("190 - Sao Paulo-SP -> Campo Grande-MS\n");
printf("255 - Curitiba-PR -> Brasilia-DF\n");
printf("327 - Sao Paulo -> Porto Alegre-RS\n");
printf("476 - Rio Branco-AC -> Rio de Janeiro-RJ\n");
printf("578 - Porto Alegre-RS -> Assuncao-PY\n");
printf("667 - Florianopolis-SC -> Goiania-GO\n");
printf("777 - Sao Paulo-SP -> Santiago-CL\n");
printf("--------------------------------------------------------\n");
comprarVoo();
pagamento();

}

#pragma endregion

#pragma region Pagina Inicial

void dashboard()
{
    printf("-------------------------------------------------------\n");
    printf("--------- Pagina Inicial Sistema CTA Airlines ---------\n");
    MenuOpcoesClientes();
    listaDeVoos();
    printf("------------------------------------------------------\n");

}

#pragma endregion

#pragma region Funcao Lista de Voos

void listaDeVoos()
{
    int opcao;
    printf("--------------------------------------------------------\n");
    printf("Voos Ativos:\n");
    printf("001 - Curitiba-PR -> Sao Paulo-SP\n");
    printf("121 - Rio de Janeiro-RJ -> Natal-RN\n");
    printf("125 - Sao Paulo-SP -> Buenos Aires-AR\n");
    printf("323 - Curitiba-PR -> Foz do Iguacu-PR\n");
    printf("412 - Amapa-AP -> Porto Alegre-RS\n");
    printf("586 - Nova York-EUA -> Rio de Janeiro-RJ\n");
    printf("654 - Sao Paulo-SP -> Assuncao-PY\n");
    printf("881 - Brasilia-DF -> Curitiba-PR\n");
    printf("996 - Santiago-CL -> Sao Paulo-SP\n");
    printf("Digite seu codigo de voo: ");
    scanf("%d", &opcao);
    printf("\n--------------------------------------------------------\n");

    switch(opcao)
    {
    case 001:
        printf("\nHorario saida:05:10\nHorario chegada:06:00");
        return 0;
    case 125:
        printf("\nHorario saida:10:00\nHorario chegada:15:15");
        return 0;
    case 323:
        printf("\nHorario saida:08:30\nHorario chegada:10:20");
        return 0;
    case 654:
        printf("\nHorario saida:11:30\nHorario chegada:16:00");
        return 0;
    case 121:
        printf("\nHorario saida:14:30\nHorario chegada:17:00");
        return 0;
    case 996:
        printf("\nHorario saida:18:20\nHorario chegada:21:50");
        return 0;
    case 586:
        printf("\nHorario saida:16:10\nHorario chegada:23:40");
        return 0;
    case 412:
        printf("\nHorario saida:17:30\nHorario chegada:22:50");
        return 0;
    case 881:
        printf("\nHorario saida:09:30\nHorario chegada:16:00");
        return 0;
    default:
        printf("Favor escolher um voo valido!!\n");
    }
}


#pragma endregion

#pragma region Funcao Compra de Voos

void comprarVoo()
{
    char destino[70], horario[5], data[11];

    printf("Destino: \n");
    printf("Favor inserir o destino por completo\n");
    printf("Exemplo: 160 - Rio de Janeiro-RJ -> Natal-RN\n");
    scanf("%s", &destino);

    fflush(stdin);

    printf("Horario de partida: \n");
    gets(horario);

    printf("Data de partida: \n");
    gets(data);

    printf("\nDestino: %s \n", destino);
    printf("Horario de partida: %s\n", horario);
    printf("Data de partida: "); puts(data);
}

#pragma endregion

#pragma region Funcao Pagamento

void pagamento()
{
    char numeroc[32],datav[5],cvv[3];
    int opcao;

    printf("Digite o numero do cartao: \n");
    gets(&numeroc);

    printf("Digite a data de validade: \n");
    gets(datav);

    printf("Digite o cvv: \n");
    scanf("%d", &cvv);

    printf("Digite 1 para confirmar e 0 para cancelar: ");
    scanf("%d", &opcao);

    switch (opcao){
        case 1:
            printf("Compra realizada com sucesso!\n");
            PaginaInicial();
            break;

        case 0:
            exit(0);
            break;
    }
}


#pragma endregion

#pragma region Funcao Compras Realizadas

void comprasRealizadas()
{
    char nomecompra[500]="Cliente Talita Alves, Compra voo 111\n Cliente Ana Nunes: Compra voo 345\n Cliente Jose Farias: Compra voo 976\n Cliente Fernando Morais: Compra voo 342";

    printf("Compras efetuadas: %s",nomecompra);
}

#pragma endregion

#pragma region Funcao Acompanhar Voos

void acompanharVoo()
{
    char nvoo[200]="Em andamento: voo 141\nEm andamento: voo 111\nEm andamento: voo 345\nEm andamento: voo 189\nEm andamento: voo 323";

    printf("Voos: %s",nvoo);
}

#pragma endregion

#pragma region Pagina Inicial Admin

void dashboardAdmin()
{
    printf("------------------------------------------------------\n");
    printf("----- Pagina Administrativa Sistema CTA Airlines -----\n");
    MenuOpcoesAdmin();
    comprasRealizadas();
    printf("------------------------------------------------------\n");
    acompanharVoo();
    printf("------------------------------------------------------\n");
    listaDeVoos();
    printf("------------------------------------------------------\n");
}

#pragma endregion

#pragma region Funcao Cadastro Cliente

void cadastroCliente()
{
// Local Variables
char *nome[60],*endereco[30],*complemento[20],*email[60],*cidade_uf[20],*senha[32];
long long int cpf = 0,telefone = 0;
int numero = 0;
//End Local Variables
    printf("---------- Paginca de Cadastro CTA Systems ----------\n");
    MenuOpcoesClientes();

    printf("Nome: ");
    scanf(" %[^\n]s",&nome);
    printf("CPF: ");
    scanf("%lld", &cpf);
    printf("Email: ");
    scanf(" %[^\n]s", &email);
    printf("Endereco: ");
    scanf(" %[^\n]s", &endereco);
    printf("Numero: ");
    scanf("%d", &numero);
    printf("Complemento: ");
    scanf(" %[^\n]s", &complemento);
    printf("Cidade-UF: ");
    scanf(" %[^\n]s", &cidade_uf);
    printf("Telefone DD123456789: ");
    scanf("%lld", &telefone);
    printf("Senha: ");
    scanf(" %[^\n]s", &senha);
    
    printf("--------------------------------\n");
    printf("Nome: %s,CPF: %lld,E-Mail: %s,Endereco: %s,Numero: %d,Complemento: %s,Cidade-UF: %s,Telefone: %lld,Senha: %s\n",nome,cpf,email,endereco,numero,complemento,cidade_uf,telefone,senha);
    printf("--------------------------------\n");
    
    opcao = 0;
    printf("Para cancelar tecle: 0\nPara confirmar tecle: 1\n");
    scanf("%d", &opcao);

    if (opcao == 0)
    {
        printf("Cadastro cancelado com sucesso!\n");
        cadastroCliente();
    }else
    {
        IncluirUsuarios(indiceUsuario,nome,cpf,email,endereco,numero,complemento,cidade_uf,telefone,senha,0);
        RegistrarLoginUsuario();
        printf("Cadastro efetuado com sucesso!\n");
        PaginaInicial();
    }
}

#pragma endregion

#pragma region Funcao Cadastro Admin

void cadastroAdmin()
{
// Local Variables
char *nome[60],*endereco[30],*complemento[20],*email[60],*cidade_uf[20],*senha[32];
long long int cpf = 0,telefone = 0;
int numero = 0,idFuncionario = 0;
//End Local Variables
    printf("-- Pagina de Cadastro de Administrador CTA Systems --\n");
    MenuOpcoesAdmin();
    
    //Inicio Questionario
    printf("Nome: ");
    scanf(" %[^\n]s",&nome);
    printf("CPF: ");
    scanf("%lld", &cpf);
    printf("Email: ");
    scanf(" %[^\n]s", &email);
    printf("Endereco: ");
    scanf(" %[^\n]s", &endereco);
    printf("Numero: ");
    scanf("%d", &numero);
    printf("Complemento: ");
    scanf(" %[^\n]s", &complemento);
    printf("Cidade-UF: ");
    scanf(" %[^\n]s", &cidade_uf);
    printf("Telefone DD123456789: ");
    scanf("%lld", &telefone);
    printf("Senha: ");
    scanf(" %[^\n]s", &senha);
    //FIM Questionario
    //Inicio Confirmar Dados
    printf("--------------------------------\n");
    printf("Nome: %s,CPF: %lld,E-Mail: %s,Endereco: %s,Numero: %d,Complemento: %s,Cidade-UF: %s,Telefone: %lld,Senha: %s\n",nome,cpf,email,endereco,numero,complemento,cidade_uf,telefone,senha);
    printf("--------------------------------\n");
    //FIM Confirmar Dados
    opcao = 0;
    printf("Para cancelar tecle: 0\nPara confirmar tecle: 1\n");
    scanf("%d", &opcao);

    if (opcao == 0)
    {
        printf("Cadastro cancelado com sucesso!\n");
        cadastroAdmin();
    }else
    {
        IncluirUsuarios(indiceUsuario,nome,cpf,email,endereco,numero,complemento,cidade_uf,telefone,senha,1);
        RegistrarLoginAdmin();
        printf("Cadastro efetuado com sucesso!\n");
        PaginaInicial();
    }
}

#pragma endregion

#pragma region Menu Principal
// Tem como objetivo mostrar a pagina inicial do sistema CTA
void MenuPrincipal()
{
    printf("-----------------------------------------------------\n");
    printf("0 - Fechar o Sistema\n");
    printf("1 - Login\n");
    printf("2 - Cadastrar-se\n");
    scanf("%d",&opcao);
    printf("-----------------------------------------------------\n");

  switch (opcao)
  {
    case 0:
      exit(0);
      break;
    case 1:
      login();
      break;
    case 2:
      cadastroCliente();
      PaginaInicial();
      break;
  default:
    printf("Favor escolher uma opcao valida");
      break;
  }
}

#pragma endregion 

#pragma region Menu Opcoes Clientes

void MenuOpcoesClientes()
{
    printf("-----------------------------------------------------\n");
    printf("0 - Fechar o Sistema\n");
    printf("1 - Deslogar\n");
    printf("2 - Atualizar Dados\n");
    printf("3 - Comprar Voo\n");
    printf("4 - Continuar\n");
    scanf("%d",&opcao);
    printf("-----------------------------------------------------\n");

  switch (opcao)
  {
    case 0:
      exit(0);
      break;
    case 1:
      PaginaInicial();
      break;
    case 2:
      AtualizarDadosPage();
      break;
    case 3:
      compraVooPage();
    case 4:
      break;
  default:
    printf("Favor escolher uma opcao valida");
      break;
  }
}

#pragma endregion 

#pragma region Menu Opcoes Admin

void MenuOpcoesAdmin()
{
    printf("-----------------------------------------------------\n");
    printf("0 - Fechar o Sistema\n");
    printf("1 - Deslogar\n");
    printf("2 - Cadastrar Cliente\n");
    printf("3 - Listar Banco de Dados\n");
    printf("4 - Atualizar Dados\n");
    printf("5 - Excluir Cliente\n");
    printf("6 - Continuar\n");
    scanf("%d",&opcao);
    printf("-----------------------------------------------------\n");

  switch (opcao)
  {
    case 0:
      exit(0);
      break;
    case 1:
      PaginaInicial();
      break;
    case 2:
      cadastroCliente();
      break;
    case 3:
      ListarClientes();
      PaginaInicial();
      break;
    case 4:
      AtualizarDadosPage();
      PaginaInicial();
      break;
    case 5:
      ExcluirClientePage();
      PaginaInicial();
      break;
    case 6:
      break;
  default:
    printf("Favor escolher uma opcao valida");
      break;
  }
}

#pragma endregion

#pragma region Pagina Inicial

void PaginaInicial()
{
printf("-----------------------------------------------------\n");
printf("--------- Bem-Vindo ao Sistema CTA Airlines ---------\n");
MenuPrincipal();
}

#pragma endregion

#pragma region Main

void main()
{
InsereClientesBancoDeDados();
PaginaInicial();
}

#pragma endregion


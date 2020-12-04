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

typedef struct RegisterUser{
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

typedef struct RegisterAdmin{
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

int opcao,contador = 0,contadorAdmin = 0,indiceUsuario = 1,indiceAdmin = 1,indiceCadastroUser = 0,indiceCadastroUserAdmin = 0;

Register_st cadastrar[MAX];
Usuario_st usuario[MAX];
RegisterAdmin_st cadastrarAdmin[MAX];

#pragma endregion

#pragma region Login

int login()
{
    printf("----- Login Page CTA Systems -----\n");
    printf("----------------------------------\n");
    printf("0 - Sair\n");
    printf("1 - Voltar para o menu\n");
    printf("2 - Cadastro\n");
    printf("3 - Logar\n");
    scanf("%d",&opcao);
    printf("----------------------------------\n");

  switch (opcao)
    {
    case 0:
      exit(0);
      break;
  case 1:
      main();
      break;
  case 2:
      cadastroCliente();
      break;
  case 3:
      break;
  default:
    printf("Favor escolher uma opcao valida");
      break;
    }

    char user_entry[32],senha_entry[32];
	int tentativas = 0,i = 0;;
    do {
        printf("Login: ");
        scanf("%s", &user_entry[32]);
        printf("Senha: ");
        scanf("%s", &senha_entry[32]);
        
        //descobre o usuario na lista(struct)
        //debugar o for e o login, pois nao esta funcionando
        for (i = 0; i < MAX; i++){
            printf("Dentro do for %d!\n",i);
            if (!strcmp("", user_entry[32])){
                printf("Nenhum usuário encontrado, abrindo cadastro!\n");
                cadastroCliente();
            }else{
                if (!strcmp(user_entry[32],usuario[i].login)){
                    printf("Dentro do for e do IF USER %d!\n",i);
                    return i;
                }else{
                    if (!strcmp(user_entry[32],usuario[i].adminUser)){
                        printf("Dentro do for do if e do IF ADMIN %d!\n",i);
                        return i;
                    }
                }
            }   
        }
  
        //validacoes login
        if (!strcmp(user_entry[32], usuario[i].login) && !strcmp(senha_entry[32], usuario[i].senha)) {
            printf("Bem vindo %s\n", usuario[i].login);
            return ListClient();
        }else{
            if (!strcmp(user_entry[32], usuario[i].adminUser) && !strcmp(senha_entry[32], usuario[i].senha)) {
            printf("Bem vindo %s\n", usuario[i].adminUser);
            return dashboardAdmin();
            } else {
            printf("Usuario ou senha invalidos!\n");
            tentativas++;
            }
        }
    } while (tentativas < 3);
    printf("Numero maximo de tentativas alcancado!\n");
    return 0;
}

#pragma endregion

#pragma region Funcao Include

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
        indiceUsuario++;
    }    
}

#pragma endregion

#pragma region Funcao Update

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
    printf("Atualizacao realizada com sucesso!");    
}

#pragma endregion

#pragma region Funcao Delete

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

int ListClient(){
    for (int i = 1; i < MAX; i++)
        if (!cadastrar[i].id == 0){
            printf("Cliente: %d , %s , %lld , %s , %s , %d , %s ,%lld\n",cadastrar[i].id,
            cadastrar[i].nome,cadastrar[i].cpf,cadastrar[i].email,cadastrar[i].endereco,
            cadastrar[i].numero,cadastrar[i].cidade_estado,cadastrar[i].telefone);
        }else if (!cadastrarAdmin[i].id == 0)
        {
            printf("Admin: %d , %s , %lld , %s , %s , %d , %s ,%lld\n",cadastrarAdmin[i].id,
            cadastrarAdmin[i].nome,cadastrarAdmin[i].cpf,cadastrarAdmin[i].email,cadastrarAdmin[i].endereco,
            cadastrarAdmin[i].numero,cadastrarAdmin[i].cidade_estado,cadastrarAdmin[i].telefone);
        }
        
}

#pragma endregion

#pragma region Banco de dados de clientes

void InsertClientsDB(){
    for (indiceUsuario = 1; indiceUsuario < 6; indiceUsuario++)
        IncluirUsuarios(indiceUsuario,"teste",12312312312,"teste@teste.com","rua teste",indiceUsuario,"Casa","CWB-PR",41123451234,"senha",0);

    for (int ii = 6; ii < 9; ii++)
        IncluirUsuarios(indiceUsuario,"testeAdmin",12312312312,"teste@teste.com","rua teste",indiceAdmin,"Casa","CWB-PR",41123451234,"senha",1);
    
}

#pragma endregion

#pragma region Atualizar Dados

void AtualizarDadosPage(){
//Variaveis Locais
char *nome[60],*endereco[30],*complemento[20],*email[60],*cidade_uf[20],*senha[32];
long long int cpf = 0,telefone = 0;
int id = 0,numero = 0;
//Fim Variaveis Locais

    printf("---- Pagina de Alteracao De Dados ----\n");
    printf("--------------------------------------\n");
    printf("0 - Sair\n");
    printf("1 - Voltar para o menu\n");
    printf("2 - Cadastro\n");
    printf("3 - Alterar\n");
    scanf("%d",&opcao);
    printf("--------------------------------------\n");
    switch (opcao)
    {
    case 0:
      exit(0);
      break;
  case 1:
      main();
      break;
  case 2:
      cadastroCliente();
      break;
  case 3:
      break;
  default:
    printf("Favor escolher uma opcao valida");
      break;
    }

    printf("Insira o Id para alterar:");
    scanf("%d",id);    
    printf("--------------------------------------\n");
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

    printf("--------------------------------------\n");
    printf("Alteracao realizada com sucesso: %d , %s , %d , %s , %s , %d , %s , %s , %d , %s\n POR:\n %s , %d , %s , %s , %d , %s , %s , %d , %s\n",id,cadastrar[id].nome,cadastrar[id].cpf,
    cadastrar[id].email,cadastrar[id].complemento,cadastrar[id].cidade_estado,cadastrar[id].telefone,cadastrar[id].senha,nome,cpf,email,endereco,numero,complemento,cidade_uf,telefone,senha);
    printf("--------------------------------------\n");
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
        CadastroLoginUsuario();
        printf("Atualizacao efetuada com sucesso!\n");
        main();
    }
    main();
}

#pragma endregion

#pragma region Exclui Cliente

void ExcluirClientePage(){
//Variaveis Locais
int id = 0;
//Fim Variaveis Locais
    printf("--- Pagina de Exclusao De Clientes ---\n");
    printf("--------------------------------------\n");
    printf("0 - Sair\n");
    printf("1 - Voltar para o menu\n");
    printf("2 - Cadastro\n");
    printf("3 - Excluir\n");
    scanf("%d",&opcao);
    printf("--------------------------------------\n");
    switch (opcao)
    {
    case 0:
      exit(0);
      break;
  case 1:
      main();
      break;
  case 2:
      cadastroCliente();
      break;
  case 3:
      break;
  default:
    printf("Favor escolher uma opcao valida");
      break;
    }

    printf("Insira o Id para ser excluir:");
    scanf("%d",id);    
    printf("--------------------------------------\n");
    ExcluirCliente(id);
    main();
}

#pragma endregion

#pragma region CadastroLoginUser

void CadastroLoginUsuario(){  
    strcpy(usuario[indiceCadastroUser].login,cadastrar[contador].email);
    strcpy(usuario[indiceCadastroUser].senha,cadastrar[contador].senha);
    indiceCadastroUser++;
}

#pragma endregion

#pragma region CadastroLoginAdmin

void cadastroLoginAdmin(){
    strcpy(usuario[indiceCadastroUserAdmin].login,cadastrar[contadorAdmin].email);
    strcpy(usuario[indiceCadastroUserAdmin].senha,cadastrar[contadorAdmin].senha);
    indiceCadastroUserAdmin++;
}

#pragma endregion

#pragma region PaginaInicial

int dashboard()
{
    //fazer um construtor para toda vez que chamar o dashboard injetar arquivos dentro da struct e listar
    //compra de voo : 1 data e horario voo 2 peso e tamanho 3 forma de pagamento 4 nota 5 devolver id voo Usuario pode cancelar a qualquer momento
    //acompanhar voo: 1 pedir codigo de voo 2 data de saida e previsao de chegada
    printf("DAshboardddd");
}

#pragma endregion

#pragma region PaginaInicialAdmin

int dashboardAdmin()
{
    //fazer um construtor para toda vez que chamar o dashboard injetar arquivos dentro da struct e listar
    //1 listar dados de clientes (compras efetuadas) 2 listar voos em andamento 
    printf("DAshboardddd de adminnn");
}

#pragma endregion

#pragma region CadastroCliente

int cadastroCliente()
{
// Local Variables
char *nome[60],*endereco[30],*complemento[20],*email[60],*cidade_uf[20],*senha[32];
long long int cpf = 0,telefone = 0;
int numero = 0;
//End Local Variables
    printf("--- Register Page CTA Systems ---\n");
    printf("----------------------------------\n");
    printf("Se deseja cadastrar um administrador efetue o login e cadastre depois de logar\n");
    printf("0 - Sair\n");
    printf("1 - Voltar para o menu\n");
    printf("2 - Login\n");
    printf("3 - Cadastrar\n");
    scanf("%d",&opcao);
    printf("----------------------------------\n");

  switch (opcao)
{
    case 0:
      exit(0);
      break;
  case 1:
      main();
      break;
  case 2:
      login();
      break;
  case 3:
      break;
  default:
    printf("Favor escolher uma opcao valida");
      break;
}
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
        CadastroLoginUsuario();
        printf("Cadastro efetuado com sucesso!\n");
        main();
    }

}

#pragma endregion

#pragma region CadastroAdmin

int cadastroAdmin()
{
// Local Variables
char *nome[60],*endereco[30],*complemento[20],*email[60],*cidade_uf[20],*senha[32];
long long int cpf = 0,telefone = 0;
int numero = 0,idFuncionario = 0;
//End Local Variables
    printf("--- Admin Register Page CTA Systems ---\n");
    printf("---------------------------------------\n");
    printf("0 - Sair\n");
    printf("1 - Voltar para o menu\n");
    printf("2 - Login\n");
    printf("3 - Cadastrar\n");
    scanf("%d",&opcao);
    printf("---------------------------------------\n");

  switch (opcao)
{
    case 0:
      exit(0);
      break;
  case 1:
      main();
      break;
  case 2:
      login();
      break;
  case 3:
      break;
  default:
    printf("Favor escolher uma opcao valida");
      break;
}
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
        cadastroAdmin();
    }else
    {
        IncluirUsuarios(indiceUsuario,nome,cpf,email,endereco,numero,complemento,cidade_uf,telefone,senha,1);
        cadastroLoginAdmin();
        printf("Cadastro efetuado com sucesso!\n");
        main();
    }

}

#pragma endregion

#pragma region Main

int main()
{

    printf("Bem-vindo ao sistema CTA Airlines\n");
    printf("---------------------------------\n");
    printf("0 - Sair\n");
    printf("1 - Login\n");
    printf("2 - Cadastro\n");
    printf("3 - Insere clientes\n");
    printf("4 - Lista clientes\n");
    printf("5 - Atualizar Dados\n");
    printf("6 - Excluir Clientes\n");
    printf("7 - Cadastrar Admin\n");
    scanf("%d",&opcao);
    printf("---------------------------------\n");

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
      break;
    case 3:
      InsertClientsDB();
      main();
      break;
    case 4:
      ListClient();
      main();
      break;
    case 5:
      AtualizarDadosPage();
      main();
      break;
    case 6:
      ExcluirClientePage();
      main();
      break;
    case 7:
      cadastroAdmin();
      main();
      break;
  default:
    printf("Favor escolher uma opcao valida");
      break;
  }
}

#pragma endregion


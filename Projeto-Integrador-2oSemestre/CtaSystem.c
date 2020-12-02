#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000

#pragma region Struct

typedef struct{
    char login[32];
	char senha[32];
    char adminUser[32];
}usuario_st;

struct list_avioes{
    int numero;
	char piloto[32];
    char destino[32];
    int horario_saida;
    int horario_chegada;
};

typedef struct{
    int id;
    char nome[60];
	int cpf[13];
    char email[40];
    char endereco[30];
    int numero[10];
    char complemento[15];
    char cidade_estado[12];
    int telefone[13];
    char senha[32];
}register_st;

typedef struct{
    int id;
    char nome[60];
	int cpf[13];
    char email[40];
    char endereco[30];
    int numero[10];
    char complemento[15];
    char cidade_estado[12];
    int telefone[13];
    char senha[32];
    char IdFuncionario[10];
}registerAdmin_st;

int opcao,contador = 0,contadorAdmin = 0,indiceUser = 0,indiceAdmin = 0,indiceCadastroUser = 0,indiceCadastroUserAdmin = 0;

register_st cadastrar[MAX];
usuario_st usuario[MAX];
registerAdmin_st cadastrarAdmin[MAX];

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

    char user_entry[32],password_entry[32];
	int tentativas = 0,i = 0;;
    do {
        printf("Login: ");
        scanf("%s", &user_entry[32]);
        printf("Senha: ");
        scanf("%s", &password_entry[32]);
        
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
        if (!strcmp(user_entry[32], usuario[i].login) && !strcmp(password_entry[32], usuario[i].senha)) {
            printf("Bem vindo %s\n", usuario[i].login);
            return ListClient();
        }else{
            if (!strcmp(user_entry[32], usuario[i].adminUser) && !strcmp(password_entry[32], usuario[i].senha)) {
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

void IncludeUser(int codigo,char nome,int cpf,char *email,char *endereco,int numero,char *complemento,char *cidade_estado,int telefone,char *senha){

    if (codigo > MAX)
    {
        printf("Erro na inclusao,Favor inseir um valor menor que %d",MAX);
    }else if (codigo < 0){
        printf("Erro na inclusao,Favor inseir um valor menor que %d",codigo);
    }else{
        cadastrar[codigo].id++;
        cadastrar[codigo].nome = nome;
        cadastrar[codigo].cpf = cpf;
        cadastrar[codigo].email = email;
        cadastrar[codigo].endereco = endereco;
        cadastrar[codigo].numero = numero;
        cadastrar[codigo].complemento = complemento;
        cadastrar[codigo].cidade_estado = cidade_estado;
        cadastrar[codigo].telefone = telefone;
        cadastrar[codigo].senha = senha;
    }
}

#pragma endregion

#pragma region Funcao Listar Cliente

int ListClient(){
    for (int i = 0; i < contador; i++)
    {
        printf("dentro do for\n");
        
            printf("antes do printf\n");
            // printf("%s\n",cadastrar[i].id);
            // printf("%s\n",cadastrar[i].nome);
            // printf("%s\n",cadastrar[i].cpf);
            // printf("%s\n",cadastrar[i].email);
            // printf("%s\n",cadastrar[i].endereco);
            // printf("%s\n",cadastrar[i].numero);
            // printf("%s\n",cadastrar[i].cidade_estado);
            // printf("%s\n",cadastrar[i].telefone);
            printf("antes do puts\n");
            puts(cadastrar[i].nome);
            puts(cadastrar[i].cpf);
            puts(cadastrar[i].email);
            puts(cadastrar[i].endereco);
            puts(cadastrar[i].numero);
            puts(cadastrar[i].complemento);
            puts(cadastrar[i].cidade_estado);
            puts(cadastrar[i].telefone);

    }
}

#pragma endregion

#pragma region Banco de dados de clientes

int InsereClientesDB(){
    for (contador = 0; contador < 5; contador++)
    {
        IncluirUser(contador,"teste",12345678900,"teste@teste.com","rua teste",123,"Casa 3","CWB-PR",41123456789,"senha");
        puts(cadastrar[contador].nome);
        puts(cadastrar[contador].cpf);
        puts(cadastrar[contador].email);
        puts(cadastrar[contador].endereco);
        puts(cadastrar[contador].numero);
        puts(cadastrar[contador].complemento);
        puts(cadastrar[contador].cidade_estado);
        puts(cadastrar[contador].telefone);
        printf("%d\n",contador);
        printf("Cliente cadastrado com sucesso!\n");
    }
}

#pragma endregion

#pragma region CadastroLoginUser

int cadastroLoginUser(){  
    strcpy(usuario[indiceCadastroUser].login,cadastrar[contador].email);
    strcpy(usuario[indiceCadastroUser].senha,cadastrar[contador].senha);
    indiceCadastroUser++;
}

#pragma endregion

#pragma region CadastroLoginAdmin

int cadastroLoginAdmin(){
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
        scanf(" %[^\n]s",&cadastrar[contador].nome);
        printf("CPF: ");
        scanf("%s", &cadastrar[contador].cpf);
        printf("Email: ");
        scanf("%s", &cadastrar[contador].email);
        printf("Endereco: ");
        scanf("%s", &cadastrar[contador].endereco);
        printf("Numero: ");
        scanf("%s", &cadastrar[contador].numero);
        printf("Complemento: ");
        scanf("%s", &cadastrar[contador].complemento);
        printf("Cidade-UF: ");
        scanf("%s", &cadastrar[contador].cidade_estado);
        printf("Telefone (DDD)12345-6789: ");
        scanf("%s", &cadastrar[contador].telefone);
        printf("Senha: ");
        scanf("%s", &cadastrar[contador].senha);
    
    printf("--------------------------------\n");
        puts(cadastrar[contador].nome);
        puts(cadastrar[contador].cpf);
        puts(cadastrar[contador].email);
        puts(cadastrar[contador].endereco);
        puts(cadastrar[contador].numero);
        puts(cadastrar[contador].complemento);
        puts(cadastrar[contador].cidade_estado);
        puts(cadastrar[contador].telefone);
        puts(cadastrar[contador].senha);
    printf("--------------------------------\n");
    cadastrar[contador].id = cadastrar[contador].id + 1;
    opcao = 0;
    printf("Para cancelar digite 0 para confirmar digite 1\n");
    scanf("%d", &opcao);

    if (opcao == 0)
    {
        printf("Cadastro cancelado com sucesso!\n");
        cadastroCliente();
    }else
    {
        printf("Id Usuario %d!\n",cadastrar[contador].id);
        printf("Index Usuario %d!\n",contador);
        cadastroLoginUser();
        contador++;
        printf("Cadastro efetuado com sucesso!\n");
        main();
    }

}

#pragma endregion

#pragma region CadastroAdmin

int cadastroAdmin()
{
    printf("--- Admin Register Page CTA Systems ---\n");
    printf("----------------------------------\n");
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
        scanf("%s", &cadastrarAdmin[contadorAdmin].nome);
        printf("CPF: ");
        scanf("%s", &cadastrarAdmin[contadorAdmin].cpf);
        printf("Email: ");
        scanf("%s", &cadastrarAdmin[contadorAdmin].email);
        printf("Endereco: ");
        scanf("%s", &cadastrarAdmin[contadorAdmin].endereco);
        printf("Numero: ");
        scanf("%s", &cadastrarAdmin[contadorAdmin].numero);
        printf("Complemento: ");
        scanf("%s", &cadastrarAdmin[contadorAdmin].complemento);
        printf("Cidade-UF: ");
        scanf("%s", &cadastrarAdmin[contadorAdmin].cidade_estado);
        printf("Telefone (DDD)12345-6789: ");
        scanf("%s", &cadastrarAdmin[contadorAdmin].telefone);
        printf("Senha: ");
        scanf("%s", &cadastrarAdmin[contadorAdmin].senha);
        printf("Id Funcionario: ");
        scanf("%s", &cadastrarAdmin[contadorAdmin].IdFuncionario);

        printf("--------------------------------\n");
        puts(cadastrarAdmin[contadorAdmin].id);
        puts(cadastrarAdmin[contadorAdmin].IdFuncionario);
        puts(cadastrarAdmin[contadorAdmin].nome);
        puts(cadastrarAdmin[contadorAdmin].cpf);
        puts(cadastrarAdmin[contadorAdmin].email);
        puts(cadastrarAdmin[contadorAdmin].endereco);
        puts(cadastrarAdmin[contadorAdmin].numero);
        puts(cadastrarAdmin[contadorAdmin].complemento);
        puts(cadastrarAdmin[contadorAdmin].cidade_estado);
        puts(cadastrarAdmin[contadorAdmin].telefone);
        puts(cadastrarAdmin[contadorAdmin].senha);
        printf("--------------------------------\n");
    cadastrarAdmin[contadorAdmin].id++;
    opcao = 0;
    printf("Para cancelar digite 0 para confirmar digite 1\n");
    scanf("%d", &opcao);

    if (opcao == 0)
    {
        printf("Cadastro cancelado com sucesso!\n");
        cadastroAdmin();
    }else
    {
        cadastroLoginAdmin();
        contadorAdmin++;
        printf("Cadastro efetuado com sucesso!\n");
        main();
    }
}

#pragma endregion

#pragma region Main

int main()
{

    printf("Bem-vindo ao sistema CTA Airlines\n");
    printf("------------------------------\n");
    printf("0 - Sair\n");
    printf("1 - Login\n");
    printf("2 - Cadastro\n");
    printf("3 - Insere e lista clientes\n");
    scanf("%d",&opcao);
    printf("----------------------------------\n");

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
      InsereClientesDB();
      ListClient();
      main();
      break;
  default:
    printf("Favor escolher uma opcao valida");
      break;
  }
}

#pragma endregion


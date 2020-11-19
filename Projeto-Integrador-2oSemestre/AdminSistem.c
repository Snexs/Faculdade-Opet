#include<stdio.h>
#include<stdlib.h>

int opcao;

struct usuario_st{
    char login[32];
	char senha[32];
};

struct list_avioes{
    int numero;
	char piloto[32];
    char destino[32];
    int horario_saida;
    int horario_chegada;
};

struct register_st{
    char nome[32];
	char cpf[15];
    char email[20];
    char endereco[18];
    char numero[10];
    char complemento[15];
    char cidade_estado[12];
    char telefone[18];
    char senha[32];
};

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
      cadastro();
      break;
  case 3:
      break;
  default:
    printf("Favor escolher uma opcao valida");
      break;
}

struct usuario_st usuario;

if (!strcmp("", usuario.login)) {
		printf("Nenhum usuário encontrado, abrindo cadastro!\n");
		cadastro();
	} else {
	    int tentativas = 0;
		do {
			char user_Model[] = "admin";
            char password_Model[] = "admincta";
			printf("Login: ");
			scanf("%s", &usuario.login);
			printf("Senha: ");
			scanf("%s", &usuario.senha);
			if (!strcmp(usuario.login, user_Model) && !strcmp(usuario.senha, password_Model)) {
				printf("Bem vindo %s\n", usuario.login);
				return dashboard();
			} else {
				printf("Usuario ou senha invalidos!\n");
				tentativas++;
			}
		} while (tentativas < 3);
		printf("Numero maximo de tentativas alcancado!\n");
        return 0;
	}
}

int dashboard()
{
    //fazer um construtor para toda vez que chamar o dashboard injetar arquivos dentro da struct e listar
    printf("DAshboardddd");
}

int cadastro()
{
    printf("--- Register Page CTA Systems ---\n");
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

    struct register_st cadastrar;

        printf("Nome: ");
        scanf("%s", &cadastrar.nome);
        printf("CPF: ");
        scanf("%s", &cadastrar.cpf);
        printf("Email: ");
        scanf("%s", &cadastrar.email);
        printf("Endereco: ");
        scanf("%s", &cadastrar.endereco);
        printf("Numero: ");
        scanf("%s", &cadastrar.numero);
        printf("Complemento: ");
        scanf("%s", &cadastrar.complemento);
        printf("Cidade-UF: ");
        scanf("%s", &cadastrar.cidade_estado);
        printf("Telefone (DDD)12345-6789: ");
        scanf("%s", &cadastrar.telefone);
        printf("Senha: ");
        scanf("%s", &cadastrar.senha);

    printf("--------------------------------\n");
        puts(cadastrar.nome);
        puts(cadastrar.cpf);
        puts(cadastrar.email);
        puts(cadastrar.endereco);
        puts(cadastrar.numero);
        puts(cadastrar.complemento);
        puts(cadastrar.cidade_estado);
        puts(cadastrar.telefone);
        puts(cadastrar.senha);
    printf("--------------------------------\n");
    opcao = 0;
    printf("Para cancelar digite 0 para confirmar digite 1\n");
    scanf("%d", &opcao);

    if (opcao == 0)
    {
        printf("Cadastro cancelado com sucesso!\n");
        cadastro();
    }else
    {
        printf("Cadastro efetuado com sucesso!\n");
        main();
    }

}

int main()
{

    printf("Bem-vindo ao sistema Admin CTA\n");
    printf("------------------------------\n");
    printf("0 - Sair\n");
    printf("1 - Login\n");
    printf("2 - Cadastro\n");
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
      cadastro();
      break;
  default:
    printf("Favor escolher uma opcao valida");
      break;
  }
}
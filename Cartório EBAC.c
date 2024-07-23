#include <locale.h> //biblioteca de localização
#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de memória
#include <string.h> //biblioteca de manipulação de strings

int registro()
{
  setlocale(LC_ALL, "Portuguese");

  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];

  printf("Digite o CPF que deseja cadastrar: ");
  scanf("%s", cpf);

  strcpy(arquivo, cpf); //Copia os valores das strings

  FILE *file; //cria arquivo
  file = fopen(arquivo, "w"); //cria o arquivo
  fprintf(file,cpf); //salva o valor da variável
  fclose(file); //fecha o arquivo

  file = fopen(arquivo, "a");
  fprintf(file,", ");
  fclose(file);

  printf("Digite o nome a ser cadastrado: ");
  scanf("%s", nome);

  file = fopen(arquivo, "a");
  fprintf(file,nome);
  fclose(file);

  file = fopen(arquivo, "a");
  fprintf(file,", ");
  fclose(file);

  printf("Digite o sobrenome a ser cadastrado: ");
  scanf("%s", sobrenome);

  file = fopen(arquivo, "a");
  fprintf(file,sobrenome);
  fclose(file);

  file = fopen(arquivo, "a");
  fprintf(file,", ");
  fclose(file);

  printf("Digite o cargo a ser cadastrado: ");
  scanf("%s", cargo);

  file = fopen(arquivo, "a");
  fprintf(file,cargo);
  fclose(file);

  system("pause");
}

int consultar()
{
  setlocale(LC_ALL, "Portuguese");

  char cpf[40];
  char conteudo[200];

  printf("Digite o CPF a ser consultado: ");
  scanf("%s", cpf);

  FILE *file;
  file = fopen(cpf, "r");

  if(file == NULL)
  {
    printf("CPF não encontrado.\n");
  }

  while(fgets(conteudo, 200, file) != NULL)
  {
    printf("\nEssas são as informações do usuário: ");
    printf("%s", conteudo);
    printf("\n\n");
  }

  system("pause");


}

int deletar()
{
  printf("Você escolheu deletar aluno\n");
  system("pause");
}


int main() 
{
  int opcao=0; //definir variável de opção
  int validacao=1;

  for(validacao=1;validacao=1;)
  {

    system("cls");

    setlocale(LC_ALL, "Portuguese"); //definir a linguagem

    printf("### Cartório da EBAC ###\n\n"); //início do menu
    printf("Escola a opção desejada:\n\n");
    printf("\t1 - Registrar aluno\n");
    printf("\t2 - Consultar aluno\n");
    printf("\t3 - Deletar aluno\n\n\n");
    printf("\t0 - Sair\n\n");
    printf("Opção: "); //final do menu

    scanf("%d", &opcao); //armazenar a escolha do usuário

    system("cls");  

    switch(opcao) //início da seleção
    {
      case 1:
      registro();
      break;

      case 2:
      consultar();
      break;

      case 3:
      deletar();
      break;

      case 0:
      printf("Obrigado por usar o sistema.\n");
      return 0;
      break;

      default:
      printf("Opção inválida\n");
      system("pause");
      break;

    } //fim da seleção 
  }
}
#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

char nome[50]={0};
char sobrenome[50]={0};
char rua [100]={0};
char bairro [100]={0};
int numero=0;
int opcao_pagamento=0;
int total=0;
char cpf[11]={0};

float precos_menu[12] = {10.0,12.0,13.0,14.0, 11.0, 5.0, 6.5, 6.0, 2.0, 3.0, 4.5, 0.0};

int pedido_hamburguer = 0;
int pedido_porcao = 0;
int pedido_bebidas = 0;

float soma_hamburguer = 0;
float soma_porcoes = 0;
float soma_bebidas = 0;

int quant_H_simples = 0;
int quant_H_duplo = 0;
int quant_H_picante = 0;
int quant_H_queijos = 0;
int quant_H_vegetariano = 0;

int quant_P_frita = 0;
int quant_P_rustica= 0;
int quant_P_aneis = 0;

int quant_B_agua = 0;
int quant_B_coca = 0;
int quant_B_suco = 0;

void introducao() // DONE !
{
  printf("\n-----ALUNOS:\n");

  printf("\n\t- Alan Ferandin Consorte\n");
  printf("\n\t- Alberto Piana Borso\n");
  printf("\n\t- Débora de Azevedo Rodrigues\n");
  printf("\n\t- Gabriel Bombardelli\n");

  printf("\n\n\tGRUPO 1: DELIVERY NA PANDEMIA\n");
  printf("\n\tCONSTRUÇÃO DE ALGORITMOS\n");
  printf("\n-----PROFESSOR: Maurício Zardo Oliveira\n\n");

  system("sleep 1");  /* Trocar por "pause" */
  system("clear");    /* Trocar por "cls" */
}

void menu_delivery()  // DONE !
{
  printf("\n\n...............................................\n");

  printf("\n\t>------- HAMBURGUER -------<\n");
  printf("\n\t0  . R$ %.2f . HAMBURGUER SIMPLES ",precos_menu[0]);
  printf("\n\t1  . R$ %.2f . HAMBURGUER DUPLO",precos_menu[1]);
  printf("\n\t2  . R$ %.2f . HAMBURGUER PICANTE",precos_menu[2]);
  printf("\n\t3  . R$ %.2f . HAMBURGUER 4 QUEIJOS",precos_menu[3]);
  printf("\n\t4  . R$ %.2f . HAMBURGUER VEGETARIANO",precos_menu[4]);
  //printf("\n\t0  . NÃO ADICIONAR",precos_menu[12]);

  printf("\n\n\t>-------- PORÇÕES --------<\n");
  printf("\n\t5  . R$ %.2f . BATATA FRITA SIMPLES",precos_menu[5]);
  printf("\n\t6  . R$ %.2f . BATATA RÚSTICA ",precos_menu[6]);
  printf("\n\t7  . R$ %.2f . ANÉIS DE CEBOLA ",precos_menu[7]);
  //printf("\n\t0  . NÃO ADICIONAR",precos_menu[12]);

  printf("\n\n\t>-------- BEBIDAS --------<\n");
  printf("\n\t8  . R$ %.2f . AGUA 300 ml",precos_menu[8]);
  printf("\n\t9 . R$ %.2f . REFRIGERANTE COCA-COLA 350ml",precos_menu[9]);
  printf("\n\t10 . R$ %.2f . SUCO 300 ml",precos_menu[10]);
  //printf("\n\t0  . NÃO ADICIONAR",precos_menu[12]);

  printf("\n\n...............................................\n\n");
}

int forma_pagamento () // DONE !
{
  int forma_pagamento=0;

  printf(" Escolha sua forma de pagamento: \n");
  printf(" 1 . DINEHIRO\n");
  printf(" 2 . CARTÃO (crédito / débito\n-> ");
  scanf("%d",&opcao_pagamento);
  fflush(stdin);
  switch(opcao_pagamento)
  {
    case 1:
      forma_pagamento = 1;
      printf("\tFORMA DE PAGAMENTO SELECIONADA: DINHEIRO\n");

    break;

    case 2:
      forma_pagamento = 2;
      printf("\tFORMA DE PAGAMENTO SELECIONADA: CARTÃO (crédito / débito\n");
    break;
  }

  return forma_pagamento;
}


float checa_preco(int id){
  int i = 0;
  float preco = 0;
  for (i = 0; i < 11; i ++)
     if (id == i){
         preco = precos_menu[i];
     }
        // printf("Preços ID %d index %d - R$ %2.2f\n\n",id,i,precos_menu[i]);
  return preco;
}

float receber_pedidos(){
  int hamburger = 0, porcao = 0 , bebidas = 0;
  float total; 
  
  printf("\nHAMBURGUERS OPÇÃO \n\t-> ");
  scanf("%d",&hamburger);
  fflush(stdin);
  printf("Preço do item: R$ %2.2f",checa_preco(hamburger));

  
  printf("\nPORÇÃO OPÇÃO \n\t-> ");
  scanf("%d",&porcao);
  fflush(stdin);
  
  printf("\nPreço do item: R$ %2.2f",checa_preco(porcao));
 
  printf("\nBEBIDA OPÇÃO \n\t-> ");
  scanf("%d",&bebidas);
  fflush(stdin);

  printf("\nPreço do item: R$ %2.2f",checa_preco(bebidas));

  total = checa_preco(hamburger) + checa_preco(porcao) + checa_preco(bebidas);
  printf("\n\nTotal R$: %2.2f",total);
  return total;
  
}

void receber_dados_cliente(){
  printf("\n\tNome do Cliente (Primeiro Nome Apenas)\n - > ");
  //scanf("%s",nome);
  fgets (nome, 50, stdin);

  printf("\n\tCPF do Cliente\n - > ");
  scanf("%s",cpf);
  
}

int main(void) {

  introducao();

  menu_delivery();

  receber_pedidos();
  
  receber_dados_cliente();
  printf("\tForma de pagamento escolhida %d \t\n",forma_pagamento());
  return 0;
}
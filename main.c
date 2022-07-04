#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sVeiculos
{
    int numero;
    char placa[10];
    char marca[20];
    char modelo[20];
    char ano [5];
    char categoria[10];
    char assentos[5];
    char status[20];
    float diaria;
    char desc[100];
};
typedef struct sVeiculos tVeiculos;
tVeiculos vetVeiculos[100];

struct sClientes
{
    int codigo;
    char nome[30];
    char cnh[20];
    char telefone[20];
    char endereco[80];
};
typedef struct sClientes tClientes;
tClientes vetClientes[100];

struct sLocacoes
{
    int codigo;
    char qtddias[10];
    char retirada[20];
    char devolucao[20];
    char seguro[5];
    char codcliente[5];
    char codveiculo[5];
};
typedef struct sLocacoes tLocacoes;
tLocacoes vetLocacoes[100];

int main()
{
    int opcao;
    carregaClientes();
    carregaVeiculos();
    carregaLocacao();

    printf("\n---------------------------------------------------\n");
    printf("\n---------------------LOCAMAIS----------------------\n");
    printf("\n---------------------------------------------------\n");

    printf("\n(1) Cadastrar veiculo\n(2) Cadastrar cliente\n(3) Cadastrar locacao\n(4) Validar locacao\n(5) Pesquisar clientes\n(6) Listar clientes\n(7) Pesquisar veiculos\n(8) Listar veiculos\n\n Caso queira SAIR, digite 0\n");

    printf("\n\nDigite um numero para executar a funcao: ");
    scanf("%d", &opcao);

    while (opcao != 0)
    {
        switch (opcao)
        {
        case 1:
            cadastraVeiculo();
            break;
        case 2:
            cadastraCliente();
            break;
        case 3:
            cadastraLoc();
            break;
        case 4:
            validaLoc();
            break;
        case 5:
            pesquisaCliente();
            break;
        case 6:
            printClientes();
            break;
        case 7:
            pesquisaVeiculo();
            break;
        case 8:
            printVeiculos();
            break;
        }
        printf("\n\n------------------------------------------------\n");
        printf("\n------------------------------------------------\n");
        printf("\n \n  O que mais voce deseja? \n \n");
        printf("\n(1) Cadastrar veiculo\n(2) Cadastrar cliente\n(3) Cadastrar locacao\n(4) Validar locacao\n(5) Pesquisar clientes\n(6) Listar clientes\n(7) Pesquisar veiculos\n(8) Lista veiculos\n\nCaso queira SAIR, digite 0\n");

        printf("\n\nDigite um numero para executar a funcao: ");
        scanf("%d", &opcao);
    }


}
int carregaClientes()
{
    int j=0,k=0;
    char nomeCampoc[256],valorCampoc[256];
    FILE *arqClientes;
    arqClientes = fopen("clientes.txt", "r");
    if (arqClientes != NULL)
    {
        k = fscanf(arqClientes, "%s %[^\n]", &nomeCampoc, &valorCampoc);
        j = 0;
        while (k != EOF)
        {
            if (strcmp(nomeCampoc,"cliente")==0 && strcmp(valorCampoc, "inicio")==0)
            {
                j = j +1;
                vetClientes[j].codigo = j;
                strcpy(vetClientes[j].nome,"");
                strcpy(vetClientes[j].cnh,"");
                strcpy(vetClientes[j].telefone,"");
                strcpy(vetClientes[j].endereco,"");
            }
            if (strcmp(nomeCampoc,"nome")==0)
                strcpy(vetClientes[j].nome,valorCampoc);
            if (strcmp(nomeCampoc,"cnh")==0)
                strcpy(vetClientes[j].cnh,valorCampoc);
            if (strcmp(nomeCampoc,"telefone")==0)
                strcpy(vetClientes[j].telefone,valorCampoc);
            if (strcmp(nomeCampoc,"endereco")==0)
                strcpy(vetClientes[j].endereco,valorCampoc);

            k = fscanf(arqClientes,"%s %[^\n}]",&nomeCampoc,&valorCampoc);
        }
        j = j + 1;
        vetClientes[j].codigo = 999;
        fclose(arqClientes);
    }
    else
    {
        printf("arquivo clientes.txt nao encontrado");
        k = -1;
    }
    return k;
}

int carregaVeiculos()
{
    int i=0,r=0;
    char nomeCampo[256],valorCampo[256];
    FILE *arqVeiculos;
    arqVeiculos = fopen("veiculos.txt", "r");
    if (arqVeiculos != NULL)
    {
        r = fscanf(arqVeiculos,"%s %[^\n]", &nomeCampo, &valorCampo);
        i = 0;
        while (r != EOF)
        {
            if (strcmp(nomeCampo,"veiculo")== 0 && strcmp(valorCampo, "inicio")== 0)
            {
                i = i +1;
                vetVeiculos[i].numero = i;
                strcpy(vetVeiculos[i].placa,"");
                strcpy(vetVeiculos[i].marca,"");
                strcpy(vetVeiculos[i].modelo,"");
                strcpy(vetVeiculos[i].ano,"");
                strcpy(vetVeiculos[i].categoria,"");
                strcpy(vetVeiculos[i].assentos,"");
                strcpy(vetVeiculos[i].status,"");
            }
            if (strcmp(nomeCampo,"placa")==0)
                strcpy(vetVeiculos[i].placa,valorCampo);
            if (strcmp(nomeCampo,"marca")==0)
                strcpy(vetVeiculos[i].marca,valorCampo);
            if (strcmp(nomeCampo,"modelo")==0)
                strcpy(vetVeiculos[i].modelo,valorCampo);
            if (strcmp(nomeCampo,"ano")==0)
                strcpy(vetVeiculos[i].ano,valorCampo);
            if (strcmp(nomeCampo,"categoria")==0)
                strcpy(vetVeiculos[i].categoria,valorCampo);
            if (strcmp(nomeCampo,"assentos")==0)
                strcpy(vetVeiculos[i].assentos,valorCampo);
            if (strcmp(nomeCampo,"status")==0)
                strcpy(vetVeiculos[i].status,valorCampo);

            r = fscanf(arqVeiculos,"%s %[^\n}]",&nomeCampo,&valorCampo);
        }
        i = i + 1;
        vetVeiculos[i].numero = 999;
        fclose(arqVeiculos);
    }
    else
    {
        printf("arquivo veiculos.txt nao encontrado");
        r = -1;
    }
    return r;
}

int carregaLocacao()
{
    int i=0,r=0;
    char nomeCampo[256],valorCampo[256];
    FILE *arqLocacao;
    arqLocacao = fopen("locacao.txt", "r");
    if (arqLocacao != NULL)
    {
        r = fscanf(arqLocacao,"%s %[^\n]", &nomeCampo, &valorCampo);
        i = 0;
        while (r != EOF)
        {
            if (strcmp(nomeCampo,"locacao")== 0 && strcmp(valorCampo, "inicio")== 0)
            {
                i = i +1;
                vetLocacoes[i].codigo = i;
                strcpy(vetLocacoes[i].qtddias,"");
                strcpy(vetLocacoes[i].retirada,"");
                strcpy(vetLocacoes[i].devolucao,"");
                strcpy(vetLocacoes[i].seguro,"");
                strcpy(vetLocacoes[i].codcliente,"");
                strcpy(vetLocacoes[i].codveiculo,"");
            }
            if (strcmp(nomeCampo,"qtddias")==0)
                strcpy(vetLocacoes[i].qtddias,valorCampo);
            if (strcmp(nomeCampo,"retirda")==0)
                strcpy(vetLocacoes[i].retirada,valorCampo);
            if (strcmp(nomeCampo,"devolucao")==0)
                strcpy(vetLocacoes[i].devolucao,valorCampo);
            if (strcmp(nomeCampo,"seguro")==0)
                strcpy(vetLocacoes[i].seguro,valorCampo);
            if (strcmp(nomeCampo,"codcliente")==0)
                strcpy(vetLocacoes[i].codcliente,valorCampo);
            if (strcmp(nomeCampo,"codveiculo")==0)
                strcpy(vetLocacoes[i].codveiculo,valorCampo);

            r = fscanf(arqLocacao,"%s %[^\n}]",&nomeCampo,&valorCampo);
        }
        i = i + 1;
        vetLocacoes[i].codigo = 999;
        fclose(arqLocacao);
    }
    else
    {
        printf("arquivo locacao.txt nao encontrado");
        r = -1;
    }
    return r;
}

void printVeiculos()
{
    for (int i = 1; i<100 && vetVeiculos[i].numero != 999; i++)
    {
        printf("\n%i %s %s %s %s %s %s",
               vetVeiculos[i].numero,
               vetVeiculos[i].placa,
               vetVeiculos[i].marca,
               vetVeiculos[i].modelo,
               vetVeiculos[i].ano,
               vetVeiculos[i].categoria,
               vetVeiculos[i].status);
    }
}

void printVeiculosLivres()
{
    for (int i = 1; i<100 && vetVeiculos[i].numero != 999 && strcmp(vetVeiculos[i].status, "Alugado") != 0; i++)
    {
        printf("\n%i %s %s %s %s %s",
               vetVeiculos[i].numero,
               vetVeiculos[i].placa,
               vetVeiculos[i].marca,
               vetVeiculos[i].modelo,
               vetVeiculos[i].ano,
               vetVeiculos[i].categoria );
    }
}

void printClientes()
{

    for (int j = 1; j<100 && vetClientes[j].codigo != 999; j++)
    {
        printf("\n%i %s %s %s %s", vetClientes[j].codigo,
               vetClientes[j].nome,
               vetClientes[j].cnh,
               vetClientes[j].telefone,
               vetClientes[j].endereco);
    }
}

void cadastraVeiculo()
{
    char desc[100], modelo[100], cor[100], placa[7], status[100], categoria[100], marca[100], ano[5], qtdOcupantes[10], qtdAssentos[10];
    int id = 1;
    float diaria;
    for (int i = 1; i<100 && vetVeiculos[i].numero != 999; i++)
    {
        id++;
    }

    vetVeiculos[id].numero = id;

    printf("\nPlaca do veículo: ");
    scanf("%s", &placa);
    strcpy(vetVeiculos[id].placa, placa);

    printf("\nMarca do veículo: ");
    scanf("%s", &marca);
    strcpy(vetVeiculos[id].marca, marca);

    printf("\nModelo do veículo: ");
    scanf("%s", &modelo);
    strcpy(vetVeiculos[id].modelo, modelo);

    printf("\nAno do veículo: ");
    scanf("%s", &ano);
    strcpy(vetVeiculos[id].ano, ano);

    printf("\nCategoria do veículo: ");
    scanf("%s", &categoria);
    strcpy(vetVeiculos[id].categoria, categoria);

    printf("\nQuantidade de assentos do veículo: ");
    scanf("%s", &qtdAssentos);
    strcpy(vetVeiculos[id].assentos, qtdAssentos);

    printf("\nValor da diária do veículo: ");
    scanf("%s", &diaria);
    vetVeiculos[id].diaria = diaria;

    printf("\nStatus do veículo: ");
    scanf("%s", &status);
    strcpy(vetVeiculos[id].status, status);

    printf("\nDescrição do veículo: ");
    scanf("%s", &desc);
    strcpy(vetVeiculos[id].desc, desc);
}

void cadastraCliente()
{

    printf ("2");

}

void cadastraLoc()
{
    int id;
    printVeiculosLivres();
    printf ("\n \nQual carro você deseja alugar? ");
    scanf("%i", &id);
    strcpy(vetVeiculos[id].status, "Alugado");
}

void validaLoc()
{

    printf ("4");

}

void pesquisaCliente()
{
    int i, cod, encontrei = 0;
    printf("\nDigite o filtro do codigo: ");
    scanf("%d", &cod);

    for(i = 0; i < 100 && vetClientes[i].codigo != 999; i++)
    {
        if(vetClientes[i].codigo == cod)
        {
            printf("\n\n----- Cliente encontrado! -----\n\n");
            printf("\n%i %s %s %s %s", vetClientes[i].codigo,
                   vetClientes[i].nome,
                   vetClientes[i].cnh,
                   vetClientes[i].telefone,
                   vetClientes[i].endereco);

            encontrei ++;
        }
    }
    if (encontrei == 0) printf("\n\n----- Codigo nao encontrado -----\n\n");
}


void pesquisaVeiculo()
{

    int i, cod, encontrei = 0;

    printf("\nDigite o codigo do veiculo: ");
    scanf("%d", &cod);

    for(i = 0; i < 100 && vetVeiculos[i].numero != 999; i++)
    {
        if(vetVeiculos[i].numero == cod)
        {
            printf("\n\n-----Veículo encontrado!-----\n\n");
            printf("\n%i %s %s %s %s %s", vetVeiculos[i].numero,
                   vetVeiculos[i].placa,
                   vetVeiculos[i].marca,
                   vetVeiculos[i].modelo,
                   vetVeiculos[i].ano,
                   vetVeiculos[i].categoria );
            encontrei ++;
        }
    }
    if (encontrei == 0) printf("\n\n----- Codigo nao encontrado -----n\n");

}

// Bibliotecas
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>

//Cores
#define CIANO   "\033[1;36m"
#define BRANCO  "\033[1;37m"
#define RESET   "\033[0m"

// Prototipação
int recursividadeDireta(int n);
bool par(int n);
bool Impar(int n);
void Vetor();
void Matriz();
void MatrizparaVetor();
void VetorparaMatriz();
void Palindromo();
void Curriculo();
void Linha();

// Variáveis Globais
int n = 0;
int Result = 0;
int cont = 0;

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    int opc = 0;
    do
    {
        system("cls"); 

        puts("Digite sua opção: \n1- Recursividade Direta\n2- Recursividade Indireta\n3- Carga Vetor\n4- Carga Matriz\n5- Matriz para vetor\n6- Vetor para matriz\n7- Palindromo\n8- Meu Currículo\n0- Sair\n");
        scanf("%d", &opc);

        switch (opc)
        {
            case 1:
            {
                puts("Digite o número para testar Recursividade Direta:");
                scanf("%d", &n);
                recursividadeDireta(n);
                Result = recursividadeDireta(n);
                printf("O fatorial de [%d] é: [%d]\n", n, Result);
                system("pause"); 
                break;
            }
            case 2:
            {
                puts("Digite o número para testar Par/Ímpar: ");
                scanf("%d", &n);
                if(par(n))
                {
                    puts("PAR");
                }
                else
                {
                    puts("ÍMPAR");
                }
                system("pause"); 
                break;
            }
            case 3:
            {
                Vetor();
                system("pause"); 
                break;
            }
            case 4:
            {
                Matriz();
                system("pause"); 
                break;
            }
            case 5:
            {
                MatrizparaVetor();
                system("pause"); 
                break;
            }
            case 6:
            {
                VetorparaMatriz();
                system("pause"); 
                break;
            }
            case 7:
            {
                Palindromo();
                system("pause"); 
                break;
            }
            case 8:
            {
                Curriculo();
                break;
            }
            default:
            {
                break;
            }
        } // Fim do Switch case
    } while (opc != 0);

    return(0);
}

// Recursividade Direta
int recursividadeDireta(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * recursividadeDireta(n - 1);
    }
}

// Recursividade Indireta
bool par(int n)
{
    if(n == 0)
    {
        return true;
    }
    else
    {
        return Impar(n - 1);
    }
}

bool Impar(int n)
{
    if(n == 0)
    {
        return false;
    }
    else
    {
        return par(n - 1);
    }
}

// Vetor
void Vetor()
{
    char Res;
    puts("Digite o Tamanho do Vetor: "); scanf("%d", &n);
    int Vet[n];
    puts("Deseja Preencher manualmente? (S/N)"); scanf(" %c", &Res);

    if(Res == 's' || Res == 'S')
    {
        for(int i = 0; i < n; i++)
        {
            printf("Posição [%d]: ", i); scanf("%d", &Vet[i]);
        }
    }
    else if(Res == 'N' || Res == 'n' )
    {
        srand(time(NULL));
        puts("Gerando Números Aleatórios.........");

        for(int i = 0; i < n; i++)
        {
            Vet[i] = rand() % 101;
        }
    }
    else
    {
        puts("Resposta Inválida\nEncerrando....");
        exit(0);
    }

    puts("Seu Vetor:");
    for(int i = 0 ; i < n; i++)
    {
        printf("[%d]", Vet[i]);
    }
    puts("");

    puts("Vetor ao Contrário:");
    for(int i = n - 1; i >= 0 ; i--)
    {
        printf("[%d]", Vet[i]);
    }
    puts("");
}

// Matriz
void Matriz()
{
    char Res;
    int L = 0;
    int C = 0;
    puts("Digite a Quantidade de Linhas: "); scanf("%d", &L);
    puts("Digite a Quantidade de Colunas: "); scanf("%d", &C);
    int Matriz[L][C];

    puts("Deseja Preencher Manualmente? (S/N)"); scanf(" %c", &Res);
    if(Res == 'S' || Res == 's')
    {
        for(int i = 0 ; i < L; i++)
        {
            for(int j = 0; j < C; j++)
            {
                printf("Posição Atual: [%d][%d]: ", i, j); scanf("%d", &Matriz[i][j]);
            }
        }
    }
    else if(Res == 'N' || Res == 'n')
    {
        srand(time(NULL));
        puts("Gerando Números Aleatórios...");

        for(int i = 0; i < L; i++)
        {
            for(int j = 0 ; j < C; j++)
            {
                Matriz[i][j] = rand() % 101;
            }
        }
    }
    else
    {
        puts("Opção Inválida\nEncerrando.....");
        exit(0);
    }

    puts("Sua Matriz:");
    for(int i = 0; i < L; i++)
    {
        for(int j = 0; j < C; j++)
        {
            printf("[%d]\t", Matriz[i][j]);
        }
        puts("");
    }
}

// Matriz para Vetor
void MatrizparaVetor()
{
    char Res;
    int L = 0;
    int C = 0;
    puts("Digite a Quantidade de Linhas: "); scanf("%d", &L);
    puts("Digite a Quantidade de Colunas: "); scanf("%d", &C);
    int Matriz[L][C];

    puts("Deseja Preencher Manualmente? (S/N)"); scanf(" %c", &Res);
    if(Res == 'S' || Res == 's')
    {
        for(int i = 0 ; i < L; i++)
        {
            for(int j = 0; j < C; j++)
            {
                printf("Posição Atual: [%d][%d]: ", i, j); scanf("%d", &Matriz[i][j]);
            }
        }
    }
    else if(Res == 'N' || Res == 'n')
    {
        srand(time(NULL));
        puts("Gerando Números Aleatórios...");

        for(int i = 0; i < L; i++)
        {
            for(int j = 0 ; j < C; j++)
            {
                Matriz[i][j] = rand() % 101;
            }
        }
    }
    else
    {
        puts("Opção Inválida\nEncerrando.....");
        exit(0);
    }

    puts("Sua Matriz:");
    for(int i = 0; i < L; i++)
    {
        for(int j = 0; j < C; j++)
        {
            printf("[%d]\t", Matriz[i][j]);
        }
        puts("");
    }

    puts("\n--- MATRIZ PARA VETOR ---");
    int k = 0;
    int Tam = L * C;
    int VET[Tam];
    for(int i = 0; i < L; i++)
    {
        for(int j = 0; j < C; j++)
        {
            VET[k] = Matriz[i][j];
            k++;
        }
    }

    puts("SEU VETOR:");
    for(int i = 0; i < Tam; i++)
    {
        printf("[%d]", VET[i]);
    }
    puts("");
}

// Vetor para Matriz
void VetorparaMatriz()
{
    char Res;
    int L = 0;
    int C = 0;
    puts("Digite a Quantidade de Linhas: "); scanf("%d", &L);
    puts("Digite a Quantidade de Colunas: "); scanf("%d", &C);
    int Tam = L * C;
    int Vet[Tam];
    int Matriz[L][C];
    puts("Deseja Digitar manualmente? (S/N)"); scanf(" %c", &Res);

    if(Res == 'S' || Res == 's')
    {
        for(int i = 0; i < Tam; i++)
        {
            printf("Posição [%d]: ", i); scanf("%d", &Vet[i]);
        }
    }
    else if(Res == 'N' || Res == 'n')
    {
        srand(time(NULL));
        for(int i = 0; i < Tam; i++)
        {
            Vet[i] = rand() % 101;
        }
    }
    else
    {
        puts("Resposta Inválida\nEncerrando...");
        return;
    }

    puts("Seu Vetor:");
    for(int i = 0; i < Tam; i++)
    {
        printf("[%d]", Vet[i]);
    }

    puts("\n\nPassando Valores para Matriz.....");
    int k = 0;
    for(int i = 0; i < L; i++)
    {
        for(int j = 0; j < C; j++)
        {
            Matriz[i][j] = Vet[k];
            k++;
        }
    }

    puts("Sua Matriz:");
    for(int i = 0 ; i < L; i++)
    {
        for(int j = 0; j < C; j++)
        {
            printf("[%d]\t", Matriz[i][j]);
        }
        puts("");
    }
}

// Palíndromo
void Palindromo()
{
    char Frase[100];
    char NFrase[100];
    int cont = 0;
    int Flag = 1; 

    puts("Digite a Frase:");
    scanf(" %[^\n]", Frase); 

    for(int i = 0; Frase[i] != '\0'; i++)
    {
        if(Frase[i] != ' ')
        {
            NFrase[cont] = Frase[i]; 
            cont++;
        }
    }
    NFrase[cont] = '\0'; 

    for(int i = 0, j = cont - 1; i < cont; i++, j--)
    {
        if(NFrase[i] != NFrase[j])
        {
            Flag = 0; 
            break;
        }
    }

    if(Flag == 1)
    {
        puts("VERDADEIRO (É um Palíndromo)");
    }
    else
    {
        puts("FALSO (Não é um Palíndromo)");
    }
}

// Currículo
void Curriculo()
{
    system("cls"); 
    
    printf(CIANO "=======================================================================\n");
    printf("                       JOÃO VITOR RUFINO SANTOS                        \n");
    printf("=======================================================================\n" RESET);
    
    printf(CIANO " Contato: " BRANCO "joaovitoroficialtrabalho@gmail.com                               \n");
    
    printf(CIANO " GitHub: " BRANCO "github.com/JoaoRufinoS | " CIANO "LinkedIn: " BRANCO "linkedin.com/in/joão-rufinos\n");
    
    printf(CIANO "=======================================================================\n\n" RESET);

    // --- RESUMO ---
    printf(CIANO "--- RESUMO E OBJETIVO PROFISSIONAL ------------------------------------\n" BRANCO);
    printf(" Desenvolvedor em evolução focado em Engenharia de Software Backend e \n");
    printf(" Soluções Técnicas. Interesses voltados para arquitetura de sistemas, \n");
    printf(" automação de processos e otimização de performance de algoritmos.     \n");
    printf(" Buscando oportunidade de Estágio ou vaga Júnior no setor financeiro.  \n\n");

    // --- FORMAÇÃO ---
    printf(CIANO "--- FORMAÇÃO ACADÊMICA ------------------------------------------------\n" BRANCO);
    printf(" * Análise e Desenvolvimento de Sistemas (Tecnólogo)                   \n");
    printf("   Faculdade de Tecnologia (FATEC) | Cursando o 3º Semestre            \n");
    printf("   Previsão de Conclusão: Julho de 2028                                \n\n");

    // --- COMPETÊNCIAS ---
    printf(CIANO "--- COMPETÊNCIAS TÉCNICAS ---------------------------------------------\n");
    printf(CIANO " * Linguagens de Programação: " BRANCO "Python, C, C++                           \n");
    printf(CIANO " * Sistemas Operacionais:     " BRANCO "Windows, Linux                           \n");
    printf(CIANO " * Ferramentas / Controle:    " BRANCO "Git e GitHub                             \n");
    printf(CIANO " * Outras Tecnologias:        " BRANCO "Visão Computacional                      \n\n");

    // --- PROJETOS ---
    printf(CIANO "--- PROJETOS EM DESTAQUE (PORTFÓLIO) ----------------------------------\n");
    
    printf(CIANO " 1. Controle de Mouse por Visão Computacional (Python)                \n" BRANCO);
    printf("    - Interface Homem-Máquina (IHM) voltada para acessibilidade.       \n");
    printf("    - Processamento de vídeo em tempo real para detecção de gestos e   \n");
    printf("      emulação de comandos do sistema (clicks e scroll).               \n\n");

    printf(CIANO " 2. Script Automatizador e Organizador de Arquivos (Python)            \n" BRANCO);
    printf("    - Automação robusta para gerenciamento e triagem de diretórios.     \n");
    printf("    - Implementação de tratamento contra erros de encoding e          \n");
    printf("      gerenciamento de fluxos de arquivos no sistema operacional.      \n\n");

    printf(CIANO " 3. Hub de Estruturas de Dados e Algoritmos (Este Console em C)        \n" BRANCO);
    printf("    - Ecossistema modular centralizado focado em lógica estruturada.   \n");
    printf("    - Implementação de algoritmos de recursividade avançada e          \n");
    printf("      linearização / redimensionamento bidirecional de matrizes.       \n\n");

    printf(CIANO "=======================================================================\n");
    printf("            Pressione qualquer tecla para voltar ao menu...            \n");
    printf("=======================================================================\n" RESET);
    
    system("pause > nul");
}
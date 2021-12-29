#include <stdio.h>
// include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

typedef struct { 
    char nome[15];
    char sobrenome[15];
    int nusp; 
    float P1, P2, Tf; //prova 1, prova 2, trabalho final
    float mf; //media final
} aluno; //tipo aluno com caracterisitcas de struct
void jo_miranha();
void limparBuffer(void){ //limpa o buffer
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

void Entrar(){
    
    //interface com o jupiterWeb, pedindo senha e usuario para realizar as ações do programa
    //as informações dadas na verdade não sao usadas durante o programa

    int nusp;
    char senha[10], senha2[10];
    int indice;

    char c1= ')', c2= '(';
    printf("\n     _                   _   _                  __        __         _            ");
    printf("\n    | |  _   _   _ __   %c_%c | |_    ___   _ __  \\ \\      / /   ___  | |__       ", c2, c1);
    printf("\n _  | | | | | | | '_ \\  | | | __|  / _ \\ | '__|  \\ \\ /\\ / /   / _ \\ | '_ \\ ");
    printf("\n| |_| | | |_| | | |_%c | | | | |_  |  __/ | |      \\ V  V /   |  __/ | |_%c |        ", c1, c1);
    printf("\n \\___/   \\__,_| | .__/  |_|  \\__|  \\___| |_|       \\_/\\_/     \\___| |_.__/     ");
    printf("\n                |_|                                                               ");

    printf("\n\t\t\tBEM VINDO AO JUPITERWEB\n");
    printf("\nEscolha dentre as opções:");
    printf("\n1. Sou Aluno da graduação\n2. Sou Aluno da pós-graduação\n3. Sou professor/ doscente\n"); 
    printf("\n>> ");
    scanf("%d", &indice);

    switch(indice){
        
        case 1:
            system("clear");
            break;
        case 2:
            system("clear");
            break;
        case 3:
            system("clear");
            printf("\nUsuario: "); scanf("%d", &nusp); limparBuffer();
            printf("\nSenha: "); scanf("%s[^\n]", senha); limparBuffer();
            system("clear");
            printf("\nSenha incorreta");
            printf("\nEsqueceu sua senha?\n");
            printf("\nUsuario: %d", nusp);
            printf("\nSenha: "); scanf("%s[^\n]", senha2);
            system("clear");
            break;
        default:
            break;
    }
}

void menu(){

    //essa funcao monta o menu que é repetido em looping
    //apenas printa na tela
    char c1= ')', c2= '(';
    printf("\n     _                   _   _                  __        __         _            ");
    printf("\n    | |  _   _   _ __   %c_%c | |_    ___   _ __  \\ \\      / /   ___  | |__       ", c2, c1);
    printf("\n _  | | | | | | | '_ \\  | | | __|  / _ \\ | '__|  \\ \\ /\\ / /   / _ \\ | '_ \\ ");
    printf("\n| |_| | | |_| | | |_%c | | | | |_  |  __/ | |      \\ V  V /   |  __/ | |_%c |        ", c1, c1);
    printf("\n \\___/   \\__,_| | .__/  |_|  \\__|  \\___| |_|       \\_/\\_/     \\___| |_.__/     ");
    printf("\n                |_|                                                               ");

    printf("\n ------------------------------");
    printf("\n|             MENU             |");
    printf("\n ------------------------------");
    printf("\n > 1. Cadastrar nova turma");
    printf("\n > 2. Procurar Aluno");
    printf("\n > 3. Estatisticas das turmas");
    printf("\n > 4. Salvar");
    printf("\n > 5. Encerrar\n");

}

void criar_turma( int n_alunos[], int n_turmas){

    //essa funcao serve apenas para pedir ao usuario o numero de alunos daquela turma
    printf("\nNumero de alunos: "); scanf("%i", &n_alunos[n_turmas]);
}

void bubblesort(int *a, int *b){
	
    //no bubblesort, se um numero é maior que o proximo numero do vetor inverte-se as posicoes, caso contrario nada é feito
    // essa funcao precisa ser rodada em 2 looping para percorrer todo o vetor até que ele esteja completamente ordenado
    int aux; 
	if(*a>*b){	
		aux= *a;   
		*a= *b;
		*b= aux;
	}	
}

void realloc_turmas(aluno **turmas, int ordena_n_alunos[], int n_alunos[]){
    
    /*O objetivo dessa funcao é garantir que o usuario possar digitar o numero de alunos que desejasse, e caso esse numero 
    seja pequeno, não haja perda de memoria. Nesse contexto, foi ordenado por meio do vetor ordena_n_alunos pela funcao
    bubblesort, em que a ultima posição esta o maior numero de alunos de todas as turmas. Assim realoca-se o numero de colunas
    (de alunos) da matriz **turmas, para que o ultimo numero de ordena_n_alunos seja seu novo numero de colunas.
    */
    int i=0;
    while(i<10){
        ordena_n_alunos[i]= n_alunos[i];
        i++;
    }i=0;
    //nesse passo é copiado os valores de n_alunos para ordena_n_alunos, pois necessitamos do vetor n_alunos intacto
    //uma vez que ele esta organizado, convenientemente, pelas turmas 


    while(i<10){	
        for (int j=0; j<9-i; j++)
            bubblesort(&(ordena_n_alunos[j]), &(ordena_n_alunos[j+1]));
        i++;
    } i=0;
    
    /*         |turma 1 | turma 2 | turma 3 | turma 4 |    |turma 10 |
    -------------------------------------------------- ... -----------
    | n_alunos |menor nº|         |         |         |    | maior n°|
    */
    while(i<10){
        turmas[i]= (aluno *)realloc( turmas[i], (ordena_n_alunos[9])*sizeof(aluno));
        i++;
    } i=0;
       /*     |aluno 1 | aluno 2 | aluno 3 | ... | aluno (maior nº de ordena_n_alunos) | 
    ----------------------------------------      ----------
    turma 1 = |        |         |         |     |         |
    turma 2 = |        |         |         |     |         |
    turma 3 = |        |         |         |     |         |
    turma 4 = |        |         |         |     |         |
    ...
    turma 10= |        |         |         |     |         |
    */
}

void info_alunos( aluno **turmas, int n_alunos[], int n_turmas){
    
    // Essa funcao registra as informações dos alunos para a turma
    //turmas[n_turmas][], n_turmas é o valor de turmas exigentes ate o momento, ou seja, a turma que deve ser cadastrada
    //o ciclo for serve para rodar todos os alunos da turma
    system("clear");
    for(int i=0; i<n_alunos[n_turmas]; i++){
        
        printf("\nAluno %i\n", i+1);
        
        printf("\nNome: "); scanf("%s[^\n]", (turmas[n_turmas][i].nome));
        printf("\nSobrenome: "); scanf("%s[^\n]", turmas[n_turmas][i].sobrenome);
        limparBuffer();
        printf("\nNumero usp: "); scanf("%d", &(turmas[n_turmas][i].nusp));
        printf("\nNota da P1: "); scanf("%f", &(turmas[n_turmas][i].P1));
        printf("\nNota da P2: "); scanf("%f", &(turmas[n_turmas][i].P2));
        printf("\nNota do trabalho: "); scanf("%f", &(turmas[n_turmas][i].Tf));
        
        turmas[n_turmas][i].mf= turmas[n_turmas][i].P1 + turmas[n_turmas][i].P2 + turmas[n_turmas][i].Tf;
        turmas[n_turmas][i].mf= turmas[n_turmas][i].mf/3;
        system("clear");
        //system("cls");
    }
}

void printa( aluno **turmas, int coluna, int linha){

        //funcao que printa as informacoe de determinado aluno, na linha e coluna especificadas
        system("clear");
        printf("\nNome: %s", turmas[linha][coluna].nome);
        printf("\nSobrenome: %s", turmas[linha][coluna].sobrenome);
        printf("\nNumero usp: %i",  turmas[linha][coluna].nusp);
        printf("\nNota da P1: %.2f", turmas[linha][coluna].P1);
        printf("\nNota da P2: %.2f", turmas[linha][coluna].P2);
        printf("\nNota do trabalho: %.2f", turmas[linha][coluna].Tf);
        printf("\nMedia final: %.2f", turmas[linha][coluna].mf); printf("\n");
        turmas[linha][coluna].mf>= 5? printf("\nO aluno passou com media final %.2f", turmas[linha][coluna].mf) : printf("\nO aluno NAO passou! A media final foi de %.2f", turmas[linha][coluna].mf);

}

int procura_aluno_rec( aluno **turmas, int col, int n_alunos[], char nome_proc[], char sobrenome_proc[],  int i){
    
    //essas funcao procura dentro de uma turma, o aluno desejado. Ela procura em 3 condiçoes principais, caso o col seja maior
    //que o n_alunos, ou seja, nao foi encontrado o aluno desejad- retorna -1 e encerra a recursão
    //caso o nome e o sobrenome sejam iguais ele retorna a coluna (o aluno) e para a recursão
    //caso o nome e/ou sobrenome não sejam encontrados, ele adiciona mais um em col (pula para o proximo aluno) e chama o
    //ciclo recursivo novamente, até que alguma condição de parada seja alcancada
    if(col >n_alunos[i]) 
        return -1;

    if(strcmp(nome_proc, turmas[i][col].nome)==0){
        if(strcmp(sobrenome_proc, turmas[i][col].sobrenome)==0){
            printf("\nAluno Enconrado com sucesso: ");
            return col;
        } else{
            col= col + 1;
            procura_aluno_rec(turmas, col, n_alunos, nome_proc, sobrenome_proc, i);
        }
    } else{
        col= col + 1;
        procura_aluno_rec(turmas, col, n_alunos, nome_proc, sobrenome_proc, i);
    }
}

void procura_aluno_base( aluno **turmas, int n_alunos[], int n_turmas){
   
    //essa funcao garante que a main fique mais "limpa", e que seja possivel criar as strings de nome e sobrenome procurados
    //dentro dessa função. A partir dessa função é chamado a função recursiva que procura aluno por aluno por aluno,
    //conferindo em qual posição o aluno procurado esta (caso ele esteja em alguma turma), retornando a posição da coluna
    //que ele se encontra. As linhas (turmas) são percorridas por um cico for
    char nome_proc[15], sobrenome_proc[15];
    int col=0;
    int lin=0;
    //system("clear");
        
    printf("\nDigite o nome do aluno procurado: "); scanf("%s[^\n]", nome_proc);
    printf("\nSobrenome: "); scanf("%s[^\n]", sobrenome_proc);

    for(int i=0; i<n_turmas; i++){    
        col= procura_aluno_rec(turmas, col, n_alunos, nome_proc, sobrenome_proc, i); //recursao pra procura aluno em uma turma
        if(col!= -1){
            lin= i;
            i=n_turmas;
            //A condicao tem como objetivo parar o looping caso ele ache o aluno (retorno != -1) 
            //o lin recebe o valor da linha (turma) que ele achou
            //i= n_turmas funcina como um exit(0) 
        }
    }
    col== -1? printf("\nvish... o aluno, infelizmente, não foi encontrado\n") : printa( turmas, col, lin);
    //caso o aluno não seja encontrado (retorno de col== -1) ele printa apenas a mensagem acima e encerra a busca, 
    //caso o aluno seja encontrado, ele printa as informaçẽos do aluno pra linha e coluna especificadas

    //para dar tempo do usuario visualizar as informações do aluno pelo tempo que necessitar, ele apenas tera que 
    //digitar 1 para voltar ao menu
    lin = 0; //reutilizacão da variavel para não ter que criar outra só para esse ciclo
    printf("\n\nDigite \"1\" para voltar ao menu: ");
    while(lin != 1)
        scanf("%d", &lin);
    system("clear"); 
}

void estats( aluno **turmas, int n_alunos[], int n_turmas,float  **matriz){
    
    //funcao que cria e printa as estatistica de cada turma, atraves da matriz com n_turmas nas linhas e as notas nas colunas
    // atraves de um ciclo que roda as turmas, para caa turma roda-se um ciclo para somar as notas de cada avaliação e depois
    //calcular a media dessa avaliação, a porcentagem de aprovados é somado 1 a cada aluno com media final >= 5
    //depois é printado tais informções
    int i=0, j=0;
    char c= '%';

    while(i<10){
        while(j<5){
            matriz[i][j]=0;
            j++;
        }
        i++;
    } i=0;

    /*  |turmas = | media P1 | media P2 | media trabalho | media final | porcentagem de aprovados |
        |------ = |----------|----------|----------------|-------------|--------------------------|
        |turma1 = |    0     |    0     |      0         |     0       |            0             |                          |
        |turma2 = |    0     |    0     |      0         |     0       |            0             |                          |
        |turma3 = |    0     |    0     |      0         |     0       |            0             |                          |
        |turma4 = |    0     |    0     |      0         |     0       |            0             |                          |
    ...
    */
    printf("\n| turmas = | media P1 | media P2 | media trabalho | media final | porcentagem de aprovados |");
    printf("\n|------  = |----------|----------|----------------|-------------|--------------------------|");
    
    while(i<(n_turmas)){
        
        j=0;
        while(j<n_alunos[i]){ // media P1
            matriz[i][0]=matriz[i][0] + turmas[i][j].P1;
            j++;
        }j=0;
        matriz[i][0]= (matriz[i][0])/(n_alunos[i]);

       while(j<n_alunos[i]){ // media P2
            matriz[i][1]=matriz[i][1] + turmas[i][j].P2;
            j++;
        } j=0;
        matriz[i][1]= (matriz[i][1])/(n_alunos[i]);

       while(j<n_alunos[i]){ // media Tf
            matriz[i][2]=matriz[i][2] + turmas[i][j].Tf;
            j++;
        }j=0;
        matriz[i][2]= (matriz[i][2])/(n_alunos[i]);

        while(j<n_alunos[i]){ // media mf
            matriz[i][3]=matriz[i][3] + turmas[i][j].mf;
            j++;
        } j=0;
        matriz[i][3]= (matriz[i][3])/(n_alunos[i]);

        while(j<n_alunos[i]){ // porcentagem de aprovados
            turmas[i][j].mf>=5 ? (matriz[i][4]=matriz[i][4]+1) : (matriz[i][4]=matriz[i][4]+0); 
            j++;
        } j=0;
        matriz[i][4]= (matriz[i][4]*100)/(n_alunos[i]);

        if(matriz[i][4]!=100)
            printf("\n|turma %i = |   %.1f    |   %.1f    |      %.1f       |    %.1f      |         %.1f%c            |", i+1, matriz[i][0], matriz[i][1], matriz[i][2], matriz[i][3], matriz[i][4], c);
        if(matriz[i][4]==100)
            printf("\n|turma %i = |   %.1f    |   %.1f    |      %.1f       |    %.1f      |         %.1f%c           |", i+1, matriz[i][0], matriz[i][1], matriz[i][2], matriz[i][3], matriz[i][4], c);
   
    i++;
    } i=0;
    
    //serve para deixar o usuario visualizar a tela pelo tempo que necessitar
    printf("\n\nDigite \"1\" para voltar ao menu: ");
    
    while(i != 1)
        scanf("%d", &i);
    system("clear");
}

void salvar(int *n_alunos, aluno **turmas, int n_turmas, float **estat){
    
    //a funcao salvar, cria 2 arquivos, um texto e um binario
    //no primeior armazena-se as informacoes de todos os alunos da turma (o usuario digita o nome do arqvo)
    //na segunda armazena-se as estatisticas da turma em um arquivo binario
    FILE *arquivo;
    FILE *binario;
    char nome[32];
    int i = 0, j=0;
    int bin;

    while(i < n_turmas){

        printf("\nDigite o nome do arquivo texto que voce deseja salvar a turma #%d: ", i);
        scanf("%s", nome);
        arquivo = fopen(nome, "wt");
        binario = fopen("estat.bin", "wb");

        if(arquivo == NULL){
            printf("Ocorreu um erro ao abrir o arquivo! Tente novamente.");
            exit(0);
        }
        
        while(j<n_alunos[i]){
            fprintf(arquivo, "nome: %s\nsobrenome: %s\nnusp: %d\nP1: %.2f\nP2: %.2f\nTf: %.2f\nmf: %.2f\n", turmas[i][j].nome, turmas[i][j].sobrenome, turmas[i][j].nusp, turmas[i][j].P1, turmas[i][j].P2, turmas[i][j].Tf, turmas[i][j].mf);
            j++;
        } j=0;
        
        while(j<5){
            fprintf(binario, "%.2f", estat[i][j]);
            j++;
        } j=0;

        fclose(arquivo);
        fclose(binario);
        i++;
    }        
}

int main(int argc, char *argv[]){

    //delcaração de variaveis
    int acao=0;
    int i=0;
    int n_turmas=0;

    //declaração de vetores para o numero de alunos
    int *n_alunos= ( int *)malloc(10*sizeof(int));
    
    /*        |turma 1 | turma 2 | turma 3 | turma 4 | turma 5 | turma 6 | ...
    ---------------------------------------------------------------------
    n_alunos = |        |         |         |         |         |         |
    */
    
    int *ordena_n_alunos= ( int *)malloc(10*sizeof(int));
    // ordena do tipo >> 3 4 2 1 5 em 1 2 3 4 5

    //matriz com as turmas 
    aluno **turmas= (aluno **)calloc( 10, sizeof(aluno*)); 
    while(i<10){
        turmas[i]= (aluno *)calloc( 10, sizeof(aluno));
        n_alunos[i]= 0;
        ordena_n_alunos[i]= 0;
        i++;
    } i=0;

    /*     |aluno 1 | aluno 2 | aluno 3 |aluno 4 | aluno 5 | aluno 6 | ...
    ---------------------------------------------------------------------
    turma 1 = |        |         |         |        |         |         |
    turma 2 = |        |         |         |        |         |         |
    turma 3 = |        |         |         |        |         |         |
    turma 4 = |        |         |         |        |         |         |
    ...
    */

    //matriz para as estatisticas
    float **matriz= (float **)calloc(10, sizeof(float*));
    while(i<10){
        matriz[i]= (float *)calloc( 5, sizeof(float));  
        i++;
    } i=0;
    
    Entrar(); //interface do JupiterWeb

    /*O programa foi condensado em um switch na main (após as declarações) que chama as funcoes necessarias, a partir do quq
    o usuario digitar como acao, baseado no menu

    */
    while(1){    //looping até o usuario pressionar 5
        
        menu();
        printf("\nDigite a acao que deseja realizar: "); scanf("%d", &acao);
        
        switch (acao){
        
        case 1:    //criar uma nova turma
            system("clear");
            criar_turma( n_alunos, n_turmas);
            realloc_turmas( turmas, ordena_n_alunos, n_alunos);
            info_alunos( turmas, n_alunos, n_turmas);
            n_turmas++;
            break;
        case 2:   //procurar um aluno
            system("clear");
            procura_aluno_base( turmas, n_alunos, n_turmas);
            break; 
        case 3:    // gerar estatisticas de todas as turmas
            system("clear");
            estats(turmas, n_alunos, n_turmas, matriz);
            break;
        case 4:     // salvar o programa em um .txt e um .bin
            system("clear");   
            salvar(n_alunos, turmas, n_turmas, matriz);
            break;
        case 5:     // fechar o programa
            system("clear");
            jo_miranha();
            printf("\nEncerrando o sistema...\n");
            for(int f=0; f<n_turmas; f++){
                free(turmas[f]);
                free(matriz[f]);
            }
            free(turmas);
            free(matriz);
            free(n_alunos);
            free(ordena_n_alunos);
            exit(0);
            break;
        default:
            break;
        }
    }
return 0; 
}

void jo_miranha(){

//dispensa comentarios...
printf("\a\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.........................................................................................................................................''''',,;:cloddxxxdoc:::c::;;;;;;;;;,,,,,'''''''''''''..............................................................................................................\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t........................................................................................................................................''',,,;;:clodddddddoc::::::;;;;;;;;;,,,,,''''''''''''''..................................................................'..........................................\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t..........................................................................................................................''...........'',,,,;;:clodddddddooc::;;;:;;;;;,;;;,,;,,,'''''''''''''..................................................................''.........................................\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.........................................':c;............................................................................'''''....'''''',,;;;::clooddddddddlc:;;;;::;;;;;;;;;;;;,,'''''''''''''................................................................';od,........................................\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.........................................;dlcl:'.........................................................................'''''..''''''',,;;;;::cloooddddddoc:::;;:::::;;;;;:::;;;,,,,,'''''''..................................'''''.........................,cooOO;........................................\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.........................................;dc',cc:'.........................................................................''''''''',,,,,;;;;;:cllooddddddollc::::::::::;;:::cc::;;,,,,,'''''.............................'''''''''''......................,clc;,k0;........................................\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.........................................;dc''.':cc,.........................................................................'''''''',,,,,,;;;::coddddxxxddxdollccc:::::::::cclc:;;;;;,,,,'''''...'''......''''''''''''''''''''''''''''''''.............';cc:,',;k0;........................................\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.........................................;xl''....;:c;........................................................................'.'''''',,,,,,,;;:codxxxxxxxxkkxddolcc::::::::cccc:;;;;;,,,,,'''''''''''''''''''''''''''''''''''''''''''''''............';c:;''',,;O0;........................................\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.........................................:xl''......'::;.................',,,,'''.........','''''','','..'...................''''''''''',,,;:::clodxxxkkkkkkOkkxdolccllllccc:c:;;;;;;,,,,,,,,,,,;;;;,,,''''''''''''''''',,,,,;;;,''''''''''''.....'.';:;'..''',,:O0;........................................\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.........................................:xl,'.........;:;'..............,cccoodc.........;l:cccddllllc,':,...............'''''''''''',,,';lllodddxxdxkkkOOOOOkxdolllddddddc::;;,,,,,,,,,;odllllolloccc,'''''''''',,,,,';clcloll:',''''''''''''''.',;,.....''',,:O0;........................................\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...................................''''''cko,''.........'l;..............,:ccodxc'........,lloooxxooolc:':;............'''''''''''''',,,,,:lllodxddxddxxkOOOOkxdollloddddddc;;;;,,,,,,,,,;oxoooddolollo;',,,,,,,,,,,,,,,coooodol:',''''''''''''''.;:.......''',;c00:........................................\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t....'''''''''''''''''''''''''''''''''''''cko;''.........'o:''.......''''',;;::;;,''','....,:::;;::::::::;::,'...',,,,'',,,,,;,;;;,,,;:::;;:lllllooooddxkkOOOOxdoollodoodoolc::::;;,;;,,;;;:clllccccllc:;',,,,,,,::;;;;;;cclccccc:,,,,,,,,''''''''.;:.......''',;c00:.'......................................\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t''''''''''''',,,,,,,,,,,,,''',,,',,'''',,lOd;,'.........,oc,''.....':lllll:;:';c:lllll,...'::c::lcllclcclloo:'..,cocclooolcloloooc::codoooddlolcodxdoxkkxkkxxxdxodddddddddllolloc;;;;;;:::coolodooooccc,,,,,,,,:olloll:c:clcooolccoc:lcc;''''''''.,:.......''',;l00:''''...................................'\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t'''',,,,,,,,,,,,;;;;;;;;;;,,,,,,,,,,,,,,;oOd:,''........,oc,,'''''',lddlco:;c,coldxoll;...,clolc;;do;ccccoxkl'..,:cc:dkdolldoooodc:ccodoxkkdodocodxdoxkxxxkddxxxddxdddddddlodoooc:::ccccccloolodxkxdclc,,,;::;,coccolc:ccclcxxddlldlcool;'''''''..,:......'''',:lKKc'''''''''...........'.'''.....''''''''''\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t',,,,,,,,,;;;;;;:::::::;;;:;;;;;;;,,,;;;:o0x:;''........,oc,,'''''',:cllllc:c:cllllllc,..,clclllccllccllllll:'..:ccc:cooollolllodlccloddooodoooloddooddddxxdxkkddxdxdddooolodoool:ccooccccllllooooooclc;,;:ll:,:olcc:cccccccloolcllllool:,,,'''''.,;......''',;:oKKc,,'''''''''''''''''''''''''''''''''''',,\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t,,,,,,,;;;;;;::::cccccccc::::::;;;;;;;;:cd0xc;,'........,oc,,'''''''''',,'''''''''''''....'''.'''''''''''''''..'',,,,,,,;;;;;::::clloolllccccccclllllooddddxkkkxxxxxddooollllllccccllcccccc:::::;;::;;;;;;;;,,,,;,,,,,;,,;;;,,;;;;;;;;;;;,,,,,,,'.';'....'''',;cdKKl;,''''''''''''''''''''''''''',,,,,,,,,,;\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t,,,,,,;;;::::ccccccccccccccc:::::::::::ccxKkc:,'........;dc,,,,,,,,,''''''''...............................''''''''''',,,;;;:ccclllooooooolllllloooodddxxkkkOOOOOOOOkxxddoooolllllllllcccc::::::;;;;;;;,,,,,,,,,,,,,,,,,,,,,,,,,,,;;;;;;;;;,,,,,'.,;'.....''',:cdKKo;;,,,,,,,,,,,,',,''',,,,,,,,,,,,,;;;;;;;\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t,,,,;;;;::cccclllllllllccccccccccc::::cllxKkl:;''.......;dc,,,,,,,,,,,'''''''''''''...................'...'''''''''',,,,;;;:clloooooddddddddoooooddxxxxkkOOO0000000OOkkxxdddooooollllllllcccc:::;;;;;;;,,,,,,,,,,,,,,,,,,,,,,,,,,;;;;;;;;;;;;,,,'.';'....'''';:ldXXd:;,,,,,,,,,,,,,,,,,,,,,,,,;;;;;;;;::::::\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t,;;;;;:::ccccclllllllllllcccccccccccccclokKOoc:,'.......:x:',,,,,,,,,,,''''''''''''''.'''.'...'...'.'''''''''''''',,,,,;;;:cclooddddddxxxxxxxddxxxkkkOOO000KKKKKKK000OOkkxxxdddddooooollllllccc::::;;;;;;;,,,,,,,,,,,,,,,,,,,,,;;;;;;;;;;;;;;;;;'.';'....'''';clxXXdl:;;;;;;;;;;;;;;;;;;;;;;;;;::::::ccccccc\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;;::::cccclllllllllllllllllllllllcclodOXOol:,''......:x:',,,,,,,,,,,,,'''''''''''''''''''''''''''''''''''''''',,,,;;;;::ccloodddxxxxkkkkkkkkkkOOO00KKKKKXXXXXXKKKKK00OOkkxxxxdddddoooooolllccc::::;;;;;;;;;;;;,,,,,,,,,,,;;;;;;;;;;;;;;;;;;;;'.';'...'''',;cokXXxoc:;;;;;;;;;;;;;;;;;:::::::ccccclllllloo\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;;::::ccclllllllooolloollllllllllllloxOX0doc;'''.....:x:';;;;,,,,,,,,,,,,'''''''''''''''''''''''''''''',,,,,,,,,;;;;;::cclloodddxxxkkkkkkkOOOO00KKKXXXXXXXXXXXXXXXXKK00OOOkkkxxxxdddoooooolllccc::::;;;;;;;;;;;,,,,,;;;;;;;;;;;;;;;;;;;;;;;;;'.';'..'''',,;ldkNNkdoc:::::::::::::cccccccclllllllloooddddd\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;;:::::ccclllllloooooooolllolllloooodk0X0xoc;''''....:x:';;;;;;;;,,,,,;;,'''''''''''''''''''''''''''',,,,,,,,,;;;;;:::ccllloodddxxkkkOOOOO000KKKXXXXXXNNNNNNXXXXXXXXKKK000OOOOkkxxxxddddoooolllccc::::::;;;;;;;;;;;;;;;;;;;;;;;;;;:;;;;;:::::,.';'..'''',,:ldONNOxdolllllllcccccccllllllloooooooddddxxxxx\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;:::::cccllllloooooodddoooooooooooodxk0NKkdl;,'''....cx:';:::;;;;;;,,;ll:;,,,''''''''''''''''''''',,,,,,,,;;;;;;;:::ccccllloodddxkkkOO00000KKXXXXXXNNNNNNNNNNNNXXXXXXXXKKKK000OOOkkkxxxxdddoolllccc:::::::::;;;;;;;;;;;;;;;;:cdd:;:::::::::::,.';'.'''',,,:oxONN0kxoooooooooooollolloooooodddddxxxxkkkkkk\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;::::ccccllllloooddddddddoooooodddddxk0NXOxo:,'''....cx:';:::::;;;;;;;o:.,:;,,,,'''''''''''''',,,,,,,,,,;;;;;;:::::cccllllooooddxkkOOOO0000KKXXXXXXNNNXXNNNNNNNNNNNNNNXXXXXKKK000OOOOkkkxxxddooollcccc:::::::::::::::::::::locldc::::::::::::,.','.'''',,;cox0NNKOxddddddddddoooodooddddddddxxxxkkkOOOOOO\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;:::::cccclllloooooddddddddddddddddxxxkOKNXOko:,'''''..cd;';:::::::;;;;;o:...,::,,,,,',,,,,,,',,,,,,,,,,,;;;;::::::cccccllllloooddxxkkOOO0000KKKKXXXXXXXXXNNNNNNNNNNNNNNNNNNNXXXXKKK000OOOOkkkxxdooolllccccccccc::::::::::cooc,.;dl:ccccccccccc,.....''',,,;cdk0NWKOkxxxxxxxdddddddddxxxxxxxxxxkkkkOOO00000\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t::::::cccclllooooodddddddddodxxxxxxxxxxkOKWX0koc,,'''''.cd;';:cc:::::::;:o:.....';:;,,,,,,,,,,,,,,,,,,;;;;;;;::::cccccclllllllooooddxxkOOOO0000KKKKXXXXXNNNNNNNNNNNWWWWWWNNNNNNNNXXXXXKKKK00OOOkxxdddoooolllllllccccc:ccclll:'...;dl:ccccccccccc,.....''',,;:ldkKWWX0OkkkkxxxxxxxxxxxkkkkkkkkkkOOOOOO00KKKKK\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t::::::ccclllloooooddddddxxdoxxkkkkkkkkkO0XWNKOdc;,,''''.cd;';ccccc:::::::oc.......';:;,,,,,,,,,,,,,,,;;;;;;::::ccllllllllloooooodddxxkkOOOOO000KKKXXXXNNNNNNNNNNWWWWWWWWWWWWWWWNNNNNNXXXXKKK00OOkkxxxdddddoooooolllllccloc;......;dlclllllllllll,.....''',,;:lxOKWWXKOOkkkkkkxxkkOOOOOOOOOOOOO00000000KKKKKK\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t:::::cccllllooooddddddxxxkdoxOkkkkOOOkOO0XWWKOdl;,,,'''.cd;':ccccccc:::::oc.........',::,,,,,,,,,,,;;;;;;::::ccllooooooooooooodddxxxkkOOOOOO000KKXXXXXNNNNNNNNWWWWWWWWWWWWWWWWWWWWNNNNNXXXKKK00OOkkkkxxxxxxdddddooooool:,........;doclllllllllll;....''',,,,:lxOXWWNK0OOOkkkkOOO00000000000000000KKKKKKKKKKK\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t::::ccccllloooddddddxxxxkkxdkOOOOOOOOOO0KXWWXOxl:,,,'''.cd;':llllcccccc::dc............,c:,,,;;;;;;;;;;;::::ccllodddddddddddddxxxxxkkOOOO00000KKKKXXXNNNNNNNNWWWWWWWWWWWWWWWWWWWWWWWNNNXXXXXKKK00OOOkkkkkkkxxxxxddddl:'..........;dolooooooooooo;....'',,,,;:ox0XWWNK0OOOOOOOOOO000KKKKKKKKKKKKKKKKKKKKKKKKK\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tcccccccclllooddddxxxxkkkkOxokOO0000OOOO0KNWWX0xo:;,,,'''cd;':lllllllcccccdc............'xo,;;;;;;;;;;;;::::cccloodxxxxxxxxxxxxkkkkkkOO000000KKKKKKXXXNNNNNWWWWWWWWWWWWWWWWWWWWWWWWWWNNNNNXXXXKKK000OOOOOOOOkkkkxxxol;............;dolooooooooddo;....'',,,;;:ox0NWWNXK0OOOO0000000KKKKXXXXXXXXXXXXXXXXXXXXXX\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tccccccccllloodddxxxkkkOOOOdoxOOOOOOOO00KXNWMN0ko:;,,,,''ld;'coooolllllcccdl............,kd,;;;;;;;;;::::ccccclloodxxxxxxxkkkkkkOOOkkO0000000OkO0KKXXXNNNNWWWWWWWWWWWWWWWWWWWWWWWWWWWNNNNNNNXXXXXKK000000OOOOOkkkkxc;;............:xoododdddddddd:....'',,,;:cox0NMMNXK000000000000KKKKKKKKXXXXXXXXXXXXXXXXXX\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tllccclllllooooddxxkkkOOO0xooxkOOOOOOO00KXNMMN0koc;,,,,,'ld;'cdoooooolllllxo............,kd,;;;;;:::::::cccclllooodxxxxkkkkkxxxxxxdl::ldxkkkkxdooodxkkO0KNWWWWWWWWWWWWWWWWWWWWWWWWWWWNNNNNNNNXXXXXXKKKKK000OOOOkkkd;;;............:xooddddxxxdddd:...'',,,;;:ldk0NMMWXKK0000000KKKKKKKKKKKKKKXXXXXXXXXXXXXNNN\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlllllllllloooddxxkkkOOO0OocdxkO0000000KKXWMMNKkdc:;;,,,'ld;'cdddddooooollko'...........,kd,:::::::::::ccllllloooddxxkkkkdc::;,,,;;;clc:cccc:clc:,,;:cllodxO0KXWWWWWWWWWWWWWWWWWWWWWWWWWNNNNNNNNXXXXXXXKKK00OOOOOOd;;;..'.........:xddddxxxxxxxxx:...'',,;;::ldkKNMMWNXKKKKKKKKKKKKKKKKKKKKKKXXXXXXXXXXXNNNNN\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlllllllooooooddxxkOOO000kcldxxk0KK000KKXNWMMNKkdl:;;,,,,ld;'cxxxdddddooookd'...........;kd;::::::::ccccllllooodddxdolcc;'..',:;;::;::c:c:'...'....,;;;,;::ccclox0XNWWWWWWWWWWWWWWWWWWWWWNNNNNNNNXXXXXXXXKK000OOOOx;;;'..'''......:xddxxxxxxxxxkxc...',,,;;::ldkKNMMWNXXKKKKKKKKKKKKKKXXXXXXXXXXXXXXXXNNNNNNN\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlllloooooddddddxxkOOO00OlcddddxOKKKKKKXNWMMMNKOdlc:;;,,,od;,lkkxxxxxddddoOx,...........;ko;:cccccccclllllooooddddl::,.....''.,:,..... ..,..     .....   ..';clc,,lx0XX0KWWWWWWWWWWWWWWWNNNNNNNNNNNNNXXXXXKKKK0000x:;;'''''''.....:xdxkxxxxkkkkkkc...',,,;;::ldkKNMMWNNXXXXXXXXXXXXXXXXXXXXXXXXXXXXNNNNNNNNNN\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlllloooodddddddxxkOOO0Ol;cddxxxxOKKKKKXXWMMMNKOdoc:;;;,,od;,lkkkkkxxxxxddOx,.'.........;ko;cccccccllllllooodddxxo:,'.........                        .......';::,..';coONWWWWWWWWWWWWWNNNNNNNNNNNNNNNXXXXXXXKKK0Kk:;;'''''''...'.:xdxkkkkkkkkkkkc...',,;;;::ldk0NWMWNNXXXXXXXXXXXXXXXXXXXXXXXXXXNNNNNNNNNNNN\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlllllooooddddxxxkOOO00d,;lollllokKKKKXXXNWMWX0kdoc::;;;,od;,oOOOkkkkkkxxx0k,.'.........;ko;clllllllloooooodddxxxdc,'......                        .........''...,....;:lxXWWWWWWWWWWWWWNNNNNNNNNNNNNNNNXXXXXXXKKKk:;;''''''''.''.:xxkOkOOOOOOOOkc...',,;;;:cldk0XWMWNXXXXXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tccllllooodddxxxkkOO000d;:olcllldOKXKKXXXNWMWX0kdlc::;;;;dd;,oOOOOOOOkkkkx0k;'''''''..'.;ko;loooooooooooddddxxxdddc.  .....                        ...................;:cldOXWWWWWWWWWWWWNNNNNNNNNNNNNNNNNNNXXXKKKO:;:'''''''''''.:xxkOOOOOOOOOOOc...',,;;::cldk0XWMWNNXXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tccccllloooddxxxkkkOO00x::olcclldOKKKKXXNNWMWXOkdlc::;;;;dd;,o00000OOOOOkkKO;''''''''''.;ko;oddddddddddddxxxxkxdo:,.              ..........'''...              ..... .;;;clo0NWWWWWWWWWWNNNNNNNNNNNNNNNNNNNNXXXXXO:;:'''''''''''.:xxkOOOOO0OOOOOc..',,,;;:ccodk0XWMWNNNNNNNNNNNNNNNNNNNWNNNNNNNNNNNWWWWWWWWW\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tcccclllloodddxxxkkkOOkc,;oooddddx0XKKXXXNWMWKOxdlc:::;;;dd;,dKK00000000OOKO;''''''''''.:ko:oxdddxxxxxxxxxkkOkd:'.         ......'',;:cloddxxxddo:,'..    ......  ..'.....':clkNWWWWWWWWNNNNNNNNNNNNNNNNNNNNNNNXXXO:;:'''''''''''.:xxkO000000000Ol..',,;;::ccldkOKWMWNNNNNNNNNNNNNNNNNNWWWWWWWWWWWWWWWWWWWWWW\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tccccllllooodddxxxxkkkd:,cxdkxxkxk0KXKKXXNWMNKOxolc:::;;:dd,,dKKKKKKKKK000KO;''''''''''':ko:dxxxxkkkkkkkkkOO0kc''..     ..',;:clloodkkOO000K00OOkxdc,.....  ........... ....;::kNWWWWWWWNNNNNNNWNNNNNNNNNNNNNNXXXXO:;:'''''''''''.cxxO00K00KKKKKKl..',,;;::clodkOKWMWWNNNNNNNNNNNNNNNNWWWWWWWWWWWWWWWWWWWWWWW\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlclllllloooodddxxxxkxc;:dxdxdxkxkO0KKKXXNWMN0Oxolc::::;:xd,,dXXXXXXXKKKK0KO:''''''''''':ko:xkkkkkkOOOOO0000KOl;'....',;;:codxxxkkkOOOO000KKKK00Okxo;..................  ....,;l0WWWWWWNNNNNNNNNNNNNNNNNNNNXXXXXXXO:;:'''''''''''.:xkKKKKKKKKKKXXo..,;;;::cclldkOKNMWNNNNNNNNNNNNNNNNWWWWWWMMMMMMMMMMMMMMMMMW\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlcclllllooooodddxxxdl,:oddxdxkxxkxkOKKXXNWMN0kxocc::::;:xd,,dXXXXXXXKK0Okxo'..''.....'':ko:xOOOOOO0000KKKKKKKko:';loodddxxxxxkkkkkOOOO00KKK0000OOkd:...........        ..  ..;lONWWWWWNNNNNNNNNNNNNNNNNNNXXXXXXXKO:;:'''''''''''':dx0KKKKKKKKXXXo..;:;;::cclldxOKNMWNNNNNNNNNNNWWWWWWWWMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlllllllllloooodddddc,,:odddddxddxxxxk0XNNWMNOkdocc::::;:xd,,dXXXXKOxoc;,... ...........'c;;dkOO000KKKKKKXXXXKOxxkkxxxxxxxxxkkkkkkkkkOOO000000000Okxo;..........        ..    'oOXNWWWWWNNNNNNNNNNNNNNNNNXXXXXXXXKOc;:'.''''',,,;;:clox0KXXXXXXXXo..;c;::ccllodxOKNMWWWNNNNNWWWWWWWWWWMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tooollllloooooodddoc;,;lxxollllloooodxOXNWWMNOxdlc::::;;:xd,,dXXKx:'........  .....    ......'cdO0KKXXXXXXXXXX00XXOkxxxxxxxxxkkkkkkkkkkOOO00000000Okdl;,''......         ..    ,d0NNWWWWNNNNNNNNNNNNNNNNNNXXXXXXKKOc;:,,,;;;::ccccccc:clxOKXXXXXXo..:c;:cccllodxO0NMWWWWWWWWWWWWWWWWMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tdddddooooooooodddo:;;;okxolcllccllldkkKNWMMXOxdlc:::::;:xd,,dKxc'.           .....           ..;okKXXXXXXXXNX00XKkxxxxxxxkkkkkkkkkkOOOO0000000000OOkdlc:;'..             ..  .'ckXNWWWWNNXXXXXXXXXNNNNNNXXXXXKK0Odc::::ccccccccccccccc:cldkKXXXXo..:c::cclllodkO0NMWWWWWWWWWWWWWWWMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tddddddxxxxdddddddl::;;dkooxxxxxxkkkkkO0XWWMXkxolc:::::;:xd,':;....  ....',;,,,,;,,'.....        .'ckKXXNNNNNNX0K0xxxxkkkkkkkkkkkkkxkkkO000000000000Okxdoc;'.               .';''cOXNWWWWNNXXXXXXXXXXXNNXXK0Oxdolcccccccccccccccccccccccc:ccox0NNo..:c::cclllodxk0NMWWWWWWWWWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tddddddxxxxxxkkkkdccc;;odcokkkkkxxkkxkOOKNWWXkdolc::::;;:xd,..  ....,:clodddddddddollcc:;,'.        'oKNNNNNNNNX0kxxxkxxxxxxxkxxxxddddooodxkOOOO00000OOOOko:..              ..   .cONNWWNNNNXXXXXXXXK0Okxolccccccccccccccccc:::ccccccc:ccccccclxOl..;c::cclloodkk0NMWWWWWWWWWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tooooodddddxxxkkkoc::::dxldO0KXKK0OkxkO0XXNWXkdolc::::;;;::.    .:looddxxxxxkkkkxxxddddooolc,.       .oXNNNNNNNNKkxxdooloooddxddxxdoollloddxOOOOOO0000000Oko,.              .    .;o0NNNNNXXXXXXKOxolcc:::cccccccccc:ccloddxxxxxddolc::cccccccccc:,,',;:ccllodxkk0NMWWWWWWWWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tddddddddddxxxkkkd::c::dxcd0KXXXKXXOxkO0KXNWXkdolcc:::;;;,.  .'..,cdxxkOOOOOOOOOOOkkxxddddol:,...     .dXNWWNWNXOxdolccccccllooooddooloooddxkkkkOOO0000000Ox:..        .'.. .    .';:dKNXXXXXXXKxc:ccccccccccccc:cldkOKXNWWWMMMWWWNXKOkdlc:ccc:cccc:;;::cllooddxk0NMWWWWWWWWWWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tdxxxxxxxxxxxxxkkdccl::dxcdKXNXKKXXKxxO0KKXWXkdlccc::::;;.  .;llc,''cxO0O000000000OOkkxxdddlc:,..      'xNWWWWNXOdooodxxxdlccloddxxdolc:;,',ldddxkO00000000Oo;.     .'cxkxdc'    .,;''cOXXXXXXXOl:ccccccccccc:cok0NWMMMMMMMMMMMMMMMMMMMWN0kocc:ccccccc:cclloodxxk0NMWWWWWWWWWWWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\txxxkkOOOOOOOOOOOxlll::dxcoOKXNNNXK0kkkOKKXNNKxlccc:::;;'.  .:odxxdc,.;ok0000O000OOOkxxxxdolc:,..       ,OWWWWWWKxdolccclollccoxkkkxdoc;:;,:xOOOOO0KKK00000Oko:,...'cdO00OkOx'   .,;,'':xKXXXXKxc:ccccccccc:lx0NMMMMMMMMMMMMMMMMMMMMMMMMMMMN0xlcccccccccccloddxxOXWWWWWWWWWWWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tddxkkOO00KKKKKKKOoll::dklokO00K00OOxxOOKKKXNNXkocc:::;;'   .:odxxkkko;.':oO0OOOOOOkkxxxddolc:;......   .xNWMMMWXxo:,;'.'lolollxkOkkkxddddxxkOO000KKK00000K0Oxolc;';lx0KKK0OOo.  .,;,,,,ckKXXX0occccccccc:lxKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKxc:ccccccccclodkKNWWWWWWWWWWNNWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\toddxxkkkO00KKKKX0dlc::dxllodddxddddoxkOKXXXNNNNKxlc:::,.   .:odxxkkOO0ko;',cdO0OOkkdooollc::c:,....    .oXWMMMMXOdoodolodxxxodxOOOkkkxxxxkkkOOO000000000KK0Okxoc:loooxO00000o. .';;,,,,;okKXXkl:cccccccco0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0occccccccccclkXWWWWWWWWWWWNNWWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\toooddxxkkOO00KKKOoc:::dkxoooooolllloxkOKXXXNXNNNN0dc::;.   .cldxxkkOOO000kl'.:oxxo:,'......',;:'....   .lXWMMMMXOkkkxxxxxxxddxkO00OkkkkxkkkkkOO00000000KKK00OkkxxxkkooxO000O; .',;,,,,,,:ox0KdcccccccccxXMMMMMMMMMMMMMMWWNXKKKXNWWMMMMMMMMMMMMMMXxcccccccccc::lONWWWWWWWNXKXXNWWMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlooddxkOO000000Kkl::;:ldxdodooooodddddkKKKXXXKXXXNXOl:;.   'clooolc:::ldkOOx:';odddoc;'....  .,;;,..   .cKWMMMMXOkkxxxxxxdddxkk000OkkkxddxxxkkO00OOO00KKK0OOOkO00OO0kxkO000l. .,;;;,,,,,,:doolcccccccckNMMMMMMMMMMMMWXOxolcccccloxOXWMMMMMMMMMMMMNxccc:::;;;,,'lKWWWWWWNK000KXNWMWMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tloodxkkkkOOOOOO0kl;;,;okOxoolloooolldxOKKKKKKKKXXNWWXxc'  .,:;;;;,,'..',;;:,..,lx0NWNOc.       .''''.  .;xKWMMWXkxxkkkxdoodxxxkO000OOkdolcoddxxkOOOOO0KKK0O00O00OO00OkOO00o. .,;;;;;,,,,,,lc,:cccccccxNMMMMMMMMMMMWKxlc:ccccccccccclxKWMMMMMMMMMWXOc;;,,,''',',dNWWWWWWNK0KKKXNWMWWMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tooddxxxxkkkkOOOOOd:;;:ok0Okxddxdddooxk0KKKKKKXXXXNNWWW0:. .',,;;;;;;,',,..,:...:lokKX0l.       .;'  ..,;::dXWMMXkxxxxxdocloooodxxdoodddddlclodddxkkkOO00000000000OOkkOO0k:...':;;;;;;,,,,,:c;:ccccc:oKMMMMMMMMMMMNkccccccccccccccccc:lkNMMWNKOxdl:;,'''''''',';OWWWWWWWX00KKKKXWWWMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tddddxxxxxxkkkOOOOxl:::oxO0kxdxkxdxddxk0KKKXXXXXXXNNNWWWO;..;::,',;'.';cc,;kOd'..',;cc:'.       ,c;...::clloONMMNkddddddl:;;,,,;:ccccldxkxxdoooddxxxkkOOO0000000000OOkko:.   .':;;;;;;;;,,,,;:ccccccckNMMMMMMMMMMNxccc:ccccccccccccccc::oxdl:;,'''','''''','','lKWWWWWWNK0O000KKNWWWMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\txxxxxxxxkkkkkkOOOxlc::ok00kxdxkxdxdddk0KKXXXXXXXNNNWWMXxc,.,cc:;;:::codo:o00kl,........       'clc,.',;lood0NMMXkdoooooolccc::cclddxkkOOkkkxxxxxxkkkOOOO0000000Oxolc:'.    ..;:;;;;;;;;;,,,;:ccccc:l0MMMMMMMMMMW0c:c::ccccccccc:::;;;,,,'''',,'',''''''','''',xNWWWWWNXK0KKKKXXXNWWWMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\txkkkkkkkkkkkkkkkkdlcccok00kxdxkxdxdodk00KKKXXXNNNNWWMMXxo:.'codddoodxkdclk00kdoc;,....     . .;loo:,;,,cooxKWMWN0doooodddollc:ccccllodxkOkkkkkkkkkOOOO00000OOOkdooodo;.    .,::::::;;;;;;,,:cccccc:lKMMMMMMMMMMWkc:cccccc::;;;;,,,'''''''''''''''''''''''',,':0WWWWNXKKKKKKKKXXXXNNWWMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tkOO000KKKKKKKK000xllccoxOOkxxxxxxxdooxO0000KKKXNNWWWMMN0kd;.;ldxxdddolcldkK0kdoodxxolc:;;:cl:'.,lo;,::clookXMMWNXkoooodooc:;,'''....',;codxxkkkkOOOOOO0000OOkxdxkkxxxo;.   .:cc:::::::;;;;;:cccccc:lKMMMMMMMMMMWkc:::;;,,'...''''',,,''''''''''''''''''''',''oXWWNXK00KKKKKKKKXXXNNNWWMMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tOO000KKKXXXXNNNNXklllcoxOOxxdddddxoloxO0OOkOOOO000KXNNXOkko::clllodddddxxOK0kxddooxkO00OOOkxdl;.,;;;;:lloxKWMMMMN0xoooooc;,........',:clodxxxkkOOOOOOO00OOOkkddxkxxxddc'   .:lccccccc::::;::cccccc:cOWMMMMMMMMMM0:'''...........'''''',,'''''''''''''''',',';kWWNK00000000KKKKKXXXXNNWWMMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tO000KKKKKKXXNNNXKkollldO00kxxdddddoloxkOOkxxxxxxxxxkkkOkddxoloxkkOkolodxxO0Oxxddl:ldooodxxdolllc;::;:cldONWMMMMMN0kdoooollccllllllooddxxxkkxxkkkOOOOOO0OOOkxdodxxxdddl:'...,lllllllccccc:::cccccccc:xNMMMMMMMMMMNx'...............'',,,''''''''''''''''',','cKWX0OOOOOO00000KKKKKXXXNNNWMMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tOO000KKKKXXKXKK0OkdddoxO0K0Okkkxxxdodkxddxxxdddddddxxxxkxodocodxdl;;lol::cooc;,'',:lc:;;coolcccl::llldk0NWMMMMMMNX0xdolllllc:::::;:clodddxxxxxkkkkOOOOOOkkxoldxkxdlc;'';cccloooooolllllcccccc:cccc:;cOWMMMMMMMMMMNk;................';;''''''''''''''''','',dNN0kOOOkkOOO0000KKKKXXXNNNWWMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tkkOO0KKKKKK000OOOkxxddkOKK0OOOOkxxddxkxdddddxxxxdddxxxxxxxdolclo:..',;,'...'.....',,'..';lolllcc;;lxO000KNWMMMMWMMN0dllllccc:::::ccloddxxxxxxkkkkkkkOkkkxoccoxxo:;,''.';lddddddddooooollcccc::;;,,'..:0MMMMMMMMMMMWXx:'...........':xK0d:,','''',''''''',,';OWXOkkkkkkOOO0000KKKKKXXXNNNWMMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tkkkkOOOO00000000OkxxxxkOKK0OkkOkxxxdxkkdddxxkOOkxxxxxkkkkkOkocll;',;,..',;:c:;;;;:;,,;ldxdolllc:;:okO0OO00KXNWWNNNXKxoccccllloooooddxkkkkkkkkkkkxxxxxdolcclooc;'.''''..;coxxxxxxdddddoool:,'''........:KMMMMMMMMMMMMMN0xoc:;;;:cox0NMMMWXkl,'''',''''''',,'cKWKOkkkOOOO0000KKKKKXXXXNNWWWWMMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\txkkkkOOOOO0000000OkkkxkO00OOOkkkkkxddxxxkOOOOkkxxkkkkOOOO0KK0dccloxkxl:coodddddoooooxkOOkdllc;;;;cdxkOkxxxkOO0XX0Oxxdolccclodddddddxxkkkkkkkxxxdoollllllcc:;,,,'.',,'..';cdkkxxxxxxxdddooc;'...........;OWMMMMMMMMMMMMMMMWNNNNNWMMMMMMMMMMNOo;'''''''',''',l0XKOkkkkkkkOOOOO0000KKKKXXNWWWWMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\txkkkOOO000KKKXXKX0kkkxkO00OOOkxxxxxddxxxkkkkkO00KKKKKXXXKK000kc:coxkOkxxxkkOOOOkkkkkOOkkxolc;,,,;cccllcclodxxxxOOxddoolccclllooooolloooodddolcc::clllc:;,,;;;;;,'',,,...';okOkkkkkxxxxdddolcc,..........,oXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKo,','''''',';d0kddddxkkkkkOOOO00KKKKKKXXXNNNWMMMMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tOO00KKKKXXNNNNWWWXOkkkO0KK0OOkkxkkxdxkO0000000KKKXXXXNNNNNNXXKx:;coxkkkkkkkkkkkkOOOOkkkxdol;,'',,'.'''',:cloooloddoollccccc::;;;;:;;;;;;;;,,;:cllc:;;,,,,;;;;;;;'',,,'..',cdO0Okkkkkxxxddoooo:............;xXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXx;..'',''''',cx0kdxkkkddOOkOOO0K0OKKOOKXNNNNNWMMWMMMMMMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t00KXXXNNNWWWMMMMMXOOkkO0KK0OOOOkxkxxxk0KKK00KKKKKKKXXNNNNWWWWWNOc;codkkkkkkkkkkkOOOOkxxxolc;'''........',;:ccc:;:llcccc::::;;,,,'',,'..',;clodoc;,',;;;,,;;;::::,',,,'...':ldO0OOkkkkxxddool:,,'............;oONWMMMMMMMMMMMMMMMMMMMMMMMWN0o;......'''''',lkkkdxxxdc:xkkOkkO00kO0kk0XXNNXNWWWWWMMWWMMMMMMMMM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t0KKKKXNWWWMMMMMMMN0OOO00KK00OOOkkkkxxO0XXXKKKKKKKKKKXXNNXNNWWWWN0l;:coxkkkkkOOOOkxxxxdol:;,,...      ....,;;,,,;,;cc::;;;;;;;;;;;;;cc:coodddo:'''',,;;;;;::::::;,',,'...'',:ldxO0Okkkxxddooc;,,''''...........':okKNWMMMMMMMMMMMMMMMWNKko:'..........'''';oxxdxkxdoc:dOOOkxkO0OO0kk0KKXXXXXNNNNWWWWNKXNNNWWM\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t00KKKKNWWMMMMMMMMN0OOO00KK00OOOkkkxxxxkkkkkxxkkkxxxkkkkkxxxxxxxxxd:'.;lddddkkkkxolccll:,'...          ...'''',;,',,;;;;;;;;,,;;;;;;:okkkxdl:,'.',,,;;::;;::::::;,,,,,'..'',;:loxO0Okkxddool::;;,,''...............,:ldkO0KXXXXKK0Okdl:,................';lddddddddoccdkkkxdxO0OOOkk0KKKKKKKXXXXNNNNXKXXXKXNN\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t0000KXNWWWWMMMMMMN00OO00KK0000OOkkdllllcllllllllllllllccc::::;::cccc,..,;:lddddoc;,'''....             .....'''',...,,,,,,,,,,,;;;;;:dkdl:;,,''',;:::cc::ccc:;,,''''''''',,;:clodk0Oxdoolc::;;,''.......................'',,,,,''.................';cldkO0X000OOO0kxxkkOOOkkO000000KKKKKKKKKKKXXKXKKXXNNXXXX\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tO00KKKXNNNWWWWWWWN0OOOO000OOOOOOOkdccccccccccccccc:::::::;;;;;;;:ccdkc....',;;;;'.....                  ................'',,,,,,;;;;;colc:;;;;;;::clloollolc;,,,,,',',,,,,,,,,;cloxkOkdlc::;;,,'''..........................................',:ooxOKXXNWNNWNXNNNNWXOxxkkkOOOOO0000KKKKKKK0O000KKKXXKKK0OOO0O\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tkO00KKK00KKKXKKXXX0OkkkkxkkOOOOOOkocc:cccccccccc:::::;:::;;;,,;:lxkdk0x;........                          ............. ...',,,,,;;;;:lol:::ccccloddoolllc:;;;;,,,,,,,,,,,,,,,,,;:codk0Oxl;;,'''......................................',;:cxkkXWK0K0K0KWKXWNXXXXXWNOllodxkOOOO0KKK0OO0KXK0O0KKK00K0000OkkOOO\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\txkO0KKKKKKKOkkO0KXKOddkxdkkxkOOOOxlcc:::::::::::::c::;;::;;;;;;:clxOkKXx:,.                              ....  ...........  ..',,,,;;;ldl::cloodddollcccc::;,;;,,,,,,,,,,,,,,,,,,;:ccldk00xc'.......................................,oOOkkkOOO0000K0K0KXKKXXXKKKKXXOdoddkO0000KKKkxddxkKX0O0KKKKOOO000OkkOkO\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tOO0KXXKKXKKOdx0XWWWNOdxOodkkxdxkkxccccccc:::::::cccc:;;::;;;;;;:cokO0xc'',.                              ...   ........       ..',,;;;ldlcldxxdollllccc::::;,;;;;,,,,,,,,,,,,,,,',;::ccldk00x:'................................',:;'';dKX0OO000KKKKKKK000000000000000000KKKKKKKX0xkxxxxOOkdxOO0KOkOKK0xddxkk\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\txkOO0000KKK0kddkKXXX0odkdxdollllooccccccccc:::ccccccc:::;;;;;;::lOKxc''';c'                             ....    ........         ..,,;cddxkOkolccccc:::::;;;,;;;;;;;;;,,,,,,,,,,,'',;ccccldk00d;..................  ............';:c;,':xKNNNNNNNNNNNXXXXXXXXXXXXXXXXXXXNNXXNNXXKOOOOOOOOxoxOO00OxOKK0kxkkOO\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlooddxxxkO00Okddddddo:lxkkdcc::cllcccccccc::c::ccccccc::;;;;::cdOx:''',;,.  .                           ...   ..  ......           ..,lkO00koc:::::::::;;;;;,;;;;;;;;;,,,,,,,,,,,'.',;cccccoxO0Oc..............              ....',;cc:,,ckXWWWWWWNNNNK0KNNNNNNNNKXNNNNWWWNXNWWNX00OO0000xdkO0K0OOKKK0xxO0OO\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tccccccllodxxxkkolccc::clxkdcc:::ccclllllccccc:::ccclllll:;;;cdkxc,''';;.    ..             .           ..   .......  ....            'x000Oocc::;;;;;;;;;;;;,,;;;;;,,,,,,,,,,,,,,,'..',:ccccldk00l...........                   ...';:cc;,:oOXWWWWWNNXOxkKNNNNNNKkOXNNNNNN0k0NNNX0000K000xdkOO00O0KK0Oxoxkxx\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tcccccllclodooooolcccccccdOxccccccllllooolcccccccccloxk0Oo:cdkxc'',,,,.                    .           .    ..  ......  ..           .lO00Odlc:;;;;;;;;;;;;;;,,;;;,,,,,,,,,,,,,,,,,'....';clccloxO0d'........                     ...',:cc;,;cd0NWWWWNNXKKNNNNNNNXKKNNNNNNNXKXNNNXKKKKKK00xdxkkO00K000Oxloddx\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;:::cc:clldxxxdlcccccllooollolcclolc:clolllllodoooodk0OkkOxc,,;;,,..                    ..         ..     .   ......              .lOO0Odlc::;;;,,,;;;;;;;;,,;;,,,,,,;,,,,,;;,,;;;,..''';cllclodk0x' ......                      ...';:c;'';:lx0NWWNWXkOXNNNNNXKxkXNNNNNN0x0NNNKOOOOOOkxoodxkO000000Okdoodd\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t,;;;;;;:::lodddoccccllllooooooolccol::coooooox0Odooodxk00xc,,;;'...                    .,,.                   ......             .;x0OOOxolcc:;,,,,,,,,,,,,,,,,,;;;;,,,,,,;;;;;;;;;;,''''';:llloddx0x'.......                      ...';:;''',;coxKNWWN0KXXXK0000ddKXKKXXN0ooOXX0kkOkolllodxkxxkkkOOOOOOOOxx\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t,;;;;;;;;;;;:cccooooooooooooddxxxxdolllooooox0X0xdddkkkxdllc::;'..                    .',.       ...     .  ......              .o00kkkxdolc:;;;,,,,,;;;;;,,,,,,;;;;;,,,,,,;;;;;;;;;;,,'''',;loooddx0d.                             ...,,'''''',:ldkKNWNNNXK0kkOOkxkOkkOO0OxoodxxkkOxc:looooddooodooodoooddd\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t,,,,,,,;;;;;::cldxxxxxxxxxxxxkkkkxoooollllodkKXXKOOKKx:;cooc;''........              .....       ..     .  .......             'xKOxxxxdoolc::;,,,,,,,;;;;;;;;,,;;;;,,,,,,,,;;;;;;;;;,,,',,,'cddodddxOl.       ...    .......       ..';;'''''''';:lxOXWWWWWNXXXXKK000OOOOOOOOkkOkOOOOkxxkkxxxxxxkkkkkOOkOO0\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t,,,,,,,;;;,;;::ldxxxkkkkkkkkkkkkkkkkxlc:clodxOXNNNX0dc;,;;;,...........             ..'..  ...         ..  .......            ;OKkxddddkxllc::;,,,,,,,,,;;;;;;,,,;;,,,,,,,,,,;;;;;;;;,;;,,,,':odxddodxk;       ...    ...''',.      .',;,''''''''',;cok0XWMMMMWWWWNNNXXXXXXXXXXKKXXXXXXXXXXXXXXXXXXXXXXNXNNN\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t'',,;;;;::;;;;:cooddxxxxxkkxxxxxdx0K0xlcldxkOKNWNKkoc;,'''......'......            ....    ...         .   ....              :O0kdoooddxkkl::;;,,,,,,,,,,;;;;;;,,;,,,,,,,,,,,,,,;;;;;,;;,,,,,c;;okxdloxd,     ...     ..;c:cc'...   .;,.''.''''''''',;ldk0XWMMMMMWWWWWWWNNNWWWNNNNNXNNNNNNXNNNNXXXXNNNNNNNNN\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t,,;;;;:::::ccccloodxxkkkkkkxxxdxkKXNNKkxxO0KXNNKkdl:;,,,''...''........          ....                 ..    ..              ;OOxollooddk0Oxl;,,,,,,,,,,,,,;;;;;,,;;,,,,,,,,,,,,,,,,,,,,,'',,;l;.;lkOxlldl.     .........:oodd;. ..  .';;;,''''''''''',;coxOKNWMMMMMMWWWWWWWWWWNNNXXNNXNNNXXNNNNNNNNNNNNNNNNN\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;;;::::ccllllloddxxxxxxxxddxkO0000OkO0XNWWXOxoc:,,,;;,.',''........          ...  . .              ..   .               :OOdolllooddkK0kdc,'',,',,,,,,,,;;;,,,;;,,,,,,,,,,,,'.....;::'..';c,';;:d0xcld:     ....  ...cdoooc' .;'  .;clc...''''''',,,;:loxO0XWMMMMMWWWWNNXKK00OOOOOO0000KKKXXNNNNNNNWWNNNW\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;;:::::ccccllllloodxxddddddddddxkO0KXNWWX0xol:;,,:lc,'.',,'......           ....            ..      .   ..             ;OkolcccllodkKXX0xc,.....'',,,,,,;;;;,,,,,,,,,,,'....     .;odc. ..'';;;::cl:l0d.     ... ...'oxool:.  .,....,ll.  ..'''''',,,;;:coxk0XNMMWWWWNXKOxooodxxdddodxkkxxkO0KXXXXXNNNNNN\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;::::::ccccccllodxxdoooddddddxkO0KNWWWX0kdl:;,,,:dc'.'.',,'....  ..        ....  .      ......          ..            :Okocccccllok0KXK0xl;..   ....'',,;;;;;,,,,,,,''..          'oxx'   ':c:;:c::ck0o.          ..;ddooc'.   .cxdllxOo,   ..'''',,,,,;;:cldxOKNWWWNNNNXK0OKXXK00OO0KK000OOO0KKKXXXXNNXN\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;::::::::cccccloodolloooooddxkOKXNWWX0kdoc;,,,,,cc'.''.','....  ...      ....    .     ....  ..                      :Okocccccccodlcdxkkxl;'..       ...'',,,,',,,''....          .:dk:  .;cc:,;:lloxxdl.   .    ...:dooo:.    .lkOK0000Oo,   ..',',,,,,,,;;:codk0NWWNNNXXNNNNXXXKKKXXXXXXKKK0000KXXXNNNN\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;:::::::ccccccccllllloooodxkO0KNWNX0kdlc;;,,,,,,c:..'..',.....  ..      .'..          ..     .                      cOxlccccccool:;;:clllc:,..        ...',,,,,'''........         .'lc. .,cc:;;;coddoxkd' ..    ..'cllol,.    ;dx0K00000K0d,   ..'',,,,,,,,,;;cldx0XWWNXXXXXXK0OOO000000KKK00KK000KNNNNW\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;::::::::ccccccllllllooodxkO0XNNKOxdlc;,,,,,,,,,l:.....',....  ...     .'.           ..                            :Oxlcccccllc;''''',,;;;,'...        ..';;;;;,'''.........         ;l. .,ccc:;,;clcoxoxx,     ...;llooc'.   '::oKXOk000000Oo,   ..'',,',,,,,,,;:loxOXWWNXXXXXXXXXKKXXXXXXXKKXXXXXNWWWWW\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;:::::::::cccccllllllloodxk0XNX0kdolc:;,,,,,,,,,;l:......'....  ..     ...            .          ...               ;kxlcclllc:'.........''''....        ..,;;:cc:;,,'.''''...         'l' .;::c::;,;;ckkccOx' .  ...:olodl'   'c;:dKWXxoxOOOOOOko,   ..'''''',,,,,,;:clokXWWNNWNNWWWWWWWWWWNNWWNNNNNWNWWWW\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;:::::::::ccccccllllloddxOKXXOxolc:;;,,,,,,,,,,;cl;..........   .     ..        ..   ..   ..  ....                'xxlccll:,'....    ...........         .';;:cc:;,,'',,'...          .c:..';;:::;,:ldkOo;oOd... ...coodxo'  'lllxxxXWKl:oxkOOkkkko,.  ..''''',,,,,,,;;::lxKWWWWWWWWNNWWWNNNNNNNWWWWWWWNNN\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;::::::::ccccccllllodxk0XKkdolc:;;;,,,,,,,,;;,co;,'.'......   ..    ..         .  ...    ..  ..                 .oxllloc,........     ....'.....       ...',;::;,,,''.....            :l. .';::c;;:oxkOx;;dOc..  ..;c:oko, .cl;lO0ddKWO:,:ldxxxxxxdl'.  ..''''''',,,,,,,;;cxKWWWNNNNNNNNNNNNNNNNNNNNNNNNN\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;;:::::::cccccclllodxOKKkolc::;;;;,,,,,,,;;'.'ol;,'........  ...             ..   .   ..    ..                 .cxolol;...........      ...''''..       ....,;;,''........            'c' ..';:c;,:oxxOx,':od, ....,cloxd,.cd::oxO0loKNd,,;:codxdddddl,.  ..'''''''''''',,,;cxKWWNNNNNNNXXXXXXXXXXXXNNNXX\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;;;::::::ccccccllodOK0xlcc:;;;;;;,,,,,,;;,. .::c;,'........  ...            .... .......                       ,dooo:'.............      ...',,'.          ........'''.....           .c;  ..';:;,;oxO0x'.,:xo.....':loddcoxlcxXOokxcdKO:'',;:codddddddl,.  ..''''''''''',,,,;cdKWWNXXXXXXXXXXXXXXXXXXXXX\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;;:::::::ccccclldOK0xlc:::;;;;;;;,,,,;;'.  .c::c,''.......   ..           ..........   ..                     .cdol;............           .';;,..           ...............          .cc. ...,;;':ox0Kd. .,lxc.....;looodxdcoXWNklxocdkc'''',;:loddddddoc'.  ..'''''''''',,,,;;cdKWWNXKKKKKKKKKKKKKKKKKK\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;;;:::::::ccclok00dc::::;;;;;;;;,,,,,'.  .,ol;c:..........  ...        ........ ....   .                      ,odl,............             .,:;,..           .............           .co.  ..',,'coxOOl. ..;dd,....,ldolol,.lXWNNxodc:dl''''''';:clodoooooc,.  ...'....''',,,,,;;:dKWWXK0000000000000000\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;;;:::::::cclx00dccc::::;;;;;;;,,,,'.  .,cdo;:c;.........   ...         ............                         .cdl,.............              ':c:,...         .......'.....           .cd.  ...'.,clxOk;   .':xl....,loolc. .cKXKWXxol,lo,'''''''';:cloooooooc,.  .......'''',,,,,;;cdKWNK0OOOOOOOOOkkkkO\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;;;;:::::cccdXKl:cc:::::;;;;;;;;,'.  .,clodc;cc;........    ....     .           .                           'oo;..............              .;ll:'..          ....'','....           .:x'  .....ckxk0o.    .,ox;...,clll;.  ,ONK0KOxoc::''''''...'';:cloooooooc,.  .....''''',,,,,,;;l0WNOkkkkkkkkkkkkkk\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;;;;:::::cccoKKl:cc::::;;;;;;;;'.  .,cloldl,,::,. .....     ....    ...         .. .   ..                    ;oc'........... ..               .coc:;'..        ....'',,,'..           .:x,   ....oKOOO:     ..:xl...,:ccl:...;dXXxdkxdo;..'''........';:cloooooool;.  ...''''''',,,,;;:kWXkxxxxxxxxxkkxkk\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;;;;;::::cc:oKKlccc::::;;;;;:;.. .,clooloxc..''.. ..... .  ....    ....   .......  .....                    .co;...... .  .                    ,oolc:'.        ......''....           .:x;   ...'xXOOd.      .'ld;..';:ccc,,oOxxOxclddo' ...'..........';clooooooool;.  ..''''''',,,;;:kWXxdddddddddddddd\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;;;;;:::::::oKKlcc:::::;;;;;dd;;:clllllloxl.............   ....   .....  ........                           .ll,..'..    .                     .ldllc,..      ....'',,''...           .;x:   ...;0Kkkc.       .,dd:,,;:cc:,;o00kdlccclxl,. .............,llloollollll:...,;''''''',,,;:kWXdoooooooooooooo\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t;;;;;;;;:::::::oK0lcc:::::;;;;;dkc::cllllllod;..  .. .....  . ...    .....  ........                           'lc'....                            ;oolc;...     ......'''....           .,d:   ...lX0Ok'        ..ckdc:coll:;:lx0Okocllxkddl'. .''........,llcollllllll:'.':;''''''',,,;:kWKdllllllllllllll\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t,,;;;;;;;::::::oK0lcc::::;;;;;;xkc::cllllllll,    .. .....   ...     .....  ...... ..                          'l:...'.                            'oool:'..    .....',,,,'...            'dc   ..'d0kOl          .,oOdcoxo::;;ldooodc:xOxdodl'.';,........,llclllllllll;'.':;.'''''',,,;:kWKdlllllccccccccc\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t,,;;;;;;;;:::::lK0lcc::::;;;;;:xkc::clllllllo:.   '. .....   ..    .  .... ..........                          ;d;..''.                            .cxddc,...    .....''''....           .'dc  ...cO0kx,           .;dklckd:,'';:oklcxllddoodl,.,:'........,llclllllllcc;'.':;.'''''',,,;:xWKocccccccccccc::\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t,,,;;;;;;;;::::lK0lcc::::;;;;;:xkc::cllllllloo'...,......         .  ..... ..........                          cx;..... .                           ;dddl;.... ......''.'....            .,xl. ..:kXX0d.           .'ckxclo;.,;lddddxo,;ddoool,.,:,........,llcllllccccc;'.':;.'''''',,,;:xWKoccccc:::::::::\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t,,,;;;;;;;;;::;lK0lcc::::;;;;;:xkc::cllllllldl'...,'.'...         ........ ....    ..                         .ox;...,....                          .okxo:'..........',,,'...            .,xl. .,o0XX0o.            .;oOx::do:cdkxooc' .dxoool,.,:,........,llclllcccccc;'.':;.''''',,,,;:xWKocc::::::::;:;;\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t,,,,,;;;;;;;::;lK0lcc::::;;;;;:kkc::clllllloo;,,...'''...        ......... ....    ...                        .dx,..',.....                         .cxdoc,...........''......           .;xc. .:kXNX0:             .':oOxdXKd:lxkoc,  'dkdooc,.,:,........,olclllcccccc;'.':;''''''',,,;:kWKo::::::;;;;;;;;\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t,,,,,,;;;;;;;:;lK0lc::::;;;;;:ckkc::cllllllc,.,'. .,;'.....      ......... .......  ..                        .xk,...'......                         ,dxdc;.........',;,'....            .cx: .;lOXNXk,              .,cxOKX00kcdkdd:  ,dxdool'.,:,........;olcllccccccc;''':;''''''',,,;:kWKo::::;;;;;;;;;;\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t,,,,,,;;;;;;;:;lK0lcc:::;;;;;:ckOl::cllllll;.''.  .;;'....      .......... ........                           .xx,...,'.''...                        .;lxo:'.........',','...            .cx;.':d0XNKo.              ..;lOXKO0Xkccldk:.;ddoooc'.,;'........;olclcccccccc;''':;'''''',,,,;:kWKo::::;;;;;;;;;;\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t,,,,,,;;;;;;;:;lK0lcc:::;;;;;:lOOl::cllcllc:c,.   .,,'...       .......... ........                           'kx'..,;'.''....                        .:xdc;........'''''.....          ..ld,.;lkKXX0c                .':oOkxKNX0kO0Xk'.cddooc'.,:,........;dlclcccccccc;''':;'''''',,,;;ckWXdc:::;;;;;;;;;;\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t,,,,,,,;;;;;;;;lK0lcc:::;;;;:clOOlc:cccccodo,.   ..,,.....     ........... .'... ...                          ,kx'..,,..,,,...                         .odo:'.......,,,;,....           .'lo,,:o0XX0x,                ..,:d0dd0XNXXNWXl..ldool'.':,........:dlclcccccccc;''';;.''''',,,;:ckWXdc::;;;;;;;;,,,\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t,,,,,,,,;;;;;;;lK0lcc:::;;;;:coOOoc:cccclxo'    ....,'.....    ... ....... .'.... ..                          ,kd'..','';;,'...                         :xdo:.......''','...            .'ll;;:xKXOOo.                 ..;ckOdd0XNNWWXx'.:dooc'.';,.......':xoclcccccccc;''';;'''''',,,;:lkWXdc::;;;;;;;,,,,\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t',,,,,,,;;;;;;;lK0lcc:::;;;;:loOOoccccccoc.         ',.....    ........... ... ..                             ,kd'.',;'';::,....                        .lxoc,...........               ..ld:,:x0xdk:                   .';lO0OKXXNNNKo,.;oodl,.,:,......''cxdllccccccc:;'.';;''''',,,,;clOWXxlc:;;;;;;,,,,,\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t',,,,,,,,,;;;;;lK0lcc::::;;:cld00olcccccc'..        .''.''.    ........... ...  ..                            ,kx,..,,';:::,'...                         'dxo:.........                 .,dx;.;dl:oo.                   ...,lOXXNNXXN0lloodxxdc;:c;'.....',lkdllcccccc::;''';;''''',,,,;coOWXxlc:;;;;;,,,,,,\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t,,,,,,,,,;;;;;;lK0ccc::::;;:cod00dlcccc:,...        ..'.''.    ........... ...  ..                            ,kx,..,,';:::;,..                           ;dd:.. .......                .;do..'',:xd.                     ..,lOK0KKKXXkxxdxxkko;:c;''....';okxolccccc:::;''';;'''',,,,,;coOWNkol:;;;;;,,,,,,\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t'',,,,,,,,,;;;;lK0ccc::::;;:loxK0doccc:'.'','..      ..','.    ........... ... ....  ..                       ,kd,.';,',::::,..                           .cd:.. ...........            .,d:....,lo:'.                     ..;okkxOXXXX0kxxxxxc;:l:'''.''';dOxolccccc:::;''';;'''',,,,;:loOWNkol:;;;;;,,,,,,\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t''',,,,,,,,;;;,lK0ccc:::::;:ldxKKxoc:c,..........    ..,;,..  ............ ... ...   ..                       .xd,.','':c:::,...                           'l:'...'',;;,'.....         ..,o:...':o: .,.                    ..,cdOOOKXXXN0kxkkd:;:o:,,'',,;cx0kdoccccc:::;''';;'''',,,;;:ld0WNOdl:;;;;;,,,,,,\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t'''',,,,,,,,;;;lK0cccc::::;:ldkKKxolcc,..'.........   '::,... ............ ...  ..                            .dd,..'',:c:::;'..                           .cc,...........   ...        .:l,...,cl. .:'                     ..,lO00KXNNNX00KOd:,:l:,,,,;::okK0xocccc::::;''';;''',,,,;;:ld0WNOxoc;;;;;,,,,,,\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t'''''',,,,,,;;,lKOcccc::::::lxOXKkdlcc;,'.     .,,..  .:l:.......... ...   ... ..                             .dd,.';,,::cc:;'...                          .ol,',,,,,,'''...   ...      .:c'...;l,  ;o,.                     .'oKXKKKKXNNX0Oko;,:c:,,,;:cld0X0kocccc::::;''';;''',,,,;;:lx0WN0xoc;;;;;,,,,,,\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t'''''',,,,,,;;,lKOlcccc::::coxOXXkdlc:cc'     .,:;;'  .:lc..........  ..   ... ..                    ..       .od,.,;,,:ccc:;'...                        .,ldlcccccc:::;;;,'.    ..     .::...,c;. .oo,.                     .;xXX0OOOKNNNKkxl,.,:;,;;::cokKNXOdlcccc:::;''';;''',,,;;:cox0WN0xoc;;;;;,,,,,,\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t''''''',,,,,,;,cK0lccccc:::cok0XXOxlc:cc.    ..;::c;. .;ll' ....  .    ..   .. .. ..               ...         ld,.,;';cccc:;,'..                       ,dxolcccccc::::;;;,,,.     .    .:;...::.  ;xl..                 .....;xXWWX0kOXNXN0xl,';c:;:;;;:oOXWWXOolccc:::,''';:'',,,,;;:coxKWW0koc;;;;;,,,,,,\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t''''''',,,,,,;,cK0lccccc:::ldk0NXOxlccc;..   ..,:;,'....:l, ..         ...  .. ..  ..             ...          cd,',;,;ccclc;,...                    .;lkxolccccccc::::;;,,,,'.     .   .;,..,:'...ld;.                ...   .,dXMMWNXXXNWNN0d:,;lc::;;;;lxKWNK0kocc::::,''';;'',,,,;;:ldkKWWKkoc:;;;,,,,,,,\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t'''''''',,,,,;,cK0lcccccc:cldkKNN0xlcc::;. ....''...   .'::.....  ..   ...     .....           .....           ;o;';;;:cllc:;,...                   ;xOko:;,,,,,;;;;,''''',,,,,.     .  .;;.,:'...,do,.              ..      .,dNWWMWNXNWWWNXx;,:lccc;;;:okXWN0kkxoccc::,''';:',,,,;;;:ldkKWWKkdc:;;;,,,,,,,\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t''''''''',,,,;,cK0lccccccccldOKWN0xocc:ll. .....         ';.....   ..  ...     .....          ......           ,o;,,,;cllll:;'..                  .ckxoc'..................',,''.     .  ;;':;.  .cdl;.                      .,xNWWWWNXXXWMWWKo:colc:,,;:okKWNKxdxxdolc:;''';:',,,,;;;:ldkKWWKkdl:;;,,,,,,,,\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t''''''''',,,,;,lKOlcccccccclxOXWN0xolc:cl'....    ...... .''...    ..  ..      .....       ...  ...            ,o;,;;:llllc:,'..                 .lxo;'.....''''.....  .. ..'''''.    .. ';;:.   'oo:,..                     .cONWWNWWNKKXWMMWKdldo:,,,,;lkKWN0xooodooll:''';:,,,,;;;::ldOXWWXOdl:;;,,,,,,,'\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t''''''''',,,,,,lKOlllcccccloxOXWWKkoc:::lc,..    ........ ...       . ...       ....   .. ...                  'l;;;;clllcc:,.....              'xOo,......'''.......      ..''''.     ..';c,   .:dl,..                     .:oOXNWNXXNNK00NMWN0xdl;,,;::lkXWN0xlccccccc:,,';:',,,;;::cldOXWWXOdl:;;,,,,,,''\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t'''''''''',,,,,lKOllllccccloxOXWWKkdc:::c:. .............             ...        ....  .....                   .c:;;:llllc:;'.....             'xOo,......'''.....          ..''''.    .,;c:.   .lxc,.                    ..:cx00KXNXXNWNKO0NWNXOo:,;;;::okKWN0xlccccc::;''';:,,,;;;::coxOXWWXOxl:;;,,,,,,''\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t''''''''''',,,,lKOlllllcclldk0XWWKkol:::,.  ...........                ..         ...    .                     .lc;:cllllc:,.......           'dkl'.......'......            .''''.   .,,cl.    .cdl'.                  ..',:ckKOO0KXXKKNNK00NNXKx:;;;;::lx0NXOdlc::::::;''';:,,,;;;::coxOXWWXOxl:;,,,,,,,''\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t'''''''''''',,,lKOllllllllldk0XWWKkdlc:,...........'''..                     .    ....                         .ll::cllllc;'......           ,xkc'.......'.....               ...'.....';o;     .;oo;.               ..'',,,;lx0K0O0KK0kO0K0O0XNX0l;;;;;;cd0NKkdc::::::;,''';:,,,;;;::coxOXWMNOxl:;,,,,,,,''\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t''''''''''''',,lK0lllllllcldk0XWWKkdlc:...'.. .....'''...                    ..........                        .ll:cclllc:,......           ,xkc..............                ..''','..,lc.      ,olc,.          ...'',,,'..,dxdkK000KK00KXK0kOXXXOl;;;;;:oOXKkoc:::::;;,''';:,,;;;:::coxOXWMN0xoc;;,,,,,'''\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t''''''''''''',;lK0ollllllcldk0XWNKkdlc;.,;. .......'....''...      .       ...........                         .ooccclllc;'......          ;xx:.......'......                  .',,...':o,       ,ll:;'.. .........'',,'....;xxdoxOOkO0XNNNX0OkOXNXOo::;;:oOX0xoc:::::;;,''';:,;;;;::ccoxOXWWXOxoc;;,,,,,'''\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.'''''''''''',;oK0olllllllldkOXWN0kdlccll'. ...,:''..  .:lcc;.     .. .........                                'docclllc:,.......         ;kx:.............                    ':;. ..;lc.       .cl:,'.............'..    .lxodxdxkkOOKNNXKOkkkKNNX0occ:coOX0xolooc::;;,.'';:,;;;:::cloxOXWWXOxl:;;,,,,,'''\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t..''''''''',,,;oX0olllllllldxOKNN0xoccc,.......,:'....  ;dxdo:.    ........                                    ,xocclllc;'......         ;xx:.............                    .:;. ..,cd;        .:c;,'..............     .,xOkOOOOkkOO00OOO0kdxOXNNX0dllodOX0xdddolc:;;,''';:,;;;::ccloxOXWWKkdl:;,,,,,''''\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...''''''''',,;dX0oollllllldxOKNNOxoc:;.   ..',lc'.'.   ,dxxxc. .';c:... ....                                  ;kdllllc:,'..............:kx:.............                    .;,. ..':oo.        .,:;,'.............      .lXNNXK000OOOkxkkO0K0kxkKNNNKxddxOX0kkkxolc:;;,''';:;;;:::ccloxOKWWKkdc;,,,,''''''\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.....''''''',;:dX0dollllllloxk0NXOdl::;.    .;dOl,;;.   'dkxxl,;loolc,.......                                  :0xoolc:;,,,,,,,,,,,,,,;cxo;............                     .'.   ..;lxc         .,:;'..............      ,kWWWNXKKXXK0kxxxk0XX0kxOXNNNX0kxOX0xdolc:;;;;,.'';:;;;::cccloxkKWW0xoc;,,,'''''''\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.....''''''',;:dXKdoollllllodk0XXkdl:;;,..  .oxxc,,;.   .okxdodkxolll:'.                                       c0xllcc::;,,''....',,;;oxl,...........                      ...    .':od,         .';;'.............      .l0KKXNWWNWWX000OOO0K0xk0K0OkkO00O0XOoc::;;;;;;,'.';:;;:::cccloxkKWN0xoc;,,,,''''''\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t....'''''''',;cxXKxdollllllodkOXXkoc:;;,,,';dxxd:,,,.   .lxddxOOxdoollc'                                      .o0dlc::;;,''...  .,,;:dxc'...........                      ..      .':dl.         .';,'............      .:kkddkKNMMWNXXXXKKXNNXKKK0OkkkxdxxOKOlc:;;;;;;;,.'';:;:::cccllodkKWN0dl:;,,,'''''''\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t......'''''',:cxXKxdollllllodxOXKxoc;;;,,,;dOdkk:,;,.   .cxddkkxdl::ccl:.                                      o0dc::;;;,,'..  .';;ldo;...........                       .........';lo;          .',,'...........      .,dkddod0NWWWXKKKK00XWWN0xdkkkkkxxddkKkl:;;;;;;;;,''';:;:::cccllodkKWNOdl:,,,,'''''''\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.......''''',:lxXKxdollllllodxkKKxl:;,,,,,;oxdkd:cc;.   .:ddxxxl;';cclc'.                                      lkl::::;;,'..   .,cdxc...........                      ........'',,;coo,          .',,'...........      .oxdddlcoxxOXNKKNX0O0KKX0OkOOkkkddxxOKkl::;;;;,,,,.'';:;::ccccllodk0WNOoc;,,,''''''''\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t......'''''',:lkNXkxdolllllldxkKKdl:,,,,,,:dxxkdlxo;.   .:oddo:..;lc::.                                        ckoc:c::;'.    .,lxd:...........                     ..........''',;col'          .,,,'..........      .cdc:cc;,,:ccd0KNWMWKxdk000000kkkxddxOKOol:::;;,,,'...;::::ccclllodk0NNkoc;,''''''''''\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t......'''''',cokNXkxdollllllodxKKdc;,,,,,,;cddxxxkd;.  ,oxdc:,. 'c:;,.                              ..         :kxddoc;'.....,cxd:'..........                     ............''',;:lc.          ';,,'..........      ,oc',,,'..,cl::lkKNWX0kO0OxdxkkkOOO0O0X0xolc:;;;,,'...;c::cccclllodx0NNklc;'''''''''''\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t........'''';coONXOkdollllllodxK0oc;,,,,,,,:ooodllc,. ;OKOo,.  .:c;'.                               ..         ;OOxo:,'','',cdxl,..........                     ..............''',,:lc.          ,c;'..........      .::'',;;;,',:c:,',:oxkkkkxocccodkOO00OOKNKkdol:;;;,'..';c:ccccllloodx0NXxl:,''''''''''.\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.......''''';cdONX0kdoolllllodx00o:,,,',,,,:olol,,;'  .cl:.   .:c;.                                            :0xc:;,'...,oxo;....',,...                     .................''',;cc'         .:c;'..........     .,:'',;clc;''::c:'',;cccol::odddxxOOxoddk0XK0xdoc:;,'..';c:ccccllloodxONXxc:,''''''''''.\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t........'''';ld0NN0kxooollllood00l:,''',,,,,;;cc;;;'         .';,..       ..                                   ,xdc:,.. .cdo:'...'''....                     ...................'',,:l;.        'c:;'..........     .:,..,;,','',;::l:,;cooc;'',:clodxOdclodk00O0Okxo:;,'..';c:ccclllloodxONXxc;,''''''''''.\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t........''',;lx0NN0Oxdoolllllod00l;,','',,,,,:oc,,,.         ....      ..','                                   'xx:'...:dd:'....'.....                           ................'',;c:.       .;c:;'...........   .;:''.'''''..';::ll::lll:'','...',;;;;:lddOXKkxxdoc;,,...;c:cccclllooddONXd:;,'''''''''..\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t........''',:lx0WNKOxdooollllod0Ol;'''''',',,cdc,,,.                 ..''''..                                  'xd;';lddc,...........                                      .......'';::'       'lc;,'...........   ':,......... .;:clc:;:lloc;::;,''''',:oddllkNXdcc:;;,'...;c:cccclllloodkNXd:,'''''''''...\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.........'',:oxKWNKOxdooollllooOOc,''''''''',cdc,,,.             ...',,'''''.                                  'xdcokxl,............                                           .....',;,.     .co:;,'..........   .;,............;ccccc::lk0xlllolc:::cldxdoooxKNk:;,,,,'...;c:cccclllloodkNXo;,'''''.......\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t..........',:okKWWKOkddoollllloOOc,''''''''',cd:',,.           ..''''''''','.                                  'kOkko;......''....                                                .....'.     ;oc;;,''........    ',. ..    ....':lloddollx0xdkxdddoocccldooddlxOd;,,,,'....;c:cccclllloookNXo;,'''''.......\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t..........',:okKWWX0kxdooolllloOO:'''''''''',cd;.''.  ....... ..''''''''''''.   ..                             ,O0d:'....'''.....                ..                              ... ....    ,ol:;;,''........   .,. ...     ...':lldOOkdlododxdoolcl:,;;c::c:clc:,,,,''....;c:cccclllloookNKl,''''''.......\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...........':okXWWX0kxdooolllloOk:'.'''''''',lo,....  .;:;:,....''''''''''''.    ..                           ,oo:'....''''.....               ....                             ...  ..''.  'ddc::;,.....'...    ',. ...       ..;:clxO0kdoodddllc;;;''..,,'..';,,'''''''...;c:cccclllooookNKl,''''''.......\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...........,:okXWWX0kxdoooollllOk;'.'''''''',cd:...   .::::,....'''''''''''..      ....                    .,ll;'......'''....              .......                            ....  ...'..,oo::::;'.   .'''.   .,'.....        .,;;;:coollddddl:,','....'.','',''''''''....;c:cccclllooookNKl,''''''.......\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t..........',cokXMWX0OxddooollllOk;'..''''''',cxKOc'..,;::::,. ..'''''''''''..                            .,cl;'.............              .......                                       ..'coc,',;;'   ..'''.   ',.  ....       .',,,,;;;,,::;:lc;,',,'',,,lx:',''''''''....;cccccllloooookXKc,''''.........\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t..........',cdOXMWNKOxddoooolllOk;...''''''',cxXWKxlcc:::::;. ..'''''''''''..                       ..',;::,...............            ..........                                       ..,,::;'',;,...',,,'.  .;'.  .....      .',,,,,,,,,'''.';cc:ccc:::;lx:''''''''''....;cccclllloooddkXKc''''..........\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...........,:dOXWWNKOkxddooolllOk;...''''''',cdKN0xocc::::c;. ..'''''''''''..                   .',:c::;'.................           ...........                                    ...'',,,,;;'..,;,,;,'...  .':'     ...       .,''',,,,,,,'..'collcc:::;lx:.'''''''''....;cccclllooooddkXKc''.''.........\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...........':oOXWWNKOkxddooolllOk;...''''''',:dKN0xlccccc:c;. ..''''''.''''..                .,loc;,'''.................           ............                             ...........''',,,,'....,;,'..      .c;      ...      .'''''''',,,'. .;c:::::::;ox:.'''''''''....,cccllloooodddkXKc''............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...........':okKWWXKOkxddoooollOx;......''''';oKNOdlccccc:c,. ..''''''.'..'..               ,xxc,''.......'''.''......          .............                                ..........''',,,,..  ....         .c:       ...     .'''''''''''.. .;:::::::::ox:.'''''''''....,cccllloooddddkXKc''............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...........':okKWWX0OkxddoooollOx,.......'''';l0XOdlccccccc,. ..''''''''.'...             .:dl,.........'',,,,,,....          .................                              .............'',,'.               .c;       ...    ..'''''''''''.. .;c::::::::ox:.'''''''''....,cclllooooddddkXK:''............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...........':oxKWWX0OkxddooooloOx,..........',l0XOdlccccccc;. ...''''.........           ':c,........'''..''''''...         .................                                 ..............','.               .oc       ....  ..''''''''''''.. .;c:::cc:c:ox:.'''''''''....,cclloooddddddkX0:''............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...........';lx0WWK0OxxdddoooooOx,..........',cOXkolccccccc;. ..................       .;:,......'''''','''.......         ..................                                  ..............''..              .o;         .....'''''''''''''.. .;cccccccc:ox;.''''''.......,clloooodddddxkX0:''............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...........';cd0NWK0OxxdddoooooOx,...........,:OKkolccccccc,. ....................    ';,'........''.............         ..............                                        .......    ...'.'''......      ,c.       ....''''''''''''''''.. .;cccccccccox;.'''''........':lloooodddddxkX0:''............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t............,coONNK0kxxdddoooooOx'...........';kKxolccccccc,.  ......................,;'......................  .         ...............                                        ....       .....,,'.',,.      ,'      ....''''''''''''''''''.  .,:ccccccccox;.'.............:llooodddddxxkX0:.'............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t............,:okNNK0kxxddddooooOx'...........';kKxllllccccc,.  ......................'.........................           ................                                        ....       ....''..',,..    ..     ....''.'''''''''''''''''.  .,:ccccccccox;.'.............:looodddddxxxkX0:..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t............':lkNNKOkxxdddddoookx'...........',x0xllclllccc,.  ..............................................           ............................ ................                         ....'...','..   .    ...'...'..''''''.'''.....'.  .':ccccccccdx;...............:loooodddxxxxOX0:..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t............';lxNN0Okxxxddddoookd'............'d0dlllllcccc,. ..............................................           ..............lxxxxxxxkxxkxdl';l:;cc;:lcclccl:.                         ...''..'',,,.    ............................... .':ccccccccdx;...............:ooooddddxxxxOX0;..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t............';cxXN0Okxxxddddoookd'............'d0dlllllllc;...............................................           ................dXXK0KK00K00Oko'';;,;:;co:okc:l:.                          .......'',;'. ....................................;ccccccccdx;...............:oooddddxxxxxOX0;..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.............,:dXN0Okxxxddddoookd'.............d0dlllllc;..........................................    ...          .................lkkOkkkkdxxxxxd,';:;;,;cc:clccc:'                          ....................................................;ccccccdx;...............;oooddddxxxxxOX0;..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.............,;oXN0Okxxxdddddooko..............oOolllc,..............................................  ..         ................................... ...............                           ...     ..............................................,:cccdx;...............;oooddddxxxxxOX0;..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.............',oXN0Okxxxdddddooxo..............oOol:'...................................................          .................                                                              .    ..................................................':cdx;...............;oooddddxxxxxOX0;..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.............',lXNOkkxxxdddddooxo..............ok:........................................................      .....................                                                            . ........................................................:d;...............;oooddddxxxxxOX0;..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t..............'cKXOkxxxxdddddooxo..............;;............................................................ ........................                                                          ............................................................,'...............;oooddddxxxxxkX0;..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...............cKXOkxxxdddddoooxo.....................................,;.................'''...''.';'.'....................',...............'..'..................              .'...         .,''''..............';,.''..........':,..'..........:;..'......................;loodddddxxxxkX0,..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...............:KXOkxxxddddooooxo........................''''''''''''.;:..'.'''''''''''''.',;'.''.,:'.,'',,'','','''',,,.. ';',,,,,,,,,,,,'';'';',,,,,,,,,,,,,'''''.           .:;'','      .'c;'',,.............'::'''''.........:o,.'''.........cc.........................;loooddddxxxxkX0,..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...............:KXkxxxdddddooooxo.....................'::,'''''''''''',' .,',c:,,,,,,,,',;,',:,',';c..,,,::,,,,;,,,;;,',;' ';,;::,;;;;;;;;;;,.':,;c:;;;;;;;;;;;:;,,;.          ':;;;,,.  ....;:,;;,;'...........'::',;,'''........;o:,,,'........ ;l,.'......................;lloooddddxxxkX0,..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...............;KXkxddddddoooooxo...................'',l;                .,';l,          .,,,c;',';:..,',c;        .';;';:.';,;c'         .   ,;,;:. ......   .,c;,;'         .;:,;;;,,'....,:,,;;,,,...........::',,::;'''.......,o:'',;'....... ,l,........................;llooooddddddxK0,..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...............;0Kxdddddooooollxo...................''','.............. .',';l'         ..,';c,','::..,',l,          ,;,,:,';,;:,..........'. ';,;:.           .:,,:'........ .:,,,,;,','..':;',,;,',,.........::'','.,c;''''.....'lc''.,;;'..... .c;.'......................,cllloooodddddK0,..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...............;00dddoooooolllldo....................',''..'''''''...,:'.''':c'.........''',c:.','::.';';l,..........';,,:;,,';:;,''''''''.;, ';,;:'...........',,,:..:;''';. ,:','.,;,',..;;','.,;',,'.......::',;,. .,c:,'''.....lc''. .,:;'.....::.''.....................,ccllllooooooo00,..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...............;00dooooollllcccdo.......................''''''''''','.::.''':c'.........'';::..,,':;.';';c'..........,,';:'';';:,',,,,,,,,,;. ,:';:;,'..'''''''',;;'  .'.''...:;',' .;;''',;'',. .:;',,......::,,,'.....',,,'''....cl''.   .;:;'...;:'.'.....................,:ccccllllooolOO,..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...............,0Ooolllllccccc:oo.....................            .'''::.'''::',,;;;;;:::;;'  .,,,c;.',';c'........',,,,c;.,;';:.             ,;';:;;:;::::::;;,;;.         .;:',,'. .:;'',,','. .;:,','....::',;;,'''''',,;,'''...:l,'..    .::;'.',''......................';:::ccccclllckO,..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...............,Okllcccccc:::::ol. ................................'',l,.'''c:............    ',',c;.',';;'.'.....'''';:;..,,,,;'...........'.,;';:'.''''''',::,'''.      ..':;',,... ':;,,,,,... .c;',,...::'',,'.........;c;'''..,l;.'...    ':c;,','......................';;;:::ccccccckO,..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.............. ,Oxcccc:::::;;;,''.................................',;c;..'.'l:              ..',''c,.''','..'.....',;:;'  .,,','''..'......';'';',:.         .,:;'''.. .....;:'','...  ,c,,,,....  ;:'.,'.;;'',,.          .;l;'...'c;.......   .'::;,'.'.....................',;;;;:::::::xO,..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...............,Ox:c::;;;;;,,.....................''',,,,,,,,,,,,,;;,.  .,',c, ...............';,,:'.,;,;;;;;;;;;;:;,..  ..;;;;;;;;;;;;;;;;::.':;::.           .;;;,,;'.....::,;,..... .,:;,'..... .:;,,,;:,,,,...........   ,:,''',:;'''......   .'::,.........................',,,;;;;::;dO,..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.............. ,kd;:;;,,,,'.........................  .............     .. ..  .................... ................    ...........................              ......................  ..........  ......................   ...................    .............................'',,,,,;,dk,..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.............. ,ko;;,,,''..........................                   ...      ................     ..               .......         ...........                       .....    ........    .......           ...............           ..........     .............................'',,,,'ok,..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.............. ,kl,,,'.....................':clc;'...........................'c,........................;clc;'..........................,:cc;....            .....................';:cc;.................................................................'......,;.......:;............''''ok,..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.............. ,xl''.......................,OWXkdxx:.........................dXc.......................'xNNOdxxl'....................:xxddool,.....       .....................'lxxdoooc.......................................................o0d:cllllo:.....cOl......lXo..............'.lk,..............\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.............. ,xc..........................xXl...cOd.......................c0o.........................oXx...;kk,.................;k0l'......................................c0Oc.........................................................:ookKkocc:,'.......c0l......:0x.................cx, .............\n");
     printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t......... ,o;.........................oNx.....:0c.....................cKx,........................:X0,....,0d................cKO,.......................................dKd'.......,:c:;,'.............................................'o0l.............c0o......:0k;.................;d' .............\n");
      printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t... .. . .,.... ....................:K0,.....:0:...',;:,...........'l0x,''.. .................. 'OXc.... ,Oo....,;:,.......:KO,............  .........................oNx.......,loodxxOx:...........................................,dKx;,;;,'.......c0o....''c0O:''.................,...............\n");
              printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.......................... .kXl.....;Oo.;kxllc:'. .  .....'oKx..,'.,:lo, ..,;::....... .oNd. ...,xx''xklllc,..... .dNo............'';ld:.l0kdd:...',;od;.... 'OX:.......ckOoloxXKl,;'.:coo'..',;:;.......'....',:od;.......,:O0c'........',,;o0o..ll,'lKO'.:l,..';::,.........................\n");
               printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t....... ...  .... ........lNk. ..;dx:.'kXd:::,..;;,::dO:.:0x..dXOxo,cd;,ll;,lKx. .... ;K0,  .,okl..oXk:::;...... .xNl........ .c:,.;0X: .dkl:;,c:'.:KK;.... 'OK;......'l0WNO0WNOoOXOxl,ld,;ol;,dXd;:;::lOd:c:'.cK0;.......'xO;.......'ll;',xXo.'kO,.,0O'.oOc'co:,;kKc;;;::oOl................\n");
                printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t....            ........;0Nd:lddd:. .oNd;;;:;,xN0l;c0o.;0x..oNNk;....c0o. .ok;. .. .'kNk:coddl'. :Xk;;::;'. .....;KO,.  ..,;;kk'.;kNdcoooOO,,0x..:OXl.......lKx.....,cxk0xcokkx0WNx,....l0l..,xkxKXx:;kOo0x..:OXl.......,kOc;:clooooO0, .:Oo..k0,.;OO'.lKl'x0; .:kxkXKo;cOd.................\n");
                                    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.. .oN0dol:.. . .lxc;::::cdl,..kO'.oo. .ox:. .. .;dl,,::.. ... .cKKxdl:'. . .ckl;;:::,. .. ...,dxolcccc,;dx:,;ll'.,:lxk::kd:,:oc. ..... .:dxolcccc::lcccc::dd;......:xl,;c;'ld:..lKl:kd:;:ol.......'x0xodolcc:;:ddc,lKx. ;d:..ld' .oo..od:,;:,,oo,..xO, ................\n");
                                        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.,.   . ........      . . .''......... .. .   ....  .  .... .,'.   .........      ...........''... ............. .......................''...................................',.................'................;'..................... ... ...''. ............   .\n");
                                              printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t. ..     ..   .. ...  ..... .......    ... ..... ................................................................................................................................................................................................. .          \n");
                                                          printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t. ..      ..  ....  ... ... .. ...... ....................................................................................................................................................................................... .. ...              \n");
                                                                           printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.     ..    .  .  .. ............... .. ................................................................ .........................................................................................  ...........  ..              \n");
                                     printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t........................  .  ...................................................................................................................................................................................................... .........    ..   .                \n");
                                     printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.',..,',,..'''.','...'........''''''...',,'''...''''''..,'''','...'''...'....'','...'',,...','..'',,..,,,,....'...''',','..','',..,'''.',..,'''','.',','......'''',,,'..,,,'',...''',,'','...',,'',',,...'''','',,',..,'','',,','.   .  ..   ..                        \n");
                                    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...'..'..........'.....'........''........'...................'.....'''..''..........''.'..........''..'.''....'...''.'.........'..'.''..'..'.'..'...'.''..'''''...''....'....'......''..'....''...'.''....'.''.....'..'.....''.'..                                     \n");
                                  printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.......'.......'...'...............''.....'... .  .....................''.......'...''.'...''........'...''.....'''....''...''.......''.............'.'..........''......'........'.....'.............''.......'.....''.'''............                                   \n");
                                  printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t..'''.',''.....',..''''.. .'''''''',,'..'','....'..',,..'''..',..',...'','..'..'',..',''....',,'.'''',...','...,',,''.','..''''....''''..''..',''''',''.....'.''.,,...'.','''..'.',''...,'',''..'...,,,,'.....','..,',''',,,'..','''...                                   \n");
                               printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t............................ .....................................................................,,'.,;'.........''.';;'....';..,,..';'.''......''''..''.........'.............................'.......................''...................                                \n");
                               printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.,,'',...'.'',,',' .',,,..'...',..',,,. .,,,...',,,'''. ......,''''''.'''..'...'...'.'...,,',.   'lc''co:.cll:,;'cdc.;l:;.  .ll''lo;'co;'lo:.   ...'''',,'..,'''',,,....',,..,'',,'',......',,'','...',. .'',..''''''. .....'','.,,'.'. .....                                \n");
                               printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.................. ......... .......... ............... ......................................   'c'.'cl:.lkx;,:'lOl';l:;.  .;c.':c,':l;'okl.      ....................................   .............. .............  ..........'....  ....                                \n");
                               printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.......,;;'.            .'.....................             .............................        'cl''co;.:ll,,;.:oc.;olc.  .:o,'cl,.co;':oc.       .................    ........................   ..'.............   ..'...'.''.....    .''.                               \n");
                               printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t........'...            .'.....................             .............................        ........................   .................        ................    ........................   ..'.......'..'.    .......'.......    .'..                               \n");
                                printf("\n\t\t\t\t CREDITOS: VITOR ODORISSO");            
                                                                                                                                                                                                                                                                                                            

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
}

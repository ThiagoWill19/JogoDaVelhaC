#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void display();
void limpaTela();
void jogada();
void analisarJogada();
void analisarJogo();

char map[3][3] = {{' ',' ',' '},
                  {' ',' ',' '},
                  {' ',' ',' '},};


int posL, posC;  //posiçao linha e posiçao coluna
int jogador = 0; // 0 para O e 1 para X
int loop = 1;    //  quando = 0 finaliza while

int main(int argc, char const *argv[])
{
    display();
    while (loop == 1)
    {
        
        jogada();
        display();
        analisarJogo();
        printf("\n");
      
    }
    
    return 0;
}

void display(){

    limpaTela();

    printf("  0 1 2\n");

    for(int i = 0; i < 3; i++){

        printf("%d",i);
        for(int j = 0; j < 3; j++){

            printf("|");
            printf("%c", map[i][j]);

        }
        printf("|");
        printf("\n");
    }
    printf("\n");

}

void limpaTela(){
    system("clear");
}

void jogada(){

    posL = 10;
    posC = 10;

    if(jogador == 0) printf("Vez do 'O'\n\n");
    else printf("Vez do 'X'\n\n");

    printf("Escolha a linha: ");
    scanf("%d",&posL);
    setbuf(stdin, NULL);
    printf("Ecolha a coluna: ");
    scanf("%d",&posC);
    setbuf(stdin, NULL);

        if(!isdigit(posL + '0') && !isdigit(posC + '0')){                               //verifica se foi digitado um número
            printf("\nSomente números de 0 a 2 são permitidos, refaça a jogada!\n");
            jogada();
        } 

        if(posL >=0 && posL <= 2 && posC >= 0 && posC <= 2){ //verifica se o número é >= 0 e <= 2
            analisarJogada();
        }else{
            printf("\nSomente números de 0 a 2 são permitidos, refaça a jogada!\n");
            jogada();
        }  
        
}

void analisarJogada(){        //verifica se a posição é válida e muda para o próximo jogador

    if(map[posL][posC] == ' '){
        if(jogador == 0){
            map[posL][posC] = 'O';
            jogador = 1;
        }else{
            map[posL][posC] = 'X';
            jogador = 0;
        } 
    
    }else{
        printf("Posição Inválida!\n");
        jogada();
    }

}

void analisarJogo(){ //verifica se há vencedor, fim de jogo ou se continua 
                     //pretendo simplificar essa função

    if(map[0][0] == 'X' && map[0][1] == 'X' && map[0][2] == 'X'){
        loop = 0;
        printf("Jogador X ganhou!");
        return;
    }
    if(map[1][0] == 'X' && map[1][1] == 'X' && map[1][2] == 'X'){
        loop = 0;
        printf("Jogador X ganhou!");
        return;
    }
    if(map[2][0] == 'X' && map[2][1] == 'X' && map[2][2] == 'X'){
        loop = 0;
        printf("Jogador 'X ganhou!");
        return;
    }
    if(map[0][0] == 'X' && map[1][0] == 'X' && map[2][0] == 'X'){
        loop = 0;
        printf("Jogador X ganhou!");
        return;
    }
    if(map[0][1] == 'X' && map[1][1] == 'X' && map[2][1] == 'X'){
        loop = 0;
        printf("Jogador X ganhou!");
        return;
    }
    if(map[0][2] == 'X' && map[1][2] == 'X' && map[2][2] == 'X'){
        loop = 0;
        printf("Jogador X ganhou!");
        return;
    }
    if(map[0][0] == 'X' && map[1][1] == 'X' && map[2][2] == 'X'){
        loop = 0;
        printf("Jogador X ganhou!");
        return;
    }
    if(map[0][2] == 'X' && map[1][1] == 'X' && map[2][0] == 'X'){
        loop = 0;
        printf("Jogador X ganhou!");
        return;
    }



     if(map[0][0] == 'O' && map[0][1] == 'O' && map[0][2] == '0'){
        loop = 0;
        printf("Jogador O ganhou!");
        return;
    }
    if(map[1][0] == 'O' && map[1][1] == 'O' && map[1][2] == 'O'){
        loop = 0;
        printf("Jogador O ganhou!");
        return;
    }
    if(map[2][0] == 'O' && map[2][1] == 'O' && map[2][2] == 'O'){
        loop = 0;
        printf("Jogador O ganhou!");
        return;
    }
    if(map[0][0] == 'O' && map[1][0] == 'O' && map[2][0] == 'O'){
        loop = 0;
        printf("Jogador O ganhou!");
        return;
    }
    if(map[0][1] == 'O' && map[1][1] == 'O' && map[2][1] == 'O'){
        loop = 0;
        printf("Jogador O ganhou!");
        return;
    }
    if(map[0][2] == 'O' && map[1][2] == 'O' && map[2][2] == 'O'){
        loop = 0;
        printf("Jogador O ganhou!");
        return;
    }
    if(map[0][0] == 'O' && map[1][1] == 'O' && map[2][2] == 'O'){
        loop = 0;
        printf("Jogador O ganhou!");
        return;
    }
    if(map[0][2] == 'O' && map[1][1] == 'O' && map[2][0] == 'O'){
        loop = 0;
        printf("Jogador O ganhou!");
        return;
    }
    
    printf("\n");
    for(int i = 0; i < 3; i++){ 
        for(int j = 0; j < 3; j++){
            if(map[i][j] == ' ') return;
        }
    }

    loop = 0;
    printf("Deu Velha!");
    printf("\n");
    
}

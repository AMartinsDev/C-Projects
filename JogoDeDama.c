#include <stdio.h>

int main (){
  
    char jogada[3];
    char tabuleiro[3][3];
    int i, j;
    int vencedor = 0;
    int aux = 0;
  
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            tabuleiro[i][j] = ' ';
      
    i = 1;
    j = 0;
  
    while (vencedor == 0){
        
        if ((tabuleiro[0][0] == 'X' && tabuleiro[0][1] == 'X' && tabuleiro[0][2] == 'X') 
        || (tabuleiro[0][0] == 'O' && tabuleiro[0][1] == 'O' && tabuleiro[0][2] == 'O'))
            vencedor++;
        
        else if ((tabuleiro[1][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[1][2] == 'X') 
        || (tabuleiro[1][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[1][2] == 'O'))
            vencedor++;
            
        else if ((tabuleiro[2][0] == 'X' && tabuleiro[2][1] == 'X' && tabuleiro[2][2] == 'X') 
        || (tabuleiro[2][0] == 'O' && tabuleiro[2][1] == 'O' && tabuleiro[2][2] == 'O'))
            vencedor++;
            
        if ((tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 'X') 
        || (tabuleiro[0][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][2] == 'O'))
            vencedor++;
            
        else if ((tabuleiro[0][2] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][0] == 'X') 
        || (tabuleiro[0][2] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][0] == 'O'))
            vencedor++;
            
        if ((tabuleiro[0][0] == 'X' && tabuleiro[1][0] == 'X' && tabuleiro[2][0] == 'X') 
        || (tabuleiro[0][0] == 'O' && tabuleiro[1][0] == 'O' && tabuleiro[2][0] == 'O'))
            vencedor++;
            
        else if ((tabuleiro[0][1] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][1] == 'X') 
        || (tabuleiro[0][1] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][1] == 'O'))
            vencedor++;
            
        else if ((tabuleiro[0][2] == 'X' && tabuleiro[1][2] == 'X' && tabuleiro[2][2] == 'X') 
        || (tabuleiro[0][2] == 'O' && tabuleiro[1][2] == 'O' && tabuleiro[2][2] == 'O'))
        vencedor++;
        
        if (tabuleiro[0][0] != ' ' && tabuleiro[0][1] != ' ' && tabuleiro[0][2] != ' ' && tabuleiro[1][0] != ' ' && tabuleiro[1][1] != ' ' && tabuleiro[1][2] != ' ' && tabuleiro[2][0] != ' ' && tabuleiro[2][1] != ' ' && tabuleiro[2][2] != ' ' && vencedor <= 0){
            printf ("Não ouve vencedores, DEU VELHA");
            return 0;
        }
                
        printf ("\n\t   1  2  3");
        printf ("\n\tA %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
        printf ("\tB %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro [1][2]);
        printf ("\tC %c | %c | %c \n", tabuleiro [2][0], tabuleiro[2][1], tabuleiro[2][2]);
        
        if (vencedor > 0){
            printf ("Vencedor e o jogador %d, PARABENS\n", i);
            return 0;
        }

        printf ("\nJogador %d, informe sua jogada:\n", i);
        scanf ("%s", &jogada);
        getchar ();

        if (vencedor == 0){
            switch (jogada[0]){
                case 'A':
                    switch (jogada[1]){
                        case '1':
                            if (tabuleiro[0][0] == ' '){
                                if (i == 1)
                                    tabuleiro[0][0] = 'X';
                                else
                                    tabuleiro[0][0] = 'O';
                            }
                            else {
                                printf ("Ja foi jogado\n");
                                j++;
                            }
                        break;
                        
                        case '2':
                            if (tabuleiro[0][1] = ' '){
                                if (i == 1)
                                    tabuleiro[0][1] = 'X';
                                else
                                    tabuleiro[0][1] = 'O';
                            }
                            else {
                                printf ("Ja foi jogado\n");
                                j++;
                            }
                        break;
                        
                        case '3':
                            if (tabuleiro[0][2] == ' '){
                                if (i == 1)
                                    tabuleiro[0][2] = 'X';
                                else 
                                    tabuleiro[0][2] = 'O';
                            }
                            else {
                                printf ("Ja foi jogado\n");
                                j++;
                            }
                        break;
                        
                        default:
                            printf ("Erro jogue de novo\n");
                            j++;
                    }
                break;
                
                case 'B':
                    switch (jogada[1]){
                        case '1':
                            if (tabuleiro[1][0] == ' '){
                                if (i == 1)
                                    tabuleiro[1][0] = 'X';
                                else
                                    tabuleiro[1][0] = 'O';
                            }
                            else {
                                printf ("Ja foi jogado\n");
                                j++;
                            }
                        break;
                        
                        case '2':
                            if (tabuleiro[1][1] == ' '){
                                if (i == 1)
                                    tabuleiro[1][1] = 'X';
                                else
                                    tabuleiro[1][1] = 'O';
                            }
                            else {
                                printf ("Ja foi jogado\n");
                                j++;
                            }
                        break;
                        
                        case '3':
                            if (tabuleiro[1][2] == ' '){
                                if (i == 1)
                                    tabuleiro[1][2] = 'X';
                                else 
                                    tabuleiro[1][2] = 'O';
                            }
                            else {
                                printf ("Ja foi jogado\n");
                                j++;
                            }
                        break;
                        
                        default:
                            printf ("Erro jogue novamente\n");
                            j++;
                    }
                break;
                
                case 'C':
                    switch (jogada[1]){
                        case '1':
                            if (tabuleiro[2][0] == ' '){
                                if (i == 1)
                                    tabuleiro[2][0] = 'X';
                                else
                                    tabuleiro[2][0] = 'O';
                            }
                            else {
                                printf ("Ja foi jogado\n");
                                j++;
                            }
                        break;
                        
                        case '2':
                            if (tabuleiro[2][1] == ' '){
                                if (i == 1)
                                    tabuleiro[2][1] = 'X';
                                else
                                    tabuleiro[2][1] = 'O';
                            }
                            else {
                                printf ("Ja foi jogado\n");
                                j++;
                            }
                        break;
                        
                        case '3':
                            if (tabuleiro[2][2] == ' '){
                                if (i == 1)
                                    tabuleiro[2][2] = 'X';
                                else 
                                    tabuleiro[2][2] = 'O';
                            }
                            else {
                                printf ("Ja foi jogado\n");
                                j++;
                            }
                        break;
                        
                        default:
                            printf ("Erro jogue novamente\n");
                            j++;
                    }
                break;
                
                default:
                    printf ("Erro jogue novamente\n");
                    j++; 
            }
        }
            
            if (j > 0){
                i = i;
                j = 0;
            }
            else 
                if (i == 1){
                i++;
                j=0;
            }
            else
                if (i == 2){
                    i--;
                    j=0;
            }
    }

return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
	
	printf ("\n***REGRAS DO JOGO!!***\n");
	printf ("* O tabuleiro eh composto por uma matriz de 3 linhas e 3 colunas.\n");
	printf ("* Dois jogadores escolhem uma coordenada, onde o primeiro sera uma bola (O) e o segundo jogador um xis (X).\n");
	printf ("* Os jogadores jogam alternadamente, uma marcacao por vez, em uma linha e coluna que esteja vazia.\n");
	printf ("* Vence o jogador que completar a linha, coluna ou diagonal principal ou secundaria primeiro.\n");
	printf ("* Para preencher a coordenada informe primeiro a linha 'espaco' informe a coluna.\n");
		
	int i,j, line, column, jogador, venceu = 0, partidas = 0, opcao;
	char matriz[3][3];
	
	do{
		// desenhando o tabuleiro com espacos
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				matriz[i][j] = ' ';
			}
		}
	
		partidas = 0; // variavel para guardar a quantidade de partidas
		venceu = 0; // uma variavel para guardar quem ganhar a partida
		jogador = 1;
		
		do{
			//imprimindo o desenho do tabuleiro utilizando as barras
			printf("\n\n\t 0   1   2\n\n");	// marcando as coordenadas de linha
			for (i=0;i<3;i++){
				for (j=0;j<3;j++){
					if(j==0)
						printf("\t");
					printf (" %c ", matriz[i][j]);
					if (j<2)
						printf ("|");		
					if(j==2)	// imprimindo as colunas usando o indice da linha
						printf (" %d", i);
				}
				if (i<2)	// imprimindo o tracejado
					printf("\n\t-----------");	
				printf("\n");
				
			}
			
			// Verificando se a linha e coluna estejam disponiveis para marcar
			do{
				printf("\nJOGADOR %d: Informe a linha e a coluna que quer marcar: ", jogador);
				scanf ("%d%d", &line, &column);
			} while( column < 0 || column > 2 || line < 0 || line > 2 || matriz[line][column] != ' ');	/// se for diferente de espaço significa que alguem ja jogou nessa posicao
			
			//marcar no tabuleiro a posicao que o jogador escolheu
			switch(jogador){
				case 1: // jogador1
					matriz [line][column] = 'O';
					jogador++;
					break;
				case 2:	//jogador2
					matriz [line][column] = 'X';
					jogador = 1;  //volta pra um pois a prox jogada vai ser do jogador 1
				break;
			}
			partidas++;	// toda vez que tiver uma posicao valida ele incrementa
			
			
			// um if para verificar quando o jogador1 vence por linha
			if (matriz[0][0] == 'O' && matriz[0][1] == 'O' && matriz[0][2] == 'O' || // o if verifica linha por linha
				matriz[1][0] == 'O' && matriz[1][1] == 'O' && matriz[1][2] == 'O' ||
				matriz[2][0] == 'O' && matriz[2][1] == 'O' && matriz[2][2] == 'O'){
					printf("\nParabens! O jogador 1 venceu, pois preencheu toda linha!\n"); // se isso acontecer, o jogador1 vence
					venceu= 1;
				}
				
			if (matriz[0][0] == 'X' && matriz[0][1] == 'X' && matriz[0][2] == 'X' ||	// if para verificar quando o jogador 2 vence por linha
				matriz[1][0] == 'X' && matriz[1][1] == 'X' && matriz[1][2] == 'X' ||
				matriz[2][0] == 'X' && matriz[2][1] == 'X' && matriz[2][2] == 'X'){
					printf("\nParabens! O jogador 2 venceu, pois preencheu toda linha!\n");
					venceu= 1;
				}
				
				
			// verificar quando o jogador1 vence por coluna
			if (matriz[0][0] == 'O' && matriz[1][0] == 'O' && matriz[2][0] == 'O' ||
				matriz[0][1] == 'O' && matriz[1][1] == 'O' && matriz[2][1] == 'O' ||
				matriz[0][2] == 'O' && matriz[1][2] == 'O' && matriz[2][2] == 'O'){
				printf("\nParabens! O jogador 1 venceu, pois prencheu toda coluna!\n");
				venceu= 1;
			}
			
			// verificar quando o jogador2 vence por coluna
			if (matriz[0][0] == 'X' && matriz[1][0] == 'X' && matriz[2][0] == 'X' ||	
				matriz[0][1] == 'X' && matriz[1][1] == 'X' && matriz[2][1] == 'X' ||
				matriz[0][2] == 'X' && matriz[1][2] == 'X' && matriz[2][2] == 'X'){
				printf("\nParabens! O jogador 2 venceu, pois preencheu toda coluna!\n");
				venceu= 1;
			}
			
			
			// verificar quando o jogador1 vence na diagonal principal
			if(matriz[0][0] == 'O' && matriz[1][1] == 'O' && matriz[2][2] == 'O'){ // verifica se a linha e coluna sao iguais
				printf("\nParabéns! O jogador 1 venceu, pois preencheu a diagonal principal!\n");
				venceu= 1;
			}
			
			// verificar quuando o jogador2 vence na diagonal principal
			if(matriz[0][0] == 'X' && matriz[1][1] == 'X' && matriz[2][2] == 'X'){
				printf("\nParabéns! O jogador 2 venceu pois, preencheu a diagonal principal!\n");
				venceu= 1;
			}
			
			
			// verificar quando o jogador1 vence na diagonal secundaria
			if(matriz[0][2] == 'O' && matriz[1][1] == 'O' && matriz[2][0] == 'O'){	
				printf("\nParabéns! O jogador 1 venceu, pois preencheu a diagonal secundaria!\n");
				venceu= 1;
			}
			
			// verifica quando o jogador2 vence na diagonal secundaria
			if(matriz[0][2] == 'X' && matriz[1][1] == 'X' && matriz[2][0] == 'X'){
				printf("\nParabéns! O jogador 2 venceu, pois preencheu a diagonal secundaria!\n");
				venceu= 1;
			}
		}while(venceu == 0 && partidas < 9); // while para repetir ate alguem ganhar uma partida, conta quantas jogadas foram feitas ate preencher todo tabuleiro e assim o jogo finaliza
		    
		if(venceu == 0)	// quando prencher todo tabuleiro e ninguem ganhar
			printf("\n O jogo terminou em empate!\n");
			printf("\nDigite 1 para recomecar o jogo: \n");
			scanf("%d", &opcao);
	}while(opcao == 1);	// while para repetir quando o usuario desejar jogar novamente e quando for diferente de 1 o jogo vai finalizar
	
	return 0;
}

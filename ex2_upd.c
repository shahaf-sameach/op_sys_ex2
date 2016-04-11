

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int board[4][4];

void print_board(){
	for(int i=0; i<4;i++){
		for(int j=0; j<4;j++){
			if (board[i][j] == 0)
				printf("|     ");
			else
				printf("| %04d",board[i][j]);
			printf(" ");
		}
		printf("|\n");
	}
}

void bye(){
	printf("BYE BYE");
}

int main (int argc, char *argv[])
{
	for(int i=0; i<4;i++){
		for(int j=0; j<4;j++){
			board[i][j] = j+i;
		}
	}

	board[2][2] = 24;
	print_board();
}


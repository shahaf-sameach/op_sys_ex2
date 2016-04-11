

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

void move_up(){
	for (int j = 0 ; j < 4 ; j++){
		for(int i = 1 ; i< 4; i++){
			while(1){
				if (board[i][j] == 0){
					break;
				}
				if (board[i-1][j] == 0){
					board[i-1][j] = board[i][j];
					board[i][j] = 0;
					i--;
				} 
				else if (board[i-1][j] == board[i][j]) {
					board[i-1][j] = board[i-1][j] * 2 * -1;
					board[i][j] = 0;
				}
				else {
					break;
				}
			}
		}
	}
}

void move_down(){
	for (int j = 0 ; j < 4 ; j++){
		for(int i = 2 ; i >= 0; i--){
			while(1){
				if (board[i][j] == 0){
					break;
				}
				if (board[i+1][j] == 0){
					board[i+1][j] = board[i][j];
					board[i][j] = 0;
					i++;
				} 
				else if (board[i+1][j] == board[i][j]) {
					board[i+1][j] = board[i+1][j] * 2 * -1;
					board[i][j] = 0;
				}
				else {
					break;
				}
			}
		}
	}
}

void move_left(){
	for (int i = 0 ; i < 4 ; i++){
		for(int j = 1 ; j < 4; j++){
			while(1){
				if (board[i][j] == 0){
					break;
				}
				if (board[i][j-1] == 0){
					board[i][j-1] = board[i][j];
					board[i][j] = 0;
					j--;
				} 
				else if (board[i][j-1] == board[i][j]) {
					board[i][j-1] = board[i][j-1] * 2 * -1;
					board[i][j] = 0;
				}
				else {
					break;
				}
			}
		}
	}
}

void move_right(){
	for (int i = 0 ; i < 4 ; i++){
		for(int j = 2 ; j >= 0; j--){
			while(1){
				if (board[i][j] == 0){
					break;
				}
				if (board[i][j+1] == 0){
					board[i][j+1] = board[i][j];
					board[i][j] = 0;
					j++;
				} 
				else if (board[i][j+1] == board[i][j]) {
					board[i][j+1] = board[i][j+1] * 2 * -1;
					board[i][j] = 0;
				}
				else {
					break;
				}
			}
		}
	}
}

void align_board(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if (board[i][j] < 0)
				board[i][j] = board[i][j] * -1;
		}
	}
}

void reset_board(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if (board[i][j] < 0)
				board[i][j] = 0;
		}
	}
}

void rand_board(){
	int i, j;
	while(1){
		i = rand() % 4; 
		j = rand() % 4;
		if (board[i][j] == 0){
			board[i][j] = 2;
			break;
		}
	}
}

void init_board(){
	reset_board();
	for(int i = 0 ; i < 2 ; i++)
		rand_board();
}

int is_loose(){
	int loose = 1;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if (board[i][j] == 0)
				loose = 0;
		}
	}
	return loose;
}

int is_win(){
	int win = 0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if (board[i][j] == 2048)
				win = 1;
		}
	}
	return win;
}


int main (int argc, char *argv[])
{
	for(int i=0; i<4;i++){
		for(int j=0; j<4;j++){
			board[i][j] = j+i;
		}
	}

	board[0][0] = 1;
	board[1][0] = 1;
	board[2][0] = 1;
	board[3][0] = 1;
	print_board();
	move_up();
	printf("\n\n");
	print_board();
}


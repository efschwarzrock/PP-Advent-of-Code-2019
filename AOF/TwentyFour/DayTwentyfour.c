 
/*
 * production.c
 *
 *  Created on: dec 25 2019
 *      Author: Erich Schwarzrock
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * the number of living neighbors for a cell to be born
 */
#define BIRTHNUM (2)
#define BIRTHNUMTWO (1)

/**
 * the  number of living neighbors for a cell to stay alive
 */
#define NEIGHBORS (1)






/**
 * Prints the board out to the counsel
 * @param nr the number of rows
 * @param nc the number of columns
 * @param arr the board
 */
void printBoard (unsigned int nr, unsigned int nc, char arr[][nc])
{
	int nRows = nr;
	int nCols = nc;
	for(int row = 0;row < nRows;row++)
	{
		printf("\n");
		for(int col=0; col < nCols; col++)
		{

				printf("%c", *( ((char*) arr) + (row * nCols) + col));
		}
	}
	printf("\n");
	printf("\n");
	printf("\n");
}



/**
 * Initializes the 3 boards to all be dead
 * @param nr the number of rows
 * @param nc the number of columns
 * @param board the boards to initialize
 */
void createBoards(int nr, int nc, int nb, char board[nb][nr][nc]){
	int row = 0;
	int col = 0;
	int b = 0;
	while(b < nb){
	while(row < nr)
		{
		col = 0;
			while(col < nc)
			{
				//initalize
					
					*( ((char*) board) + (nr * nc * b) + (row * nc) + col) = 'o';
					col++;
			}
			row++;
		}
	b++;
	}
}


/**
 * Checks if the board contains only 'o'
 * @param nr the number of rows
 * @param nc the number of columns
 * @param board the board to check
 * @return true if it is dead false otherwise
 */
bool IsDead(int nr, int nc, char board[][nc]){
	bool isDead = true;
	for(int row=0;row<nr && isDead;row++)
			{
				for(int col=0; col<nc && isDead; col++)
				{
					//checks if it is alive
					if(board[row][col] == 'x')
					{
						isDead = false;
					}
				}
			}
	return isDead;
}



/**
 * Checks if two boards of equal size have identical values
 * @param nr the number of rows
 * @param nc the number of columns
 * @param boardOne the first board to compare
 * @param boardTwo the second board to compare
 * @return true if they are equal false otherwise
 */
bool IsRepeat(int nr, int nc, char boardOne[][nc], char boardTwo[][nc]){
	bool isIdentical = true;
	for(int row=0;row<nr && isIdentical;row++)
			{
				for(int col=0; col<nc && isIdentical; col++)
				{
					//checks if they arn't equal
					if(boardOne[row][col] != boardTwo[row][col])
					{
						isIdentical = false;
					}
				}
			}
	return isIdentical;
}


/**
 * Checks if the specified cell is alive, dead or out of bounds
 * @param row the row of the cell to check
 * @param col the column of the cell to check
 * @param nr the number of rows
 * @param nc the number of columns
 * @param old the board to check on
 * @return 1 if it is alive 0 if it is dead or out of bounds
 */
int isNeighbor(int row, int col, int nr, int nc, char Old[][nc]){
	//checks if it is out of bounds
	if(row < 0 || col < 0 || row >= nr || col >= nc){
		return 0;
	}
	//checks if it is alive
	return (*( ((char*) Old) + (row * nc) + col) == 'x');
}

/**
 * Counts the number of living neighbors of the given cell
 * @param row the row of the cell to check
 * @param col the column of the cell to check
 * @param nr the number of rows
 * @param nc the number of columns
 * @param old the board to check on
 * @return the number of living neighbors it has
 */
int getNumNeighbors(unsigned int row, unsigned int col, unsigned int nr, unsigned int nc, char Old[][nc]){
	int numNeighbors = 0;
	//checks each side and adds them
	numNeighbors += isNeighbor(row-1, col, nr, nc, Old);
	numNeighbors += isNeighbor(row, col-1, nr, nc, Old);
	numNeighbors += isNeighbor(row, col+1, nr, nc, Old);
	numNeighbors += isNeighbor(row+1, col, nr, nc, Old);
	return numNeighbors;


}


/**
 * PlayOne carries out one generation
 * @param unsigned int nr, the number of rows in the petri dish
 * @param unsigned int nc, the number of columns in the petri dish
 * @param char* Old, the location of the upper left of starting petri dish
 * @param New, the location of the upper left of the ending petri dish
 * @return There is none, because results are in New array
 */
void PlayOne (unsigned int nr, unsigned int nc, char Old[][nc], char New[][nc], bool printstuff)
{
	int nRows = nr;
	int nCols = nc;
	for(int row = 0;row < nRows;row++)
	{
		for(int col=0; col < nCols; col++)
		{
			int neighbors = 0;
			neighbors = getNumNeighbors(row, col, nRows, nCols, Old);
			if(printstuff){
				printf("%d%c", neighbors, *( ((char*) Old) + (row * nCols) + col));
			}
			//checks if it should be born
			if((neighbors == BIRTHNUM ||  neighbors == BIRTHNUMTWO )&& *( ((char*) Old) + (row * nCols) + col) == 'o' ){
				*( ((char*) New) + (row * nCols) + col) = 'x';


				// check if it is living and should stay living
			}else if(*( ((char*) Old) + (row * nCols) + col) == 'x' && neighbors == NEIGHBORS){
				*( ((char*) New) + (row * nCols) + col) = 'x';


				//checks if the cell is in play then kills it
			}else if(*( ((char*) Old) + (row * nCols) + col) == 'x' || *( ((char*) Old) + (row * nCols) + col) == 'o'){
				*( ((char*) New) + (row * nCols) + col) = 'o';

				//keeps the cell whatever garbage value it has
			}else{
				*( ((char*) New) + (row * nCols) + col) = *( ((char*) Old) + (row * nCols) + col);
			}
		}
		printf("\n");
	}
}

void calcBio(unsigned int nRows, unsigned int nCols, char board[nRows][nCols]){
	int i = 0;
	int sum = 0;
	int add = 1;
	while(i<nRows){
		int j = 0;
		while(j<nCols){
			if(*( ((char*) board) + (i * nCols) + j) == 'x'){
				sum += add;
			}
			add = add*2;
			j++;
		}
		i++;
	}
	printf("bio = %d\n", sum);
}
			

/**
 * Plays the game of life for the specified number of generations
 * @param nRows the number of rows in the boards
 * @param nCols the number of columns in the boards
 * @param nb the number of generations to run and the number of boards to pass in
 * @param boards the 3 boards the play the game on
 * @param printGens whether or not to print each generation
 * @param stopBetweenGens whether or not to wait for a key stroke to play the next generation
 */
void playGame(unsigned int nRows, unsigned int nCols, int nb, char boards[nb][nRows][nCols], bool printGens, bool stopBetweenGens){
	int exitCondition = 0; // whether the game terminated
	//0 it hasn't 1 its a stable state 3 is it ran the number of gens and -1 is everything died
	int curentAge = 0;
	//prints the first board
	printBoard(nRows, nCols, boards[0]);
	bool printstuff = false;
	//keeps iterating until it ends
	while(exitCondition == 0){

		if(curentAge == 2){
			//sprintstuff = true;
		}

		//plays a gen onto the next board
		PlayOne(nRows, nCols, boards[curentAge%nb], boards[(curentAge+1)%nb], printstuff);
		//checks if it ran all the gens yet
		if(curentAge >= nb - 2){
			exitCondition =  3;
		}


		int i = 0;
		while(i < curentAge){
			//checks if it is a repet
			if(IsRepeat(nRows, nCols, boards[i], boards[curentAge + 1])){
				exitCondition = 1;
			}
			i++;
		}
		



		//checks if its dead
		if(IsDead(nRows, nCols, boards[(curentAge+1)])){
			exitCondition = -1;
		}
		//stops it if it was specified to stop
		if(stopBetweenGens){
			printf("press enter to continue");
			getc(stdin);
		}
		//prints if its specified to print
		if(printGens){
			printBoard(nRows, nCols, boards[(curentAge+1)]);
		}
		curentAge ++;
	}
	//prints why it exited
	if(exitCondition == 1){
		printf("repete found\n");
		printBoard(nRows, nCols, boards[(curentAge)]);
		calcBio(5, 5, boards[(curentAge)]);
	}else if(exitCondition == 2){
		printf("entered a binary sicle\n");
	}else if(exitCondition == 3){
		printf("ended after %d generations\n", nb);
	}else if(exitCondition == -1){
		printf("dead\n");
	}
}


int main(int argc, char* argv[]){
	char boards[100][5][5];
	createBoards(5, 5, 100, boards);
	//char bio[5][7] = {"ooooo", "ooooo", "ooooo", "xoooo", "oxooo"};
	//calcBio(5, 5, bio);
	char lines[5][7] = {"xxxxo", "oxxoo", "xxoxo", "xxxoo", "xxoox"};
	int i = 0;
	while(i<5){
		int j = 0;
		while(j	< 5){
			boards[0][i][j] = lines[i][j];
			j++;
		}
		i++;
	}
	playGame(5,5,100,boards, true, true);
	return 0;
}





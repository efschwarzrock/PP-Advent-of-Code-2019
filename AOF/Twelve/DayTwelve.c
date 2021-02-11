#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void partOne(){
	int pos[4][3] = {
			{14, 4, 5},
			{12, 10, 8},
			{1, 7, -10},
			{16, -5, 3}};
	
	/*int pos[4][3] = {
			{-1, 0, 2},
			{2, -10, -7},
			{4, -8, 8},
			{3, 5, -1}};
	*/
	int vel[4][3] = {
			{0, 0, 0},
			{0, 0, 0},
			{0, 0, 0},
			{0, 0, 0}};
	int time = 0;
	while(time<1000){
		int moona = 0;
		while(moona < 4){
			int moonb = moona + 1;
			while(moonb < 4){
				int i = 0;
				while(i<3){
					if(pos[moona][i] > pos[moonb][i]){
						vel[moona][i]--;
						vel[moonb][i]++;
					}else if(pos[moona][i] < pos[moonb][i]){
						vel[moona][i]++;
						vel[moonb][i]--;
					}
					i++;
				}
				moonb++;
			}
			moona++;
		}
		int i = 0;
		while(i<4){
			int j = 0;
			while(j<3){
				pos[i][j] += vel[i][j];
				j++;
			}
			i++;
		}
		time++;
	}
	int i = 0;
	int energy = 0;
	while(i<4){
		int j = 0;
		int ke = 0;
		int pe = 0;
		while(j<3){
			pe = pe + abs(pos[i][j]);
			ke = ke + abs(vel[i][j]);
			j++;
		}
		energy += ke*pe;
		i++;
	}
	printf("%d\n", energy);
}


int main(int argc, char* argv[]){
	partOne();
	return 0;
}
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void partOne(){
	FILE* fp = fopen("input.txt", "r");
	printf("here\n");
	fflush(stdout);
	if(fp == false){
		printf("bad file");
		return;
	}
	bool done = false;
	char str[16000];
	int layers[100][6][25]; 
	char leter[2] = "";
	int i = 0;
	str[0] = '\0';
	printf("here");
	fflush(stdout);
	fscanf(fp, "%s", str);
	printf("here\n");
	fflush(stdout);
	if(strlen(str) > 0){
		while(i<16000){
			if(str[i] == '\0' || str[i] == '\n'){
				printf("done");
				i = 17000;
			}else{
				leter[0] = str[i];
				leter[1] = '\0';
				layers[i/150][(i%150)/25][i%25] = atoi(leter);
			}
			i++;
		}
		printf("ther\n");
		fflush(stdout);
		int o = 0;
		int u = 0;
		int p = 0;
		while(o < 100){
			u = 0;
			printf("layer %d\n", o);
			while(u < 6){
				p = 0;
				while(p < 25){
					printf("%d, ", layers[o][u][p]);
					p++;
				}
				printf("\n");
				u++;
			}
			printf("\n\n\n");
			o++;
		}
		fclose(fp);
		o = 0;
		int numO = 0;
		int minNumO = 10000;
		int minNumOI = 0;
		int numOne = 0;
		int numTwo = 0;
		int minNumOneAndTwo = 0;
		while(o<100){
			u = 0;
			numO = 0;
			numOne = 0;
			numTwo = 0;
			while(u < 6){
				p = 0;
				while(p < 25){
					if(layers[o][u][p] == 0){
						numO++;
					}else if(layers[o][u][p] == 1){
						numOne++;
					}else if(layers[o][u][p] == 2){
						numTwo++;
					}
					p++;
				}
				u++;
			}
			//printf("0 = %d\n", numO);
			if(numO < minNumO){
				minNumO = numO;
				minNumOI = o;
				minNumOneAndTwo = numOne * numTwo;
			}
			o++;
		}
		printf("\nresult = %d\n", minNumOneAndTwo); 
	}else{
		printf("bad");
		fclose(fp);
	}
}

void partTwo(){
	FILE* fp = fopen("input.txt", "r");
	printf("here\n");
	fflush(stdout);
	if(fp == false){
		printf("bad file");
		return;
	}
	bool done = false;
	char str[16000];
	int layers[100][6][25]; 
	char leter[2] = "";
	int i = 0;
	str[0] = '\0';
	printf("here");
	fflush(stdout);
	fscanf(fp, "%s", str);
	printf("here\n");
	fflush(stdout);
	if(strlen(str) > 0){
		while(i<16000){
			if(str[i] == '\0' || str[i] == '\n'){
				printf("done");
				i = 17000;
			}else{
				leter[0] = str[i];
				leter[1] = '\0';
				layers[i/150][(i%150)/25][i%25] = atoi(leter);
			}
			i++;
		}
		printf("ther\n");
		fflush(stdout);
		int o = 0;
		int u = 0;
		int p = 0;
		while(u < 6){
			p = 0;
			while(p < 25){
				o = 0;
				while(o < 100){
					if(layers[o][u][p] == 2){
						o++;
					}else{
						if(layers[o][u][p] == 1){
							printf("*");
						}else{
							printf(" ");
						}
						o = 150;					
					}				
				}
				p++;
			}
			printf("\n");
			u++;
		}
		fclose(fp);
	}else{
		printf("bad");
		fclose(fp);
	}
}

int main(int argc, char* argv[]){
	partOne();
	partTwo();
	return 0;
}
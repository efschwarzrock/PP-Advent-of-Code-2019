#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>


int main(int argc, char* argv[]){
	FILE* fp = fopen("input.txt", "r");
	if(fp == false){
		printf("bad file");
		return 0;
	}
	bool done = false;
	char str[1000];
	int i[200];
	int j = 0;
			char num[7];
			int k = 0;
			int l = 0;
		str[0] = '\0';
		fscanf(fp, "%s", str);
		if(strlen(str) > 0){
			printf("dhbghdbf %ld\n", strlen(str));
			
			while(j < strlen(str)+1){
				if(isdigit(str[j])){
					printf("h\n");
					num[k] = str[j];
					k++;
				}else if(k != 0){
					printf("g\n");
					num[k] = '\0';
					i[l] = atoi(num);
					printf("num = %d\n", i[l]);
					l++;
					k = 0;
				}
				if(str[j] == '\0' || str[j] == '\n'){
					printf("done\n\n\n");
					done = true;
				}
				j++;
			}
			int newj = 0;
			while(newj < l){
				printf("d = %d\n", i[newj]);
				newj++;
			}
		}
	int x = 0;
	int com = 0;
	int desA = 0;
	int desB = 0;
	int desC = 0;
	int output = -1;
	while(x < l && output == -1){
		com = i[x];
		desA = i[x+1];
		desB = i[x+2];
		desC = i[x+3];
		if(com == 1){
			i[desC] = i[desA] + i[desB];
		}else if( com == 2){
			i[desC] = i[desA] * i[desB];
		}else if( com == 99){
			output = 0;
		}else{
			output = 1;
		}
		x = x + 4;
	}
	printf("\n\n\no = %d\n", output);
	printf("\n\n%d\n\n", i[0]);

	return 0;
}
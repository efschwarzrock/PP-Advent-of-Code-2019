#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int comp(int a, int b){
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
			
			while(j < strlen(str)+1){
				if(isdigit(str[j])){
					num[k] = str[j];
					k++;
				}else if(k != 0){
					num[k] = '\0';
					i[l] = atoi(num);
					l++;
					k = 0;
				}
				if(str[j] == '\0' || str[j] == '\n'){
					done = true;
				}
				j++;
			}
			int newj = 0;
			while(newj < l){
				newj++;
			}
		}
	i[1] = a;
	i[2] = b;
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
	fclose(fp);
	return i[0];
}

int main(int argc, char* argv[]){
	int i = 0;
	int b = 0;
	while(i<100){
		b = 0;
		while(b<100){
			if(comp(i, b) == 19690720){
				printf("i = %d, b = %d\n", i, b);
			}
			b++;
		}
		i++;
	}
	return 0;
}
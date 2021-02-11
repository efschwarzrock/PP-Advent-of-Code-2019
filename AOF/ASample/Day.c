#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main(int argc, char* argv[]){
	FILE* fp = fopen("input.txt", "r");
	if(fp == false){
		printf("bad file");
		return 0;
	}
	bool done = false;
	char str[256];
	int i;
	while(!done){
		str[0] = '\0';
		fscanf(fp, "%s", str);
		if(strlen(str) > 0){
			i = atoi(str);
			printf("s = %s\n", str);
			printf("d = %d\n", i);
		}else{
			done = true;
			fclose(fp);
		}
	}
	return 0;
}
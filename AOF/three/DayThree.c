#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

struct comand{
	int d;
	int n;
};

void findInter(char str[1024], int* array){
	printf("there\n");
fflush(stdout);
	int i = 0;
	bool done = false;
	char num[10];
	int numi = 0;
	int ci = 0;
	struct comand cs[500];
	while(!done){
		if(isdigit(str[i])){
			num[numi] = str[i];
			numi++;
		}else if(str[i] == '\n' || str[i] == '\0'){
			done  = true;
			num[numi] = '\0';
			cs[ci].n = atoi(num);
			ci++;
			numi = 0;
		}else if(str[i] == 'L'){
			cs[ci].d = 4;
		}else if(str[i] == 'U'){
			cs[ci].d = 1;
		}else if(str[i] == 'R'){
			cs[ci].d = 2;
		}else if(str[i] == 'D'){
			cs[ci].d = 3;
		}else{
			num[numi] = '\0';
			cs[ci].n = atoi(num);
			ci++;
			numi = 0;
		}
		i++;
	}
	cs[ci].d = -1;
	struct comand inters[1000];
	ci = 0;
	int x = 5000;
	int y = 5000;
	int ii = 0;
	done = false;
	while(!done){
		if(cs[ci].d == 1){
			i = 0;
			while(i < cs[ci].n){
				if(*(array + x*20000 + y + i) == 1){
					inters[ii].d = x;
					inters[ii].n = y+i;
					printf("gotone\n");
					ii++;
				}
				i++;
			}
			y = y + i;
		}else if(cs[ci].d == 3){
			i = 0;
			while(i < cs[ci].n){
				if(*(array + x*20000 + y - i) == 1){
					inters[ii].d = x;
					inters[ii].n = y-i;
					printf("gotone\n");
					ii++;
				}
				i++;
			}
			y = y - i;
		}else if(cs[ci].d == 2){
			i = 0;
			while(i < cs[ci].n){
				if(*(array + (x+i)*20000 + y) == 1){
					inters[ii].d = x+i;
					inters[ii].n = y;
					printf("gotone\n");
					ii++;
				}
				i++;
			}
			x = x + i;
		}else if(cs[ci].d == 4){
			i = 0;
			while(i < cs[ci].n){
				if(*(array + (x-i)*20000 + y) == 1){
					printf("gotone\n");
					inters[ii].d = x-i;
					inters[ii].n = y;
					ii++;
				}
				i++;
			}
			x = x - i;
		}else{
			done = true;
		}
		//printf("x = %d, y = %d\n", cs[ci-1].d, cs[ci-1].n);
		ci++;
	}
	printf("three = %d\n", *(array + 18400*20000 + 7124));
fflush(stdout);
	inters[ii].d = -1;
	inters[ii].n = -1;
	struct comand minInter;
	minInter.d = 50000;
	minInter.n = 50000;
	ii = 0;
	done = false;
	while(!done){
		if(inters[ii].d == -1){
			done = true;
		}else if(abs(minInter.d - 5000) + abs(minInter.n - 5000) > abs(inters[ii].d - 5000) + abs(inters[ii].n - 5000) &&
			abs(inters[ii].d - 5000) + abs(inters[ii].n - 5000) != 0){
			minInter.d = inters[ii].d;
			minInter.n = inters[ii].n;
		}
		ii++;
	}
	printf("dddx = %d, dddy = %d\n", minInter.d, minInter.n);
		
		
}


void makeWire(char str[1024], int* array){
	int i = 0;
	bool done = false;
	char num[10];
	int numi = 0;
	int ci = 0;
printf("^^^^^^^\n");
		fflush(stdout);
	struct comand cs[500];
printf(")))))))\n");
		fflush(stdout);
	while(!done){
		if(isdigit(str[i])){
			num[numi] = str[i];
			numi++;
		}else if(str[i] == '\n' || str[i] == '\0'){
			done  = true;
			num[numi] = '\0';
			cs[ci].n = atoi(num);
			ci++;
			numi = 0;
		}else if(str[i] == 'L'){
			cs[ci].d = 4;
		}else if(str[i] == 'U'){
			cs[ci].d = 1;
		}else if(str[i] == 'R'){
			cs[ci].d = 2;
		}else if(str[i] == 'D'){
			cs[ci].d = 3;
		}else{
			num[numi] = '\0';
			cs[ci].n = atoi(num);
			ci++;
			numi = 0;
		}
		i++;
	}
	cs[ci].d = -1;
	ci = 0;
	int x = 5000;
	int y = 5000;
	done = false;
printf(")))))))\n");
		fflush(stdout);
	while(!done){
		if(cs[ci].d == 1){
			i = 0;
			while(i < cs[ci].n){
				*(array + x*20000 + y + i) = 1;
				i++;
			}
			y = y + i;
		}else if(cs[ci].d == 3){
			i = 0;
			while(i < cs[ci].n){
				*(array + x*20000 + y - i) = 1;
				i++;
			}
			y = y - i;
		}else if(cs[ci].d == 2){
			i = 0;
			while(i < cs[ci].n){
				*(array + (x+i)*20000 + y) = 1;
				i++;
			}
			x = x + i;
		}else if(cs[ci].d == 4){
			i = 0;
			while(i < cs[ci].n){
				*(array + (x-i)*20000 + y) = 1;
				i++;
			}
			x = x - i;
		}else{
			done = true;
		}
		printf("x = %d, y = %d\n", x, y);
		ci++;
	}
printf(")))))))\n");
		fflush(stdout);
		
}

void partOne(int* array){
	FILE* fp = fopen("input.txt", "r");
	if(fp == false){
		printf("bad file");
		return ;
	}
	bool done = false;
	char str[4024];
	str[0] = '\0';
	fscanf(fp, "%s", str);
	if(strlen(str) > 0){
		printf("kedfkjvn\n");
		fflush(stdout);
		makeWire(str, array);
		printf("here\n");
		fflush(stdout);
	}else{
		printf("jhfbvehbd");
		fclose(fp);
	}
	fscanf(fp, "%s", str);
	if(strlen(str) > 0){
		findInter(str, array);
	}else{
		printf("*****");
		fclose(fp);
	}
	
}

int main(int argc, char* argv[]){
	int* array = (int*)calloc(20000, sizeof(int)*20000);
	printf("kedfkjvn\n");
	fflush(stdout);
	int i = 0;
	while(i<20000){
		int j = 0;
		while(j < 20000){
			*(array+i*20000+j) = 0;
			j++;
		}
		i++;
	}
	printf("done\n");
	partOne(array);
	return 0;
}
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
	int s;
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
	int steps = 1;
	done = false;
	while(!done){
		if(cs[ci].d == 1){
			i = 0;
			while(i < cs[ci].n){
				if(*(array + x*20000 + y + i) != 0){
					inters[ii].d = x;
					inters[ii].n = y+i;
					inters[ii].s = *(array + x*20000 + y + i) + steps;
					printf("gotone\n");
					ii++;
				}
				steps++;
				i++;
			}
			y = y + i;
		}else if(cs[ci].d == 3){
			i = 0;
			while(i < cs[ci].n){
				if(*(array + x*20000 + y - i) != 0){
					inters[ii].d = x;
					inters[ii].n = y-i;
					printf("gotone\n");
					inters[ii].s = *(array + x*20000 + y - i) + steps;
					ii++;
				}
				steps++;
				i++;
			}
			y = y - i;
		}else if(cs[ci].d == 2){
			i = 0;
			while(i < cs[ci].n){
				if(*(array + (x+i)*20000 + y) != 0){
					inters[ii].d = x+i;
					inters[ii].n = y;
					printf("gotone\n");
					inters[ii].s = *(array + (x+i)*20000 + y)  + steps;
					ii++;
				}
				steps++;
				i++;
			}
			x = x + i;
		}else if(cs[ci].d == 4){
			i = 0;
			while(i < cs[ci].n){
				if(*(array + (x-i)*20000 + y) != 0){
					printf("gotone\n");
					inters[ii].d = x-i;
					inters[ii].n = y;
					inters[ii].s = steps + *(array + (x-i)*20000 + y);
					ii++;
				}
				steps++;
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
	int minStep = 100000;
	ii = 0;
	done = false;
	while(!done){
		if(inters[ii].d == -1){
			done = true;
		}else if(minStep > inters[ii].s && !(inters[ii].d == 5000 && inters[ii].n == 5000)){
			minStep = inters[ii].s;
		}
		ii++;
	}
	printf("dddx = %d, dddy = %d\n", minStep, 0);
		
		
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
	int steps = 1;
printf(")))))))\n");
		fflush(stdout);
	while(!done){
		if(cs[ci].d == 1){
			i = 0;
			while(i < cs[ci].n){
				*(array + x*20000 + y + i) = steps;
				i++;
				steps++;
			}
			y = y + i;
		}else if(cs[ci].d == 3){
			i = 0;
			while(i < cs[ci].n){
				*(array + x*20000 + y - i) = steps;
				i++;
				steps++;
			}
			y = y - i;
		}else if(cs[ci].d == 2){
			i = 0;
			while(i < cs[ci].n){
				*(array + (x+i)*20000 + y) = steps;
				i++;
				steps++;
			}
			x = x + i;
		}else if(cs[ci].d == 4){
			i = 0;
			while(i < cs[ci].n){
				*(array + (x-i)*20000 + y) = steps;
				i++;
				steps++;
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
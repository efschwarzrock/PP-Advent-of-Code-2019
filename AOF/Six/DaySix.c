#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct orbit{
	char name[4];
	struct orbit* orbited[100];
	struct orbit* orbiting;
};

int find(int i, struct orbit o){
	bool done = false;
	struct orbit n = *o.orbiting;	
	while(!done){
		printf("%s\n", n.name);
		fflush(stdout);
		if(strcmp("COM", n.name) == 0){
			done = true;
		}else{
		n = *n.orbiting;
		}
	}

}


void add(struct orbit* o, struct orbit* a){
	if(strcmp("PQB", o->name) == 0){
			printf("pqb\n");
	}
	int i = 0;
	bool done = false;
	while (!done){
		if(o->orbited[i] == NULL){
			done = true;
			o->orbited[i] = a;
			o->orbited[i + 1] = NULL;
		}
		i++;
	}
}

int calc(int i, struct orbit o){
	int j = 0;
	int sum = 0;
	while(j < 10){
		if(o.orbited[j] == NULL){
			j = 150;
		}else{
			//printf("%d\n",i);
			sum = sum + i + 1;
			sum = sum + calc(i + 1, *o.orbited[j]);	
		}
		j++;
	}
	return sum;
	 
}

void partOne(){
	FILE* fp = fopen("input.txt", "r");
	struct orbit os[2000];
	int i = 0;
	while(i<2000){
		strcpy(os[i].name, "");
		os[i].orbited[0] = NULL;
		i++;
	}
	if(fp == false){
		printf("bad file");
	}
	bool done = false;
	char str[256];
	int numorbits = 0;
	int total = 0;
	while(!done){
		str[0] = '\0';
		fscanf(fp, "%s", str);
		if(strlen(str) > 0){
			int fi = -1;
			char f[4];
			f[0] = str[0];
			f[1] = str[1];
			f[2] = str[2];
			f[3] = '\0';
			char s[4];
			int si = -1;
			s[0] = str[4];
			s[1] = str[5];
			s[2] = str[6];
			s[3] = '\0';
			i = 0;
			while(i<numorbits){
				if(strcmp(s, os[i].name)  == 0){
					si = i;
				}
				if(strcmp(f, os[i].name)  == 0){
					fi = i;
				}
				i++;
			}
			if(fi < 0 && si < 0){
				strcpy(os[numorbits].name, s);
				strcpy(os[numorbits + 1].name, f);
				os[numorbits + 1].orbited[0] = &os[numorbits];
				os[numorbits + 1].orbited[1] = NULL;
				numorbits = numorbits + 2;
			}else if(si < 0){
			
				strcpy(os[numorbits].name, s);
				add(&os[fi], &os[numorbits]);
				numorbits++;
			}else if(fi < 0){
				strcpy(os[numorbits].name, f);
				os[numorbits].orbited[0] = &os[si];
				os[numorbits].orbited[1] = NULL;
				numorbits++;
			}else{
				
				add(&os[fi], &os[si]);
			}
		}else{
			done = true;
			fclose(fp);
		}
	}
	printf("here %d\n", numorbits);
	i = 0;
	int comi = 0;
	while(i< 2000){
		if(strcmp("COM", os[i].name) == 0){
			printf("djfrhvberhb\n");
			comi = i;
			i = 3000;
		}
		i++;
	}
	total = calc(0, os[comi]);
	printf("total = %d\n\n", total);

}

void partTwo(){
	FILE* fp = fopen("input.txt", "r");
	struct orbit os[2000];
	int i = 0;
	while(i<2000){
		strcpy(os[i].name, "");
		os[i].orbited[0] = NULL;
		i++;
	}
	if(fp == false){
		printf("bad file");
	}
	bool done = false;
	char str[256];
	int numorbits = 0;
	int total = 0;
	while(!done){
		str[0] = '\0';
		fscanf(fp, "%s", str);
		if(strlen(str) > 0){
			int fi = -1;
			char f[4];
			f[0] = str[0];
			f[1] = str[1];
			f[2] = str[2];
			f[3] = '\0';
			char s[4];
			int si = -1;
			s[0] = str[4];
			s[1] = str[5];
			s[2] = str[6];
			s[3] = '\0';
			i = 0;
			while(i<numorbits){
				if(strcmp(s, os[i].name)  == 0){
					si = i;
				}
				if(strcmp(f, os[i].name)  == 0){
					fi = i;
				}
				i++;
			}
			if(fi < 0 && si < 0){
				strcpy(os[numorbits].name, s);
				strcpy(os[numorbits + 1].name, f);
				os[numorbits + 1].orbited[0] = &os[numorbits];
				os[numorbits + 1].orbited[1] = NULL;
				os[numorbits].orbiting = &os[numorbits + 1];
				numorbits = numorbits + 2;
			}else if(si < 0){
			
				strcpy(os[numorbits].name, s);
				add(&os[fi], &os[numorbits]);
				os[numorbits].orbiting = &os[fi];
				numorbits++;
			}else if(fi < 0){
				strcpy(os[numorbits].name, f);
				os[numorbits].orbited[0] = &os[si];
				os[numorbits].orbited[1] = NULL;
				os[si].orbiting = &os[numorbits];
				numorbits++;
			}else{
				os[si].orbiting = &os[fi];
				add(&os[fi], &os[si]);
			}
		}else{
			done = true;
			fclose(fp);
		}
	}
	printf("here %d\n", numorbits);
	i = 0;
	int comi = 0;
	while(i< 2000){
		if(strcmp("SAN", os[i].name) == 0){
			comi = i;
			i = 3000;
		}
		i++;
	}
	total = find(1000, os[comi]);
	printf("total = %d\n\n", total);

}


int main(int argc, char* argv[]){
	partOne();
	partTwo();
	return 0;
}
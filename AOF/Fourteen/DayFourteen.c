#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

struct chemical{
	char name[10];
	long long amount;
	long long amountNeeded;
};

struct reaction{
	struct chemical product;
	int productnum;
	struct chemical inputs[10];
	int nums[10];
};

void printChems(struct chemical chems[]){
	int i = 0;
	while(i>-1){
		if(chems[i].name[0] == '\0'){
			i = -10;
		}else{
			printf("%s, %lld, %lld\n", chems[i].name, chems[i].amount, chems[i].amountNeeded);
		}
		i++;
	}
}

bool isIn(char name[], char list[][10], int n){
	int i = 0;
	bool notIn = true;
	while(i < n){
		if(strcmp(name, list[i]) == 0){
			notIn = false;
			i = n;
		}
		i++;
	}
	return !notIn;
}

int checkEven(struct chemical chems[]){
	int i = 0;
	while(i>-1){
		if(chems[i].amount != chems[i].amountNeeded){
			return false;
		}
		i++;
	}
	return true;
}

void printReactions(struct reaction rs[]){
	int i = 0;
	while(i>-1){
		int j = 0;
		if(rs[i].productnum == 0){
			j = -10;
			i = -10;
		}else{
			printf("%d %s\n", rs[i].productnum, rs[i].product.name);
		}
		while(j>-1){
			if(rs[i].inputs[j].name[0] == '\0'){
				j = -10;
			}else{
				printf("\t%d %s\n", rs[i].nums[j], rs[i].inputs[j].name);
			}
			j++;
		}
			
		printf("\n");
		i++;
	}
}

int getChemI(struct chemical chems[], char name[]){
	int i = 0;
	bool done = false;
	while(!done){
		if(chems[i].name[0] == '\0'){
			done = true;
		}else if(strcmp(name, chems[i].name) == 0){
			done = true;
		}else{
			i++;
		}
	}
	return i;
}

int getRecI(struct reaction r[], char name[]){
	int i = 0;
	bool done = false;
	while(!done){
		if(r[i].product.name[0] == '\0'){
			done = true;
		}else if(strcmp(name, r[i].product.name) == 0){
			done = true;
		}else{
			i++;
		}
	}
	return i;
}

void partOne(){
	struct reaction r[100];
	struct chemical chems[100];
	int aabc = 0;
	while(aabc<100){
		int w = 0;
		chems[aabc].name[0] = '\0';
		r[aabc].productnum = 0;
		while(w<10){
			r[aabc].inputs[w].name[0] = '\0';
			w++;
		}
		aabc++;
	}
	FILE* fp = fopen("input.txt", "r");
	if(fp == false){
		printf("bad file");
		return ;
	}
	bool done = false;
	char str[256];
	int reci = 0;
	while(!done){
		str[0] = '\0';
		fgets(str, 100, fp);
		if(strlen(str) > 0){
			//printf("%s\n", str);
			int inputi = 0;
			int z = 0;
			char num[5];
			int numi = 0;
			char name[5];
			int namei = 0;
			int pos = 0;
			while(z < 200){
				if(str[z] == '>'){
					//printf("jhfbvjhrb\n");
					pos = 3;
					z++;
					numi = 0;
				}else if(pos == 0){
					if(isdigit(str[z])){
						num[numi] = str[z];
						numi++;
					}else{
						num[numi] = '\0';
						numi = 0;
						pos = 1;
					}
				}else if(pos == 1){
					if(isalpha(str[z])){
						name[namei] = str[z];
						namei++;
					}else{
						
						name[namei] = '\0';
						namei = 0;
						pos = 0;
						z++;
						int ci = getChemI(chems, name);
						strcpy(chems[ci].name, name);						
						chems[ci].amount = 0;
						chems[ci].amountNeeded = 0;
						r[reci].inputs[inputi] = chems[ci];
						r[reci].nums[inputi] = atoi(num);
						inputi++;
					}
				}else if(pos == 3){
					if(isdigit(str[z])){
						num[numi] = str[z];
						numi++;
					}else{
						num[numi] = '\0';
						numi = 0;
						pos = 4;
					}
				}else if(pos == 4){
					//printf("sssssssssssssss\n");
					if(isalpha(str[z])){
						name[namei] = str[z];
						namei++;
					}else{
						name[namei] = '\0';
						namei = 0;
						pos = 0;
						z = 2000;
						int ci = getChemI(chems, name);
						strcpy(chems[ci].name, name);
						chems[ci].amount = 0;
						chems[ci].amountNeeded = 0;
						
						r[reci].product = chems[ci];
						r[reci].productnum = atoi(num);
						inputi = 0;
						reci++;
						printf("%s\n", r[reci].product.name);
					}
					//printf("kkkkkkkkkkk\n");
				}
				z++;
			}
		}else{
			done = true;
			fclose(fp);
		}
	}
	printChems(chems);
	printReactions(r);


	done = false;
	struct chemical empty;
	empty.name[0] = '\0';
	char list[10000][10];
	aabc = 0;
	while(aabc < 100){
		list[aabc][0] = '\0';
		aabc++;
	}
	int liststart = 0;
	int listend = 1;
	int chemI = getChemI(chems, "FUEL");
	chems[chemI].amountNeeded = 1;
	strcpy(list[0], chems[chemI].name);
	while(!done){
	//printChems(chems);
		printf("top %d  %d\n", liststart, listend);
		//fflush(stdout);
		if(strcmp("ORE",list[liststart]) == 0){
			liststart++;
		}else if(liststart < listend){
		struct reaction re = r[getRecI(r, list[liststart])];
		long long numReaction = 0;
		long long numProduct = 0;
		long long needed = chems[getChemI(chems, list[liststart])].amountNeeded - chems[getChemI(chems, list[liststart])].amount;
		//printf("\ttop %s  %d %d\n", list[liststart].name, list[liststart].amountNeeded,  list[liststart].amount);
		//printf("\ttop %s  %lld\n", list[liststart], chems[getChemI(chems, list[liststart])].amountNeeded);
		long long produced = re.productnum;
		while(needed>numProduct){
			//printf("jjjjj %s %d %d\n", list[liststart], needed, produced);
			numProduct += produced;
			numReaction++;
		}
		chems[getChemI(chems, list[liststart])].amount += numProduct;
		//printf("\t\thhhhhh %d  \n", chems[getChemI(chems, list[liststart].name)].amount);
		int inputsI = 0;
		while(inputsI > -1){
			if(re.inputs[inputsI].name[0] == '\0'){
				//printf("here done\n");
				inputsI = -10;
			}else{
				//printf("here %d\n", numReaction);
				chems[getChemI(chems, re.inputs[inputsI].name)].amountNeeded += re.nums[inputsI]*numReaction;
				strcpy(list[listend], chems[getChemI(chems, re.inputs[inputsI].name)].name);
				//printf("\t\t\t %d  \n", list[listend].amountNeeded);
				//printf("\t\t\t %d  \n", chems[getChemI(chems, re.inputs[inputsI].name)].amountNeeded);
				listend++;
			}
			inputsI++;
		}
		//printf("\t\thhhhhh %d  \n", chems[getChemI(chems, list[liststart].name)].amount);
		//list[liststart] = empty;
		liststart++;
		}else if(liststart >= listend){
			//printf("here hhhhhh\n");
			done = true;
		}
		//printf("\t\thhhhhh %d  \n", chems[getChemI(chems, list[liststart -1].name)].amount);
	}
	printf("here final\n");
	fflush(stdout);
	printf("answer = %lld\n", 	chems[getChemI(chems, "ORE")].amountNeeded);




}


void partTwo(){
	struct reaction r[100];
	struct chemical chems[100];
	int aabc = 0;
	while(aabc<100){
		int w = 0;
		chems[aabc].name[0] = '\0';
		r[aabc].productnum = 0;
		while(w<10){
			r[aabc].inputs[w].name[0] = '\0';
			w++;
		}
		aabc++;
	}
	FILE* fp = fopen("input.txt", "r");
	if(fp == false){
		printf("bad file");
		return ;
	}
	bool done = false;
	char str[256];
	int reci = 0;
	while(!done){
		str[0] = '\0';
		fgets(str, 100, fp);
		if(strlen(str) > 0){
			//printf("%s\n", str);
			int inputi = 0;
			int z = 0;
			char num[5];
			int numi = 0;
			char name[5];
			int namei = 0;
			int pos = 0;
			while(z < 200){
				if(str[z] == '>'){
					//printf("jhfbvjhrb\n");
					pos = 3;
					z++;
					numi = 0;
				}else if(pos == 0){
					if(isdigit(str[z])){
						num[numi] = str[z];
						numi++;
					}else{
						num[numi] = '\0';
						numi = 0;
						pos = 1;
					}
				}else if(pos == 1){
					if(isalpha(str[z])){
						name[namei] = str[z];
						namei++;
					}else{
						
						name[namei] = '\0';
						namei = 0;
						pos = 0;
						z++;
						int ci = getChemI(chems, name);
						strcpy(chems[ci].name, name);						
						chems[ci].amount = 0;
						chems[ci].amountNeeded = 0;
						r[reci].inputs[inputi] = chems[ci];
						r[reci].nums[inputi] = atoi(num);
						inputi++;
					}
				}else if(pos == 3){
					if(isdigit(str[z])){
						num[numi] = str[z];
						numi++;
					}else{
						num[numi] = '\0';
						numi = 0;
						pos = 4;
					}
				}else if(pos == 4){
					//printf("sssssssssssssss\n");
					if(isalpha(str[z])){
						name[namei] = str[z];
						namei++;
					}else{
						name[namei] = '\0';
						namei = 0;
						pos = 0;
						z = 2000;
						int ci = getChemI(chems, name);
						strcpy(chems[ci].name, name);
						chems[ci].amount = 0;
						chems[ci].amountNeeded = 0;
						
						r[reci].product = chems[ci];
						r[reci].productnum = atoi(num);
						inputi = 0;
						reci++;
						printf("%s\n", r[reci].product.name);
					}
					//printf("kkkkkkkkkkk\n");
				}
				z++;
			}
		}else{
			done = true;
			fclose(fp);
		}
	}
	//printChems(chems);
	//printReactions(r);

	done = false;
	struct chemical empty;
	empty.name[0] = '\0';
	char list[10000][10];
	aabc = 0;
	while(aabc < 10000){
		list[aabc][0] = '\0';
		aabc++;
	}
	int liststart = 0;
	int listend = 1;
	int chemI = getChemI(chems, "FUEL");
	strcpy(list[0], chems[chemI].name);
	while(!done){
		if(strcmp("ORE",list[liststart]) == 0){
			liststart++;
		}else if(liststart < listend){
		struct reaction re = r[getRecI(r, list[liststart])];
		int inputsI = 0;
		while(inputsI > -1){
			if(re.inputs[inputsI].name[0] == '\0'){
				inputsI = -10;
			}else{
				strcpy(list[listend], chems[getChemI(chems, re.inputs[inputsI].name)].name);
				listend++;
			}
			inputsI++;
		}
		liststart++;
		}else if(liststart >= listend){
			//printf("here hhhhhh\n");
			done = true;
		}
	}
	
	int numreac = 61;
	char order[numreac][10];
	aabc = 0;
	while(aabc < numreac){
		order[aabc][0] = '\0';
		aabc++;
	}
	aabc = numreac - 1;
	listend--;
	while(listend >= 0 && aabc >= 0){
		
		if(!isIn(list[listend], order, numreac)){
			strcpy(order[aabc], list[listend]);
			aabc--;
		}
		listend--;
	}
	printf("here jjjjjjjjjjj\n");
	fflush(stdout);
	int hello = 0;
	while(hello < numreac){
		printf("%s %d\n", order[hello], hello);
		hello++;
	}
	bool oreEmpty = false;
	while(!oreEmpty){
		



		
		bool done = false;
		int oi = 0;
		int chemI = getChemI(chems, "FUEL");
		chems[chemI].amountNeeded++;
		while(!done){
			if(strcmp("ORE",order[oi]) == 0){
				done = true;
			}else{
				struct reaction re = r[getRecI(r, order[oi])];
				long long numReaction = 0;
				long long numProduct = 0;
				long long needed = chems[getChemI(chems, order[oi])].amountNeeded - chems[getChemI(chems, order[oi])].amount;
				long long produced = re.productnum;
				while(needed>numProduct){
					numProduct += produced;
					numReaction++;
				}
				chems[getChemI(chems, order[oi])].amount += numProduct;
				int inputsI = 0;
				while(inputsI > -1){
					if(re.inputs[inputsI].name[0] == '\0'){
						inputsI = -10;
					}else{
						
						chems[getChemI(chems, re.inputs[inputsI].name)].amountNeeded += re.nums[inputsI]*numReaction;
					}
					inputsI++;
				}
				oi++;
			}
		}
		printf("done %lld\n", chems[getChemI(chems, "ORE")].amountNeeded);
		//if(chems[getChemI(chems, "ORE")].amountNeeded > 900000){
		if(chems[getChemI(chems, "ORE")].amountNeeded > 1000000000000){
			oreEmpty = true;
		}	








	}




	printf("fule = %lld\n",chems[getChemI(chems, "FUEL")].amount);




}
int main(int argc, char* argv[]){
	//partOne();
	partTwo();
	return 0;
}
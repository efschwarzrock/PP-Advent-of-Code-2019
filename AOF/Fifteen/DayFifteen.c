#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct memory{
	long long adress;
	long long value;
};

#define natMem 1045

long long i[] = {3,1033,1008,1033,1,1032,1005,1032,31,1008,1033,2,1032,1005,1032,58,1008,1033,3,1032,1005,1032,81,1008,1033,4,1032,1005,1032,104,99,1001,1034,0,1039,1002,1036,1,1041,1001,1035,-1,1040,1008,1038,0,1043,102,-1,1043,1032,1,1037,1032,1042,1106,0,124,1001,1034,0,1039,102,1,1036,1041,1001,1035,1,1040,1008,1038,0,1043,1,1037,1038,1042,1105,1,124,1001,1034,-1,1039,1008,1036,0,1041,102,1,1035,1040,1002,1038,1,1043,101,0,1037,1042,1105,1,124,1001,1034,1,1039,1008,1036,0,1041,102,1,1035,1040,1001,1038,0,1043,101,0,1037,1042,1006,1039,217,1006,1040,217,1008,1039,40,1032,1005,1032,217,1008,1040,40,1032,1005,1032,217,1008,1039,33,1032,1006,1032,165,1008,1040,33,1032,1006,1032,165,1101,0,2,1044,1106,0,224,2,1041,1043,1032,1006,1032,179,1102,1,1,1044,1105,1,224,1,1041,1043,1032,1006,1032,217,1,1042,1043,1032,1001,1032,-1,1032,1002,1032,39,1032,1,1032,1039,1032,101,-1,1032,1032,101,252,1032,211,1007,0,42,1044,1106,0,224,1102,0,1,1044,1106,0,224,1006,1044,247,1001,1039,0,1034,1001,1040,0,1035,1001,1041,0,1036,1001,1043,0,1038,102,1,1042,1037,4,1044,1106,0,0,6,28,51,33,63,27,52,11,53,13,96,8,87,11,23,65,43,11,13,9,37,66,68,40,19,41,6,90,28,19,38,86,38,22,7,44,36,23,17,1,16,54,36,74,14,79,2,14,83,10,38,19,62,66,27,56,33,52,47,98,41,39,77,83,48,29,49,15,80,59,9,72,79,55,24,66,50,24,27,56,37,41,13,72,35,13,64,70,5,66,78,37,78,24,43,93,22,41,30,58,14,45,6,27,44,48,40,52,31,12,3,72,7,14,59,35,17,63,34,79,93,17,54,98,35,21,91,25,32,77,10,31,88,17,35,79,96,11,83,15,48,9,19,64,24,65,86,32,71,22,88,55,31,18,88,68,34,40,94,1,71,24,40,44,28,43,4,98,21,80,17,53,2,94,6,43,59,23,66,63,12,30,45,39,93,41,85,43,51,18,99,59,86,40,36,26,94,33,41,28,66,79,81,11,61,46,32,72,71,47,39,22,69,60,36,50,12,44,28,41,79,17,6,74,8,56,39,33,67,23,20,51,12,7,26,57,1,92,80,11,52,19,5,54,13,41,56,37,22,57,43,18,97,27,83,30,3,77,85,66,64,17,99,27,25,95,40,81,97,13,35,46,14,25,63,36,72,87,20,96,29,2,69,90,27,27,91,52,14,14,73,55,4,73,19,85,39,84,23,23,90,40,5,88,53,77,8,92,11,82,66,6,27,84,53,38,93,34,37,58,20,43,25,73,78,30,17,92,54,38,26,67,16,30,28,79,77,26,3,15,82,59,34,34,18,44,34,33,83,35,90,31,58,44,16,18,65,8,70,90,32,46,21,41,54,39,43,93,23,99,11,43,50,98,33,34,53,54,53,16,39,88,53,36,69,85,26,44,38,62,98,6,79,26,35,49,67,22,11,74,35,80,4,50,18,54,4,10,4,58,4,46,20,15,77,73,11,41,58,85,39,87,37,73,36,36,67,28,12,17,34,53,38,89,96,34,39,67,64,33,81,37,74,88,20,84,94,53,39,57,73,13,76,1,35,14,73,29,29,23,73,52,16,85,87,33,48,13,2,93,78,7,17,60,49,13,36,89,40,25,44,55,26,81,37,31,84,31,62,2,66,77,23,88,11,81,9,63,46,19,35,54,17,85,24,1,86,28,72,1,1,61,27,38,81,8,67,82,3,11,77,35,62,83,20,28,61,37,37,92,22,72,76,37,52,17,62,68,38,53,2,57,82,67,25,11,59,3,49,97,1,40,91,75,7,85,98,33,90,1,37,57,14,34,67,65,20,85,10,18,86,20,52,84,24,20,70,10,64,16,64,2,15,85,36,28,7,87,47,44,9,29,54,83,28,37,81,68,18,12,80,26,98,97,25,86,69,39,70,22,23,72,15,56,94,27,14,13,8,50,73,90,24,95,14,41,57,22,67,25,80,46,39,84,80,19,22,63,53,45,62,21,84,36,69,41,44,96,38,92,21,23,64,35,11,75,57,88,6,7,90,10,36,19,68,78,23,62,34,49,4,80,38,2,70,48,39,55,20,22,39,8,90,64,38,39,47,41,63,72,5,10,72,88,35,50,5,66,30,80,74,23,97,39,98,19,17,85,38,34,62,37,25,58,15,93,37,13,71,72,72,4,84,40,92,61,88,9,7,62,59,87,17,36,39,43,21,11,16,58,16,58,20,66,18,83,33,66,62,90,32,74,15,58,62,43,16,66,22,90,2,68,30,54,18,59,22,50,12,60,35,66,77,51,36,64,89,82,21,85,0,0,21,21,1,10,1,0,0,0,0,0,0};
int ramused = 0;
struct memory ram[1000];

void printMap(int n, char map[n][n + 1]){
	int i = 0;
	printf("==========\n");
	while(i<n){
		printf("\"%s\"\n", map[i]);
		i++;
	}
	printf("==========\n");
}

long long getMemory(long long index){
	int j = 0;
	if(index < natMem && index >= 0){
		return i[index];
	}else{
		while(j<ramused){
			if(ram[j].adress == index){
				return ram[j].value;
			}
			j++;
		}
	}
	ram[j].adress = index;
	ram[j].value = 0;
	ramused++;
	return 0;
}

void setMemory(long long index, long long val){
	int j = 0;
	if(index < natMem && index >= 0){
		i[index] = val;
		return;
	}else{
		while(j<ramused){
			if(ram[j].adress == index){
				ram[j].value = val;
				return;
			}
			j++;
		}
	}
	ram[j].adress = index;
	ram[j].value = val;
	ramused++;
}

int howLongToFill(int n, char map[n][n+1]){
	printf("\n\n\nhow lone\n");
	printMap(n, map);
	int time = 0;
	bool done = false;
	while(!done){
		bool stillEmpty = false;
		int i = 0;
		while(i<n){
			int j = 0;
			while(j<n){
				if(map[i][j] == 'O'){
					if(map[i + 1][j] == '.' || map[i + 1][j] == 'D'){
						stillEmpty = true;
						map[i + 1][j] = 'o';
					}
					if(map[i - 1][j] == '.' || map[i - 1][j] == 'D'){
						stillEmpty = true;
						map[i - 1][j] = 'o';
					}
					if(map[i][j + 1] == '.' || map[i][j + 1] == 'D'){
						stillEmpty = true;
						map[i][j + 1] = 'o';
					}
					if(map[i][j - 1] == '.' || map[i][j - 1] == 'D'){
						stillEmpty = true;
						map[i][j - 1] = 'o';
					}
				}
				j++;
			}
			i++;
		}
		i = 0;
		while(i<n){
			int j = 0;
			while(j<n){
				if(map[i][j] == 'o'){
					stillEmpty = true;
					map[i][j] = 'O';
				}
				j++;
			}
			i++;
		}
		time++;
		done = !stillEmpty;
		if(time<10){
			printMap(n, map);
		}
		
	}
	return time;

}

void partOne(){	
	int xp = 100;
	int yp = 50;
	int moves = 0;
	int movement = 2;
	int lastmovement = 1;
	bool stuck = false;
	char map[200][201];
	int aabc = 0;
	while(aabc < 200){
		int aabbc = 0;
		while(aabbc < 200){
			map[aabc][aabbc] = ' ';
			aabbc++;
		}
		map[aabc][aabbc] = '\0';
		printf("\"%s\"\n", map[aabc]);
		aabc++;
	}

	printMap(200, map);
	long long x = 0;
	long long com = 0;
	long long valA = 0;
	long long valB = 0;
	long long desC = 0;
	long long relativeBase = 0;
	long long done = -1;
	long long input = 1;
	long long output = 1;
	while(x < 974 && done == -1){
		
		//printf("here\n");
		com = getMemory(x);
		int comand = com%100;
		//printf("comand = %d\n", comand);
		//printf("x = %lld\n", x);
		com = com/100;
		int pa = com%10;
		int pb = com/10%10;
		int pc = com/100%10;
		if(comand < 3){
			if(pa == 0){
				valA = getMemory(getMemory(x+1));
			}else if(pa == 1){
				valA = getMemory(x+1);
			}else{
				valA = getMemory(relativeBase + getMemory(x+1));
			}
			if(pb == 0){
				valB = getMemory(getMemory(x+2));
			}else if(pb == 1){
				valB = getMemory(x+2);
			}else{
				valB = getMemory(relativeBase + getMemory(x+2));
			}
			if(pc == 0){
				desC = getMemory(x+3);
			}else{
				desC = relativeBase + getMemory(x+3);
			}
			
			if(comand == 1){
				setMemory(desC, valA + valB);
				
				//printf("add %d + %d\n", valA, valB);
			}else if( comand == 2){
				setMemory(desC, valA * valB);
			}
			x = x + 4;
		}else if(comand < 5){
			//printf("here\n");
			if(pa == 0){
				desC = getMemory(x+1);	
			}else{
				desC = relativeBase + getMemory(x+1);
			}
			if(comand == 3){
				if(lastmovement == 9){
				char userinputstr[5];
  				bool badinput = true;
				while(badinput){
				if(fgets(userinputstr, 5, stdin) == NULL || strcmp(userinputstr, "\n") == 0){
     					 badinput = true;
  				}else{
					badinput = false;
    					if(strcmp(userinputstr, "w\n") == 0){
						printf("here");
						input = 1;
					}else if( strcmp(userinputstr, "d\n") == 0){
						input = 4;
					}else if( strcmp(userinputstr, "s\n") == 0){
						input = 2;
					}else if( strcmp(userinputstr, "a\n") == 0){
						input = 3;
					}else if( strcmp(userinputstr, "c\n") == 0){
						
						input = 3;
					}
  				}
				}
				}else{

				if(output != 0){
					if(input == 1){
						input = 3;
						lastmovement = 3;	
					}else if(input == 2){
						input = 4;
						lastmovement = 3;	
					}else if(input == 3){
						input = 2;
						lastmovement = 3;       //Subtract 2	
					}else{
						input = 1;
						lastmovement = 3;
					}
				}else{
					if(lastmovement == 3){
						if(input == 1){
							input = 4;
							lastmovement = 4;	
						}else if(input == 2){
							input = 3;
							lastmovement = 4;	
						}else if(input == 3){
							input = 1;
							lastmovement = 4;	
						}else{
							input = 2;
							lastmovement = 4;
						}
					}else if(lastmovement == 4){
						if(input == 1){
							input = 4;
							lastmovement = 4;	
						}else if(input == 2){
							input = 3;
							lastmovement = 4;	
						}else if(input == 3){
							input = 1;
							lastmovement = 4;	
						}else{
							input = 2;
							lastmovement = 4;
						}
					}else{
					if(input == 1){
						input = 3;
						lastmovement = 3;	
					}else if(input == 2){
						input = 4;
						lastmovement = 3;	
					}else if(input == 3){
						input = 2;
						lastmovement = 3;	
					}else{
						input = 1;
						lastmovement = 3;
					}}
								
				}
				}
				setMemory(desC, input);	
			}else{
				output = getMemory(desC);
				printf("\n%lld\n", desC);
				if(output == 2){
					if(input == 1){
						xp--;
					}else if(input == 2){
						xp++;
					}else if(input == 4){
						yp++;
					}else if(input == 3){
						yp--;
					}
					lastmovement = 9;
					moves = 0;
					map[100][50] = 'X';
					map[xp][yp] = 'o';
				}else if(output == 1){
					moves++;
					printf("here 1\n");
					map[xp][yp] = '.';
					if(input == 1){
						xp--;
					}else if(input == 2){
						xp++;
					}else if(input == 3){
						yp--;
					}else if(input == 4){
						yp++;
					}
					map[xp][yp] = 'D';
				}else{
					printf("here 2\n");
					if(input == 1){
						map[xp - 1][yp] = '#';
					}else if(input == 2){
						map[xp + 1][yp] = '#';
					}else if(input == 4){
						map[xp][yp + 1] = '#';
					}else if(input == 3){
						map[xp][yp - 1] = '#';
					}
					map[xp][yp] = 'D';
				}
				printMap(200, map);
				printf("moves = %d\n", moves);
				if(xp > 49 || yp > 49){
					done = 2;
				}
			}
			x = x + 2;
		}else if(comand < 7){
			if(pa == 0){
				valA = getMemory(getMemory(x+1));
			}else if(pa == 1){
				valA = getMemory(x+1);
			}else{
				valA = getMemory(relativeBase + getMemory(x+1));
			}
			if(pb == 0){
				valB = getMemory(getMemory(x+2));
			}else if(pb == 1){
				valB = getMemory(x+2);
			}else{
				valB = getMemory(relativeBase + getMemory(x+2));
			}
			if(comand == 5){
				if(valA == 0){
					x = x + 3;
				}else{
					x = valB;
				}
			}else{
				if(valA != 0){
					x = x + 3;
				}else{
					x = valB;
				}
			}
		}else if(comand < 9){
			if(pc == 0){
				desC = getMemory(x+3);
			}else{
				desC = relativeBase + getMemory(x+3);
			}
			if(pa == 0){
				valA = getMemory(getMemory(x+1));
			}else if(pa == 1){
				valA = getMemory(x+1);
			}else{
				valA = getMemory(relativeBase + getMemory(x+1));
			}
			if(pb == 0){
				valB = getMemory(getMemory(x+2));
			}else if(pb == 1){
				valB = getMemory(x+2);
			}else{
				valB = getMemory(relativeBase + getMemory(x+2));
			}
			if(comand == 7){
				if(valA < valB){
					setMemory(desC, 1);
				}else{
					setMemory(desC, 0);
				}
			}else{
				if(valA == valB){
					setMemory(desC, 1);
				}else{
					setMemory(desC, 0);
				}
			}
			x = x + 4;
		}else if(comand == 9){
			if(pa == 0){
				valA = getMemory(getMemory(x+1));
			}else if(pa == 1){
				valA = getMemory(x+1);
			}else{
				valA = getMemory(relativeBase +getMemory(x+1));
			}
			relativeBase += valA;
			x += 2;
		}else if(comand == 99){
			printf("halt\n");
			done = 0;
		}else{
			printf("error");
			done = 1;
		}
	}
	printf("%lld done\n", done);

}


void partTwo(){	
	int xp = 25;
	int yp = 25;
	int ox = 0;
	int oy = 0;
	int moves = 0;
	int movement = 2;
	int lastmovement = 1;
	bool stuck = false;
	char map[50][51];
	int aabc = 0;
	while(aabc < 50){
		int aabbc = 0;
		while(aabbc < 50){
			map[aabc][aabbc] = ' ';
			aabbc++;
		}
		map[aabc][aabbc] = '\0';
		printf("\"%s\"\n", map[aabc]);
		aabc++;
	}

	printMap(50, map);
	long long x = 0;
	long long com = 0;
	long long valA = 0;
	long long valB = 0;
	long long desC = 0;
	long long relativeBase = 0;
	long long done = -1;
	long long input = 1;
	long long output = 1;
	while(x < 974 && done == -1){
		if(moves > 100000){
			done = 4;
		}
		//printf("here\n");
		com = getMemory(x);
		int comand = com%100;
		//printf("comand = %d\n", comand);
		//printf("x = %lld\n", x);
		com = com/100;
		int pa = com%10;
		int pb = com/10%10;
		int pc = com/100%10;
		if(comand < 3){
			if(pa == 0){
				valA = getMemory(getMemory(x+1));
			}else if(pa == 1){
				valA = getMemory(x+1);
			}else{
				valA = getMemory(relativeBase + getMemory(x+1));
			}
			if(pb == 0){
				valB = getMemory(getMemory(x+2));
			}else if(pb == 1){
				valB = getMemory(x+2);
			}else{
				valB = getMemory(relativeBase + getMemory(x+2));
			}
			if(pc == 0){
				desC = getMemory(x+3);
			}else{
				desC = relativeBase + getMemory(x+3);
			}
			
			if(comand == 1){
				setMemory(desC, valA + valB);
				
				//printf("add %d + %d\n", valA, valB);
			}else if( comand == 2){
				setMemory(desC, valA * valB);
			}
			x = x + 4;
		}else if(comand < 5){
			//printf("here\n");
			if(pa == 0){
				desC = getMemory(x+1);	
			}else{
				desC = relativeBase + getMemory(x+1);
			}
			if(comand == 3){
				if(lastmovement == 9){
				char userinputstr[5];
  				bool badinput = true;
				while(badinput){
				if(fgets(userinputstr, 5, stdin) == NULL || strcmp(userinputstr, "\n") == 0){
     					 badinput = true;
  				}else{
					badinput = false;
    					if(strcmp(userinputstr, "w\n") == 0){
						printf("here");
						input = 1;
					}else if( strcmp(userinputstr, "d\n") == 0){
						input = 4;
					}else if( strcmp(userinputstr, "s\n") == 0){
						input = 2;
					}else if( strcmp(userinputstr, "a\n") == 0){
						input = 3;
					}else if( strcmp(userinputstr, "c\n") == 0){
						
						input = 3;
					}
  				}
				}
				}else{

				if(output != 0){
					if(input == 1){
						input = 3;
						lastmovement = 3;	
					}else if(input == 2){
						input = 4;
						lastmovement = 3;	
					}else if(input == 3){
						input = 2;
						lastmovement = 3;      	
					}else{
						input = 1;
						lastmovement = 3;
					}
				}else{
					if(lastmovement == 3){
						if(input == 1){
							input = 4;
							lastmovement = 4;	
						}else if(input == 2){
							input = 3;
							lastmovement = 4;	
						}else if(input == 3){
							input = 1;
							lastmovement = 4;	
						}else{
							input = 2;
							lastmovement = 4;
						}
					}else if(lastmovement == 4){
						if(input == 1){
							input = 4;
							lastmovement = 4;	
						}else if(input == 2){
							input = 3;
							lastmovement = 4;	
						}else if(input == 3){
							input = 1;
							lastmovement = 4;	
						}else{
							input = 2;
							lastmovement = 4;
						}
					}else{
					if(input == 1){
						input = 3;
						lastmovement = 3;	
					}else if(input == 2){
						input = 4;
						lastmovement = 3;	
					}else if(input == 3){
						input = 2;
						lastmovement = 3;	
					}else{
						input = 1;
						lastmovement = 3;
					}}
								
				}
				}
				setMemory(desC, input);	
			}else{
				output = getMemory(desC);
				//printf("\n%lld\n", desC);
				if(output == 2){
					if(input == 1){
						xp--;
					}else if(input == 2){
						xp++;
					}else if(input == 4){
						yp++;
					}else if(input == 3){
						yp--;
					}
					
					map[xp][yp] = 'o';
					ox = xp;
					oy = yp;
				}else if(output == 1){
					moves++;
					//printf("here 1\n");
					map[xp][yp] = '.';
					if(input == 1){
						xp--;
					}else if(input == 2){
						xp++;
					}else if(input == 3){
						yp--;
					}else if(input == 4){
						yp++;
					}
					map[xp][yp] = 'D';
				}else{
					//printf("here 2\n");
					if(input == 1){
						map[xp - 1][yp] = '#';
					}else if(input == 2){
						map[xp + 1][yp] = '#';
					}else if(input == 4){
						map[xp][yp + 1] = '#';
					}else if(input == 3){
						map[xp][yp - 1] = '#';
					}
					map[xp][yp] = 'D';
				}
				//printf("moves = %d\n", moves);
				if(xp > 199 || yp > 199){
					done = 2;
				}
			}
			x = x + 2;
		}else if(comand < 7){
			if(pa == 0){
				valA = getMemory(getMemory(x+1));
			}else if(pa == 1){
				valA = getMemory(x+1);
			}else{
				valA = getMemory(relativeBase + getMemory(x+1));
			}
			if(pb == 0){
				valB = getMemory(getMemory(x+2));
			}else if(pb == 1){
				valB = getMemory(x+2);
			}else{
				valB = getMemory(relativeBase + getMemory(x+2));
			}
			if(comand == 5){
				if(valA == 0){
					x = x + 3;
				}else{
					x = valB;
				}
			}else{
				if(valA != 0){
					x = x + 3;
				}else{
					x = valB;
				}
			}
		}else if(comand < 9){
			if(pc == 0){
				desC = getMemory(x+3);
			}else{
				desC = relativeBase + getMemory(x+3);
			}
			if(pa == 0){
				valA = getMemory(getMemory(x+1));
			}else if(pa == 1){
				valA = getMemory(x+1);
			}else{
				valA = getMemory(relativeBase + getMemory(x+1));
			}
			if(pb == 0){
				valB = getMemory(getMemory(x+2));
			}else if(pb == 1){
				valB = getMemory(x+2);
			}else{
				valB = getMemory(relativeBase + getMemory(x+2));
			}
			if(comand == 7){
				if(valA < valB){
					setMemory(desC, 1);
				}else{
					setMemory(desC, 0);
				}
			}else{
				if(valA == valB){
					setMemory(desC, 1);
				}else{
					setMemory(desC, 0);
				}
			}
			x = x + 4;
		}else if(comand == 9){
			if(pa == 0){
				valA = getMemory(getMemory(x+1));
			}else if(pa == 1){
				valA = getMemory(x+1);
			}else{
				valA = getMemory(relativeBase +getMemory(x+1));
			}
			relativeBase += valA;
			x += 2;
		}else if(comand == 99){
			printf("halt\n");
			done = 0;
		}else{
			printf("error");
			done = 1;
		}
	}
	map[ox][oy] = 'O';
	printMap(50, map);
	printf("%lld done\n", done);
	int time = howLongToFill(50, map);
	printf("time = %d\n", time);


}


int main(int argc, char* argv[]){
	//partOne();
	partTwo();
	return 0;
}
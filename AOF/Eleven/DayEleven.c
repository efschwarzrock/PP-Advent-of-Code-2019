#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct memory{
	long long adress;
	long long value;
};

struct space{
	int x;
	int y;
	int color;
	bool hereBefor;
};

#define natMem 632

long long i[] = {3,8,1005,8,310,1106,0,11,0,0,0,104,1,104,0,3,8,1002,8,-1,10,101,1,10,10,4,10,1008,8,0,10,4,10,1001,8,0,29,1,2,11,10,1,1101,2,10,2,1008,18,10,2,106,3,10,3,8,1002,8,-1,10,1001,10,1,10,4,10,1008,8,1,10,4,10,102,1,8,67,2,105,15,10,3,8,1002,8,-1,10,101,1,10,10,4,10,1008,8,0,10,4,10,1001,8,0,93,2,1001,16,10,3,8,102,-1,8,10,1001,10,1,10,4,10,1008,8,1,10,4,10,102,1,8,119,3,8,1002,8,-1,10,1001,10,1,10,4,10,1008,8,1,10,4,10,101,0,8,141,2,7,17,10,1,1103,16,10,3,8,1002,8,-1,10,101,1,10,10,4,10,108,0,8,10,4,10,102,1,8,170,3,8,1002,8,-1,10,1001,10,1,10,4,10,1008,8,1,10,4,10,1002,8,1,193,1,7,15,10,2,105,13,10,1006,0,92,1006,0,99,3,8,1002,8,-1,10,101,1,10,10,4,10,108,1,8,10,4,10,101,0,8,228,1,3,11,10,1006,0,14,1006,0,71,3,8,1002,8,-1,10,101,1,10,10,4,10,1008,8,0,10,4,10,101,0,8,261,2,2,2,10,1006,0,4,3,8,102,-1,8,10,101,1,10,10,4,10,108,0,8,10,4,10,101,0,8,289,101,1,9,9,1007,9,1049,10,1005,10,15,99,109,632,104,0,104,1,21101,0,387240009756,1,21101,327,0,0,1105,1,431,21101,0,387239486208,1,21102,1,338,0,1106,0,431,3,10,104,0,104,1,3,10,104,0,104,0,3,10,104,0,104,1,3,10,104,0,104,1,3,10,104,0,104,0,3,10,104,0,104,1,21102,3224472579,1,1,21101,0,385,0,1106,0,431,21101,0,206253952003,1,21102,396,1,0,1105,1,431,3,10,104,0,104,0,3,10,104,0,104,0,21102,709052072296,1,1,21102,419,1,0,1105,1,431,21102,1,709051962212,1,21102,430,1,0,1106,0,431,99,109,2,21202,-1,1,1,21102,1,40,2,21102,462,1,3,21102,452,1,0,1105,1,495,109,-2,2105,1,0,0,1,0,0,1,109,2,3,10,204,-1,1001,457,458,473,4,0,1001,457,1,457,108,4,457,10,1006,10,489,1101,0,0,457,109,-2,2105,1,0,0,109,4,2102,1,-1,494,1207,-3,0,10,1006,10,512,21101,0,0,-3,22101,0,-3,1,21202,-2,1,2,21102,1,1,3,21101,531,0,0,1105,1,536,109,-4,2106,0,0,109,5,1207,-3,1,10,1006,10,559,2207,-4,-2,10,1006,10,559,21202,-4,1,-4,1105,1,627,22102,1,-4,1,21201,-3,-1,2,21202,-2,2,3,21102,1,578,0,1105,1,536,21202,1,1,-4,21102,1,1,-1,2207,-4,-2,10,1006,10,597,21101,0,0,-1,22202,-2,-1,-2,2107,0,-3,10,1006,10,619,21201,-1,0,1,21102,1,619,0,106,0,494,21202,-2,-1,-2,22201,-4,-2,-4,109,-5,2106,0,0};
//long long i[] = {3, 0, 104, 1, 104, 0, 3, 0, 104, 1, 104, 0, 3, 0, 104, 1, 104, 0, 3, 0, 104, 1, 104, 0, 3, 0, 104, 1, 104, 0,3, 0, 104, 1, 104, 0, 3, 0, 104, 1, 104, 1,3, 0, 104, 1, 104, 1,3, 0, 104, 1, 104, 1,3, 0, 104, 1, 104, 1,3, 0, 104, 1, 104, 1, 99};
int ramused = 0;
struct memory ram[1000];
struct space cords[10000];
int spaceUsed = 0;

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

int getSpace(int x, int y){
	int i = 0;
	while(i<spaceUsed){
		if(cords[i].x == x && cords[i].y == y){
			return i;
		}
		i++;
	}
	cords[i].x = x;
	cords[i].y = y;
	cords[i].color = 0;
	cords[i].hereBefor = false;
	spaceUsed++;
	return i;
}

void partOne(){	
	int numMoves = 0;
	int rx = 0;
	int ry = 0;
	int direc = 0;
	long long x = 0;
	long long com = 0;
	long long valA = 0;
	long long valB = 0;
	long long desC = 0;
	long long relativeBase = 0;
	long long done = -1;
	long long input = 1;
	long long output = -1;
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
			}else if(pa == 1){
				desC = x+1;
			}else{
				desC = relativeBase + getMemory(x+1);
			}
			if(comand == 3){
				//printf("here\n");
				input = cords[getSpace(rx, ry)].color;
				setMemory(desC, input);	
			}else{
				if(output == -1){
					output = getMemory(desC);
					int ci = getSpace(rx, ry);
					cords[ci].color = output;
					if(!cords[ci].hereBefor){
						printf("her\n");
						numMoves++;
						cords[ci].hereBefor = true;
					}
					printf("output = %lld, %d, %d\n", output, rx, ry);
				}else{
					output = getMemory(desC);
					printf("output = %lld, %d, %d\n\n", output, rx, ry);
					if(output == 0){
						direc = (direc + 3)%4;
					}else{
						direc = (direc + 1)%4;
					}
					if(direc == 0){
						rx--;
					}else if(direc == 2){
						rx++;
					}else if(direc == 3){
						ry--;
					}else if(direc == 1){
						ry++;
					}
					output = -1;
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
		if(spaceUsed>10000){
			printf("ehbviebrveb\n");
			done = 7;
		}
	}
	printf("%lld done\n", done);
	printf("numSquare = %d\n", numMoves);
}


void partTwo(){	
	int numMoves = 0;
	int rx = 0;
	int ry = 0;
	int panels[10][60];
	int ia = 0;
	int ib = 0;
	while(ia<10){
		ib = 0;
		while(ib<60){
			panels[ia][ib] = 0;
			ib++;
		}
		ia++;
	}
	panels[0][0] = 1;

	int direc = 0;
	long long x = 0;
	long long com = 0;
	long long valA = 0;
	long long valB = 0;
	long long desC = 0;
	long long relativeBase = 0;
	long long done = -1;
	long long input = 1;
	long long output = -1;
	bool firstpanal = true;
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
			}else if(pa == 1){
				desC = x+1;
			}else{
				desC = relativeBase + getMemory(x+1);
			}
			if(comand == 3){
				//printf("here\n");
				if(firstpanal){
					input = 1;
					firstpanal = false;
				}else{
					input = cords[getSpace(rx, ry)].color;
				}
				setMemory(desC, input);	
			}else{
				if(output == -1){
					output = getMemory(desC);
					int ci = getSpace(rx, ry);
					cords[ci].color = output;
					if(!cords[ci].hereBefor){
						printf("her\n");
						numMoves++;
						cords[ci].hereBefor = true;
					}
					printf("output = %lld, %d, %d\n", output, rx, ry);
					panels[rx][ry] = output;
				}else{
					output = getMemory(desC);
					printf("output = %lld, %d, %d\n\n", output, rx, ry);
					if(output == 0){
						direc = (direc + 3)%4;
					}else{
						direc = (direc + 1)%4;
					}
					if(direc == 0){
						rx--;
					}else if(direc == 2){
						rx++;
					}else if(direc == 3){
						ry--;
					}else if(direc == 1){
						ry++;
					}
					
					output = -1;
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
		if(spaceUsed>10000){
			printf("ehbviebrveb\n");
			done = 7;
		}
	}
	printf("%lld done\n", done);
	int ic = 0;
	int id = 0;
	while(ic<10){
		id = 0;
		while(id<60){
			if(panels[ic][id] == 0){
				printf(".");
			}else{
				printf("#");
			}
			id++;
		}
		printf("\n");
		ic++;
	}
}


int main(int argc, char* argv[]){
	//can only run one at a time or else it will overwrite the program
	//partOne();
	partTwo();
	return 0;
}
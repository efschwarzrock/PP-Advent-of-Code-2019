#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

struct memory{
	long long adress;
	long long value;
};
#define numram 10000

///////////////////////////////////////
//CHANGE ME
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#define natMem 424


long long getMemory(long long index, long long *i, struct memory *ram, int *ramused){
	int j = 0;
	if(index < natMem && index >= 0){
		return i[index];
	}else{
		while(j<*ramused){
			if(ram[j].adress == index){
				return ram[j].value;
			}
			j++;
		}
	}
	if(j>=numram){
		printf("error not enough ram\n");
		fflush(stdout);
		return 0;
	}
	ram[j].adress = index;
	ram[j].value = 0;
	(*ramused)++;
	return 0;
}

void setMemory(long long index, long long val,  long long *i, struct memory *ram, int *ramused){
	int j = 0;
	if(index < natMem && index >= 0){
		i[index] = val;
		return;
	}else{
		while(j<*ramused){
			if(ram[j].adress == index){
				ram[j].value = val;
				return;
			}
			j++;
		}
	}
	if(j>=numram){
		printf("error not enough ram\n");
		fflush(stdout);
		return;
	}
	ram[j].adress = index;
	ram[j].value = val;
	(*ramused)++;
}






////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////

int x = 0;
int y = 0;
bool firstInput = true;


long long getInputPtOne(){
	if(firstInput){
		firstInput = false;
		return x;
	}else{
		firstInput = true;
		return y;
	}
	return 0;
}



long long getInputPtTwo(){
	if(firstInput){
		firstInput = false;
		return x;
	}else{
		firstInput = true;
		return y;
	}
	return 0;
}

long long getInput(int part){
	if(part == 1){
		return getInputPtOne();
	}else{
		return getInputPtTwo();
	}
	return 0;
}








int sum = 0;

void endPtOne(){
	
}

void handelOutputPtOne(long long output, bool end){
	if(end){
		endPtOne();
	}else{
		sum += output;
		if(output == 1){
			printf("#");
		}else{
			printf(" ");
		}
	}
}




void endPtTwo(){
	
}

int out = 0;

void handelOutputPtTwo(long long output, bool end){
	if(end){
		endPtTwo();
	}else{
		out = output;
	}
}

void handelOutput(long long output, int part, bool end){
	if(part == 1){
		handelOutputPtOne(output, end);
	}else{
		handelOutputPtTwo(output, end);
	}
}

void specialCodeChange(int part, long long *i){
	
}


////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////










void intCodeComputer(int part){

//////////////////////////////////////////////////////
	//dont forget to change natMem
//////////////////////////////////////////////////////
	long long i[] = {109,424,203,1,21101,11,0,0,1105,1,282,21102,18,1,0,1105,1,259,1201,1,0,221,203,1,21102,1,31,0,1105,1,282,21101,38,0,0,1105,1,259,20102,1,23,2,21202,1,1,3,21102,1,1,1,21101,0,57,0,1106,0,303,1201,1,0,222,21001,221,0,3,21002,221,1,2,21101,0,259,1,21102,80,1,0,1106,0,225,21102,1,93,2,21101,0,91,0,1105,1,303,2102,1,1,223,21002,222,1,4,21101,0,259,3,21102,225,1,2,21101,0,225,1,21102,1,118,0,1105,1,225,21001,222,0,3,21101,0,73,2,21101,133,0,0,1105,1,303,21202,1,-1,1,22001,223,1,1,21101,148,0,0,1106,0,259,2102,1,1,223,20101,0,221,4,21001,222,0,3,21102,1,11,2,1001,132,-2,224,1002,224,2,224,1001,224,3,224,1002,132,-1,132,1,224,132,224,21001,224,1,1,21102,195,1,0,105,1,109,20207,1,223,2,21002,23,1,1,21101,-1,0,3,21101,214,0,0,1105,1,303,22101,1,1,1,204,1,99,0,0,0,0,109,5,2101,0,-4,249,22101,0,-3,1,22101,0,-2,2,21201,-1,0,3,21101,250,0,0,1106,0,225,22101,0,1,-4,109,-5,2106,0,0,109,3,22107,0,-2,-1,21202,-1,2,-1,21201,-1,-1,-1,22202,-1,-2,-2,109,-3,2105,1,0,109,3,21207,-2,0,-1,1206,-1,294,104,0,99,22101,0,-2,-2,109,-3,2105,1,0,109,5,22207,-3,-4,-1,1206,-1,346,22201,-4,-3,-4,21202,-3,-1,-1,22201,-4,-1,2,21202,2,-1,-1,22201,-4,-1,1,21202,-2,1,3,21102,1,343,0,1106,0,303,1106,0,415,22207,-2,-3,-1,1206,-1,387,22201,-3,-2,-3,21202,-2,-1,-1,22201,-3,-1,3,21202,3,-1,-1,22201,-3,-1,2,22101,0,-4,1,21102,1,384,0,1105,1,303,1105,1,415,21202,-4,-1,-4,22201,-4,-3,-4,22202,-3,-2,-2,22202,-2,-4,-4,22202,-3,-2,-3,21202,-4,-1,-2,22201,-3,-2,1,21202,1,1,-4,109,-5,2105,1,0};
	//incase we need to change the code based on the part
	specialCodeChange(part, i);	
	int ramused = 0;
	struct memory ram[numram];
	long long x = 0;
	long long parameter[4] = {0, 0, 0, 0};
	long long relativeBase = 0;
	long long done = -1;
	long long input = 1;
	long long output = 0;
	while(x < natMem && done == -1){
		//get comand and perameter modes
		parameter[0] = getMemory(x, i, ram, &ramused);
		int comand = parameter[0]%100;
		parameter[0] = parameter[0]/100;
		int parameterMode[3];
		parameterMode[0] = parameter[0]%10;
		parameterMode[1] = parameter[0]/10%10;
		parameterMode[2] = parameter[0]/100%10;


		//add and multiply the 2 perameters
		if(comand < 3){
			if(parameterMode[0] == 0){
				parameter[1] = getMemory(getMemory(x+1, i, ram, &ramused), i, ram, &ramused);
			}else if(parameterMode[0] == 1){
				parameter[1] = getMemory(x+1, i, ram, &ramused);
			}else{
				parameter[1] = getMemory(relativeBase + getMemory(x+1, i, ram, &ramused), i, ram, &ramused);
			}
			if(parameterMode[1] == 0){
				parameter[2] = getMemory(getMemory(x+2, i, ram, &ramused), i, ram, &ramused);
			}else if(parameterMode[1] == 1){
				parameter[2] = getMemory(x+2, i, ram, &ramused);
			}else{
				parameter[2] = getMemory(relativeBase + getMemory(x+2, i, ram, &ramused), i, ram, &ramused);
			}
			if(parameterMode[2] == 0){
				parameter[3] = getMemory(x+3, i, ram, &ramused);
			}else{
				parameter[3] = relativeBase + getMemory(x+3, i, ram, &ramused);
			}
			//add
			if(comand == 1){
				setMemory(parameter[3], parameter[1] + parameter[2], i, ram, &ramused);
			//multiply
			}else if( comand == 2){
				setMemory(parameter[3], parameter[1] * parameter[2], i, ram, &ramused);
			}
			x = x + 4;



		//get input and put output
		}else if(comand < 5){
			if(parameterMode[0] == 0){
				parameter[3] = getMemory(x+1, i, ram, &ramused);	
			}else{
				parameter[3] = relativeBase + getMemory(x+1, i, ram, &ramused);
			}
			//input
			if(comand == 3){
				input = getInput(part);
				setMemory(parameter[3], input, i, ram, &ramused);	
			//output
			}else{
				output = getMemory(parameter[3], i, ram, &ramused);
				handelOutput(output, part, false);
			}
			x = x + 2;




		//jump-if-true and jump-if-false
		}else if(comand < 7){
			if(parameterMode[0] == 0){
				parameter[1] = getMemory(getMemory(x+1, i, ram, &ramused), i, ram, &ramused);
			}else if(parameterMode[0] == 1){
				parameter[1] = getMemory(x+1, i, ram, &ramused);
			}else{
				parameter[1] = getMemory(relativeBase + getMemory(x+1, i, ram, &ramused), i, ram, &ramused);
			}
			if(parameterMode[1] == 0){
				parameter[2] = getMemory(getMemory(x+2, i, ram, &ramused), i, ram, &ramused);
			}else if(parameterMode[1] == 1){
				parameter[2] = getMemory(x+2, i, ram, &ramused);
			}else{
				parameter[2] = getMemory(relativeBase + getMemory(x+2, i, ram, &ramused), i, ram, &ramused);
			}
			//jump-if-true
			if(comand == 5){
				if(parameter[1] == 0){
					x = x + 3;
				}else{
					x = parameter[2];
				}
			//jump-if-false
			}else{
				if(parameter[1] != 0){
					x = x + 3;
				}else{
					x = parameter[2];
				}
			}




		//less-than? and equal-to?
		}else if(comand < 9){
			if(parameterMode[2] == 0){
				parameter[3] = getMemory(x+3, i, ram, &ramused);
			}else{
				parameter[3] = relativeBase + getMemory(x+3, i, ram, &ramused);
			}
			if(parameterMode[0] == 0){
				parameter[1] = getMemory(getMemory(x+1, i, ram, &ramused), i, ram, &ramused);
			}else if(parameterMode[0] == 1){
				parameter[1] = getMemory(x+1, i, ram, &ramused);
			}else{
				parameter[1] = getMemory(relativeBase + getMemory(x+1, i, ram, &ramused), i, ram, &ramused);
			}
			if(parameterMode[1] == 0){
				parameter[2] = getMemory(getMemory(x+2, i, ram, &ramused), i, ram, &ramused);
			}else if(parameterMode[1] == 1){
				parameter[2] = getMemory(x+2, i, ram, &ramused);
			}else{
				parameter[2] = getMemory(relativeBase + getMemory(x+2, i, ram, &ramused), i, ram, &ramused);
			}
			//less-than?
			if(comand == 7){
				if(parameter[1] < parameter[2]){
					setMemory(parameter[3], 1, i, ram, &ramused);
				}else{
					setMemory(parameter[3], 0, i, ram, &ramused);
				}
			//equal-to?
			}else{
				if(parameter[1] == parameter[2]){
					setMemory(parameter[3], 1, i, ram, &ramused);
				}else{
					setMemory(parameter[3], 0, i, ram, &ramused);
				}
			}
			x = x + 4;





		//adjust relative base
		}else if(comand == 9){
			if(parameterMode[0] == 0){
				parameter[1] = getMemory(getMemory(x+1, i, ram, &ramused), i, ram, &ramused);
			}else if(parameterMode[0] == 1){
				parameter[1] = getMemory(x+1, i, ram, &ramused);
			}else{
				parameter[1] = getMemory(relativeBase +getMemory(x+1, i, ram, &ramused), i, ram, &ramused);
			}
			relativeBase += parameter[1];
			x += 2;


		//terminate
		}else if(comand == 99){
			done = 0;
		//not a comand
		}else{
			done = 1;
			output = parameter[0];
		}
	}
	//executed sucsesfuly
	if(done == 0){
		handelOutput(0, part, true);
		//printf("executed sucsesfully\n");
	}else{
	//did not execute sucessfuly
		printf("error: error code %lld at index %lld", output, x);
	}
	
}

void partOne(){
	while(x<100){
		y = 0;
		while(y < 100){
			intCodeComputer(1);
			y++;
		}
		printf("\n");
		x++;
	}
	printf("sum = %d\n", sum);
}

void partTwo(){
	//after running part one the first part of the beam was found to be 5,6
	x = 5;
	y = 6;
	bool done = false;
	while(!done){
		intCodeComputer(2);
		if(out == 1){
			int ox = x;
			x = x - 99;
			if(x > 0){
				intCodeComputer(2);
				if(out == 1){
					int oy = y;
					y = y + 99;
					intCodeComputer(2);
					if(out == 1){
						done = true;
						printf("%d, %d\n", x, y-99);
					}
					y = oy;
				}
			}
			x = ox;
			x++;
			y++;
		}else{
			y++;
		}	
	}
}

int main(int argc, char* argv[]){
	partOne();
	//we will traverse the bottom line to find santas sleigh
	partTwo();
	return 0;
}
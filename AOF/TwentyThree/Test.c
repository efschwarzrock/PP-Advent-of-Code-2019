#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

struct memory{
	long long adress;
	long long value;
	int comp;
};

struct msg{
	int i;
	long long pos[2];
};


#define numram 10000

///////////////////////////////////////
//CHANGE ME
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#define natMem 2229


long long getMemory(long long index, long long *i, struct memory ram[numram], int *ramused, int comp){
	
	int j = 0;
	if(index < natMem && index >= 0){
		//printf("index = %lld\n", index);
		//printf("mem %lld\n", i[index]);
		
		return i[index];
	}else{
		while(j<*ramused){
			if(ram[j].adress == index && ram[j].comp == comp){
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
	ram[j].comp = comp;
	(*ramused)++;

	return 0;
}

void setMemory(long long index, long long val,  long long *i, struct memory *ram, int *ramused, int comp){
	int j = 0;
	if(index < natMem && index >= 0){
		i[index] = val;
		return;
	}else{
		while(j<*ramused){
			if(ram[j].adress == index && ram[j].comp == comp){
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
	ram[j].comp = comp;
	(*ramused)++;
}






////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////

struct msg mailbox[50][1000];
int nxtmsg[50];
int finalmsg[50];

long long to[50];
long long x[50];
long long y[50];
int oi[50];
bool bootup[50];

void initalizemailBoxes(){
	int i = 0;
	while(i < 50){
		int j = 0;
		while(j<100){
			mailbox[i][j].i = -1;
			j++;
		}
		nxtmsg[i] = 0;
		finalmsg[i] = 0;
		to[i] = -1;
		oi[i] = 0;
		bootup[i] = true;
		i++;
	}
}



long long getInputPtOne(int to){
	if(bootup[to]){	
		bootup[to] = false;
		return to;
	}
	if(nxtmsg[to] == finalmsg[to]){
		return -1;
	}else{
		int returnval = mailbox[to][nxtmsg[to]].pos[mailbox[to][nxtmsg[to]].i];
		mailbox[to][nxtmsg[to]].i++;
		if(mailbox[to][nxtmsg[to]].i == 2){
			mailbox[to][nxtmsg[to]].i = -1;
			nxtmsg[to]++;
		}
		return returnval;
	}
		
	return 0;
}



long long getInputPtTwo(){
	return 0;
}

long long getInput(int part, int to){
	if(part == 1){
		return getInputPtOne(to);
	}else{
		return getInputPtTwo();
	}
	return 0;
}









void endPtOne(){
	
}
bool wierd = false;
bool print = false;
void handelOutputPtOne(long long output, bool end, int from){
	if(oi[from] == 2){
		//printf(" out = %lld\n", output);
	}
	if(end){
		endPtOne();
	}else{
		
	if(from == 0){
		//printf("out %d\n", from);
		}
		if(oi[from] == 0){
			if(output == 255){
				print = true;
				}
				
			to[from] = output;
			oi[from]++;
		}else if(oi[from] == 1){
			
				printf("1 %lld\n", output);
				
				
			x[from] = output;
			oi[from]++;
		}else if(oi[from] == 2){
			
				printf("2 %lld\n", output);
				
				
			if((finalmsg[to[from]]%100 == 99 && nxtmsg[to[from]]%100 == 0) || finalmsg[to[from]] - nxtmsg[to[from]] == -1){
				printf("errror output: not enough msgs\n");
			}
			if(to[from] == 255){
				printf("\n\n\n\n\n y = %lld\n\n\n\n", output);
			}else if(to[from] < 50){
				y[from] = output;
				oi[from] = 0;
				mailbox[ to[from] ][ finalmsg[to[from]]].i = 0;
				mailbox[to[from]][finalmsg[to[from]]].pos[0] = x[from];
				mailbox[to[from]][finalmsg[to[from]]].pos[1] = y[from];
				finalmsg[to[from]]++;
				//printf("not wierd %lld\n", to[from]);
			}else{
				oi[from] = 0;
				//wierd = true;
				if(from == 0){
				printf("wierd %lld\n", to[from]);
				}
			}
		}else{
			printf("errror output\n");
		}
		
	}
}




void endPtTwo(){
	
}

void handelOutputPtTwo(long long output, bool end){
	if(end){
		endPtTwo();
	}else{
		
	}
}

void handelOutput(long long output, int part, bool end, int from){
	if(part == 1){
		handelOutputPtOne(output, end, from);
	}else{
		handelOutputPtTwo(output, end);
	}
}

void specialCodeChange(int part, long long *i){
	i[0] = part;
}


////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////










void intCodeComputer(int part){

//////////////////////////////////////////////////////
	//dont forget to change natMem
//////////////////////////////////////////////////////
	printf("herehhhhhhhhh\n");
	fflush(stdout); 
	long long i[50][2229];
	long long code[] = {3, 62, 1108, 3, 8, 62, 4, 62, 99};
	int ii = 0;
	printf("here %lld\n", code[62]);
	fflush(stdout);
	while(ii < 50){
		int ij = 0;
		while(ij < 2229){
			i[ii][ij] = code[ij];
			ij++;
		}
		ii++;
	}
	//incase we need to change the code based on the part
	//specialCodeChange(part, i);
	
	int ramused;
	struct memory ram[numram];
	long long x[50];
	long long comp = 0;
	long long parameter[4] = {0, 0, 0, 0};
	long long relativeBase[50];
	long long done[50];
	bool bigDone = false;
	long long input = 1;
	long long output = 0;
	while(comp < 50){
		x[comp] = 0;
		relativeBase[comp] = 0;
		done[comp] = -1;
		comp++;
	}
	comp = 0;
	int fff = 0;
	while(!bigDone && !wierd){

	while(x[comp] < natMem && done[comp] == -1 &&  !wierd){
		//get comand and perameter modes
		parameter[0] =  getMemory(x[comp], i[comp], ram, &ramused, comp);
		if(comp == 0){
			fff++;
			//printf("comand %lld   %lld\n", parameter[0], x[0]);
		}
		if(fff == 500){
			//wierd = true;
}
		//printf("%lld\n", x[comp]);
		//printf("comand %lld\n", i[comp][2]);
		//printf("paramo %lld\n", parameter[0]);
		int comand = parameter[0]%100;
		parameter[0] = parameter[0]/100;

		int parameterMode[3];
		parameterMode[0] = parameter[0]%10;
		parameterMode[1] = parameter[0]/10%10;
		parameterMode[2] = parameter[0]/100%10;
		if(comand<=0){
			//printf("here\n");
			done[comp] = 1;
			output = parameter[0];
		//add and multiply the 2 perameters
		}else if(comand < 3 && comand > 0){
			if(parameterMode[0] == 0){
				parameter[1] = getMemory(getMemory(x[comp]+1, i[comp], ram, &ramused, comp), i[comp], ram, &ramused, comp);
			}else if(parameterMode[0] == 1){
				parameter[1] = getMemory(x[comp]+1, i[comp], ram, &ramused, comp);
			}else{
				parameter[1] = getMemory(relativeBase[comp] + getMemory(x[comp]+1, i[comp], ram, &ramused, comp), i[comp], ram, &ramused, comp);
			}
			if(parameterMode[1] == 0){
				parameter[2] = getMemory(getMemory(x[comp]+2, i[comp], ram, &ramused, comp), i[comp], ram, &ramused, comp);
			}else if(parameterMode[1] == 1){
				parameter[2] = getMemory(x[comp]+2, i[comp], ram, &ramused, comp);
			}else{
				parameter[2] = getMemory(relativeBase[comp] + getMemory(x[comp]+2, i[comp], ram, &ramused, comp), i[comp], ram, &ramused, comp);
			}
			if(parameterMode[2] == 0){
				parameter[3] = getMemory(x[comp]+3, i[comp], ram, &ramused, comp);
			}else if(parameterMode[2] == 1){
				parameter[3] = x[comp]+3;
			}else{
				parameter[3] = relativeBase[comp] + getMemory(x[comp]+3, i[comp], ram, &ramused, comp);
			}
			if(!wierd && comp == 0 ){
				//printf("%lld, %lld, ", parameter[3]);
			}
			
			//add
			if(comand == 1){
				setMemory(parameter[3], parameter[1] + parameter[2], i[comp], ram, &ramused, comp);
			//multiply
			}else if( comand == 2){
				setMemory(parameter[3], parameter[1] * parameter[2], i[comp], ram, &ramused, comp);
			}
			x[comp] = x[comp] + 4;



		//get input and put output
		}else if(comand < 5){
			if(parameterMode[0] == 0){
				parameter[3] = getMemory(x[comp]+1, i[comp], ram, &ramused, comp);
			}else if(parameterMode[0] == 1){
				parameter[3] = x[comp]+1;
			}else{
				parameter[3] = relativeBase[comp] + getMemory(x[comp]+1, i[comp], ram, &ramused, comp);
			}
			if( comp == 0 && comand == 4){
				//printf("\n\nmem %lld\n", parameter[3]);
				if(parameter[3] == 13){
				//	printf("val %lld\n", i[1][13]);
				}
				
		}
			//input
			if(comand == 3){
				input = getInput(part, comp);
				if(comp == 23 &&  parameter[3] == 70){
				printf("changein %lld\n", input);
			}	
			if(comp == 23 &&  parameter[3] == 2231){
				printf("changein %lld\n", input);
			}	
				setMemory(parameter[3], input, i[comp], ram, &ramused, comp);
			
				if(wierd && comp == 1){
			//printf("parami %lld\n", input);
			
		}
			//output
			}else{
				
				output = getMemory(parameter[3], i[comp], ram, &ramused, comp);
				printf("%lld\n", output);
				if(print){
				printf("param3 %lld %lld %lld\n", parameter[3], comp, output);
			
		}
				handelOutput(output, part, false, comp);
			}
			x[comp] = x[comp] + 2;
			//printf("after %lld\n", x[comp]);



		//jump-if-true and jump-if-false
		}else if(comand < 7){
			if(parameterMode[0] == 0){
				parameter[1] = getMemory(getMemory(x[comp]+1, i[comp], ram, &ramused, comp), i[comp], ram, &ramused, comp);
			}else if(parameterMode[0] == 1){
				parameter[1] = getMemory(x[comp]+1, i[comp], ram, &ramused, comp);
			}else{
				parameter[1] = getMemory(relativeBase[comp] + getMemory(x[comp]+1, i[comp], ram, &ramused, comp), i[comp], ram, &ramused, comp);
			}
			if(parameterMode[1] == 0){
				parameter[2] = getMemory(getMemory(x[comp]+2, i[comp], ram, &ramused, comp), i[comp], ram, &ramused, comp);
			}else if(parameterMode[1] == 1){
				parameter[2] = getMemory(x[comp]+2, i[comp], ram, &ramused, comp);
			}else{
				parameter[2] = getMemory(relativeBase[comp] + getMemory(x[comp]+2, i[comp], ram, &ramused, comp), i[comp], ram, &ramused, comp);
			}
			//jump-if-true
			if(comand == 5){
				if(parameter[1] == 0){
					x[comp] = x[comp] + 3;
				}else{
					x[comp] = parameter[2];
				}
			//jump-if-false
			}else{
				if(parameter[1] != 0){
					x[comp] = x[comp] + 3;
				}else{
					x[comp] = parameter[2];
				}
			}




		//less-than? and equal-to?
		}else if(comand < 9){
			if(parameterMode[2] == 0){
				parameter[3] = getMemory(x[comp]+3, i[comp], ram, &ramused, comp);
			}else if(parameterMode[2] == 1){
				parameter[3] = x[comp]+3;
			}else{
				parameter[3] = relativeBase[comp] + getMemory(x[comp]+3, i[comp], ram, &ramused, comp);
			}
			if(parameterMode[0] == 0){
				parameter[1] = getMemory(getMemory(x[comp]+1, i[comp], ram, &ramused, comp), i[comp], ram, &ramused, comp);
			}else if(parameterMode[0] == 1){
				parameter[1] = getMemory(x[comp]+1, i[comp], ram, &ramused, comp);
			}else{
				parameter[1] = getMemory(relativeBase[comp] + getMemory(x[comp]+1, i[comp], ram, &ramused, comp), i[comp], ram, &ramused, comp);
			}
			if(parameterMode[1] == 0){
				parameter[2] = getMemory(getMemory(x[comp]+2, i[comp], ram, &ramused, comp), i[comp], ram, &ramused, comp);
			}else if(parameterMode[1] == 1){
				parameter[2] = getMemory(x[comp]+2, i[comp], ram, &ramused, comp);
			}else{
				parameter[2] = getMemory(relativeBase[comp] + getMemory(x[comp]+2, i[comp], ram, &ramused, comp), i[comp], ram, &ramused, comp);
			}
			if(comp == 23 &&  parameter[3] == 2231){
				printf("changesevennnnnnnnnnnnn\n");
			}
			//less-than?
			if(comand == 7){
				if(parameter[1] < parameter[2]){
					setMemory(parameter[3], 1, i[comp], ram, &ramused, comp);
				}else{
					setMemory(parameter[3], 0, i[comp], ram, &ramused, comp);
				}
			//equal-to?
			}else{
				if(parameter[1] == parameter[2]){
					setMemory(parameter[3], 1, i[comp], ram, &ramused, comp);
				}else{
					setMemory(parameter[3], 0, i[comp], ram, &ramused, comp);
				}
			}
			x[comp] = x[comp] + 4;





		//adjust relative base
		}else if(comand == 9){
			if(parameterMode[0] == 0){
				parameter[1] = getMemory(getMemory(x[comp]+1, i[comp], ram, &ramused, comp), i[comp], ram, &ramused, comp);
			}else if(parameterMode[0] == 1){
				parameter[1] = getMemory(x[comp]+1, i[comp], ram, &ramused, comp);
			}else{
				parameter[1] = getMemory(relativeBase[comp] + getMemory(x[comp]+1, i[comp], ram, &ramused, comp), i[comp], ram, &ramused, comp);
			}
			if(comp == 23){
				//printf("changesevennnnnnnnnnnnn %lld %lld\n", relativeBase[23], parameter[1]);
			}
			relativeBase[comp] += parameter[1];
			//printf("%lld\n", relativeBase[comp]);
			x[comp] += 2;


		//terminate
		}else if(comand == 99){
			done[comp] = 0;
			//printf("here\n");
		//not a comand
		}else{
			printf("here\n");
			done[comp] = 1;
			output = parameter[0];
		}


		comp++;
		if(comp == 50){
			comp = 0;
		}
	}
	
	int y = 0;
	bigDone = true;
	while(y<50){
		if(done[y] == -1){
			//printf("here\n");
			bigDone = false;
		}
		y++;
	}


	}
	//executed sucsesfuly
	if(done == 0){
		handelOutput(0, part, true, 5);
		//printf("executed sucsesfully\n");
	}else{
	//did not execute sucessfuly
		printf("error: error code %lld at index %lld\n", output, x[comp]);
	}

	
}

int main(int argc, char* argv[]){
	//For part one to work change ardess 0 of i to 1
	printf("Part One:\n==============\n");
	initalizemailBoxes();
	printf("here\n");
	fflush(stdout);
	intCodeComputer(1);
	//For part Two to work change ardess 0 of i to 2
	//didn't find a clever way to find the paterns, i just ploted the scafolding in excel, 
	//found a big chunk tha was the same, wrote out the path and then found repeting 
	//comands and stitched them together
	//printf("\n\n\n\n\n\n\nPart Two:\n==============\n");
	//intCodeComputer(2);

	return 0;
}
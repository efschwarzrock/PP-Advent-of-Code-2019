#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct memory{
	long long adress;
	long long value;
};

#define natMem 1471
#define numram 10000

long long i[] = {2,330,331,332,109,3890,1102,1,1182,16,1102,1471,1,24,101,0,0,570,1006,570,36,1002,571,1,0,1001,570,-1,570,1001,24,1,24,1105,1,18,1008,571,0,571,1001,16,1,16,1008,16,1471,570,1006,570,14,21102,58,1,0,1105,1,786,1006,332,62,99,21102,333,1,1,21102,73,1,0,1105,1,579,1102,0,1,572,1102,1,0,573,3,574,101,1,573,573,1007,574,65,570,1005,570,151,107,67,574,570,1005,570,151,1001,574,-64,574,1002,574,-1,574,1001,572,1,572,1007,572,11,570,1006,570,165,101,1182,572,127,101,0,574,0,3,574,101,1,573,573,1008,574,10,570,1005,570,189,1008,574,44,570,1006,570,158,1105,1,81,21102,1,340,1,1106,0,177,21102,1,477,1,1106,0,177,21101,0,514,1,21101,0,176,0,1105,1,579,99,21101,184,0,0,1106,0,579,4,574,104,10,99,1007,573,22,570,1006,570,165,102,1,572,1182,21101,375,0,1,21101,0,211,0,1105,1,579,21101,1182,11,1,21102,1,222,0,1106,0,979,21102,1,388,1,21101,0,233,0,1106,0,579,21101,1182,22,1,21102,244,1,0,1105,1,979,21102,401,1,1,21102,1,255,0,1106,0,579,21101,1182,33,1,21101,266,0,0,1105,1,979,21102,1,414,1,21102,277,1,0,1105,1,579,3,575,1008,575,89,570,1008,575,121,575,1,575,570,575,3,574,1008,574,10,570,1006,570,291,104,10,21101,0,1182,1,21101,313,0,0,1105,1,622,1005,575,327,1101,0,1,575,21102,327,1,0,1105,1,786,4,438,99,0,1,1,6,77,97,105,110,58,10,33,10,69,120,112,101,99,116,101,100,32,102,117,110,99,116,105,111,110,32,110,97,109,101,32,98,117,116,32,103,111,116,58,32,0,12,70,117,110,99,116,105,111,110,32,65,58,10,12,70,117,110,99,116,105,111,110,32,66,58,10,12,70,117,110,99,116,105,111,110,32,67,58,10,23,67,111,110,116,105,110,117,111,117,115,32,118,105,100,101,111,32,102,101,101,100,63,10,0,37,10,69,120,112,101,99,116,101,100,32,82,44,32,76,44,32,111,114,32,100,105,115,116,97,110,99,101,32,98,117,116,32,103,111,116,58,32,36,10,69,120,112,101,99,116,101,100,32,99,111,109,109,97,32,111,114,32,110,101,119,108,105,110,101,32,98,117,116,32,103,111,116,58,32,43,10,68,101,102,105,110,105,116,105,111,110,115,32,109,97,121,32,98,101,32,97,116,32,109,111,115,116,32,50,48,32,99,104,97,114,97,99,116,101,114,115,33,10,94,62,118,60,0,1,0,-1,-1,0,1,0,0,0,0,0,0,1,32,0,0,109,4,2101,0,-3,586,21002,0,1,-1,22101,1,-3,-3,21101,0,0,-2,2208,-2,-1,570,1005,570,617,2201,-3,-2,609,4,0,21201,-2,1,-2,1105,1,597,109,-4,2105,1,0,109,5,1201,-4,0,630,20102,1,0,-2,22101,1,-4,-4,21102,0,1,-3,2208,-3,-2,570,1005,570,781,2201,-4,-3,652,21001,0,0,-1,1208,-1,-4,570,1005,570,709,1208,-1,-5,570,1005,570,734,1207,-1,0,570,1005,570,759,1206,-1,774,1001,578,562,684,1,0,576,576,1001,578,566,692,1,0,577,577,21102,1,702,0,1105,1,786,21201,-1,-1,-1,1106,0,676,1001,578,1,578,1008,578,4,570,1006,570,724,1001,578,-4,578,21101,0,731,0,1106,0,786,1105,1,774,1001,578,-1,578,1008,578,-1,570,1006,570,749,1001,578,4,578,21102,756,1,0,1106,0,786,1106,0,774,21202,-1,-11,1,22101,1182,1,1,21101,774,0,0,1106,0,622,21201,-3,1,-3,1105,1,640,109,-5,2105,1,0,109,7,1005,575,802,21001,576,0,-6,20101,0,577,-5,1105,1,814,21102,1,0,-1,21101,0,0,-5,21101,0,0,-6,20208,-6,576,-2,208,-5,577,570,22002,570,-2,-2,21202,-5,41,-3,22201,-6,-3,-3,22101,1471,-3,-3,1202,-3,1,843,1005,0,863,21202,-2,42,-4,22101,46,-4,-4,1206,-2,924,21102,1,1,-1,1105,1,924,1205,-2,873,21101,35,0,-4,1106,0,924,2102,1,-3,878,1008,0,1,570,1006,570,916,1001,374,1,374,2101,0,-3,895,1102,1,2,0,1201,-3,0,902,1001,438,0,438,2202,-6,-5,570,1,570,374,570,1,570,438,438,1001,578,558,922,20101,0,0,-4,1006,575,959,204,-4,22101,1,-6,-6,1208,-6,41,570,1006,570,814,104,10,22101,1,-5,-5,1208,-5,59,570,1006,570,810,104,10,1206,-1,974,99,1206,-1,974,1101,0,1,575,21101,0,973,0,1106,0,786,99,109,-7,2106,0,0,109,6,21102,0,1,-4,21101,0,0,-3,203,-2,22101,1,-3,-3,21208,-2,82,-1,1205,-1,1030,21208,-2,76,-1,1205,-1,1037,21207,-2,48,-1,1205,-1,1124,22107,57,-2,-1,1205,-1,1124,21201,-2,-48,-2,1105,1,1041,21102,1,-4,-2,1106,0,1041,21102,-5,1,-2,21201,-4,1,-4,21207,-4,11,-1,1206,-1,1138,2201,-5,-4,1059,1202,-2,1,0,203,-2,22101,1,-3,-3,21207,-2,48,-1,1205,-1,1107,22107,57,-2,-1,1205,-1,1107,21201,-2,-48,-2,2201,-5,-4,1090,20102,10,0,-1,22201,-2,-1,-2,2201,-5,-4,1103,2101,0,-2,0,1106,0,1060,21208,-2,10,-1,1205,-1,1162,21208,-2,44,-1,1206,-1,1131,1105,1,989,21102,1,439,1,1105,1,1150,21101,477,0,1,1106,0,1150,21102,1,514,1,21101,1149,0,0,1105,1,579,99,21101,1157,0,0,1106,0,579,204,-2,104,10,99,21207,-3,22,-1,1206,-1,1138,2101,0,-5,1176,1202,-4,1,0,109,-6,2105,1,0,32,5,40,1,40,1,40,1,40,1,40,1,40,1,40,1,40,1,40,1,40,1,40,1,30,11,30,1,40,1,40,1,30,13,38,1,1,1,26,5,7,1,1,1,26,1,3,1,7,1,1,1,26,1,3,1,7,1,1,1,26,1,3,1,7,1,1,1,26,1,3,1,7,1,1,1,1,11,14,1,3,1,7,1,1,1,1,1,9,1,14,1,3,1,7,13,1,1,14,1,3,1,9,1,1,1,7,1,1,1,14,1,3,1,9,13,14,1,3,1,11,1,7,1,12,13,3,13,12,1,3,1,3,1,3,1,3,1,3,1,12,13,3,13,12,1,7,1,11,1,3,1,16,1,7,1,11,1,3,1,16,1,7,1,11,1,3,1,16,13,7,1,3,1,24,1,3,1,7,1,3,1,14,11,3,1,7,1,3,1,14,1,13,1,7,1,3,1,14,1,13,1,7,1,3,1,14,1,13,1,7,1,3,1,14,1,13,1,7,5,14,1,13,1,26,1,13,1,26,1,13,1,26,1,13,1,26,1,13,1,26,1,3,11,26,1,3,1,36,9,36,1,3,1,36,1,3,1,36,1,3,1,36,1,3,1,36,1,3,1,36,1,3,1,36,1,3,1,36,1,3,1,36,1,3,1,36,5,32};
int ramused = 0;
struct memory ram[numram];

long long getMemory(long long index){
        //printf("here");
	//fflush(stdout);
	int j = 0;
	if(index < natMem && index >= 0){

	// printf(" done\n");
	//fflush(stdout);
		return i[index];
	}else{
		while(j<ramused){
			if(ram[j].adress == index){

	// printf(" done");
	//fflush(stdout);
				return ram[j].value;
			}
			j++;
		}
	}
	ram[j].adress = index;
	ram[j].value = 0;
	ramused++;
	// printf(" done");
	//fflush(stdout);
	return 0;
}

void setMemory(long long index, long long val){
	if(index == 3907){
		printf("set\n");
	}
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
	if(j>=numram){
		printf("error not enough ram\n");
		return;
	}
	ram[j].adress = index;
	ram[j].value = val;
	ramused++;
}

void partOne(){	
	long long x = 0;
	long long com = 0;
	long long valA = 0;
	long long valB = 0;
	long long desC = 0;
	long long relativeBase = 0;
	long long done = -1;
	long long input = 1;
	long long output = 0;
	int numouts = 0;
	char str[2500];
	int timethrough = 0;
	int comandi = 0;
	while(x < natMem && done == -1){

		com = getMemory(x);
		int comand = com%100;
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
			}else if( comand == 2){
				setMemory(desC, valA * valB);
			}
			x = x + 4;
		}else if(comand < 5){
			if(pa == 0){
				desC = getMemory(x+1);	
			}else if(pa == 1){
				desC = x+1;
			}else{
				desC = relativeBase + getMemory(x+1);
			}
			if(comand == 3){
				setMemory(desC, input);	
			}else{
				output = getMemory(desC);
				str[numouts] = output;
				
				numouts++;
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
	printf("%lld done, %d\n", done, numouts);
	str[numouts] = '\0';
	printf("%s\n", str);
	fflush(stdout);
	int map[59][41];
	int mx = 0;
	int my = 0;
	int si = 0;
	while(si<2500){
		if(str[si] == '\0'){
			si = 2600;
		}else if(str[si] == '\n'){
			mx++;
			my = 0;
		}else {
			if(str[si] == '.'){
				map[mx][my] = 0;
			}else if(str[si] == '#'){
				map[mx][my] = 1;
			}else if(str[si] == '^'){
				map[mx][my] = 10;
			}else if(str[si] == '>'){
				map[mx][my] = 11;
			}else if(str[si] == 'v'){
				map[mx][my] = 12;
			}else if(str[si] == '<'){
				map[mx][my] = 13;
			}
			my++;
		}
		si++;
	}
	mx = 0;
	my = 0;
	int sumAlign = 0;
	while(mx<59){
		my = 0;
		while(my<41){
			/*
			if(map[mx][my] == 0){
				printf(".");
			}else if(map[mx][my] == 1){
				printf("#");
			}else if(map[mx][my] == 10){
				printf("^");
			}else if(map[mx][my] == 11){
				printf(">");
			}else if(map[mx][my] == 12){
				printf("v");
			}else if(map[mx][my] == 13){
				printf("<");
			}
			*/
			if(mx != 0 && my != 0 && mx != 59 && my != 41){
				if(map[mx][my] == 1 && map[mx + 1][my] == 1 && map[mx - 1][my] == 1 && map[mx][my + 1] == 1 && map[mx][my - 1] == 1){
					sumAlign += mx*my;
				}
			}
			my++;
		}
		//printf("\n");
		mx++;
	}
	printf("sum = %d\n", sumAlign);
}


void partTwo(){	
	long long x = 0;
	long long com = 0;
	long long valA = 0;
	long long valB = 0;
	long long desC = 0;
	long long relativeBase = 0;
	long long done = -1;
	long long input = 1;
	long long output = 0;
	int numouts = 0;
	char str[25000];

	char inputstr[100] = "A,B,B,C,C,A,B,B,C,A\nR,4,R,12,R,10,L,12\nL,12,R,4,R,12\nL,12,L,8,R,10\nn\n";
	int inputstri = 0;

	int timethrough = 0;
	int comandi = 0;
	while(x < natMem && done == -1){

		com = getMemory(x);
		int comand = com%100;
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
			}else if( comand == 2){
				setMemory(desC, valA * valB);
			}
			x = x + 4;
		}else if(comand < 5){
			if(pa == 0){
				desC = getMemory(x+1);	
			}else if(pa == 1){
				desC = x+1;
			}else{
				desC = relativeBase + getMemory(x+1);
			}
			if(comand == 3){
				input = inputstr[inputstri];
				inputstri++;
				setMemory(desC, input);	
			}else{
				output = getMemory(desC);
				//printf("output = %lld\n", output);
				str[numouts] = output;
				
				numouts++;
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
	printf("%lld done, %d\n", done, numouts);
	str[numouts] = '\0';
	printf("%s\n", str);
	printf("dust colected = %lld\n", output);
	fflush(stdout);
	

}


int main(int argc, char* argv[]){
	//For part one to work change ardess 0 of i to 1
	//partOne();
	//For part Two to work change ardess 0 of i to 2
	//didn't find a clever way to find the paterns, i just ploted the scafolding in excel, 
	//found a big chunk tha was the same, wrote out the path and then found repeting 
	//comands and stitched them together
	partTwo();
	return 0;
}
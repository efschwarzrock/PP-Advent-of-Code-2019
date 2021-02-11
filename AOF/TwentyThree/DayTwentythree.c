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

long long natX = 0;
long long natY = 0;
long long natYPrev = 1;

int idol = 2;
int buffer = 0;

void nat(){
	bool isIdol = true;
	int i = 0;
	while(i<50){
		if(nxtmsg[i] != finalmsg[i]){
			isIdol  = false;
			i = 60;
		}
		i++;
	}
	if(isIdol){
		if(buffer < 500){
			buffer++;
			return;
		}
		printf("\nidoling\n");
		fflush(stdout);
		
		mailbox[0][ finalmsg[0]].i = 0;
		mailbox[0][finalmsg[0]].pos[0] = natX;
		mailbox[0][finalmsg[0]].pos[1] = natY;


		finalmsg[0]++;
		if(natY == natYPrev){
			printf("\n\n\n\n\n y 2x in row = %lld\n\n\n\n", natY);
			exit(0);
		}else{
			natYPrev = natY;
			printf("natYPrev = %lld\n", natYPrev);
		}
	}
}

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
		long long returnval = mailbox[to][nxtmsg[to]].pos[mailbox[to][nxtmsg[to]].i];
		mailbox[to][nxtmsg[to]].i++;
		if(mailbox[to][nxtmsg[to]].i == 2){
			mailbox[to][nxtmsg[to]].i = -1;
			nxtmsg[to]++;
			if(nxtmsg[to] == 1000){
				nxtmsg[to] = 0;
			}
		}
		return returnval;
	}
		
	return 0;
}



long long getInputPtTwo(int to){

	
	if(to == 0){	
	printf("here   i2\n");
	}
	fflush(stdout);
	if(bootup[to]){	
		bootup[to] = false;
		return to;
	}
	if(nxtmsg[to] == finalmsg[to] && to == 0){
		nat();
		return -1;
	}else if(nxtmsg[to] == finalmsg[to]){
		return -1;
	}else{
		long long returnval = mailbox[to][nxtmsg[to]].pos[mailbox[to][nxtmsg[to]].i];
		mailbox[to][nxtmsg[to]].i++;
		if(mailbox[to][nxtmsg[to]].i == 2){
			mailbox[to][nxtmsg[to]].i = -1;
			nxtmsg[to]++;
			if(nxtmsg[to] == 1000){
				nxtmsg[to] = 0;
			}
		}
		return returnval;
	}
		
	return 0;

}

long long getInput(int part, int to){
	if(part == 1){
		return getInputPtOne(to);
	}else{
		return getInputPtTwo(to);
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
			
				//printf("1 %lld\n", output);
				
				
			x[from] = output;
			oi[from]++;
		}else if(oi[from] == 2){
			
				//printf("2 %lld\n", output);
				
				
			if((finalmsg[to[from]]%100 == 99 && nxtmsg[to[from]]%100 == 0) || finalmsg[to[from]] - nxtmsg[to[from]] == -1){
				printf("errror output: not enough msgs\n");
			}
			if(to[from] == 255){
				printf("\n\n\n\ny = %lld\n\n\n\n", output);
				
			}else if(to[from] < 50){
				y[from] = output;
				oi[from] = 0;
				mailbox[ to[from] ][ finalmsg[to[from]]].i = 0;
				mailbox[to[from]][finalmsg[to[from]]].pos[0] = x[from];
				mailbox[to[from]][finalmsg[to[from]]].pos[1] = y[from];
				finalmsg[to[from]]++;
				if(finalmsg[to[from]] == 1000){
					finalmsg[to[from]] = 0;
				}
				if(to[from] == 23){
			printf("output = %lld, %lld\n", x[from], y[from]);
		}
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

void handelOutputPtTwo(long long output, bool end, int from){

	if(end){
		endPtTwo();
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
			
				//printf("1 %lld\n", output);
				
				
			x[from] = output;
			oi[from]++;
		}else if(oi[from] == 2){
			
				//printf("2 %lld\n", output);
				
				
			if((finalmsg[to[from]]%100 == 99 && nxtmsg[to[from]]%100 == 0) || finalmsg[to[from]] - nxtmsg[to[from]] == -1){
				printf("errror output: not enough msgs\n");
			}
			if(to[from] == 255){
				natY = output;
				printf("here out nat\n");
				oi[from] = 0;
				natX = x[from];
				
			}else if(to[from] < 50){
				y[from] = output;
				oi[from] = 0;
				mailbox[ to[from] ][ finalmsg[to[from]]].i = 0;
				mailbox[to[from]][finalmsg[to[from]]].pos[0] = x[from];
				mailbox[to[from]][finalmsg[to[from]]].pos[1] = y[from];
				finalmsg[to[from]]++;
				if(finalmsg[to[from]] == 1000){
					finalmsg[to[from]] = 0;
				}
				if(to[from] == 23){
			printf("output = %lld, %lld\n", x[from], y[from]);
		}
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

void handelOutput(long long output, int part, bool end, int from){
	if(part == 1){
		handelOutputPtOne(output, end, from);
	}else{
		handelOutputPtTwo(output, end, from);
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
	long long code[] = {3,62,1001,62,11,10,109,2229,105,1,0,703,1792,1586,775,1524,1856,1002,2058,1965,637,1930,1334,1262,2025,2196,744,1557,1615,1159,1460,1124,666,839,1759,971,1396,1093,1064,806,2163,1365,606,1730,2093,1644,1231,868,1033,1297,1825,901,571,1190,936,1994,1693,1491,2130,1427,1895,0,0,0,0,0,0,0,0,0,0,0,0,3,64,1008,64,-1,62,1006,62,88,1006,61,170,1106,0,73,3,65,20101,0,64,1,20102,1,66,2,21102,105,1,0,1106,0,436,1201,1,-1,64,1007,64,0,62,1005,62,73,7,64,67,62,1006,62,73,1002,64,2,133,1,133,68,133,102,1,0,62,1001,133,1,140,8,0,65,63,2,63,62,62,1005,62,73,1002,64,2,161,1,161,68,161,1102,1,1,0,1001,161,1,169,102,1,65,0,1101,0,1,61,1102,1,0,63,7,63,67,62,1006,62,203,1002,63,2,194,1,68,194,194,1006,0,73,1001,63,1,63,1105,1,178,21101,210,0,0,106,0,69,1202,1,1,70,1101,0,0,63,7,63,71,62,1006,62,250,1002,63,2,234,1,72,234,234,4,0,101,1,234,240,4,0,4,70,1001,63,1,63,1106,0,218,1106,0,73,109,4,21102,1,0,-3,21101,0,0,-2,20207,-2,67,-1,1206,-1,293,1202,-2,2,283,101,1,283,283,1,68,283,283,22001,0,-3,-3,21201,-2,1,-2,1106,0,263,21202,-3,1,-3,109,-4,2105,1,0,109,4,21101,0,1,-3,21102,1,0,-2,20207,-2,67,-1,1206,-1,342,1202,-2,2,332,101,1,332,332,1,68,332,332,22002,0,-3,-3,21201,-2,1,-2,1105,1,312,22101,0,-3,-3,109,-4,2106,0,0,109,1,101,1,68,358,21002,0,1,1,101,3,68,366,21002,0,1,2,21102,1,376,0,1106,0,436,22102,1,1,0,109,-1,2105,1,0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296,8589934592,17179869184,34359738368,68719476736,137438953472,274877906944,549755813888,1099511627776,2199023255552,4398046511104,8796093022208,17592186044416,35184372088832,70368744177664,140737488355328,281474976710656,562949953421312,1125899906842624,109,8,21202,-6,10,-5,22207,-7,-5,-5,1205,-5,521,21101,0,0,-4,21101,0,0,-3,21101,51,0,-2,21201,-2,-1,-2,1201,-2,385,471,20101,0,0,-1,21202,-3,2,-3,22207,-7,-1,-5,1205,-5,496,21201,-3,1,-3,22102,-1,-1,-5,22201,-7,-5,-7,22207,-3,-6,-5,1205,-5,515,22102,-1,-6,-5,22201,-3,-5,-3,22201,-1,-4,-4,1205,-2,461,1105,1,547,21102,-1,1,-4,21202,-6,-1,-6,21207,-7,0,-5,1205,-5,547,22201,-7,-6,-7,21201,-4,1,-4,1105,1,529,22101,0,-4,-7,109,-8,2106,0,0,109,1,101,1,68,564,20102,1,0,0,109,-1,2105,1,0,1101,75553,0,66,1102,3,1,67,1102,598,1,68,1101,302,0,69,1102,1,1,71,1102,1,604,72,1105,1,73,0,0,0,0,0,0,21,87573,1101,91453,0,66,1102,1,1,67,1102,1,633,68,1101,556,0,69,1102,1,1,71,1102,635,1,72,1105,1,73,1,261,7,49526,1102,1,29483,66,1101,0,1,67,1101,664,0,68,1101,0,556,69,1102,1,0,71,1101,666,0,72,1105,1,73,1,1321,1102,1,29191,66,1101,0,4,67,1101,0,693,68,1101,253,0,69,1101,0,1,71,1101,701,0,72,1106,0,73,0,0,0,0,0,0,0,0,1,99581,1102,31063,1,66,1102,1,1,67,1102,1,730,68,1101,0,556,69,1102,6,1,71,1102,732,1,72,1106,0,73,1,18402,13,11069,49,90473,49,271419,40,39887,40,79774,40,119661,1101,64579,0,66,1101,0,1,67,1102,1,771,68,1101,556,0,69,1101,0,1,71,1102,1,773,72,1105,1,73,1,389,7,24763,1102,1,60659,66,1102,1,1,67,1102,802,1,68,1101,0,556,69,1101,1,0,71,1101,804,0,72,1106,0,73,1,9467,41,75553,1102,1,59399,66,1101,2,0,67,1101,0,833,68,1101,302,0,69,1101,1,0,71,1102,837,1,72,1105,1,73,0,0,0,0,21,116764,1101,0,92857,66,1101,1,0,67,1101,0,866,68,1102,556,1,69,1102,1,0,71,1101,0,868,72,1105,1,73,1,1300,1102,1,3659,66,1101,2,0,67,1101,0,895,68,1101,0,302,69,1102,1,1,71,1101,0,899,72,1105,1,73,0,0,0,0,5,110914,1102,39887,1,66,1101,3,0,67,1101,0,928,68,1102,302,1,69,1101,1,0,71,1101,934,0,72,1105,1,73,0,0,0,0,0,0,38,76786,1102,1297,1,66,1102,1,3,67,1101,0,963,68,1102,1,302,69,1101,1,0,71,1102,969,1,72,1106,0,73,0,0,0,0,0,0,21,58382,1102,1,3187,66,1101,0,1,67,1101,998,0,68,1102,556,1,69,1101,0,1,71,1101,0,1000,72,1105,1,73,1,3,41,226659,1102,58763,1,66,1101,1,0,67,1102,1,1029,68,1101,556,0,69,1101,0,1,71,1101,1031,0,72,1105,1,73,1,4096,5,166371,1102,1,9851,66,1101,0,1,67,1101,1060,0,68,1101,556,0,69,1102,1,1,71,1101,1062,0,72,1106,0,73,1,13,5,55457,1102,1,100981,66,1101,0,1,67,1101,0,1091,68,1102,556,1,69,1101,0,0,71,1101,0,1093,72,1106,0,73,1,1601,1101,0,94169,66,1102,1,1,67,1102,1120,1,68,1102,556,1,69,1102,1,1,71,1102,1,1122,72,1106,0,73,1,36,43,2594,1102,38699,1,66,1102,1,3,67,1102,1,1151,68,1102,302,1,69,1101,0,1,71,1101,1157,0,72,1105,1,73,0,0,0,0,0,0,49,180946,1101,51061,0,66,1102,1,1,67,1102,1,1186,68,1102,1,556,69,1101,0,1,71,1102,1188,1,72,1105,1,73,1,409,43,3891,1102,1,68351,66,1101,6,0,67,1102,1,1217,68,1101,0,302,69,1101,0,1,71,1101,1229,0,72,1105,1,73,0,0,0,0,0,0,0,0,0,0,0,0,23,106562,1102,24359,1,66,1102,1,1,67,1101,1258,0,68,1102,556,1,69,1102,1,1,71,1101,0,1260,72,1106,0,73,1,256,1,199162,1101,26561,0,66,1102,1,3,67,1101,1289,0,68,1102,302,1,69,1101,1,0,71,1101,0,1295,72,1105,1,73,0,0,0,0,0,0,13,22138,1101,38393,0,66,1101,0,4,67,1101,0,1324,68,1102,253,1,69,1102,1,1,71,1101,0,1332,72,1105,1,73,0,0,0,0,0,0,0,0,23,53281,1102,1,1657,66,1102,1,1,67,1101,0,1361,68,1101,556,0,69,1101,0,1,71,1101,0,1363,72,1106,0,73,1,25189,46,2753,1102,67789,1,66,1102,1,1,67,1101,0,1392,68,1102,1,556,69,1101,1,0,71,1101,1394,0,72,1105,1,73,1,160,42,341755,1102,1,55967,66,1102,1,1,67,1102,1423,1,68,1101,556,0,69,1102,1,1,71,1101,0,1425,72,1106,0,73,1,17,12,79683,1102,70769,1,66,1102,2,1,67,1101,1454,0,68,1101,302,0,69,1101,0,1,71,1102,1,1458,72,1106,0,73,0,0,0,0,36,3659,1102,1,54577,66,1102,1,1,67,1102,1487,1,68,1101,556,0,69,1101,1,0,71,1102,1,1489,72,1105,1,73,1,125,33,63073,1102,2753,1,66,1102,2,1,67,1102,1,1518,68,1102,302,1,69,1102,1,1,71,1102,1522,1,72,1106,0,73,0,0,0,0,4,104369,1101,104369,0,66,1101,2,0,67,1101,1551,0,68,1101,0,302,69,1101,1,0,71,1102,1,1555,72,1105,1,73,0,0,0,0,48,70769,1102,1,57373,66,1102,1,1,67,1102,1584,1,68,1101,556,0,69,1101,0,0,71,1101,1586,0,72,1105,1,73,1,1767,1101,0,53891,66,1102,1,1,67,1101,1613,0,68,1102,556,1,69,1101,0,0,71,1101,1615,0,72,1105,1,73,1,1013,1102,1,14767,66,1102,1,1,67,1102,1642,1,68,1101,556,0,69,1101,0,0,71,1102,1644,1,72,1105,1,73,1,1657,1101,97177,0,66,1102,1,1,67,1102,1,1671,68,1102,556,1,69,1102,10,1,71,1102,1673,1,72,1106,0,73,1,1,46,5506,4,208738,48,141538,36,7318,43,1297,41,151106,47,9697,28,59399,7,74289,20,116097,1102,93371,1,66,1101,0,1,67,1101,0,1720,68,1102,1,556,69,1102,1,4,71,1102,1722,1,72,1105,1,73,1,2,5,221828,12,53122,42,68351,42,136702,1101,0,37589,66,1101,1,0,67,1101,1757,0,68,1101,0,556,69,1101,0,0,71,1101,0,1759,72,1106,0,73,1,1080,1102,53281,1,66,1102,1,2,67,1102,1786,1,68,1102,351,1,69,1101,1,0,71,1102,1790,1,72,1106,0,73,0,0,0,0,255,31063,1101,0,99581,66,1101,0,2,67,1101,1819,0,68,1102,302,1,69,1101,0,1,71,1101,1823,0,72,1106,0,73,0,0,0,0,12,26561,1101,0,51473,66,1101,1,0,67,1102,1852,1,68,1101,556,0,69,1102,1,1,71,1102,1,1854,72,1106,0,73,1,-18617,47,19394,1102,55457,1,66,1101,5,0,67,1101,0,1883,68,1102,1,302,69,1102,1,1,71,1101,1893,0,72,1106,0,73,0,0,0,0,0,0,0,0,0,0,38,38393,1102,90473,1,66,1102,3,1,67,1101,1922,0,68,1102,302,1,69,1101,1,0,71,1102,1,1928,72,1105,1,73,0,0,0,0,0,0,38,153572,1102,1,27191,66,1102,1,1,67,1102,1,1957,68,1101,556,0,69,1101,3,0,71,1102,1959,1,72,1106,0,73,1,5,33,126146,33,189219,42,273404,1102,30293,1,66,1102,1,1,67,1102,1,1992,68,1102,556,1,69,1101,0,0,71,1101,1994,0,72,1105,1,73,1,1647,1101,103867,0,66,1102,1,1,67,1101,0,2021,68,1101,0,556,69,1101,0,1,71,1101,2023,0,72,1106,0,73,1,-48,20,38699,1101,0,11069,66,1102,1,2,67,1102,2052,1,68,1102,302,1,69,1102,1,1,71,1102,1,2056,72,1106,0,73,0,0,0,0,38,115179,1101,24763,0,66,1101,0,3,67,1101,0,2085,68,1102,1,302,69,1102,1,1,71,1102,1,2091,72,1106,0,73,0,0,0,0,0,0,21,29191,1102,1,63073,66,1102,4,1,67,1102,1,2120,68,1102,302,1,69,1102,1,1,71,1101,2128,0,72,1105,1,73,0,0,0,0,0,0,0,0,42,410106,1102,1,9697,66,1101,2,0,67,1102,1,2157,68,1102,302,1,69,1102,1,1,71,1102,1,2161,72,1106,0,73,0,0,0,0,28,118798,1102,56671,1,66,1102,1,1,67,1102,1,2190,68,1102,1,556,69,1101,0,2,71,1102,1,2192,72,1105,1,73,1,719,5,277285,20,77398,1102,1,2683,66,1102,1,1,67,1102,1,2223,68,1101,0,556,69,1102,1,2,71,1102,2225,1,72,1106,0,73,1,10,33,252292,42,205053};
		
	int ii = 0;
	printf("here %lld\n", code[62]);
	fflush(stdout);
	while(ii < 50){
		printf("here");
		int ij = 0;
		while(ij < 2229){
			i[ii][ij] = code[ij];
			ij++;
		}
		ii++;
	}
	printf("hereccscwdeccsdcsdcs");
	fflush(stdout);
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
		printf("here");
		x[comp] = 0;
		relativeBase[comp] = 0;
		done[comp] = -1;
		comp++;
	}
	comp = 0;
	int fff = 0;
	while(!bigDone ){
	while(x[comp] < natMem && done[comp] == -1){
		
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
			x[comp] += 2;


		//terminate
		}else if(comand == 99){
			done[comp] = 0;
			printf("here\n");
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
	intCodeComputer(2);
	//For part Two to work change ardess 0 of i to 2
	//didn't find a clever way to find the paterns, i just ploted the scafolding in excel, 
	//found a big chunk tha was the same, wrote out the path and then found repeting 
	//comands and stitched them together
	//printf("\n\n\n\n\n\n\nPart Two:\n==============\n");
	//intCodeComputer(2);

	return 0;
}
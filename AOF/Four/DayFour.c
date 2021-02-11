#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void partOne(){
	int min = 134792;
	int max = 675810;
	int num = min;
	int pos = 0;
	while(num<=max){
		bool isValid = true;
		int i = 0;
		int in = num;
		while(i < 5){
			if(in%10 < in/10%10){
				isValid = false;
			}
			in = in/10;
			i++;
		}
		i = 0;
		bool try = false;
		in = num;
		while(i<6){
			if(in%10 == in/10%10){
				try = true;
			}
			in = in/10;
			i++;
		}
		if(try && isValid){
			pos++;
		}
		num++;		
	}
	printf("%d\n", pos);
}


void partTwo(){
	int min = 134792;
	int max = 675810;
	int num = min;
	int pos = 0;
	while(num<=max){
		bool isValid = true;
		int i = 0;
		int in = num;
		while(i < 5){
			if(in%10 < in/10%10){
				isValid = false;
			}
			in = in/10;
			i++;
		}
		i = 0;
		int numnum[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		bool try = false;
		in = num;
		while(i<6){
			numnum[in%10]++;
			in = in/10;
			i++;
		}
		i = 0;
		while(i<10){
			if(numnum[i] == 2){
				try = true;
			}
			i++;
		}
		if(try && isValid){
			pos++;
		}
		num++;		
	}
	printf("%d\n", pos);
}

int main(int argc, char* argv[]){
	partOne();
	partTwo();
	return 0;
}
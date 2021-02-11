#include <stdio.h>
#include <stdlib.h>

int calc(int w){
	if(w < 9){
	return 0;
	}else{
		return w/3 - 2 + calc(w/3 -2);
}
}


int main(int argc, char* argv[]) {
	int i = 1;
	int sum = 0;
	int mm = 0;
	while (i < argc) {
		char* ptr1 = 0;
		long n_l = strtol(argv[i], &ptr1, 10);//get the NR
		mm = ((int)n_l)/3 - 2;
		mm += calc(mm);
		sum += mm;
		i++;
	}
	printf("%d\n", sum);
	return sum;
}
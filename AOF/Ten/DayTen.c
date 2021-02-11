#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct slopes{
	int dx;
	int dy;
};

int gcd(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = a % b;

        a = b;
        b = temp;
    }
    return abs(a);
}



int findShot(int m[20][20], int x, int y, int num){
	printf("%d, %d\n", x, y);
	double angles[400];
	double oas[400];
	struct slopes s[400];
	struct slopes os[400];
	int i = 0;
	int shot = 0;
	while(i<400){
		oas[i] = 100;
		angles[i] = -500;
		s[i].dx = 100;
		os[i].dx = 100;
		i++;
	}
	i = 0;
	while(i<20){
		int j = 0;
		while(j<20){
			if(m[i][j] != 0 && !(i == x && j == y)){
				double ang;
				if(x == i){
					if(j - y > 0){
						ang = 3.1415926535/2;
					}else{
						ang = 3*3.1415926535/2;
					}
				}else{
					double slope =  (1.0*(y-j))/(i-x);
					ang = atan(slope);
					if(i-x > 0){
						ang += 3.1415926535;
					}
					if(ang < 0){
						ang = ang + 2 * 3.1415926535;
					}
				}
				int k = 0;
				while(k < 1000){
					if(angles[k] == ang){
						k = 1500;
					}else if(angles[k] == -500){
						//printf("%f\n", ang);						
						angles[k] = ang;
						int pdx = i-x;
						int pdy = j-y;
						s[k].dx = (i - x)/gcd(pdx, pdy);
						s[k].dy = (j - y)/gcd(pdx, pdy);						
						printf("%f, x = %d, y = %d\n", ang, s[k].dx, s[k].dy);						
						k = 1500;
					}
					k++;
				}
			}
			j++;
		}
		i++;
	}

	double min = 100;
	int minI = 0;
	i = 0;
	while(i < 214){
		
		int j = 0;
		min = 100;
		while(j<400){
			if(min > angles[j] && angles[j] > -1){
				min = angles[j];
				minI = j;
			}
			j++;
		}
		if(min < 50){
			oas[i] = min;
			os[i] = s[minI];
			angles[minI] = 200;
		}
		i++;
	}

	i = 0;
	while(i<400){
		if(os[i].dx == 100){
			i = 800;
		}else{
			printf("\t\t%d, %d\n", os[i].dx, os[i].dy);
		}
		i++;
	}
	int destroyed = 0;
	i = 0;
	int h = 0;
	int j = 1;
	while(i<400 && h < 400){
		if(oas[i] == 100){
			printf("here\n");
			i = -1;
		}else{
			j = 1;
			bool done = false;
			while(!done){
				if(j*os[i].dx + x > 20 || j*os[i].dy + y > 20 || j*os[i].dx + x < 0 || j*os[i].dy + y < 0){
					done = true;
				}else if(m[j*os[i].dx + x][j*os[i].dy + y] != 0){
					m[j*os[i].dx + x][j*os[i].dy + y] = 0;
					destroyed++;
					printf("%d\n", i);
					printf("%d, %d, num = %d\n", j*os[i].dx + x, j*os[i].dy + y, destroyed);
					done = true;
				}else{
					j++;
				}
			}
			if(destroyed == num){
				return j*os[i].dx + x * 100 + j*os[i].dy + y;
			}
		}
		i++;
		h++;
	}
	return shot;
}



















int howMany(int m[20][20], int x, int y){
	printf("%d, %d", x, y);
	double angles[400];
	int i = 0;
	int wieViel = 0;
	while(i<400){
		angles[i] = -500;
		i++;
	}
	i = 0;
	while(i<20){
		int j = 0;
		while(j<20){
			if(m[i][j] != 0 && !(i == x && j == y)){
				double ang;
				if(j == y){
					if(i - x > 0){
						ang = 400;
					}else{
						ang = 420;
					}
				}else{
					ang =  (1.0*(i-x))/(j-y);
					if(i-x == 0 && j-y > 0){
						ang += 700;
					}else if(i-x > 0){
						ang += 700;
					}
				}
				int k = 0;
				while(k < 1000){
					if(angles[k] == ang){
						k = 1500;
					}else if(angles[k] == -500){						
						angles[k] = ang;
						wieViel++;
						k = 1500;
					}
					k++;
				}
			}
			j++;
		}
		i++;
	}
	return wieViel;
}

void partOne(){
	int m[20][20];
	FILE* fp = fopen("input.txt", "r");
	if(fp == false){
		printf("bad file");
		return;
	}
	bool done = false;
	char str[256];
	int i = 0;
	while(!done){
		str[0] = '\0';
		fscanf(fp, "%s", str);
		if(strlen(str) > 0){
			int j = 0;
			while(j<20){
				if(str[j] == '.'){
					m[i][j] = 0;
				}else{
					m[i][j] = 1;
				}
				j++;
			}
			i++;
		}else{
			done = true;
			fclose(fp);
		}
	}
	int y = 0;
	int z = 0;
	while(y<20){
		z = 0;
		while(z<20){
			if(m[y][z] == 1){
				m[y][z] = howMany(m, y, z);
			}else{
			}
			z++;
		}
		printf("\n");
		y++;
	}
	y = 0;
	z = 0;
	int max = 0;
	int maxX = 0;
	int maxY = 0;
	while(y<20){
		z = 0;
		while(z<20){
			if(m[y][z] > max){
				max = m[y][z];
				maxX = y;
				maxY = z;
			}
			printf("%d ", m[y][z]);
			z++;
		}
		printf("\n");
		y++;
	}
	printf("max = %d @ %d,%d\n", max, maxX, maxY);
}

void partTwo(){
	int m[20][20];
	FILE* fp = fopen("input.txt", "r");
	if(fp == false){
		printf("bad file");
		return;
	}
	bool done = false;
	char str[256];
	int i = 0;
	while(!done){
		str[0] = '\0';
		fscanf(fp, "%s", str);
		if(strlen(str) > 0){
			int j = 0;
			while(j<20){
				if(str[j] == '.'){
					m[i][j] = 0;
				}else{
					m[i][j] = 1;
				}
				j++;
			}
			i++;
		}else{
			done = true;
			fclose(fp);
		}
	}
	int result = findShot(m, 16, 8, 400);
	//int result = findShot(m, 3, 4, 3);
	printf("result = %d\n", result);
}

int main(int argc, char* argv[]){
	partOne();
	partTwo();
	return 0;
}
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

struct point{
	int x;
	int y;	
};

struct point findExit(int x, int y, char map[127][256]){
	int xo = x;
	int yo = y;
	int xt = 0;
	int yt = 0;
	char one = map[xo][yo];
	struct point p;
	if(isalpha(map[x+1][y])){
		xt = x+1;
		yt = y;
	}else if(isalpha(map[x-1][y])){
		xt = x-1;
		yt = y;
	}else if(isalpha(map[x][y+1])){
		xt = x;
		yt = y+1;
	}else if(isalpha(map[x][y-1])){
		xt = x;
		yt = y-1;
	}else{
		printf("\n\n\n\nerror\n"); 
	}

	char two = map[xt][yt];

	if(map[xo][yo] == 'Z' && map[xt][yt] == 'Z'){
		//printf("\n\n\n\n\nend\n");
		p.x = -1;
		p.y = -1;
		return p;
	}else{
		int i = 0;
		while(i < 127){
			int j = 0;
			while(j<256){
				if(map[i][j] == one && i != x && j != y){
					if(map[i+1][j] == two || map[i-1][j] == two){
						if(i == 1 || i == 0){
							p.x = 2;
						}else if(i == 125 || i == 126){
							p.x = 124;
						}else if(map[i+1][j] == '.'){
							p.x = i+1;
						}else if(map[i+2][j] == '.'){
							p.x = i+2;
						}else if(map[i-1][j] == '.'){
							p.x = i-1;
						}else if(map[i-2][j] == '.'){
							p.x = i-2;
						}
						p.y = j;
					}else if(map[i][j+1] == two || map[i][j-1] == two){
						if(j == 1 || j == 0){
							p.y = 2;
						}else if(j == 122 || j == 123){
							p.y = 121;
						}else if(map[i][j+1] == '.'){
							p.y = j+1;
						}else if(map[i][j+2] == '.'){
							p.y = j+2;
						}else if(map[i][j-1] == '.'){
							p.y = j-1;
						}else if(map[i][j-2] == '.'){
							p.y = j-2;
						}
						p.x = i;
					}
				}
				j++;
			}
			i++;
		}
	}
	//printf("return %d %d\n", p.x, p.y);
	return p;
	
}

void partOne(){
	FILE* fp = fopen("input.txt", "r");
	if(fp == false){
		printf("bad file");
		return;
	}
	bool done = false;
	char map[127][256];
	int mapInt[127][125];
	char str[256];
	int i = 0;
	while(!done){
		str[0] = '\0';
		fscanf(fp, "%s", str);
		if(strlen(str) > 0){
			strcpy(map[i], str);
			int j = 0;
			while(j<125){
				if(str[j] == '.'){
					mapInt[i][j] = 10000;
				}else if(isalpha(str[j])){
					mapInt[i][j] = -123456;
				}else{
					mapInt[i][j] = -1;
				}
				j++;
			}
			i++;
		}else{
			done = true;
			fclose(fp);
		}
	}

	mapInt[83][0] = -1;
	mapInt[83][1] = -1;
	mapInt[83][2] = 0;
	int numSteps = 10000;
	done = false;
	int w = 0;
	while(!done && w < 90){
		printf("here aaaaa\n");
		i = 0;
		while(i < 127){
			int j = 0;	
			while(j<125){
				if(mapInt[i][j] != -123456 && mapInt[i][j] != -1 && mapInt[i][j] != 10000){
					if(mapInt[i+1][j] > mapInt[i][j] + 1){
						mapInt[i+1][j] = mapInt[i][j] + 1;
					}
					if(mapInt[i+1][j] == -123456){
						//printf("here\n");
						struct point p = findExit(i+1, j, map);
						if(p.x == -1){
							if(numSteps>mapInt[i][j] + 1){
								numSteps = mapInt[i][j] + 1;
							}					
						}else if(mapInt[p.x][p.y] > mapInt[i][j] + 1){
							mapInt[p.x][p.y] = mapInt[i][j] + 1;
						}
					}
					
					if(mapInt[i-1][j] > mapInt[i][j] + 1){
						mapInt[i-1][j] = mapInt[i][j] + 1;
					}
					if(mapInt[i-1][j] == -123456){
						//printf("here\n");
						struct point p = findExit(i-1, j, map);
						if(p.x == -1){
							if(numSteps>mapInt[i][j] + 1){
								numSteps = mapInt[i][j] + 1;
							}					
						}else if(mapInt[p.x][p.y] > mapInt[i][j] + 1){
							mapInt[p.x][p.y] = mapInt[i][j] + 1;
						}
					}
					
					if(mapInt[i][j+1] > mapInt[i][j] + 1){
						//printf("here\n");
						mapInt[i][j+1] = mapInt[i][j] + 1;
					}
					if(mapInt[i][j+1] == -123456){
						//printf("here\n");
						struct point p = findExit(i, j+1, map);
						if(p.x == -1){
							if(numSteps>mapInt[i][j] + 1){
								numSteps = mapInt[i][j] + 1;
							}					
						}else if(mapInt[p.x][p.y] > mapInt[i][j] + 1){
							mapInt[p.x][p.y] = mapInt[i][j] + 1;
						}
					}
					
					
					if(mapInt[i][j-1] > mapInt[i][j] + 1){
						mapInt[i][j-1] = mapInt[i][j] + 1;
					}
					if(mapInt[i][j-1] == -123456){
						//printf("here\n");
						struct point p = findExit(i, j-1, map);
						if(p.x == -1){
							if(numSteps>mapInt[i][j] + 1){
								numSteps = mapInt[i][j] + 1;
							}					
						}else if(mapInt[p.x][p.y] > mapInt[i][j] + 1){
							mapInt[p.x][p.y] = mapInt[i][j] + 1;
						}
					}

	
				}
				j++;
			}
			
			i++;
		}

if(w == -3){
int ia = 0;
		while(ia < 127){
			int ja = 0;	
			while(ja<125){
				printf("%d", abs(mapInt[ia][ja])%10);
				ja++;
			}
			printf("\n");
			ia++;
		}

printf("\n\n\n\n");
}
		bool complete = true;
		int r = 0;
		i = 126;
		while(i > -1){
			int j = 124;	
			while(j > -1){
				if(mapInt[i][j] == 10000){
					if(w == 89){
					printf("\n\n\nfalse %d %d\n\n\n", i, j);
					}
					complete = false;
				}
				if(mapInt[i][j] != -123456 && mapInt[i][j] != -1 && mapInt[i][j] != 10000){
					if(mapInt[i+1][j] > mapInt[i][j] + 1){
						if(r == 1){
						//printf("herea %d %d\n", mapInt[i][j],mapInt[i+1][j]);
						}
						mapInt[i+1][j] = mapInt[i][j] + 1;
					}
					if(mapInt[i+1][j] == -123456){
						//printf("herea\n");
						struct point p = findExit(i+1, j, map);
						if(p.x == -1){
							if(numSteps>mapInt[i][j] + 1){
								numSteps = mapInt[i][j] + 1;
							}					
						}else if(mapInt[p.x][p.y] > mapInt[i][j] + 1){
							//printf("here\n");
							mapInt[p.x][p.y] = mapInt[i][j] + 1;
						}
	/*					
int ia = 0;
		while(ia < 127){
			int ja = 0;	
			while(ja<125){
				printf("%d", abs(mapInt[ia][ja])%10);
				ja++;
			}
			printf("\n");
			ia++;
		}
r = 1;
*/

					}
					

					if(mapInt[i-1][j] > mapInt[i][j] + 1){
						mapInt[i-1][j] = mapInt[i][j] + 1;
						if(r == 1){
							printf("hereb\n");
						}
					}
					if(mapInt[i-1][j] == -123456){
						//printf("hereb\n");
						struct point p = findExit(i-1, j, map);
						if(p.x == -1){
							if(numSteps>mapInt[i][j] + 1){
								numSteps = mapInt[i][j] + 1;
							}					
						}else if(mapInt[p.x][p.y] > mapInt[i][j] + 1){
							mapInt[p.x][p.y] = mapInt[i][j] + 1;
						}
					}
					
					
					if(mapInt[i][j+1] > mapInt[i][j] + 1){
						mapInt[i][j+1] = mapInt[i][j] + 1;
						if(r == 1){
						//printf("herec\n");
						}
					}
					if(mapInt[i][j+1] == -123456){
						//printf("herec\n");
						struct point p = findExit(i, j+1, map);
						if(p.x == -1){
							if(numSteps>mapInt[i][j] + 1){
								numSteps = mapInt[i][j] + 1;	
							}				
						}else if(mapInt[p.x][p.y] > mapInt[i][j] + 1){
							mapInt[p.x][p.y] = mapInt[i][j] + 1;
						}
					}

					if(mapInt[i][j-1] > mapInt[i][j] + 1){
						mapInt[i][j-1] = mapInt[i][j] + 1;
						if(r == 1){
						//printf("hered\n");
						}
					}
					if(mapInt[i][j-1] == -123456){
						//printf("hered %d\n",  mapInt[i][j]);
						struct point p = findExit(i, j-1, map);
						if(p.x == -1){
							if(numSteps>mapInt[i][j] + 1){
								numSteps = mapInt[i][j] + 1;	
							}				
						}else if(mapInt[p.x][p.y] > mapInt[i][j] + 1){
							mapInt[p.x][p.y] = mapInt[i][j] + 1;
							//printf("hered %d\n",  mapInt[p.x][p.y]);
						}
					}


/*
if(r == 2){
					int ia = 0;
		while(ia < 127){
			int ja = 0;	
			while(ja<125){
				printf("%d", abs(mapInt[ia][ja])%10);
				ja++;
			}
			printf("\n");
			ia++;
		}
	r = 3;
}


if(r == 1){
					int ia = 0;
		while(ia < 127){
			int ja = 0;	
			while(ja<125){
				printf("%d", abs(mapInt[ia][ja])%10);
				ja++;
			}
			printf("\n");
			ia++;
		}
	r = 2;
}
*/
				}
				j--;
			}
			
			i--;
		}
		done = complete;
		w++;
	}


	i = 0;
		while(i < 127){
			int j = 0;	
			while(j<125){
				if(mapInt[i][j] == -1){
					printf("#");
				}else{
					printf("%d", abs(mapInt[i][j])%10);
				}
				j++;
			}
			printf("\n");
			i++;
		}
	if(done){
		printf("%d\n", numSteps);
}
	

}


int main(int argc, char* argv[]){
	partOne();
	return 0;
}
import java.util.HashMap;

public class DayTwelve {
	
	public static void axisThree(){
		HashMap<String, Boolean> h = new HashMap<String, Boolean>();
		boolean w = true;
		int[][] pos = {
				{14},
				{12},
				{1},
				{16}};
		int[][] startpos = {
				{5},
				{8},
				{10},
				{3}};
		/*
		 * int[][] pos = {
				{5},
				{8},
				{-10},
				{3}};
		int[][] pos = {
				{5},
				{8},
				{10},
				{3}};
		int[][] startpos = {
				{5},
				{8},
				{10},
				{3}};
		
		
		
		int[][] pos = {
				{4, 1, 1},
				{6, 1, 1},
				{1, 10, 1},
				{1, 1, 1}};
		
		int[][] startpos = {
				{4, 1, 1},
				{6, 1, 1},
				{1, 10, 1},
				{1, 1, 1}};
		*/
		int[][] vel = {
				{0},
				{0},
				{0},
				{0}};
		int[][] startvel = {
				{0},
				{0},
				{0},
				{0}};
		int time = 0;
		while(time>-1){
			int moona = 0;
			while(moona < 4){
				int moonb = moona + 1;
				while(moonb < 4){
					int i = 0;
					while(i<1){
						if(pos[moona][i] > pos[moonb][i]){
							vel[moona][i]--;
							vel[moonb][i]++;
						}else if(pos[moona][i] < pos[moonb][i]){
							vel[moona][i]++;
							vel[moonb][i]--;
						}
						i++;
					}
					moonb++;
				}
				moona++;
			}
			int i = 0;
			while(i<4){
				int j = 0;
				while(j<1){
					pos[i][j] += vel[i][j];
					//System.out.print(pos[i][j]);
					j++;
				}
				//System.out.print("\n");
				i++;
			}
			//System.out.print("\n");
			i = 0;
			String name = "";
			while(i<4){
				name = name + pos[i][0] + "," + vel[i][0] + ",";
				i++;
			}
			Boolean b = h.get(name);
			if(b!=null && w){
				System.out.println(time);
				int x = 0;
				while(x<4){
					startpos[x][0] = pos[x][0];
					startvel[x][0] = vel[x][0];
					x++;
				}
				time = 0;
				w = false;
			}else if(!w){
				int x = 0;
				boolean t = true;
				while(x<4){
					if(startpos[x][0] != pos[x][0] || startvel[x][0] != vel[x][0]){
						t = false;
					}
					x++;
				}
				if(t){
					System.out.println(time);
					time = -10;
				}
			}else{
				h.put(name, true);
			}
			
			
			time++;
		}
	}
	
	
	public static void axisTwo(){
		HashMap<String, Boolean> h = new HashMap<String, Boolean>();
		boolean w = true;
		int[][] pos = {
				{4},
				{10},
				{7},
				{-5}};
		int[][] startpos = {
				{4},
				{10},
				{7},
				{-5}};
		
		
		/*
		int[][] pos = {
				{4},
				{10},
				{7},
				{-5}};
		int[][] startpos = {
				{4},
				{10},
				{7},
				{-5}};
		/*
		int[][] pos = {
				{4, 1, 1},
				{6, 1, 1},
				{1, 10, 1},
				{1, 1, 1}};
		
		int[][] startpos = {
				{4, 1, 1},
				{6, 1, 1},
				{1, 10, 1},
				{1, 1, 1}};
		*/
		int[][] vel = {
				{0},
				{0},
				{0},
				{0}};
		int[][] startvel = {
				{0},
				{0},
				{0},
				{0}};
		int time = 0;
		while(time>-1){
			int moona = 0;
			while(moona < 4){
				int moonb = moona + 1;
				while(moonb < 4){
					int i = 0;
					while(i<1){
						if(pos[moona][i] > pos[moonb][i]){
							vel[moona][i]--;
							vel[moonb][i]++;
						}else if(pos[moona][i] < pos[moonb][i]){
							vel[moona][i]++;
							vel[moonb][i]--;
						}
						i++;
					}
					moonb++;
				}
				moona++;
			}
			int i = 0;
			while(i<4){
				int j = 0;
				while(j<1){
					pos[i][j] += vel[i][j];
					//System.out.print(pos[i][j]);
					j++;
				}
				//System.out.print("\n");
				i++;
			}
			//System.out.print("\n");
			i = 0;
			String name = "";
			while(i<4){
				name = name + pos[i][0] + "," + vel[i][0] + ",";
				i++;
			}
			Boolean b = h.get(name);
			if(b!=null && w){
				System.out.println(time);
				int x = 0;
				while(x<4){
					startpos[x][0] = pos[x][0];
					startvel[x][0] = vel[x][0];
					x++;
				}
				time = 0;
				w = false;
			}else if(!w){
				int x = 0;
				boolean t = true;
				while(x<4){
					if(startpos[x][0] != pos[x][0] || startvel[x][0] != vel[x][0]){
						t = false;
					}
					x++;
				}
				if(t){
					System.out.println(time);
					time = -10;
				}
			}else{
				h.put(name, true);
			}
			
			time++;
		}
	}
	
	
	public static void axisOne(){
		HashMap<String, Boolean> h = new HashMap<String, Boolean>();
		boolean w= true;
		int[][] pos = {
				{5},
				{8},
				{-10},
				{3}};
		int[][] startpos = {
				{14},
				{12},
				{1},
				{16}};
		
		/*
		 * int[][] pos = {
				{14},
				{12},
				{1},
				{16}};
		 *
		int[][] pos = {
				{14},
				{12},
				{1},
				{16}};
		int[][] startpos = {
				{14},
				{12},
				{1},
				{16}};
		
		/*
		int[][] pos = {
				{4, 1, 1},
				{6, 1, 1},
				{1, 10, 1},
				{1, 1, 1}};
		
		int[][] startpos = {
				{4, 1, 1},
				{6, 1, 1},
				{1, 10, 1},
				{1, 1, 1}};
		*/
		int[][] vel = {
				{0},
				{0},
				{0},
				{0}};
		
		int[][] startvel = {
				{0},
				{0},
				{0},
				{0}};
		int time = 0;
		while(time>-1){
			int moona = 0;
			while(moona < 4){
				int moonb = moona + 1;
				while(moonb < 4){
					int i = 0;
					while(i<1){
						if(pos[moona][i] > pos[moonb][i]){
							vel[moona][i]--;
							vel[moonb][i]++;
						}else if(pos[moona][i] < pos[moonb][i]){
							vel[moona][i]++;
							vel[moonb][i]--;
						}
						i++;
					}
					moonb++;
				}
				moona++;
			}
			int i = 0;
			while(i<4){
				int j = 0;
				while(j<1){
					pos[i][j] += vel[i][j];
					//System.out.print(pos[i][j]);
					j++;
				}
				//System.out.print("\n");
				i++;
			}
			//System.out.print("\n");
			i = 0;
			String name = "";
			while(i<4){
				name = name + pos[i][0] + "," + vel[i][0] + ",";
				i++;
			}
			Boolean b = h.get(name);
			if(b!=null && w){
				System.out.println(time);
				int x = 0;
				while(x<4){
					startpos[x][0] = pos[x][0];
					startvel[x][0] = vel[x][0];
					x++;
				}
				w = false;
				time = 0;
			}else if(!w){
				int x = 0;
				boolean t = true;
				while(x<4){
					if(startpos[x][0] != pos[x][0] || startvel[x][0] != vel[x][0]){
						t = false;
					}
					x++;
				}
				if(t){
					System.out.println(time);
					time = -10;
				}
			}else{
				h.put(name, true);
			}
			
			
			
			
			time++;
		}
	}
	
	public static void main(String[] args) {
		axisOne();
		axisTwo();
		axisThree();
		

	}

}

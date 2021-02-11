import java.io.File;
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.PriorityQueue;
import java.util.Scanner;

public class DayEighteen {
	public static int height = 0;
	public static int width = 0;
	public static int numKeys = 0;
	public static Hashtable<String, Node> nodes = new Hashtable<String, Node>();
	public static ArrayList<Node> nodesArry = new ArrayList<Node>();
	public static Node StartNode;
	
	public static void makeGraph(){
		File f = new File("DayEighteenInput.txt"); 
		try{
			Scanner scan = new Scanner(f); 
			String lines[] = new String[150];
			int i = 0;
			//get the lines
			while (scan.hasNextLine()){ 
					 lines[i] = scan.nextLine();
					 if(lines[i].length() > width){
						 width = lines[i].length();
					 }
				     i++;
			}
			height = i;
			
			
			
			//get the map
			char map[][] = new char[height][width];
			scan.close();
			int starti = 0;
			int startj = 0;
			i = 0;
			while(i < height){
				//System.out.println(lines[i]);
				int j = 0;
				while(j<width){
					map[i][j] = lines[i].charAt(j);
					if(map[i][j] == '@'){
						starti = i;
						startj = j;
					}
					j++;
				}
				i++;
			}
			
			
			
			//get all the nodes
			//System.out.println("\n\n\n");
			i = 1;
			int numNodes = 0;
			while(i < height - 1){
				int j = 1;
				while(j < width - 1){
					int numPaths = 0;
					if(map[i+1][j] != '#'){
						numPaths++;
						
					}
					if(map[i-1][j] != '#'){
						numPaths++;
						
					}
					if(map[i][j+1] != '#'){
						numPaths++;
						
					}
					if(map[i][j-1] != '#'){
						numPaths++;
						
					}
					if(map[i][j] == '.' && numPaths != 2){
						Node n = new Node("^:" + i + "," + j, numPaths);
						nodes.put(i + "," + j, n);
						nodesArry.add(n);
						numNodes++;
						//System.out.println(i + ", " + j);
					}else if(map[i][j] == '@'){
						StartNode = new Node("^:" + i + "," + j, numPaths);
						nodes.put(i + "," + j, StartNode);
						nodesArry.add(StartNode);
						numNodes++;
						//System.out.println(i + ", " + j);
					}else if(Character.isLetter(map[i][j])){
						Node n = new Node(map[i][j] + ":" + i + "," + j, numPaths);
						nodes.put(i + "," + j, n);
						nodesArry.add(n);
						numNodes++;
						if(Character.isLowerCase(map[i][j])){
							numKeys++;
						}
						//System.out.println(i + ", " + j);
					}
					j++;
				}
				i++;
			}
			//System.out.println(numNodes);
			
			
			//connect the nodes
			i = 1;
			while(i < height - 1){
				int j = 1;
				while(j < width - 1){
					if(nodes.containsKey(i + "," + j)){
						//we found a node need to connect it
						if(map[i+1][j] != '#'){
							int direc = 0;
							boolean done = false;
							int mi = i+1;
							int mj = j;
							int numMoves = 1;
							while(!done){
								if(nodes.containsKey(mi + "," + mj)){
									nodes.get(i + "," + j).addNeighbor(nodes.get(mi + "," + mj), numMoves);
									done = true;
								}else{
									if(map[mi+1][mj] != '#' && direc != 1){
										mi++;
										direc = 0;
									}else if(map[mi-1][mj] != '#' && direc != 0){
										mi--;
										direc = 1;
									}else if(map[mi][mj+1] != '#' && direc != 3){
										mj++;
										direc = 2;										
									}else if(map[mi][mj-1] != '#' && direc != 2){
										mj--;
										direc = 3;
									}
								}
								numMoves++;
							}
							
							
						}
						if(map[i-1][j] != '#'){
							int direc = 1;
							boolean done = false;
							int mi = i-1;
							int mj = j;
							int numMoves = 1;
							while(!done){
								if(nodes.containsKey(mi + "," + mj)){
									nodes.get(i + "," + j).addNeighbor(nodes.get(mi + "," + mj), numMoves);
									done = true;
								}else{
									if(map[mi+1][mj] != '#' && direc != 1){
										mi++;
										direc = 0;
									}else if(map[mi-1][mj] != '#' && direc != 0){
										mi--;
										direc = 1;
									}else if(map[mi][mj+1] != '#' && direc != 3){
										mj++;
										direc = 2;										
									}else if(map[mi][mj-1] != '#' && direc != 2){
										mj--;
										direc = 3;
									}
									numMoves++;
								}
							}
							
						}
						if(map[i][j+1] != '#'){
							int direc = 2;
							boolean done = false;
							int mi = i;
							int mj = j+1;
							int numMoves = 1;
							while(!done){
								if(nodes.containsKey(mi + "," + mj)){
									nodes.get(i + "," + j).addNeighbor(nodes.get(mi + "," + mj), numMoves);
									done = true;
								}else{
									if(map[mi+1][mj] != '#' && direc != 1){
										mi++;
										direc = 0;
									}else if(map[mi-1][mj] != '#' && direc != 0){
										mi--;
										direc = 1;
									}else if(map[mi][mj+1] != '#' && direc != 3){
										mj++;
										direc = 2;										
									}else if(map[mi][mj-1] != '#' && direc != 2){
										mj--;
										direc = 3;
									}
								}
								numMoves++;
							}
							
						}
						if(map[i][j-1] != '#'){
							int direc = 3;
							boolean done = false;
							int mi = i;
							int mj = j-1;
							int numMoves = 1;
							while(!done){
								if(nodes.containsKey(mi + "," + mj)){
									nodes.get(i + "," + j).addNeighbor(nodes.get(mi + "," + mj), numMoves);
									done = true;
								}else{
									if(map[mi+1][mj] != '#' && direc != 1){
										mi++;
										direc = 0;
									}else if(map[mi-1][mj] != '#' && direc != 0){
										mi--;
										direc = 1;
									}else if(map[mi][mj+1] != '#' && direc != 3){
										mj++;
										direc = 2;										
									}else if(map[mi][mj-1] != '#' && direc != 2){
										mj--;
										direc = 3;
									}
								}
								numMoves++;
							}
							
							
						}
						
						
						
						
						
					}
					
					
					
					j++;
				}
				i++;
			}
			//System.out.println("\n\n" + StartNode);
			
			
			
		}catch(Exception e){
			
		}
	}
	
	public static void findPath(){
		Path startPath = new Path();
		startPath.startNode = StartNode;
		PriorityQueue<Path> paths = new PriorityQueue<Path>();
		PriorityQueue<Path> corners = new PriorityQueue<Path>();
		
		
		//find the first keys
		corners.add(startPath);
		while(!corners.isEmpty()){
			Path curPath = corners.remove();
			if(Character.isUpperCase(curPath.startNode.name.charAt(0)) || curPath.startNode.visited){
				
			}else{
				int i = 0;
				while(i < curPath.startNode.neighbors.size()){
					if(!curPath.startNode.neighbors.get(i).visited){
						Path newCorner = new Path();
						newCorner.startNode = curPath.startNode.neighbors.get(i);
						newCorner.numSteps = curPath.startNode.values.get(i) + curPath.numSteps;
						corners.add(newCorner);
					}
					i++;
				}
				
				if(Character.isLowerCase(curPath.startNode.name.charAt(0))){
					Path newPath = new Path();
					newPath.startNode = curPath.startNode;
					newPath.numSteps = curPath.numSteps;
					newPath.addFlags(curPath.flags);
					newPath.addFlag(curPath.startNode.name.charAt(0));
					paths.add(newPath);
				}
				
			}
			
			
			
			curPath.startNode.visited = true;
		}
		
		
		//find shortest path
		boolean done = false;
		while(!paths.isEmpty() && !done){
			unvisitNodes();
			Path curPathBig = paths.remove();
			corners.add(curPathBig);
			if(curPathBig.hasAllKeys(numKeys)){
				done = true;
				System.out.println("we found all the keyes in " + curPathBig.numSteps + " number of steps");
				curPathBig.printflags();
			}
			
			while(!corners.isEmpty() && !done){
				Path curPath = corners.remove();
				//you can not go further if a) you are at a gate and you dont have the key or b) you already visited the node
				if((Character.isUpperCase(curPath.startNode.name.charAt(0)) &&  !curPathBig.hasKey(curPath.startNode.name.charAt(0)) )|| curPath.startNode.visited){
					
				}else{
					int i = 0;
					while(i < curPath.startNode.neighbors.size()){
						if(!curPath.startNode.neighbors.get(i).visited){
							Path newCorner = new Path();
							newCorner.startNode = curPath.startNode.neighbors.get(i);
							newCorner.numSteps = curPath.startNode.values.get(i) + curPath.numSteps;
							corners.add(newCorner);
						}
						i++;
					}
					//if it is a key and we dont allready have it
					if(Character.isLowerCase(curPath.startNode.name.charAt(0)) && !curPathBig.hasKey(Character.toUpperCase(curPath.startNode.name.charAt(0)))){
						Path newPath = new Path();
						newPath.startNode = curPath.startNode;
						newPath.numSteps = curPath.numSteps;
						newPath.addFlags(curPathBig.flags);
						newPath.addFlag(curPath.startNode.name.charAt(0));
						paths.add(newPath);
					}
					
				}
				
				
				
				curPath.startNode.visited = true;
			}
			
			
			
			//System.out.print(curPathBig.startNode.name + ": " + curPathBig.numSteps + ": ");
			curPathBig.printflags();
		}
		
		
	}
	

	public static void unvisitNodes() {
		int i = 0;
		while(i < nodesArry.size()){
			nodesArry.get(i).visited = false;
			i++;
		}
	}

	public static void main(String[] args) {
		makeGraph();
		//findPath();

	}

}

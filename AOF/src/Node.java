import java.util.ArrayList;

public class Node {
	public String name;
	public Boolean printed;
	public Boolean visited;
	public int numN;
	public int curN;
	public ArrayList<Node> neighbors = new ArrayList<Node>(8);
	public ArrayList<Integer> values = new ArrayList<Integer>(8);
	
	public Node(){
		
	}
	
	public Node(String n, int ns){
		name = n;
		printed = false;
		numN = ns;
		curN = 0;
		visited = false;
	}
	
	public void addNeighbor(Node n, int v){
		neighbors.add(n);
		values.add(v);
		curN++;
	}
	
	@Override
	public String toString(){
		printed = true;
		String ret = name;
		int i = 0;
		while(i<neighbors.size()){
			ret = ret + "\n\t" + neighbors.get(i).name + ": " + values.get(i);
			i++;
		}
		ret = ret + "\n\n";
		i = 0;
		while(i<neighbors.size()){
			if(!neighbors.get(i).printed){
				ret = ret + neighbors.get(i).toString();
			}
			i++;
		}
		
		return ret;
		
	}
	
}


public class Path implements Comparable<Path>{
	public int numSteps;
	public char flags[];
	public Node startNode;
	
	public Path(){
		flags = null;
		numSteps = 0;
	}
	
	public void addFlags(char fs[]){
		if(fs != null){
		flags = fs.clone();
		}
	}
	
	public void addFlag(char f){
		int s = 0;
		if(flags == null){
			s = 1;
		}else{
			s = flags.length+1;
		}
		char nfs[] = new char[s];
		int i = 0;
		while(i<s-1){
			nfs[i] = flags[i];
			i++;
		}
		nfs[i] = f;
		flags = nfs;
	}
	
	public void printflags(){
		int i = 0;
		while(i<flags.length){
			System.out.print(flags[i] + " ");
			i++;
		}
		System.out.print("\n");
	}

	@Override
	public int compareTo(Path arg0) {
		int fl = 0;
		if(flags == null){
			fl = 1;
		}else{
			fl = flags.length;
		}
		
		int flo = 0;
		if(arg0.flags == null){
			flo = 1;
		}else{
			flo = arg0.flags.length;
		}
		
			return this.numSteps - arg0.numSteps;
		
	}
    //   a b c d e f g h i j k l m n o p q r s t u v w x y z
	public boolean hasKey(char gate) {
		boolean foundKey = false;
		int i = 0;
		int fl = 0;
		if(flags == null){
			fl = 0;
		}else{
			fl = flags.length;
		}
		
		while(i < fl){
			if(Character.toUpperCase(flags[i]) == gate){
				foundKey = true;
				i = fl;
			}
			i++;
		}
		return foundKey;
	}

	public boolean hasAllKeys(int numKeys) {
		return flags != null && flags.length == numKeys;
	}
	
}

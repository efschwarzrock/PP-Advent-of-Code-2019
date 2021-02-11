import java.io.File; 
import java.io.FileNotFoundException;
import java.util.*;


public class DayTwentytwo {
	public static MyLinkedList cards = new MyLinkedList();
	public static int size;
	
	
	public static void cut(int num, boolean forward){
		if(forward){
			int n;
			if(num < 0){
				n = size + num;
			}else{
				n = num;
			}
			cards.cutf(n);
		}else{
			int n;
			if(num < 0){
				n = size + num;
			}else{
				n = num;
			}
			cards.cutf(size-n);
		}
	}
	
	public static void printCards(boolean f){
		if(f){
			int i = 0;
			while(i<size){
				System.out.print(cards.get(i) + " ");
				i++;
			}
		}else{
			int i = size - 1;
			while(i>-1){
				System.out.print(cards.get(i) + " ");
				i--;
			}
		}
	}
	
	public static void increment(int n, boolean f){
		if(f){
			cards = cards.dealWithF(n);
		}else{
			cards = cards.dealWithB(n);
		}
	}
	
	public static void partOne(){
		File f = new File("DayTwentytwoInput.txt"); 
		try{
			Scanner scan = new Scanner(f); 
			String comands[] = new String[150];
			int i = 0;
			while (scan.hasNextLine()){ 
				     comands[i] = scan.nextLine();
				     i++;
			}
			scan.close();
			boolean forward = true;
			
			i = 0;
			//System.out.println("herea");
			while(i<181){
				if(comands[i] == null){
					i = 190;
				}else if(comands[i].contains("cut")){
					int num = Integer.parseInt(comands[i].substring(4));
					//System.out.println("cut " + num);
					cut(num, forward);
				}else if(comands[i].contains("new")){
					//System.out.println("new");
					forward = !forward;
				}else if(comands[i].contains("increment")){
					int num = Integer.parseInt(comands[i].substring(20));
					//System.out.println("increment " + num);
					increment(num, forward);
				}else{
					i = 190;
				}
				i++;
			}
			System.out.println("here");
			//printCards(forward);
			System.out.println(cards.getIndexOf(2019));
			System.out.println(forward);
		}catch(Exception e){
			
		}
		
	}
	
	public static void makeList(int max){
		cards.clear();
		size = max;
		int i = 0;
		while(i<max){
			cards.add(i);
			i++;
		}
	}
	
	public static void partTwo(){
		File f = new File("DayTwentytwoInput.txt"); 
		try{
			Scanner scan = new Scanner(f); 
			String comands[] = new String[150];
			int i = 0;
			while (scan.hasNextLine()){ 
				     comands[i] = scan.nextLine();
				     i++;
			}
			scan.close();
			boolean forward = true;
			long address = 2020;
			long numCards = 119315717514047L;
			Hashtable<Long, Long> adresses = new Hashtable<Long, Long>();
			long t = 0;
			//long address = 4;
			//long numCards = 10;
			while(t<101000L){
				i = 99;
				while(i>-1){
					if(comands[i] == null){
						i = 190;
					}else if(comands[i].contains("cut")){
						long num = Integer.parseInt(comands[i].substring(4));
						if(num<0){
							num = numCards + num;
						}
						address = (address + num )%numCards;
					}else if(comands[i].contains("new")){
						address = numCards - (address+1);
					}else if(comands[i].contains("increment")){	
						long num = Integer.parseInt(comands[i].substring(20));
						boolean d = false;;
						while(!d){
							if(address%num == 0){
								address = address/num;
								d = true;
							}else{
								address+=numCards;
							}
						}
					}else{
						i = 190;
					}
					i--;
				}
				if(adresses.contains(address)){
					System.out.println("periodic");
				}
				adresses.put(address, address);
				//System.out.println(address);
				
			t++;
			}
				
			//the value in the address at the end
			System.out.println(address);
		}catch(Exception e){
			
		}
	}
	
	public static void main(String args[]){
		//makeList(10007);
		//partOne();
		partTwo();
	}
	
}

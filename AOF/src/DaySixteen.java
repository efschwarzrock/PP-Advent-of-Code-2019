/**
 * 
 * Did cheat on part 2 and looked at subredit as well as gravaty moons and day 14
 * @author Erich
 *
 */
public class DaySixteen {
	public static String str = "59728776137831964407973962002190906766322659303479564518502254685706025795824872901465838782474078135479504351754597318603898249365886373257507600323820091333924823533976723324070520961217627430323336204524247721593859226704485849491418129908885940064664115882392043975997862502832791753443475733972832341211432322108298512512553114533929906718683734211778737511609226184538973092804715035096933160826733751936056316586618837326144846607181591957802127283758478256860673616576061374687104534470102346796536051507583471850382678959394486801952841777641763547422116981527264877636892414006855332078225310912793451227305425976335026620670455240087933409";
	static int[] arr = new int[str.length()];
	public static String strTwo = "59728776137831964407973962002190906766322659303479564518502254685706025795824872901465838782474078135479504351754597318603898249365886373257507600323820091333924823533976723324070520961217627430323336204524247721593859226704485849491418129908885940064664115882392043975997862502832791753443475733972832341211432322108298512512553114533929906718683734211778737511609226184538973092804715035096933160826733751936056316586618837326144846607181591957802127283758478256860673616576061374687104534470102346796536051507583471850382678959394486801952841777641763547422116981527264877636892414006855332078225310912793451227305425976335026620670455240087933409";
	static int[] arrTwo = new int[strTwo.length()*10000];
	
	public static void makeArray(){
		int i = 0;
		while(i < str.length()){
			arr[i] = Integer.parseInt(str.substring(i, i+1));
			i++;
		}
	}
	
	public static void makeArrayTwo(){
		int i = 0;
		while(i < strTwo.length()*10000){
			arrTwo[i] = Integer.parseInt(strTwo.substring(i%strTwo.length(), (i%strTwo.length())+1));
			i++;
		}
	}
	
	public static int getStart(){
		return Integer.parseInt(strTwo.substring(0, 7));
	}
	
	public static void partOne(){
		int[] pattern = {0, 1, 0, -1};
		makeArray();
		int[] inputarr = arr.clone();
		int[] outputarr = new int[str.length()];
		System.out.println("output");
		int phase = 0;
		while(phase < 100){
			int pos = 0;
			while(pos < str.length()){
				int output = 0;
				int i = pos;
				while(i < str.length()){
					if(pattern[((i+1)/(pos+1))%4] == 0){
						i = i + pos;
					}else{
						output += inputarr[i]*pattern[((i+1)/(pos+1))%4];
					}
					i++;
				}
				outputarr[pos] = Math.abs(output%10);
				pos++;
			}
			inputarr = outputarr.clone();
			phase++;
		}
		System.out.println("phase " + phase);
		int pos2 = 500;
		while(pos2<508){
			System.out.print(outputarr[pos2] + " ");
			pos2++;
		}
		System.out.print("\n\n");
	}

	public static void partTwo(){
		makeArrayTwo();
		int start = getStart();
		int[] inputarr = arrTwo.clone();
		int[] outputarr = new int[inputarr.length];
		//makeArray();
		//int[] inputarr = arr.clone();
		//int[] outputarr = new int[inputarr.length];
		//int start = 500;
		System.out.println("output" + start);
		System.out.println("output");
		int phase = 0;
		while(phase < 100){
			int pos = inputarr.length - 1;
			outputarr[pos] = inputarr[pos];
			pos--;
			while(pos >= start){
				int output = 0;
				output = inputarr[pos] + outputarr[pos + 1];
				outputarr[pos] = Math.abs(output%10);
				pos--;
			}
			inputarr = outputarr.clone();
			int pos2 = start;
			int i = 0;
			System.out.println("phase " + phase);
			while(i<8 && pos2 < inputarr.length){
				System.out.print(outputarr[pos2] + " ");
				pos2++;
				i++;
			}
			System.out.print("\n");
			phase++;
		}
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		partOne();
		partTwo();
	}

}

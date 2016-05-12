
public class ComplementArray {
	public static void main(String[] args){
		boolean[] arr;
		int i;
		int j;
		
		arr = new boolean[] {true, true, false, true, false, true, false, false, true};
		i = 9;
		
		for(j=0;j<i-1;j++){
			arr[j] = !(arr[j] && arr[j+1]);
		}
	}
}

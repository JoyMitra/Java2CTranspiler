
public class PostfixArray {
	public static void main(String[] args){
		int[] a;
		int i;
		
		a = new int[5];
		for(i=0;i<5;i++){
			a[i] = i;
		}
		
		i=0;
		a[a[i]]++;
		i++;
		a[a[a[i]]]++;
	}
	
}

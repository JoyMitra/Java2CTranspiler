class Res{
	public boolean found;
}

public class BinSearch {
	public static void main(String[] args){
		int[] nos;
		int n;
		int limit;
		int low;
		int mid;
		
		nos = new int[] {1,2,3,4,4,3,2,2,4,2,4,5};
		n = 5;
		limit = 12;
		low = 0;
		while(low < limit){
			mid = (low+limit)/2;
			if(nos[mid]==n){
				new Res().found = true;
				low = limit +1;
			}
			else {
				if(n > nos[mid]){
					low = mid +1;
				}
				else{
					limit = mid -1;
				}
			}
				
		}
	}
}

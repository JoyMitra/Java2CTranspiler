
public class DivisibleByFive {

	public static void main(String[] args) {
		boolean[] result;
		int[] numbers;
		int i;
		
		result = new boolean[5];
		numbers = new int[] {12,32,45,654,23};
		
		for(i=0;i<5;i++){
			if(numbers[i]%5==0){
				result[i] = true;
 			}
		}

	}

}

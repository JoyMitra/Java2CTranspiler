
public class SumOneMillionIntegers {

	public static void main(String[] args) {
		int[] aMillionNos;
		int sum;
		int i;
		int limit;
		int j;
		
		limit = 1000000;
		aMillionNos = new int[limit];
		i = 0;
		j = 0;
		for(i=0;i<limit;i++)
		{
			j = j+3;
			aMillionNos[i] = j;
		}
		i = 0;
		sum = 0;
		for(i=0;i<limit;i++){
			sum = sum + aMillionNos[i];
		}
		
		new Sum().result = sum;
		

	}

}

class Sum{
	public int result;
}

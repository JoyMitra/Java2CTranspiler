public class CreateArrayOfOneMillionObjects {

	public static void main(String[] args) {
		Obj[] arr;
		int i;
		
		arr = new Obj[1000000];
		for(i=0;i<1000000;i++)
		{
			arr[i] = new Obj();
		}

	}

}

class Obj {
	
}

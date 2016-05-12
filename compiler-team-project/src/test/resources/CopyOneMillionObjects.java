class A1{
	public int valueA;
}
public class CopyOneMillionObjects {
	public static void main(String[] args){
		A1[] a;
		B1[] b;
		A1 objA;
		B1 objB;
		int i;
		
		a = new A1[1000000];
		b = new B1[1000000];
		
		for(i=0;i<1000000;i++){
			objA = new A1();
			objA.valueA = i;
			a[i] = objA;
		}
		
		for(i=0;i<1000000;i++){
			objB = new B1();
			b[i] = objB;
		}
		
		for(i=0;i<1000000;i++)
		{
			b[i].valueB = a[i].valueA;
		}
	}
}

class B1{
	public int valueB;
}
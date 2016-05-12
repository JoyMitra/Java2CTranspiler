
public class CopyArrayElemToField {
	public static void main(String[] args){
		ArrCl o;
		
		o = new ArrCl();
		o.a = new int[1];
		o.b = new ArrCl1();
		o.b.c = new ArrCl2();
		
		o.a[0] = 5;
		o.a[0] = o.a[0]*10;
		
		o.b.c.z = o.a[0];
		o.b.c.z++;
		o.a[0] = ~(o.b.c.z);
		
		
	}
}

class ArrCl{
	public ArrCl1 b;
	public int[] a;
}

class ArrCl1{
	public ArrCl2 c;
}

class ArrCl2{
	public int z;
}
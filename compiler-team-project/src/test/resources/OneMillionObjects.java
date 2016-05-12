public class OneMillionObjects {

	public static void main(String[] args) {
		Obj1[] a;
		Obj1 o;
		int i;
		
		a = new Obj1[1000000];
		i = 0;
		
		while(i<1000000){
			o = new Obj1();
			a[i] = o;
			i++;
		}
		
		for(i=0;i<1000000;i++){
			a[i].f = true;
		}

	}

}

class Obj1{
	public boolean f;
}


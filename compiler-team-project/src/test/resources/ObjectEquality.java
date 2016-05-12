class Object100{
	
}
public class ObjectEquality {

	public static void main(String[] args) {
		Object100 o1;
		Object200 o2;
		Object300 o3;
		EqRes e;
		
		o1 = new Object100();
		o2 = new Object200();
		o3 = new Object300();
		e = new EqRes();
		
		if(o1==new Object100()){
			e.res = true;
		}
		if(o2== new Object200()){
			e.res = true;
		}
		if(o3!= new Object300()){
			e.res = false;
		}

	}

}

class Object200{
	
}

class Object300{
	
}

class EqRes{
	public boolean res;
}
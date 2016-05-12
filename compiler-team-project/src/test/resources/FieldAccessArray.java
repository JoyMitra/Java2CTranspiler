class Z{
	public ZA[] za;
}
public class FieldAccessArray {

	public static void main(String[] args) {
		Z z;
		ZA[] zas;
		int j;
		
		z = new Z();
		z.za = new ZA[] {null,new ZA(),new ZA(),null};
		zas = z.za;

		for(j=0;j<4;j++){
			if(zas[j]!=null){
				zas[j].i = j;
			}
			else{
				zas[j] = new ZA();
			}
		}
	}

}

class ZA{
	public int i;
}
class XY{
	public int a;
}
public class ObjectSum {

	public static void main(String[] args) {
		int res;
		XY xy;
		XX xx;
		XZ xz;
		
		xy = new XY();
		xx = new XX();
		xz = new XZ();
		
		res = ObjectSum.sum(xy, xx, xz);

	}
	
	static int sum(XY xy, XX xx, XZ xz){
		xy.a = 5;
		xx.b = xy.a*2;
		xz.c = xx.b/2;
		
		return (xy.a+xx.b+xz.c);
	}

}

class XX{
	public int b;
}

class XZ{
	public int c;
}
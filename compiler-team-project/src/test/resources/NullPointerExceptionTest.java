
public class NullPointerExceptionTest {
	public static void main(String[] args) {
		ANTO1 o;

		o = null;
		o.i = 5;
	}
}
class ANTO1 {
	public int i;
}
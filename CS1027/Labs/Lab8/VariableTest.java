/**
 * VariableTest accesses the static variable from a class
 * @author MeganDaCosta
 *
 */
//Exercise 1
public class VariableTest {

	private static int sNum = 0;
	private int iNum = 0;
	
	public VariableTest () {
		iNum = 5;
	}
	
	public void update (int num) {
		iNum = num;
	}

	public static void main (String[] args) {
//		System.out.println(iNum); //This line won't work because iNum is not a static variable so it needs to be called with an object
		System.out.println(sNum);
		VariableTest vTest = new VariableTest();
		System.out.println(vTest.iNum);
	}
}

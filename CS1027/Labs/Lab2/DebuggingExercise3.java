/**
 * Lab2 debugging3 Focus on following the code and predicting the outcome
 * @author meganDaCosta
 */
//Exercise 4
public class DebuggingExercise3 {
	private static int var1;
	private static MyObject obj1;
	
	private static void method1 (int var1) {
		var1 = 10;
	}
	
	private static void method2 (MyObject obj2) {
		MyObject obj1 = new MyObject("joe");
		
		if (obj1 == obj2) 
			var1 = 20;
		else
			var1 = -20; //joe (obj1) and joe (obj2) may be the same name but this == comparison looks at their object location rather than what the names are and since these locations of these objects are different this statement returns false
		
		obj2 = new MyObject("john");
	}
	
	public static void main(String[] args) {
		var1 = 2;
		obj1 = new MyObject("joe");

		for (int i = 1; i < 2; ++i) { //only goes to 1 and then exits the for loop but the variable assignment is not used anywhere else
			int var1 = i; //This block of code complains because the local variable var1 is not used
		}
		
//		i = 8; //Causes compilation error on first run. Program works when commented out (no output)
		
		method2(obj1);
		
		// What are the values of var1 and obj1.name? var1 is -20 and obj1.name is joe
		
		method1(var1);
			
		// What are the values of var1 and obj1.name? var1 would be 10 (incorrect it equals 2) and obj1.name is joe

	}
}

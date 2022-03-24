//Exercise 3
public class StringCompare {
	
	public static void main(String[] args) {
		String s1, s2, s3, s4;

		s1 = new String("hello");
		s2 = new String("hello");
		// Test 1
		if (s1 == s2) System.out.println("Test 1: true");
		else System.out.println("Test 1: false");           //expected "Test 1: false" because its looking at their addresses

		s3 = "hello";
		s4 = "hello";
		// Test 2
		if (s3 == s4) System.out.println("Test 2: true");
		else System.out.println("Test2: false");	        //expected "Test 2: true" because it is "ranking" the strings against each other but they're the same

		s1 = new String("hello");
		s3 = "hello";
		// Test 3
		if (s1 == s3) System.out.println("Test 3: true");
		else System.out.println("Test 3: false");	          //expected "Test 3: false" because == compares their memory address

		// Test 4
		if (s1.equals(s2)) System.out.println ("Test 4: true");
		else System.out.println("Test 4: false");                   //expected "Test 4: true" because they are different objects

		// Test 5
		if (s3.equals(s4)) System.out.println ("Test 5: true");
		else System.out.println("Test 5: false");                   //expected "Test 5: true" because .equals compares the actual strings at their memory addressed

		// Test 6
		if (s1.equals(s3)) System.out.println ("Test 6: true");
		else System.out.println("Test 6: false");                   //expected; "Test 6: true" 
	}
	
}

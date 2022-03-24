import java.util.Scanner;

/**
 * @author MeganDaCosta - student ID: 251009855
 */
//Exercise 3
public class Permutations {
	
	public void permutations(String prefix, String suffix) {
		if(suffix.length()==0) {
			System.out.println(prefix);
		} else {
			for(int i = 0; i<suffix.length();i++) {
				char c = suffix.charAt(i);
				String suff = removeChar(suffix, i);
	            String pre = prefix + c;
				permutations(pre, suff);
			}
		}
		
	}
	
	private static String removeChar(String s, int i) {
		 return s.substring(0, i) + s.substring(i+1, s.length());
		}
	
	public static void main (String[] args) {
		Scanner scnr = new Scanner(System.in);
		Permutations permut = new Permutations();
		System.out.print("Enter a string: ");
		String word = scnr.next();
		permut.permutations("", word);
		scnr.close();
		
	}

}

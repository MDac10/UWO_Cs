/**
 * @author MeganDaCosta
 */

//Exercise 2
public class Abo {
	
	public int rabo(int n) {
		if(n<=0) {
			return 0;
		} else if(n==1) {
			return 1;
		}else if(n%2==0) {
			return 1 + rabo(n/2);
		} else {
			return 2 + rabo((n+1)/2);
		}
	}
	
//	public int iabo(int n) {
//		
//	}
	
	public static void main (String[] args) {
		Abo abo = new Abo();
		for(int i =0; i<19;i++) {
			System.out.print(abo.rabo(i) + ", ");
		}
		System.out.print(abo.rabo(19));

	}
}

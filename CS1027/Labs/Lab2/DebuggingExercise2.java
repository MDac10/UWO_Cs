/**
 * Lab2 debugging2 Looking at the sequence at which the code occurs to avoid errors
 * @author meganDaCosta
 */
//Exercise 3
public class DebuggingExercise2 {

	private static int load = 1;
	public static void main(String[] args) {
		int i;
		int total;
		
		i = process(2);

		//The value of load coming out of i = process(2) is 0 and when F6 is pressed again it crashes because there was a division by zero
		if (load == 0) {
			System.out.println("The value of total is infinity");
		} else {
			total = (i * 100) / load; //Moved line from above the if statement to the else block so that the division by 0 won't occur and crash the program
			System.out.println("The value of total is " + total);
		}
	}

	private static int process(int step) {
		int i = 1;
		int result = step;
		for (; i <= 3; ++i) {
			result = result * i * step + step;
			if (result > 100) {
				load = 0;
				step = step - result;
			}
			else {
				load = load * result;
				++step;
			}
		}
		
		// What are the values of i, step, result, and load?
		return result;	
	}
}

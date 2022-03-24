/**
 * Lab 2 dubugging1 looking at the range of variables
 * @author meganDaCosta
 */

//Exercise 2
public class DebuggingExercise1 {

	public static void main(String[] args) {
		int[][] testArray = new int[5][6];

		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 6; j++) //changed so that the range starts j at 0 and ends it before it hits 6 (at 5)
				testArray[i][j] = (i + 1) * (j + 1); //correct equation rather than (i+1)*j which would make all first slots in testArray[0][j] equal 0 and throws off all other values
				//testArray[0][0] didn't change using the first equation because both i and j were 0 so when multiplied they also equal 0 and don't change
				//at testArray[0][5] the value was 5 when it should've equaled 6 where i is 0 and j is 5
		printArray(testArray);
	}

	private static void printArray(int[][] array) {
		for (int i = 0; i < array.length; ++i)
			for (int j = 0; j < array[0].length; ++j) {
				System.out.print(array[i][j]);
				if (j < array[0].length - 1)
					System.out.print(", ");
				else
					System.out.print("\n");
			}
	}
}

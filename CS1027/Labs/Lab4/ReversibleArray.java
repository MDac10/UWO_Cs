//Exercise 1

public class ReversibleArray<T> {
	private T[] array;
	private int count;
	
	public ReversibleArray(T[] array) {
		this.array = array;
		count = array.length;
	}
	
	public String toString() {
		String arrayString = "";
		for(int i = 0; i < count-1; i++) {
			arrayString = arrayString + array[i] + ", ";
		}
		return arrayString + array[count - 1];
	}
	
	public void reverse() {
		T tempVar;
		for (int a = 0; a < count/2; a++) {
			tempVar = array[a];
			array[a] = array[count - a - 1];
			array[count - a - 1] = tempVar;
		}
	}
}

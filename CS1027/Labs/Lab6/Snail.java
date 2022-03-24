//Exercise 2
public class Snail {
	
	public static char icon = '@';
	private int position;
	private QueueADT<Integer> movePattern;
	
	public Snail (int[] pattern) {
		position = 0;
		movePattern = new LinkedQueue<Integer>();
		for(int i =0; i<pattern.length;i++) {
			movePattern.enqueue(pattern[i]);
		}
	}
	
	public void move () {
		int first = movePattern.dequeue();
		movePattern.enqueue(first);
		position = position + first;
		if(position==50||position>50) {
			position = 50;
		}
	}
	
	public int getPosition () {
		return position;
	}
	
	public void display () {
		int dashesBefore = position;
		int dashesAfter = 50 - position;
		String display = "";
		for(int i = 0; i < dashesBefore;i++) {
			display = display + "-";
		}
		display = display + icon;
		for(int i = 0; i<dashesAfter; i++) {
			display = display + "-";
		}
		System.out.print(display);
		System.out.println();
	}

}

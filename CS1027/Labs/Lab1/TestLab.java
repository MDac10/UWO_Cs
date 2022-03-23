public class TestLab {

	public static void main(String[] args) {
		//Exercise 2
		Player p1 = new Player("Megan", "Goalie", 4);
		p1.getName();
		p1.getPosition();
		p1.getJerseyNum();
		
		p1.setName("Hermione");
		p1.setPosition("Defence");
		p1.setJerseyNum(7);
		
		p1.getName();
		p1.getPosition();
		p1.getJerseyNum();
		
		System.out.println(p1);
		
		Player p2 = new Player("Hermione", "Defence", 7);
		if (p1.equals(p2)) {
			System.out.println("Same player");
		} else {
			 System.out.println("Different player");
		} //Predicting that program will print "Different player
		//Prediction correct

	}

}

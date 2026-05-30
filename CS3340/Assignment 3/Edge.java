/**
 * @author Megan Da Costa - Student ID: 251009855
 * CS3340 Assignment 3**/
public class Edge {
	
	private int weight;
	private boolean inPath = false;
	
	public void setWeight(int weight) {
		this.weight = weight;
	}
	
	public void markInPath() {
		this.inPath = true;
	}
	
	public int getWeight() {
		return weight;
	}
	
	public boolean getInPath() {
		return inPath;
	}

}

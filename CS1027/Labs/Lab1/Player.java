//Exercise 1

/**
 * Player class sets, gets, and can compare info on players in a game given their name, position, and jersey number
 * @author meganDaCosta
 */

public class Player {
	private String name;
	private String position;
	private int jerseyNum;
	
	/**
	 * This is the constructor so we will be
	 * initializing the member variables here
	 * @param name is name of player
	 * @param position is player's position in game (example: Defense)
	 * @param jerseyNum is number worn on player's jersey
	 */
	public Player(String name, String position, int jerseyNum) {
		this.name = name;
		this.position = position;
		this.jerseyNum = jerseyNum;
	}
	
	/**
	 * Accessor method to get the name of the player
	 * @return the name of the player
	 */
	public String getName() {
		System.out.println(name); //I added the print statement because the lab doc wanted the info printed not just returned even though this isn't a void method
		//Get the player's name
		return name;
	}

	public String getPosition() {
		System.out.println(position);
		return name;
	}
	
	public int getJerseyNum() {
		System.out.println(jerseyNum);
		return jerseyNum;
	}
	
	/**
	 * Setter method that takes a given parameter and assigns it as a variable
	 * @param newName changes the variable name to itself
	 */
	public void setName(String newName) {
		this.name = newName;
	}
	
	public void setPosition(String newPosition) {
		this.position = newPosition;
	}
	
	public void setJerseyNum(int newJerseyNum) {
		this.jerseyNum = newJerseyNum;
	}
	
	//Exercise 3
	public String toString() {
		return name + ": #" + jerseyNum;
	}
	
	public boolean equals(Player other) {
		if (this.name.equals(other.name) && this.jerseyNum == other.jerseyNum) {
			return true;
		} else {
			return false;
		}
	}
			
}

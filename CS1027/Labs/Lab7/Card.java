/**
 * Card ranks cards from a deck or those that are input by their ranks and then their suits
 * @author MeganDaCosta - student ID: 251009855
 */
//Exercise 1
public class Card implements Comparable<Card>{
	
	private String suit; // S (spade), H (heart), D (diamond), or C (club)
	private String rank; // A (ace), 2, 3, ..., 10, J (jack), Q (queen), or K (king)

	public Card (String suit, String rank) {
		this.suit = suit;
		this.rank = rank;
	}

	public String getSuit () {
		return suit;
	}
	
	public String getRank () {
		return rank;
	}
	
	public void setSuit (String suit) {
		this.suit = suit;
	}
	
	public void setRank (String rank) {
		this.rank = rank;
	}
	
	public String toString () {
		return this.rank + " of " + this.suit;
	}
	
	public int getSuitValue() {
		int suitValue = 0;
		if(suit.equals("D")) {
			suitValue = 1;
		} else if(suit.equals("C")) {
			suitValue = 2;
		} else if(suit.equals("H")) {
			suitValue = 3;
		} else if (suit.equals("S")){
			suitValue = 4;}
		return suitValue;
	}
	
	public int getRankValue() {
		int rankValue = 0;
		if(rank.equals("J") || rank.equals("Q") || rank.equals("K")) {
			rankValue = 11;
		} else if(rank.equals("A")) {
			rankValue = 12;
		} else { rankValue = Integer.parseInt(rank);}
		return rankValue;
	}
	
	public boolean equals(Card other) {
		if (this.rank.equals(other.rank) && this.suit.equals(other.suit)) {
			return true;
		} else {
			return false;}
	}

	@Override
	public int compareTo(Card other) {
		if(this.equals(other)) {
		return 0;
		}
		if(this.getRankValue()!=other.getRankValue()) {
			if(this.getRankValue()<other.getRankValue()) {
				return -1;
			} else {return 1;}
		}
		if(this.getSuitValue()<other.getSuitValue()) {
			return -1;
		} else {return 1;}
	}
}

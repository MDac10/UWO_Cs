//Exercise 2

import java.util.StringTokenizer;

public class HTMLChecker {
	
	private String text;
	private String[] tags;
	private int tagNum;
	private ArrayStack<String> stack;
	
	public HTMLChecker (String input) {
		tags = new String[5];
		text = input;
		stack = new ArrayStack<String>();
		
		parseText();
	}
	
	public void parseText() {
		int openCounter = 0;
		int closeCounter = 0;
		int slashCounter = 0;
		int open;
		int newOpen = 0;
		String tagTracker = "";
		boolean stackTrack = true;
		stack = new ArrayStack<String>();
		for(int i = newOpen; i<text.length(); i++) {
			if(text.charAt(i)=='<'){
				openCounter++;
				open = text.indexOf('<', newOpen) + 1;
				for(int j = open; j < text.indexOf('>', open); j++) {
					tagTracker = tagTracker + text.charAt(j);
					newOpen = text.indexOf('>', open) + 1;}
				closeCounter++;
				if(tagTracker.charAt(0)=='/'){
					slashCounter++;
					tagTracker = tagTracker.replaceFirst("/", "");
					try {
						String var = stack.pop();
						if(var.equals(tagTracker)) {
							stackTrack = true;
							tagTracker = "";
						}else {stackTrack = false;}
					}
					catch ( EmptyCollectionException e) {
						continue;
					}
				}else {
				addTagToArray(tagTracker);
				stack.push(tagTracker);
				tagTracker = "";
				continue;
				}
			}
		}
		if(text.charAt(0) != '<' || text.charAt(text.length()-1) != '>') {
			System.out.println("The HTML is NOT formatted correctly");
		} else if ((openCounter==closeCounter) && (slashCounter==openCounter/2) && (stackTrack == true)) {
			System.out.print("The HTML is formatted correctly:");
			printTagList();
		} else {System.out.println("The HTML is NOT formatted correctly");}
	}
	/**
	 * Check if the given tag is already contained in the array of tags. If not, it adds it to
	 * the array, otherwise nothing is done. This is so we can avoid duplicate tags.
	 * @param tag the tag that has just been encountered in HTML to be added to the array, unless
	 * it has been added previously
	 */
	public void addTagToArray (String tag) {
		boolean found = false;
		
		// Loop through array and check if the input tag is already there.
		for (int i = 0; i < tags.length; i++) {
			if (tags[i] != null && tags[i].equals(tag)) {
				found = true;
			}
		}
		
		// If the tag was found in the array, then do nothing. Otherwise, add it to the array.
		if (!found) {
			
			// Expand capacity if needed.
			if (tagNum == tags.length) {
				expandCapacity();
			}
			
			// Add tag to array and increment counter;
			tags[tagNum] = tag;
			tagNum++;
			
		}
	}
	
	/**
	 * Expand the array's capacity by adding 5 additional slots.
	 */
	private void expandCapacity () {
		String[] larger = new String[tags.length + 5];
		
		// Transfer existing items to the new, larger array.
		for (int i = 0; i < tags.length; i++) {
			larger[i] = tags[i];
		}
		
		tags = larger;
	}
	
	/**
	 * Print out the array of tags that were found in the HTML input.
	 */
	public void printTagList () {
		String str = "";
		
		for (int i = 0; i < tags.length; i++) {
			
			if (tags[i] != null) {
				str += tags[i] + " ";
			}
		}
		
		System.out.println(str);
	}
	
	
	
	public static void main (String[] args) {
		
		String s1 = "Stacks are helpful in many computer applications</h2>";
		new HTMLChecker(s1);

		String s2 = "<p>Java is my favourite language!</p><p>Programming is fun";
		new HTMLChecker(s2);

		String s3 = "<h1><i>I am learning a lot in CS 1027!</h1></i>";
		new HTMLChecker(s3);

		String s4 = "<table><tr><td>Python</td><td>Java</td></tr><tr><td>1026</td><td>1027</td></tr></table>";
		new HTMLChecker(s4);
		
		String s5 = "<html><head><title>My Website</title></head><body><h1>Welcome to my website!</h1><p>This is my website about Java programming.</p><p>Thanks for stopping by.</p></body></html>";
		new HTMLChecker(s5);

		
	}

}

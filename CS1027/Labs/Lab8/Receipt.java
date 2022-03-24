/**
 * Receipt prints a receipt based on the item values input into Product class
 * @author MeganDaCosta - student ID: 251009855
 */

//Exercise 4
public class Receipt {
	
	public Receipt(Product[] cart) {
		String name, code;
		double cost,costTax;
		double total = 0.0;
		System.out.println("Item:\tCode:\tCost:\tCost+Tax:");
		System.out.println("----------------------------------");
		for(int i = 0; i<cart.length; i++) {
			name = cart[i].getName();
			code = cart[i].getCode();
			cost = cart[i].getCost();
			costTax = cost*Product.getTax() + cost;
			System.out.printf("%s\t%s\t%.2f\t%.2f\n", name, code, cost, costTax);
			total = total + costTax;
		}
		System.out.println("----------------------------------");
		System.out.println(String.format("\t\t\t%.2f", total));
		
		
	}
	
	public static void main (String[] args) {
		Product[] prod = new Product[3];
		Product item1 = new Product("Bacon", "BC14769", 4.84);
		prod[0] = item1;
		Product item2 = new Product ("Eggs", "EG985", 3.16);
		prod[1] = item2;
		Product item3 = new Product("Milk", "MLK1964", 2.47);
		prod[2] = item3;
		
		Receipt print = new Receipt(prod);
	}

}

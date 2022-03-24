//Exercise 1

public class SavingsAccount extends BankAccount {
	private double interestRate;
	
	public SavingsAccount(double initialAmount, double rate) {
		super(initialAmount);
		interestRate = rate;
	}
	
	public double getInterestRate() {
		return interestRate;
	}
	
	public void calculateInterest() {
		double monthlyInterest = super.getBalance() * getInterestRate();
		double newBalance = super.getBalance() + monthlyInterest;
		super.deposit(newBalance);
	}
	
	public String toString() {
		return String.format("SavingsAccount: balance $%d, interest rate %.2f", (int)super.getBalance(), getInterestRate());
	}
	
	public static void main(String[] args) {
        SavingsAccount myAccount = new SavingsAccount(100.0,0.15);
	myAccount.calculateInterest();
	System.out.println(myAccount.toString());
	}

}
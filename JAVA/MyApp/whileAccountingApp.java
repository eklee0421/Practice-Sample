public class whileAccountingApp {
	public static void main(String[] args) {
    
    //콘솔에서 입력 받기
    Scanner sc = new Scanner(System.in);
    double valueOfSupply = sc.next();
    
		double vatRate = 0.1;
		double expenseRate = 0.3;
		
		double vat = valueOfSupply *vatRate;
		double total = valueOfSupply + valueOfSupply * vatRate;
		double expense = valueOfSupply * expenseRate;
		double income = valueOfSupply - expense;
		double dividend = income;
    
    double[] dividendRates = new double[3];
    dividendRates[0] = 0.5;
    dividendRates[1] = 0.3;
    dividendRates[2] = 0.2;
        
		System.out.println("Value of supply: " + valueOfSupply);
		System.out.println("VAT: " + vat);
		System.out.println("Total: " + total);
		System.out.println("Expense: " + expense);
		System.out.println("Income: " + income);
		
    int i = 0;
    while (i < dividendRates.length) {
        System.out.println("Dividend " i + ": " + income * dividendRates[i]);
        i = i + 1;
    }
		
	}
}

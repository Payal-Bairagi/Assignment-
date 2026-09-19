public class Program {
	
	public static void main(String[] args) {
		
		boolean status = true;
		Date objDate = null;
		
		while(status) {
			
			System.out.println("-----------------------------------------");
			System.out.println("Press 1 to set Date");
			System.out.println("Press 2 to Add Days");
			System.out.println("Press 3 to set Month");
			System.out.println("Press 4 to Compare date");
			System.out.println("Press 5 to Exit");
			System.out.println("-----------------------------------------");
			
			int userInput = ConsoleInput.getInt();
			
			if(userInput == 1) {
				System.out.println("Enter the date: ");
				int date = ConsoleInput.getInt();

				System.out.println("Enter thr month: ");
				int month = ConsoleInput.getInt();

				System.out.println("Enter thr year: ");
				int year = ConsoleInput.getInt();
				objDate = new Date(date,month,year);
				objDate.display();
			}
			
			if(objDate!=null) {
				if(userInput == 5)
					status = false;
				else {
					objDate.callingMethod(userInput);
					
				}
			}
			else {
				System.out.println("Please Set the Date First.");
			}
			
			
			
		}
		
	}
}
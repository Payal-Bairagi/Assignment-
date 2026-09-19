
public class Date {
	private int date;
	private int month;
	private int year;
	
	public Date(int dd, int mm, int yy) {
		
		year = yy;
		
		//Month validation
		if(mm>=1 && mm<=12) 
			month = mm;
		else {
			System.out.println("Invalid month!! setting it to 1.");
			month = 1;
			mm = 1;
		}
		setDate(dd);
		display();
			
		
	}
	
	//getter
	public int getDate() {
		return date;
	}

	public int getMonth() {
		return month;
	}

	public int getYear() {
		return year;
	}

	
	
	//31 days -> 1, 3, 5, 7, 8, 10, 12
	//30 days -> 4, 6, 9, 11
	//February -> 2
	
	//set Date
	public void setDate(int dd) {
		int mm = month;
		//31 days months validation
		if(mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) {
			if(dd>=1 && dd<=31) 
				date = dd;
			else {
				System.out.println("Invalid month!! setting it to 1.");
				date = 1;
			}
					
			
		}
		//month of 30 days validation
		if(mm == 2 || mm == 4 || mm == 6 || mm == 8 || mm == 9 || mm == 11) {
			
			if(mm==2) {
				
				//checking leap year
				if(isLeapYear(year))
					if(dd>=1 && dd<=29) 
						date = dd;
					else {
						System.out.println("Invalid date in Feb month!! setting it to 1.");
						date = 1;
					}
				else
				{
					if(dd>=1 && dd<=28) 
						date = dd;
					else {
						System.out.println("Invalid date in Feb month!! setting it to 1.");
						date = 1;
					}
				}
				
						
			}
			else {
				if(dd>=1 && dd<=30) 
					date = dd;
				else {
					System.out.println("Invalid date!! setting it to 1.");
					date = 1;
				}
			}
		}
	}
	
	//Add days
	public void addDays(int num) {
		for(int i = 1;i<=num;i++) {
			date++;       
			if(date> daysInMonth(month)) {
				
				month++;
				date=1;
				
				
				if(month>12) {
					month = 1;
					year++;
				}
			}
		}
	}
	
	//31 days -> 1, 3, 5, 7, 8, 10, 12
	//30 days -> 4, 6, 9, 11
	//February -> 2
	//Days In Month
	public int daysInMonth(int month) {
		
		if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) 
			return 31;
		
		else if(month == 4 || month == 6 || month == 9 || month == 11 )
			return 30;
		
		else {
			if(isLeapYear(year)) 
				return 29;
			else
				return 28;			
		}
	}
	
	//Leap year
	public Boolean isLeapYear(int year) {
		if(year%400 == 0 || (year%4 == 0 && year%100 != 0))
			return true;
		else
			return false;
	}
	
	//Add month
	public void addMonth(int num) {
		
		for(int i=0;i<num;i++) {
			month++;
			if(month>12) {
				month = 1;
				year++;
			}
			if(date > daysInMonth(month)) {
				date = daysInMonth(month);
			}
		}
	}
	//Display method
	public void display() {
		System.out.println("Date: " + getDate() + "/" + getMonth() + "/" + getYear());
	}
	
	//Calling method based on user
	public void callingMethod(int input) {
		if(input == 2) {
			System.out.println("Enter number of days to add: ");
			int num = ConsoleInput.getInt();
			addDays(num);
			display();
		}
		else if(input == 3) {
			System.out.println("Enter number of month to add: ");
			int num = ConsoleInput.getInt();
			addMonth(num);
			display();
		}
		else if(input == 4) {
			System.out.println("Enter Date to compare: ");
			System.out.println("Done!");
			display();	
		}
		else if(input<0 && input >4) {
			System.out.println("Enter valid Input");
		}
			
	}
	
}
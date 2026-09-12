
public class Employee {
             String name;
             int year_of_joining;
             int salary;
             String address;
             
             void setData(String n, int y,int s, String a) {
                   name = n;
                   year_of_joining = y;
                   salary = s;
                   address = a;
}
             void display() {
            	 System.out.println(name + "\t" + year_of_joining + "\t\t\t"  + address);
             }
public static void main(String[] args) {
             Employee e1 = new Employee();
             Employee e2 = new Employee();
             Employee e3 = new Employee();

             // Assign values
             e1.setData("Robert", 1994, 50000, "64C- WallsStreet");
             e2.setData("Sam", 2000, 60000, "68D- WallsStreet");
             e3.setData("John", 1999, 55000, "26B- WallsStreet");

             // Print heading
             System.out.println("Name\t Year of joining\t Address");

             // Display data
             e1.display();
             e2.display();
             e3.display();
         }
}
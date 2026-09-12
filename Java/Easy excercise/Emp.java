

public class Emp {
	int salary;
    int hours;

    // Method to get info
    void getInfo(int s, int h) {
        salary = s;
        hours = h;
    }

    // Add $10 if salary < 500
    void addSal() {
        if (salary < 500) {
            salary = salary + 10;
        }
    }

    // Add $5 if working hours > 6
    void addWork() {
        if (hours > 6) {
            salary = salary + 5;
        }
    }

    void display() {
        System.out.println("Final Salary = " + salary);
    }
    public static void main(String[] args) {

        Emp e = new Emp();

        // Assign values (example)
        e.getInfo(400, 7);

        e.addSal();
        e.addWork();

        e.display();
    }
}



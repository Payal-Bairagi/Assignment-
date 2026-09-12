public class Entry {

    static Employee[] emp = new Employee[100];
    static int count = 0;
    static int current = -1;

    public static void main(String[] args) {

        while (true) {

            System.out.println("\n1. Add Employee");
            System.out.println("2. Display");
            System.out.println("3. Sort");
            System.out.println("4. Exit");

            int choice = ConsoleInput.getInt();

            switch (choice) {

                case 1:
                    addEmployee();
                    break;

                case 2:
                    displayMenu();
                    break;

                case 3:
                    sortEmployees();
                    break;

                case 4:
                    System.exit(0);
            }
        }
    }

    // ================= ADD =================
    static void addEmployee() {

        System.out.println("a. Manager");
        System.out.println("b. Engineer");

        char ch = ConsoleInput.getChar();

        System.out.println("Enter name:");
        String name = ConsoleInput.getString();

        System.out.println("Enter address:");
        String address = ConsoleInput.getString();

        System.out.println("Enter age:");
        int age = ConsoleInput.getInt();

        System.out.println("Enter gender:");
        char gender = ConsoleInput.getChar();

        System.out.println("Enter salary:");
        double salary = ConsoleInput.getDouble();

        if (ch == 'a') {
            System.out.println("Enter HRA:");
            double hra = ConsoleInput.getDouble();

            emp[count++] = new Manager(name, address, age, gender, salary, hra);
        }

        else if (ch == 'b') {
            System.out.println("Enter overtime:");
            float ot = ConsoleInput.getFloat();

            emp[count++] = new Engineer(name, address, age, gender, salary, ot);
        }

        current = count - 1;
    }

    // ================= DISPLAY =================
    static void displayMenu() {

        if (count == 0) {
            System.out.println("No Employees");
            return;
        }

        System.out.println("a. All");
        System.out.println("b. First");
        System.out.println("c. Next");
        System.out.println("d. Previous");
        System.out.println("e. Last");

        char ch = ConsoleInput.getChar();

        switch (ch) {

            case 'a':
                for (int i = 0; i < count; i++) {
                    emp[i].display();
                }
                break;

            case 'b':
                current = 0;
                emp[current].display();
                break;

            case 'c':
                if (current < count - 1) current++;
                emp[current].display();
                break;

            case 'd':
                if (current > 0) current--;
                emp[current].display();
                break;

            case 'e':
                current = count - 1;
                emp[current].display();
                break;
        }
    }

    // ================= SORT =================
    static void sortEmployees() {

        // Simple bubble sort (ascending by name)
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {

                if (emp[j].getName().compareTo(emp[j + 1].getName()) > 0) {

                    Employee temp = emp[j];
                    emp[j] = emp[j + 1];
                    emp[j + 1] = temp;
                }
            }
        }

        System.out.println("Sorted Successfully!");
    }
}
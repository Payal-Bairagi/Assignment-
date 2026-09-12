class Engineer extends Employee {

    private float overtime;

    // Override method
    @Override
    String getRole() {
        return "Engineer";
    }

    // Constructor
    public Engineer(String name, String address, int age, char gender, double basicsalary, float overtime) {
        super(name, address, age, gender, basicsalary);
        this.overtime = overtime;
    }

    // Getter
    public float getOvertime() {
        return overtime;
    }

    // Setter
    public void setOvertime(float overtime) {
        this.overtime = overtime;
    }

    // Display method
    void display() {
        System.out.println("Name: " + name);
        System.out.println("Address: " + address);
        System.out.println("Age: " + age);
        System.out.println("Gender: " + gender);
        System.out.println("Salary: " + basicsalary);
        System.out.println("Overtime: " + overtime);
    }
}
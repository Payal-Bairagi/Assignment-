
class Manager extends Employee {
    private double hra;

    @Override
    String getRole() {
        return "Manager";
    }

    public Manager(String name, String address, int age, char gender, double basicsalary, double hra) {
        super(name, address, age, gender, basicsalary);
        this.hra = hra;
    }

    public double getHra() {
        return hra;
    }

    public void setHra(double hra) {
        this.hra = hra;
    }

    void display() {
        System.out.println("Name: " + name);
        System.out.println("Address: " + address);
        System.out.println("Age: " + age);
        System.out.println("Gender: " + gender);
        System.out.println("Salary: " + basicsalary);
    }
}

class SalesPerson extends Employee {

    double commission;

    @Override
    String getRole() {
        return "SalesPerson";
    }

    public SalesPerson(String name, String address, int age, char gender, double basicsalary, double commission) {
        super(name, address, age, gender, basicsalary);
        this.commission = commission;
    }

    void display() {
        System.out.println("Name: " + name);
        System.out.println("Address: " + address);
        System.out.println("Age: " + age);
        System.out.println("Gender: " + gender);
        System.out.println("Salary: " + basicsalary);
        System.out.println("Commission: " + commission);
    }
}

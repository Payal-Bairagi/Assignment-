class Member {
    private String name;
    private int age;
    private String phoneNumber;
    private String address;
    private float salary;

    // Setters & Getters
    public void setName(String name) { this.name = name; }
    public String getName() { return name; }

    public void setAge(int age) { this.age = age; }
    public int getAge() { return age; }

    public void setPhoneNumber(String phoneNumber) { this.phoneNumber = phoneNumber; }
    public String getPhoneNumber() { return phoneNumber; }

    public void setAddress(String address) { this.address = address; }
    public String getAddress() { return address; }

    public void setSalary(float salary) { this.salary = salary; }
    public float getSalary() { return salary; }

    public void printSalary() {
        System.out.println("Salary: " + salary);
    }
}

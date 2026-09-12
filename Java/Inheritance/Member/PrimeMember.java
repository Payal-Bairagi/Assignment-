class PrimeMembers extends Member {
    private int joiningYear;
    private float joiningFees;
    private boolean isActive;

    public void setJoiningYear(int joiningYear) { this.joiningYear = joiningYear; }
    public void setJoiningFees(float joiningFees) { this.joiningFees = joiningFees; }
    public void setIsActive(boolean isActive) { this.isActive = isActive; }

    public void display() {
        System.out.println("\n--- Member Details ---");
        System.out.println("Name: " + getName());
        System.out.println("Age: " + getAge());
        System.out.println("Phone: " + getPhoneNumber());
        System.out.println("Address: " + getAddress());
        printSalary();

        System.out.println("\n--- Prime Member Details ---");
        System.out.println("Joining Year: " + joiningYear);
        System.out.println("Joining Fees: " + joiningFees);
        System.out.println("Active: " + isActive);
    }
}


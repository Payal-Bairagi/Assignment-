
abstract class Employee {
    protected String name;
    protected String address;
    protected int age;
	protected char gender;
    protected double basicsalary;
  
abstract String getRole();


	public Employee(String name, String address, int age, char gender, double basicsalary) {
		super();
		this.name = name;
		this.address = address;
		this.age = age;
		this.gender = gender;
		this.basicsalary = basicsalary;
	}


	public String getName() {
		return name;
	}


	public void setName(String name) {
		this.name = name;
	}


	public String getAdress() {
		return address;
	}


	public void setAdress(String adress) {
		this.address = adress;
	}


	public int getAge() {
		return age;
	}


	public void setAge(int age) {
		this.age = age;
	}


	public char getGender() {
		return gender;
	}


	public void setGender(char gender) {
		this.gender = gender;
	}
	
	public double getBasicsalary() {
		return basicsalary;
	}
	
	public void setBasicsalary(double basicsalary) {
		this.basicsalary = basicsalary;
	}
	void display() {
		System.out.println("Name:" +name);
		System.out.println("Address:" + address);
		System.out.println("Age:" + age);
		System.out.println("Gender:" +gender);
		System.out.println("Salary:" + basicsalary);
		System.out.println("Role:" + getRole());
	}
}
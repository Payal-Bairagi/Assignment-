public class Student {
             String name;
             int roll_no;
             String phone_no;
             String address;
             
             
             void display() {
             System.out.println("Name:" +name);
             System.out.println("Roll_no:" +roll_no);
             System.out.println("Phone_no:" +phone_no);
             System.out.println("Address:" +address);
}


public static void main(String[] args) {
      Student s1 = new Student();
      s1.name = "Jhon";
      s1.roll_no= 2;
      
      Student s2 = new Student();
      s2.name = "Sam";
      s2.roll_no = 1;
      s2.phone_no = "9876543210";
      s2.address = "Sangamner";
      
      Student s3 = new Student();
      s3.name = "John";
      s3.roll_no = 2;
      s3.phone_no = "9123456780";
      s3.address = "Mumbai";
      
      s2.display();
      s3.display();
}
}

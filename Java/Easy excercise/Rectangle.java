
public class Rectangle {
	  int length, breadth;

	    // Constructor
	    Rectangle(int l, int b) {
	        length = l;
	        breadth = b;
	    }

	    void displayArea() {
	        int area = (length * breadth);
	        System.out.println("Area = " + area);
	    }


    public static void main(String[] args) {

        // Object created using constructor
        Rectangle r1 = new Rectangle(4,5);
        Rectangle r2 = new Rectangle(5,8);
        r1.displayArea();
        r2.displayArea();
    }
}


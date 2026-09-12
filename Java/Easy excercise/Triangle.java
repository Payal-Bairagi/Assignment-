
public class Triangle {
        int side1;
        int side2;
        int side3;
        Triangle(int x, int y, int z){
        	side1 = x;
        	side2 = y;
        	side3 = z;
        }	
        	void displayPerimeter() {
        		int perimeter = side1 + side2 + side3;
                System.out.println("Perimeter = " + perimeter);
        	}
        
            public static void main(String[] args) {

                // Object created using constructor
                Triangle t = new Triangle(3,4,5);

                t.displayPerimeter();
            }
        }   


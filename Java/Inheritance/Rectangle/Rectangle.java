// Parent class
class Rectangle {
    protected float length;
    protected float breadth;

    // Constructor
    Rectangle(float length, float breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    // Method to calculate area
    void printArea() {
        System.out.println("Area: " + (length * breadth));
    }

    // Method to calculate perimeter
    void printPerimeter() {
        System.out.println("Perimeter: " + (2 * (length + breadth)));
    }
}



class Shape {
    void printShape() {
        System.out.println("This is shape");
    }
}

// Rectangle class inherits Shape
class Rectangle extends Shape {
    void printRectangle() {
        System.out.println("This is rectangular shape");
    }
}

// Circle class inherits Shape
class Circle extends Shape {
    void printCircle() {
        System.out.println("This is circular shape");
    }
}

// Square class inherits Rectangle
class Square extends Rectangle {
    void printSquare() {
        System.out.println("Square is a rectangle");
    }


public class Main{
    public static void main(String[] args) {

        Square obj = new Square();

        obj.printShape();      // from Shape
        obj.printRectangle();  // from Rectangle
        obj.printSquare();     // from Square
    }
}
}

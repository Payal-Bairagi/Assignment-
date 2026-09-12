public class Main1 {
    public static void main(String[] args) {

        // Rectangle object
        Rectangle rect = new Rectangle(10, 5);
        System.out.println("Rectangle:");
        rect.printArea();
        rect.printPerimeter();

        // Square object
        Square sq = new Square(4);
        System.out.println("\nSquare:");
        sq.printArea();
        sq.printPerimeter();
    }
}
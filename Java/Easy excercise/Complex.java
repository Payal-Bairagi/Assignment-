
public class Complex {
         int real;
         int imag;
         
         void set(int r, int i) {
             real = r;
             imag = i;
         }
         void sum(Complex c) {
             int r = real + c.real;
             int i = imag + c.imag;
             System.out.println("Sum = " + r + " + " + i + "i");
                  
         }
         // Difference
         void difference(Complex c) {
             int r = real - c.real;
             int i = imag - c.imag;
             System.out.println("Difference = " + r + " + " + i + "i");
         }
         

         // Product
         void product(Complex c) {
             int r = (real * c.real) - (imag * c.imag);
             int i = (real * c.imag) + (imag * c.real);
             System.out.println("Product = " + r + " + " + i + "i");
         }
    public static void main(String[] args) {

        Complex c1 = new Complex();
        Complex c2 = new Complex();

        // Assign values directly
        c1.set(2, 3);   // 2 + 3i
        c2.set(4, 5);   // 4 + 5i

        c1.sum(c2);
        c1.difference(c2);
        c1.product(c2);
    }
}    
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         


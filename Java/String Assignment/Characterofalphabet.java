
public class Characterofalphabet  {
	    public static void main(String[] args) {
	        String str = "abcdefghijklmnopqrstuvwxyz";
	        String test = "the quick brown fox jumps over the lazy dog";

	        System.out.println("a b c d e f g h i j");
	        System.out.println("=========================");

	        for (char ch = 'a'; ch <= 'j'; ch++) {
	            System.out.print(test.indexOf(ch) + " ");
	        }

	        System.out.println("\n");

	        System.out.println("k l m n o p q r s t");
	        System.out.println("===========================");

	        for (char ch = 'k'; ch <= 't'; ch++) {
	            System.out.print(test.indexOf(ch) + " ");
	        }

	        System.out.println("\n");

	        System.out.println("u v w x y z");
	        System.out.println("================");

	        for (char ch = 'u'; ch <= 'z'; ch++) {
	            System.out.print(test.indexOf(ch) + " ");
	        }
	    }
	}

